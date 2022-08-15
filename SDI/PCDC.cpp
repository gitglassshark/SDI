#include "pch.h"
#include "PCDC.h"
#include "muse.h"

//size_t PCDC::icount = 0;

class CColor dccr;
PCDC* pcout = nullptr;

CString hex( ) { return CString( ); }
CString HEX( ) { return CString( ); }
CString oct( ) { return CString( ); }
CString udec( ) { return CString( ); }
CString address( ) { CString cs; return cs; }

PCDC& sp( PCDC& dc ) { return  dc << "  "; }
PCDC& dash( PCDC& dc ) { return dc << "-";; }
PCDC& com( PCDC& dc ) { return dc << ','; }
PCDC& tab( PCDC& dc ) { return dc << '\t'; }
PCDC& semi( PCDC& dc ) { return dc << ';'; }


PCDC& nl( PCDC& dc ) {
	if ( dc.p.x == dc.mrect.left + dc.initalpos )
		return dc;
	return  dc << '\n';
}
PCDC& newl( PCDC& dc )
{
	return  dc << '\n';
}
PCDC& endl( PCDC& dc )
{
	if ( dc.p.x == dc.mrect.left + dc.initalpos )
		return dc;
	return  dc << '\n';
}
PCDC& cut( PCDC& dc )
{
	dc.cut( );
	return dc;
}
PCDC& star( PCDC& dc ) { return dc << "*"; }
PCDC& separtor( PCDC& dc )
{
	if ( dc.p.x != dc.mrect.left + dc.initalpos )
		dc << nl;
	dc.cut( );
	return 	dc;
}

PCDC& clear( PCDC& dc )
{
	dc.flushscreen( );
	return dc;
}
PCDC& cl( PCDC& dc )
{
	dc.flushscreen( );
	return dc;
}



PCDC::PCDC( CWnd* pwnd ) :m_pwnd( pwnd )
{
	if ( ( m_pwnd != nullptr ) && ( this != nullptr ) )
	{
		//id = icount;
		//++icount;
		bool iret = Create( m_pwnd );
		if ( iret == false )
			AfxMessageBox( _T( "Create XCout is faile!" ) );
	}
}

PCDC::~PCDC( )
{
	//--icount;
	if ( ( this != nullptr ) && ( icreate != false ) )
	{
		bool iret = this->Release( );
		if ( iret == false )
			AfxMessageBox( _T( "Relase XCout is faile!" ) );
	}
}

inline bool PCDC::Create( CWnd* pwnd )
{
	if ( ( pwnd != nullptr ) && ( icreate != true ) && ( this != nullptr ) )
	{
		m_pwnd = pwnd;
		CDC* pdc = m_pwnd->GetWindowDC( );
		if ( pdc != nullptr ) {
			m_hDC = pdc->m_hDC;
			CDC& dc = *this;

			//设置缺省字体
			LOGFONT lf;
			// zero out structure
			memset( &lf , 0 , sizeof( LOGFONT ) );
			font.CreatePointFont( this->mfontsize , _T( "Cascadia Code SemiLight" ) );
			pfont = dc.SelectObject( &font );
			if ( pfont != nullptr )
			{
				//设置窗口背景颜色
				dc.SetBkColor( m_bk );
				//设置字体颜色
				dc.SetTextColor( m_tk );
				flushscreen( );

				//根据字体大小调整步长
				font.GetLogFont( &lf );
				step = abs( lf.lfHeight + lf.lfHeight / 2 );

				//设置日志记录容量
				size_t maxline = getmaxline( );
				size_t totalmaxline = maxline * maxrecode;
				mvlogs.reserve( totalmaxline );

				//检查输出位置
				if ( !dc.PtVisible( p ) ) {
					p.x = initalpos;
					p.y = initalpos;
				}

				icreate = true;
				pXCout = this;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

inline bool PCDC::Release( )
{
	if ( ( icreate != false ) && ( this != nullptr ) )
	{
		CDC& dc = *this;
		if ( pfont != nullptr )
			dc.SelectObject( pfont );
		if ( m_pwnd != nullptr )
		{
			m_pwnd->ReleaseDC( this );
		}
		font.DeleteObject( );
		m_pwnd = nullptr;
		pfont = nullptr;
		pXCout = nullptr;
		icreate = false;
		return true;
	}
	else
	{
		return false;
	}
	//m_cdc = nullptr;
}

PCDC& PCDC::resettcolor( )
{
	SetTextColor( m_tk );
	return *this;
}

PCDC& PCDC::settcolor( COLORREF tk )
{
	SetTextColor( tk );
	return *this;
}

PCDC& PCDC::setcolor( COLORREF line , COLORREF bar , COLORREF bk , COLORREF tk )
{
	m_bk = bk;
	m_tk = tk;
	m_bark = bar;
	m_linek = line;
	return *this;
}

PCDC& PCDC::lmod( unsigned char  imod )
{
	ilinemod = imod;
	return *this;
}

char PCDC::setlinechar( const char& c )
{
	char rc = mlinechar;
	mlinechar = c;
	return rc;
}

PCDC& PCDC::flushscreen( const CRect* r , const COLORREF* cr )
{
	m_pwnd->GetClientRect( &mrect );
	//CRect rect( mrect );
	//if ( r != nullptr ) { mrect = *r; } else { }
	//cr != nullptr ? m_bk = *cr : true;
	rinitxy( );
	auto rect = mrect;
	auto iwbar = initalpos / 4;
	//rect.left = 0;
	//rect.top = 0;
	FillSolidRect( rect , m_bark );

	rect.bottom -= iwbar;
	rect.left += iwbar;
	rect.right -= iwbar;
	rect.top += iwbar;
	FillSolidRect( rect , m_linek );

	rect.bottom -= iwbar;
	rect.left += iwbar;
	rect.right -= iwbar;
	rect.top += iwbar;
	FillSolidRect( rect , m_bk );
	return *this;
}

PCDC& PCDC::displayfile( CString filename )
{
	if ( filename.IsEmpty( ) )
		return *this;

	CFile cfile;
	bool iresult = cfile.Open( filename , CFile::modeRead );
	if ( !iresult )
		return *this;
	//准备读入缓冲区
	const int imaxcount = 1024;
	int iretcount = 1023;
	char pbufRead[imaxcount] {};
	memset( pbufRead , 0 , sizeof( pbufRead ) );
	pbufRead[imaxcount - 1] = '\0';
	ASSERT( sizeof( pbufRead ) == imaxcount );

	cfile.SeekToBegin( );
	string readline;

	//开始读入数据，如果读入字节数小于设置读入字节（返回值），说明读到文件末尾，退出读取循环。
	while ( iretcount == imaxcount - 1 )
	{
		iretcount = cfile.Read( pbufRead , imaxcount - 1 );
		pbufRead[iretcount] = '\0';
		readline.append( pbufRead , iretcount );
		*this << readline;
		readline = "";
	}
	//ASSERT(0 == memcmp(pbufWrite, pbufRead, sizeof(pbufWrite)));
	cfile.Close( );
	return *this;
}

void PCDC::status_head( bool ishow , size_t nline , bool ishowtail )
{
	static bool ifirst = true;
	ifirst = ishow;
	if ( ifirst != true )
		return;
	CString cs;
	cs = "abcdefgABCDEFG";
	auto maxl = getmaxline( );
	auto maxc = getmaxcows( );
	auto size = sizeof( cs[0] );
	auto& cout = *this;
	LOGFONT l;
	CAtlString str = _T( "显示设备XCout工作状态" );
	size_t* pnstore = cout.storesms( false );
	size_t cslen = cs.GetLength( );
	size_t maxline = cout.getmaxline( ) - 6;
	size_t logsize = cout.mvlogs.size( );
	font.GetLogFont( &l );
	m_pwnd->GetWindowRect( &mrect );
	m_pwnd->SetWindowText( str );
	size_t totallength = 0;
	for ( const auto& i : mvlogs )
		totallength += i.GetLength( );

	cout << clear;
	cout.sourcemode( );
	cout << "XCout纪录状态:" << tab;
	cout << "当前保存记录行数 " << cout.mvlogs.size( ) << sp;
	cout << "纪录容量行 " << cout.mvlogs.capacity( ) << sp;
	cout << "纪录最大内存空间" << double( maxl * maxc * size * cout.maxrecode ) / ( 1024 * 1024 ) << "M" << sp;
	cout << "当前占用内存" << (double)( totallength * size ) / ( 1024 * 1024 ) << "M" << sp;
	cout << "字符" << totallength << sp;
	cout << "单字符占用字节" << size << sp;
	cout << "实际记录 " << pnstore[2];

	cout << newl << "XCout调用数据:" << tab;
	cout << "记录调用 " << pnstore[0] << sp;
	cout << "记录调整 " << pnstore[1] << sp;
	cout << "空记录调用 " << pnstore[3] - pnstore[2] << sp;
	cout << "空输出调用 " << pnstore[4] << sp;
	cout << "行内输出 " << pnstore[5] << sp;
	cout << "换行 " << pnstore[6] << sp;
	cout << "满屏 " << pnstore[7] << sp;
	cout << "分行打印 " << pnstore[8] << sp;
	cout << "输出总调用 " << pnstore[9] << sp;
	cout << "记录总耗时 " << pnstore[10] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "输出总耗时 " << pnstore[11] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API总耗时 " << pnstore[12] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API调用 " << pnstore[13];

	cout << newl << "XCout显示状态:" << tab;
	cout << "单屏行数 " << cout.getmaxline( ) << sp;
	cout << "单屏列数 " << cout.getmaxcows( ) << sp;
	cout << "字体 " << CString( l.lfFaceName ) << sp;
	cout << "当前位置（XY) " << p.x << com << p.y << sp;
	cout << "步进/行高 " << step << sp;
	cout << "左 " << mrect.left << sp;
	cout << "右 " << mrect.right << sp;
	cout << "上 " << mrect.top << sp;
	cout << "下 " << mrect.bottom << sp;
	cout << "剩余行数 " << getmaxline( false ) << sp;
	cout << "剩余列数 " << getmaxcows( false );

	if ( ishowtail == true ) {
		cout << separtor;
		str = _T( " [历史记录]-尾部 " );
		cout << str << newl;
	}

	ifirst = false;
}

size_t PCDC::showlogn( size_t start , size_t end )
{
	end = min( end , ( mvlogs.size( ) - 1 ) );
	if ( ( start < 0 ) || ( end < 0 ) || ( end < start ) || mvlogs.empty( ) )
	{
		return -1;
	}
	else
	{
		for ( int i = start; i <= end; i++ )
			*this << mvlogs[i] << nl;
		return end - start + 1;
	}
}

void PCDC::status( bool ibshowrecode , size_t nline )
{
	static bool ifirst = true;
	static size_t oldshow = 0;
	size_t maxline;
	CString cs;

	auto& cout = *this;
	cout.stoprecode( );

	if ( ifirst == true )
		status_head( true , nline );

	size_t logsize = cout.mvlogs.size( );

	if ( ifirst )
	{
		maxline = cout.getmaxline( false ) - 1;
		if ( nline <= maxline )maxline = nline;
	}
	else
	{
		maxline = cout.getmaxline( );
		if ( logsize < maxline )maxline = logsize;
	}

	auto start = logsize - maxline + 1 - oldshow;
	start = max( 0 , start );
	auto end = logsize - 1 - oldshow;
	end = max( 0 , end );
	end = max( start , end );
	end = min( logsize - 1 , end );

	settcolor( dccr.gteal );
	if ( ibshowrecode ) {
		if ( start == 0 && end == 0 )
		{
			ifirst = true;
			oldshow = 0;
			status( true , getmaxline( ) );
		}
		showlogn( start , end );
		oldshow += end - start + 1;
		ifirst = false;
	}

	if ( oldshow >= logsize - 1 )
	{
		ifirst = true;
		oldshow = 0;
	}

	cout.resettcolor( );
	cout.startrecode( );
}

PCDC& PCDC::operator << ( PCDC& ( *op ) ( PCDC& ) )
{
	//if ( op == nl || op == cl )
	//{
	//	if ( p.x == mrect.left + initalpos )
	//		return *this;
	//}
	return ( *op ) ( *this );
}

PCDC& PCDC::operator <<( LPCTSTR p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( char* p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const char* p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const CAtlString& s )
{
	if ( s.IsEmpty( ) )
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	else
	{
		imresizeout( s );
	}
	return *this;
}

PCDC& PCDC::operator <<( const std::wstring& s )
{
	if ( ( s.length( ) ) && ( s.at( 0 ) != '\0' ) ) {
		ms = s.c_str( );
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const std::string& s )
{
	if ( ( s.length( ) ) && ( s.at( 0 ) != '\0' ) )
	{
		ms = s.c_str( );
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const CString& s )
{
	if ( !s.IsEmpty( ) )
	{
		imresizeout( s );
	}
	else
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	return *this;
}

PCDC& PCDC::operator <<( const CString&& s )
{
	if ( !s.IsEmpty( ) )
	{
		imresizeout( s );
	}
	else
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	return *this;
}

PCDC& PCDC::operator <<( const int n )
{
	ms.Format( _T( "%ld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const char c )
{
	if ( c == 0 ) { ms = "null(0)"; }
	if ( c == '\n' ) {
		p.y += step;
		p.x = initalpos;
		storesms( );
		return *this;
	}
	if ( c == '\t' )
	{
		tabs( );
		return *this;
	}
	if ( isprint( c ) ) {
		ms = c;
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const float n )
{
	ms.Format( _T( "%4.2lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const double n )
{
	ms.Format( _T( "%lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long double n )
{
	ms.Format( _T( "%lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long int n )
{
	ms.Format( _T( "%ld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long long n )
{
	ms.Format( _T( "%lld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const size_t n )
{
	ms.Format( _T( "%zu" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const bool b )
{
	if ( b == true )
	{
		ms = st( true );
	}
	else {
		ms = st( false );
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const unsigned long int n )
{
	ms.Format( _T( "%lu" ) , n );
	imresizeout( ms );
	return *this;
};

PCDC& PCDC::operator <<( const unsigned int n )
{
	//( *this ) << (const int)n; return *this; 
	ms.Format( _T( "%lu" ) , n );
	imresizeout( ms );
	return *this;
};

PCDC& PCDC::operator <<( std::nullptr_t p )
{
	ms = "nullptr";
	imresizeout( ms );
	return *this;
}

CString bools( )
{
	CString cs;
	cs = "}";
	return cs;
}

CString tab( size_t Ntimes )
{
	Ntimes = Ntimes <= 0 ? 1 : Ntimes;
	CString cs;
	NTIME( Ntimes )
		cs += "    ";
	return cs;
}

CString sp( size_t Ntimes )
{
	Ntimes = Ntimes <= 0 ? 1 : Ntimes;
	CString cs;
	NTIME( Ntimes )
		cs += ' ';
	return cs;
}

CString letters( char lc , size_t Ntimes )
{
	Ntimes = Ntimes <= 0 ? 1 : Ntimes;
	CString cs;
	if ( isprint( lc ) )
		NTIME( Ntimes )
		cs += lc;
	return cs;
}

CString tasktimestr( clock_t start , clock_t end , size_t itimes )
{
	itimes = itimes <= 0 ? 1 : itimes;
	CString cs;
	cs.Format( _T( "%zu's " ) , itimes );
	cs += "Totaltimes: ";
	cs.AppendFormat( _T( "%8.2lf" ) , ( (long double)(end)-(long double)start ) * 1000 / CLOCKS_PER_SEC );
	cs += "\'ms.  Once: ";
	cs.AppendFormat( _T( "%8.2lf" ) , long double( ( (long double)end - (long double)start ) * 1000 * 1000 ) / ( CLOCKS_PER_SEC * itimes ) );
	cs += "\'us     ";

	cs.AppendFormat( _T( "%8.2lf" ) , long double( ( (long double)end - (long double)start ) * 1000 * 1000 * 1000 ) / ( CLOCKS_PER_SEC * itimes ) );
	cs += "\'ns.   Total clock: ";
	cs.AppendFormat( _T( "%lu" ) , ( end - start ) );
	return cs;
}

std::chrono::time_point<std::chrono::steady_clock> timestart( bool isstart )
{
	using namespace std::chrono_literals;
	decltype( std::chrono::high_resolution_clock::now( ) ) static start = std::chrono::high_resolution_clock::now( );
	if ( isstart == true ) {
		start = std::chrono::high_resolution_clock::now( );
	}
	return start;
}

CString timeend( size_t itimes )
{
	using namespace std::literals;
	static bool ic = true;
	using namespace std::chrono_literals;
	getcout;
	decltype( std::chrono::high_resolution_clock::now( ) ) static end = {};
	end = std::chrono::high_resolution_clock::now( );
	decltype( std::chrono::high_resolution_clock::now( ) ) start;
	start = timestart( false );

	auto itcount = end - start;
	static auto total = itcount - itcount;
	total += itcount;
	auto ns = std::chrono::duration_cast<std::chrono::microseconds>( total ).count( );
	static size_t times = 0;
	times += itimes >= 1 ? itimes : 1;

	CString cs;
	cs.Format( _T( "%zu's " ) , times );
	cs += "Totaltimes: ";
	cs.AppendFormat( _T( "%5ld" ) , ns / ( 1000 ) );
	cs += "\'ms.  Once: ";
	cs.AppendFormat( _T( "%ld" ) , ns / 1000 / times );
	cs += "\'ms  ";
	cs.AppendFormat( _T( "%ld" ) , ns / ( times ) );
	cs += "\'us  ";
	cs.AppendFormat( _T( "%ld" ) , ns * 1000 / times );
	cs += "\'ns.";
	cout << cs << newl;
	return cs;
}

inline bool sleep( size_t ms )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
	return true;
}
inline bool wait( size_t ms )
{
	return sleep( ms );
}

shared_ptr<pair<STARTUPINFO , PROCESS_INFORMATION>> RunProgram( wchar_t* name )
{
	LPWSTR filee = name;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si , sizeof( si ) );
	si.cb = sizeof( si );
	ZeroMemory( &pi , sizeof( pi ) );

	pair<STARTUPINFO , PROCESS_INFORMATION>* p = new pair<STARTUPINFO , PROCESS_INFORMATION>( si , pi );
	shared_ptr<pair<STARTUPINFO , PROCESS_INFORMATION>> ret( p );

	auto t = CreateProcess(
		nullptr ,
		filee ,
		nullptr ,
		nullptr ,
		false ,
		0 ,
		nullptr ,
		nullptr ,
		&( p->first ) ,
		&( p->second )
	);
	return ret;
}

//
//namespace netsocket
//{
//	class iSocket {
//	public:
//		WSADATA ws;
//		WORD ver = MAKEWORD( 2 , 2 );
//		SOCKET sersock = INVALID_SOCKET , clientsock = INVALID_SOCKET , sock = INVALID_SOCKET;
//		string ipstr = "127.0.0.1";
//		string strdata;
//		vector<string> vectData;
//		IPPROTO proto = IPPROTO_TCP;
//		inline static const int size = 1024;
//		char recvbuf[size + 1] = { 0 };
//		char sendbuf[size + 1] = { 0 };
//		int recvbyte = 0;
//		int sendbyte = 0;
//
//
//		SOCKADDR_IN seradd , clientadd;
//		int addrsize = sizeof( SOCKADDR_IN );
//		int ninlog = 20;
//		int isserver = 0;
//
//	public:
//		iSocket( )
//		{
//			initsocket( );
//		}
//		bool initsocket( )
//		{
//			strdata.reserve( size * 2 );
//			int ret = WSAStartup( ver , &ws );
//			noequalerr( 0 , ret , "WSAstartup error:" );
//			sock = socket( AF_INET , SOCK_STREAM , proto );
//			return equalerr( sock , INVALID_SOCKET , "socket create error(INVALID_SOCKET):" );
//		}
//		iSocket( const char* ip , int port = 9999 , bool isServer = false )
//		{
//			initsocket( );
//			if ( isServer )
//				createServer( ip , port );
//			else
//				createClient( ip , port );
//		}
//		void createClient( const char* ip = nullptr , int port = 9999 )
//		{
//			noequalerr( 0 , isserver , "socket already create error(double_create_SOCKET):" );
//			isserver = 2;
//			ipstr = ip;
//			sersock = sock;
//			seradd.sin_family = AF_INET;
//			seradd.sin_port = htons( port );
//			if ( ip == nullptr )
//				seradd.sin_addr.S_un.S_addr = ADDR_ANY;
//			else
//				seradd.sin_addr.S_un.S_addr = inet_addr( ip );
//			int ret = connect( sersock , (sockaddr*)&seradd , addrsize );
//		}
//		void createServer( const char* ip = nullptr , int port = 9999 )
//		{
//			noequalerr( 0 , isserver , "socket already create error(double_create_SOCKET):" );
//			isserver = 1;
//			ipstr = ip;
//			sersock = sock;
//			seradd.sin_family = AF_INET;
//			seradd.sin_port = htons( port );
//			if ( ip == nullptr )
//				seradd.sin_addr.S_un.S_addr = ADDR_ANY;
//			else
//				seradd.sin_addr.S_un.S_addr = inet_addr( ip );
//			int ret = ::bind( sersock , (sockaddr*)&seradd , addrsize );
//			equalerr( ret , SOCKET_ERROR , "socket bind is error(SOCKET_ERROR):" );
//		}
//		int listen( int nlog = 0 )
//		{
//			if ( nlog )
//				ninlog = nlog;
//			int nlisten = ::listen( sersock , ninlog );
//			return nlisten;
//		}
//		SOCKET closeclientsocket( )
//		{
//			closesocket( clientsock );
//			return clientsock = INVALID_SOCKET;
//		}
//		SOCKET accept( )
//		{
//			clientsock = ::accept( sersock , (sockaddr*)&clientadd , &addrsize );
//			equalerr( clientsock , INVALID_SOCKET , "socket accept error(INVALID_SOCKET):" );
//			return clientsock;
//		}
//		int senddata( const char* ibuf = nullptr , int len = size )
//		{
//			int iret;
//			char* buf = nullptr;
//			if ( ibuf == nullptr ) buf = sendbuf;
//			if ( isserver == 1 )
//			{
//				iret = send( clientsock , buf , len , 0 );
//			}
//			else
//			{
//				iret = send( sersock , buf , len , 0 );
//			}
//			if ( iret > 0 ) {
//				sendbuf[size] = 0;
//				sendbyte += iret;
//			}
//			return iret;
//		}
//		int recvdata( char* buf = nullptr , int len = size )
//		{
//			int iret;
//			if ( buf == nullptr ) buf = recvbuf;
//			if ( isserver == 1 )
//			{
//				iret = recv( clientsock , buf , len , 0 );
//			}
//			else
//			{
//				iret = recv( sersock , buf , len , 0 );
//			}
//			if ( iret > 0 ) {
//				CString message;
//				recvbyte += iret;
//				buf[iret] = 0;
//				strdata = buf;
//				vectData.push_back( strdata );
//				memset( buf , 0 , size + 1 );
//				message.Format( _T( "%ld %ld %ld %ld" ) , iret , recvbyte , size , len );
//			}
//			return iret;
//		}
//		string getRecvData( )
//		{
//			return strdata;
//		}
//		bool circlerecv( int n = 5 )
//		{
//			int iret = 0;
//			return true;
//		}
//		bool noequalerr( int errcode , int retcode , CString message )
//		{
//			if ( errcode != retcode )
//			{
//				message.AppendFormat( _T( " %ld != %ld" ) , errcode , retcode );
//				AfxMessageBox( message );
//				return false;
//			}
//			return true;
//		}
//		bool equalerr( int errcode , int retcode , CString message )
//		{
//			if ( errcode == retcode )
//			{
//				message.AppendFormat( _T( " %ld == %ld" ) , errcode , retcode );
//				AfxMessageBox( message );
//				return false;
//			}
//			return true;
//
//		}
//		~iSocket( )
//		{
//			if ( isserver == 1 )
//				::closesocket( sersock );
//			clientsock = sersock = sock = INVALID_SOCKET;
//			int ret = WSACleanup( );
//			noequalerr( 0 , ret , "WSACleanup error:" );
//		}
//	};
//}
//
//
//namespace WindowsBar
//{
//	template<typename T>
//	struct ret
//	{
//		bool ok;
//		T rvalue;
//		T& value = rvalue;
//		T& returnvalue = rvalue;
//	};
//	using llong = long long;
//	template<typename T>
//	T sort( T& a , T& b )
//	{
//		if ( a > b )
//		{
//			T c = a;
//			a = b;
//			b = c;
//		}
//		return a;
//	}
//	auto fact( llong n , llong m )
//	{
//		long double sum = 1;
//		sort( n , m );
//		getcout;
//		for ( size_t i = n; i <= m; i++ )
//		{
//			cout << sum << '*' << i;
//			sum *= i;
//			cout << " = " << sum << semi << tab;
//			cout.circle( 4 );
//		}
//		return ret<long double>{true , sum};
//	}
//	bool IsPrime( llong x )
//	{
//		for ( size_t i = 2; i < x; ++i )
//		{
//			if ( x % i == 0 )
//				return false;
//		}
//		return true;
//	}
//
//	inline bool sleep( size_t ms )
//	{
//		std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
//		return true;
//	}
//	inline bool wait( size_t ms )
//	{
//		return sleep( ms );
//	}
//
//	template<typename T>
//	T getMiddle( T up , T down , T m )
//	{
//		sort( down , up );
//		if ( m >= up )
//			return up;
//		if ( m <= down )
//			return down;
//		return m;
//	}
//
//	CPoint GetRandomPoint( CRect& WindowsRectLimitRect )
//	{
//		CPoint t;
//		getcout;
//		auto& r = WindowsRectLimitRect;
//		t.x = cout.initalpos + rand( ) % ( r.right - cout.initalpos * 2 );
//		t.x = getMiddle( r.right - cout.initalpos , r.left + cout.initalpos , t.x );
//		t.y = cout.initalpos + rand( ) % ( r.bottom - cout.initalpos * 2 );
//		t.y = getMiddle( r.bottom - cout.initalpos , r.top + cout.initalpos , t.y );
//		return t;
//	}
//
//	void drawLineP2P( CDC& dc , CPoint& startPoint , CPoint& endPoint )
//	{
//		dc.MoveTo( startPoint );
//		dc.LineTo( endPoint );
//	}
//
//	COLORREF randomColor( )
//	{
//		return COLORREF( RGB( rand( ) % 255 , rand( ) % 255 , rand( ) % 255 ) );
//	}
//
//	template<typename T>
//	T tplround( T t )
//	{
//		return static_cast<long long>( t + 0.5 );
//	}
//
//	auto _randomColor( )
//	{
//		CColor c;
//		auto cc = c.chocolate;
//		vector <decltype( cc )> crv;
//		auto* pc = &c.red;
//		size_t numcc = sizeof( c ) / sizeof( cc );
//		for ( size_t i = 0; i < numcc; ++i )
//		{
//			crv.push_back( *( pc + i ) );
//		}
//		static size_t cindex = 0;
//		cindex = rand( ) % numcc;
//		return crv.at( cindex );
//	}
//
//	void DrawTriangleCircle( size_t numTriangle , size_t numCircle , size_t sleepTriangle , size_t sleepCircle )
//	{
//		getcout;
//		CRect WindowsRect = cout.GetDCWindowsRect( );
//
//		CPoint startPoint;
//		CPoint secondPoint;
//		CPoint endPoint;
//
//		CBrush Brush;
//
//		linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
//		auto oldPen = cout.SelectObject( Brush );
//		startPoint = GetRandomPoint( WindowsRect );
//		secondPoint = GetRandomPoint( WindowsRect );
//		for ( size_t j = 1; j <= numCircle; ++j )
//		{
//			for ( size_t i = 1; i <= numTriangle; ++i )
//			{
//				Brush.DeleteObject( );
//				auto clor = randomColor( );
//				Brush.CreateSolidBrush( clor );
//				cout.SelectObject( Brush );
//				endPoint = GetRandomPoint( WindowsRect );
//				CPoint pt[3] = { startPoint,secondPoint,endPoint };
//				cout.Polygon( pt , 3 );
//				startPoint = secondPoint;
//				secondPoint = endPoint;
//				sleep( sleepTriangle );
//			}
//
//			sleep( sleepCircle );
//			cout << clear;
//		}
//		cout.SelectObject( oldPen );
//		Brush.DeleteObject( );
//	}
//
//	void DrawLineCircle( size_t numline , size_t numCircle , size_t sleepLine , size_t sleepCircle )
//	{
//		getcout;
//		CRect WindowsRect = cout.GetDCWindowsRect( );
//
//		CPoint startPoint;
//		CPoint endPoint;
//
//		CPen linePen;
//
//		linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
//		auto oldPen = cout.SelectObject( linePen );
//		startPoint = GetRandomPoint( WindowsRect );
//		for ( size_t j = 1; j <= numCircle; ++j )
//		{
//			for ( size_t i = 1; i <= numline; ++i )
//			{
//				linePen.CreatePen( PS_SOLID , 5 , randomColor( ) );
//				cout.SelectObject( linePen );
//				endPoint = GetRandomPoint( WindowsRect );
//
//				drawLineP2P( cout , startPoint , endPoint );
//				startPoint = endPoint;
//				sleep( sleepLine );
//			}
//
//			sleep( sleepCircle );
//			cout << clear;
//		}
//		cout.SelectObject( oldPen );
//		linePen.DeleteObject( );
//	}
//
//	void DrawEllipseCircle( size_t numEllipse , size_t numCircle , size_t sleepEllipse , size_t sleepCircle )
//	{
//		getcout;
//		CRect WindowsRect = cout.GetDCWindowsRect( );
//
//		CPoint startPoint;
//		CPoint endPoint;
//
//		CBrush Brush;
//
//		linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
//		auto oldPen = cout.SelectObject( Brush );
//		startPoint = GetRandomPoint( WindowsRect );
//		for ( size_t j = 1; j <= numCircle; ++j )
//		{
//			for ( size_t i = 1; i <= numEllipse; ++i )
//			{
//				Brush.CreateSolidBrush( randomColor( ) );
//				cout.SelectObject( Brush );
//				endPoint = GetRandomPoint( WindowsRect );
//				cout.Ellipse( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
//				startPoint = endPoint;
//				sleep( sleepEllipse );
//			}
//			sleep( sleepCircle );
//			cout << clear;
//		}
//		cout.SelectObject( oldPen );
//		Brush.DeleteObject( );
//	}
//	void DrawRectangleCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
//	{
//		getcout;
//		CRect WindowsRect = cout.GetDCWindowsRect( );
//
//		CPoint startPoint;
//		CPoint endPoint;
//
//		CBrush Brush;
//
//		auto oldPen = cout.SelectObject( Brush );
//		startPoint = GetRandomPoint( WindowsRect );
//		for ( size_t j = 1; j <= numCircle; ++j )
//		{
//			for ( size_t i = 1; i <= numRectangle; ++i )
//			{
//				auto clor = randomColor( );
//				Brush.CreateSolidBrush( clor );
//				cout.SelectObject( Brush );
//				endPoint = GetRandomPoint( WindowsRect );
//				cout.Rectangle( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
//				startPoint = endPoint;
//				sleep( sleepRectangle );
//			}
//			sleep( sleepCircle );
//			cout << clear;
//		}
//		cout.SelectObject( oldPen );
//		Brush.DeleteObject( );
//	}
//
//	void DrawSnakeCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
//	{
//		getcout;
//		CRect WindowsRect = cout.GetDCWindowsRect( );
//
//		auto width = 50;
//
//		CPoint startPoint;
//		CPoint endPoint;
//
//		CBrush Brush;
//
//		linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
//		auto oldPen = cout.SelectObject( Brush );
//		startPoint = GetRandomPoint( WindowsRect );
//		for ( size_t j = 1; j <= numCircle; ++j )
//		{
//			for ( size_t i = 1; i <= numRectangle; ++i )
//			{
//				Brush.CreateSolidBrush( randomColor( ) );
//				cout.SelectObject( Brush );
//				endPoint = GetRandomPoint( WindowsRect );
//				sort( startPoint.x , endPoint.x );
//				sort( startPoint.y , endPoint.y );
//				cout.Rectangle( startPoint.x , startPoint.y , startPoint.x + width , endPoint.y );
//				cout.Rectangle( startPoint.x , endPoint.y - width , endPoint.x , endPoint.y );
//				startPoint = endPoint;
//				sleep( sleepRectangle );
//			}
//			sleep( sleepCircle );
//			cout << clear;
//		}
//		cout.SelectObject( oldPen );
//		Brush.DeleteObject( );
//	}
//
//	CRect SortWindowsRect( CRect WindowsRect )
//	{
//		sort( WindowsRect.top , WindowsRect.bottom );
//		sort( WindowsRect.left , WindowsRect.right );
//		return WindowsRect;
//	}
//
//	CRect MoveWindowsRect( CRect WindowsRect , int xMove , int yMove )
//	{
//		SortWindowsRect( WindowsRect );
//
//		auto h = WindowsRect.bottom - WindowsRect.top;
//		auto v = WindowsRect.right - WindowsRect.left;
//
//		WindowsRect.top += yMove;
//		WindowsRect.bottom += yMove;
//		WindowsRect.left += xMove;
//		WindowsRect.right += xMove;
//		return WindowsRect;
//	}
//
//	CRect ZoomWindowsRect( CRect WindowsRect , int vZoomRate , int hZoomRate )
//	{
//		SortWindowsRect( WindowsRect );
//		auto h = WindowsRect.bottom - WindowsRect.top;
//		auto v = WindowsRect.right - WindowsRect.left;
//
//		WindowsRect.top = WindowsRect.top + h * ( 100 - hZoomRate ) / 200;
//		WindowsRect.bottom = WindowsRect.bottom - h * ( 100 - hZoomRate ) / 200;
//		WindowsRect.left = WindowsRect.left + v * ( 100 - vZoomRate ) / 200;
//		WindowsRect.right = WindowsRect.right - v * ( 100 - vZoomRate ) / 200;
//		return WindowsRect;
//	}
//	CRect vaildWindowRect( CRect rect , CRect WindowsRect )
//	{
//		SortWindowsRect( WindowsRect );
//		SortWindowsRect( rect );
//		rect.bottom = min( rect.bottom , WindowsRect.bottom );
//		rect.top = min( rect.bottom , rect.top );
//		rect.right = min( rect.right , WindowsRect.right );
//		rect.left = min( rect.left , rect.right );
//		return rect;
//	}
//
//	CRect PutWindowsRect( CRect WindowsRect , int xMove , int yMove , int vZoomRate , int hZoomRate )
//	{
//		CRect rect;
//		rect = ZoomWindowsRect( WindowsRect , vZoomRate , hZoomRate );
//		rect = MoveWindowsRect( rect , xMove , yMove );
//		rect = vaildWindowRect( rect , WindowsRect );
//		return rect;
//	}
//
//	template<typename DT>
//	void DrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
//	{
//		auto width = BarWidth;
//
//		auto drawWidth = DrawRect.right - DrawRect.left;
//		auto drawHeight = DrawRect.bottom - DrawRect.top;
//
//		auto dataItems = data.size( );
//		auto itemWidth = drawWidth / ( dataItems * 2 + 1 );
//		auto maxhight = gmax( data );
//		if ( BarWidth )
//			itemWidth = BarWidth;
//
//		CBrush Brush;
//		Brush.CreateSolidBrush( randomColor( ) );
//		auto saveoldBrush = dc.SelectObject( Brush );
//		for ( size_t i = 0; i < dataItems; ++i )
//		{
//			auto itemData = data.at( i );
//			double size = drawHeight - itemData * drawHeight / maxhight;
//
//			dc.Rectangle( DrawRect.left + 2 * i * itemWidth , DrawRect.top + size , DrawRect.left + ( 2 * i + 1 ) * itemWidth , DrawRect.bottom );
//			Brush.DeleteObject( );
//			Brush.CreateSolidBrush( randomColor( ) );
//			dc.SelectObject( Brush );
//			sleep( 30 );
//		}
//		dc.SelectObject( saveoldBrush );
//		Brush.DeleteObject( );
//	}
//
//	template<typename DT>
//	void VDrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
//	{
//		auto width = BarWidth;
//
//		auto drawWidth = DrawRect.right - DrawRect.left;
//		auto drawHeight = DrawRect.bottom - DrawRect.top;
//
//		auto dataItems = data.size( );
//		auto itemHeight = drawHeight / ( dataItems * 2 + 1 );
//		auto maxWidth = gmax( data );
//		if ( BarWidth )
//			itemHeight = BarWidth;
//
//		CBrush Brush;
//		Brush.CreateSolidBrush( randomColor( ) );
//		auto saveoldBrush = dc.SelectObject( Brush );
//		for ( size_t i = 0; i < dataItems; ++i )
//		{
//			auto itemData = data.at( i );
//			double size = drawWidth - itemData * drawWidth / maxWidth;
//
//			dc.Rectangle( DrawRect.left , DrawRect.top + 2 * i * itemHeight , DrawRect.left + size , DrawRect.top + ( 2 * i + 1 ) * itemHeight );
//			Brush.DeleteObject( );
//			Brush.CreateSolidBrush( randomColor( ) );
//			dc.SelectObject( Brush );
//			sleep( 30 );
//		}
//		dc.SelectObject( saveoldBrush );
//		Brush.DeleteObject( );
//	}
//
//	string colorValue( COLORREF c )
//	{
//		string ret;
//		ret = "R:";
//		int r = (int)GetRValue( c );
//		int g = (int)GetGValue( c );
//		int b = (int)GetBValue( c );
//		ret.append( std::to_string( r ) );
//		ret += " G:";
//		ret.append( std::to_string( g ) );
//		ret += " B:";
//		ret.append( std::to_string( b ) );
//		return ret;
//	}
//
//	template<typename T>
//	struct axset
//	{
//		bool ok = false;
//		T value;
//	};
//
//	template<typename T , size_t N = 1>
//	struct axsetn
//	{
//		bool ok = false;
//		size_t size = N;
//		T value[N];
//		T& operator []( size_t pos )
//		{
//			return value[limit( pos )];
//		}
//		T& valuen( size_t pos )
//		{
//			return value[limit( pos )];
//		}
//		size_t limit( size_t pos )
//		{
//			if ( pos > N )
//				pos = N;
//			if ( pos < 0 )
//				pos = 0;
//			return pos;
//		}
//	};
//
//	template<typename T>
//	T iFset( axset<T> a , T o )
//	{
//		if ( a.ok )
//			return a.value;
//		else
//			return o;
//	}
//
//	template<typename T , size_t n = 1>
//	T iFset( axsetn<T , n> a , T o , size_t pos = 0 )
//	{
//		getcout;
//		cout << '*' << n << star;
//		if ( a.ok )
//			return a.value[pos];
//		else
//			return o;
//	}
//
//	void DrawRectangleAText( CPoint start , CPoint end , string text , axset<COLORREF> c = { false,0 } , axset<COLORREF> tc = { false,0 } )
//	{
//		getcout;
//		CSize t = cout.GetTextExtent( CString( text.c_str( ) ) );
//
//		CBrush Brush;
//		auto clor = randomColor( );
//		Brush.CreateSolidBrush( iFset( c , clor ) );
//		auto old = cout.SelectObject( Brush );
//		cout.Rectangle( start.x , start.y , end.x , end.y );
//		cout.SetBkColor( iFset( c , clor ) );
//		cout.SetTextColor( iFset( tc , randomColor( ) ) );
//		auto width = end.x - start.x;
//		auto hight = end.y - start.y;
//		auto midwidth = ( width - t.cx ) / 2;
//		auto midhight = ( hight - t.cy ) / 2;
//		auto posx = start.x + midwidth;
//		auto posy = start.y + midhight;
//		cout.TextOut( posx , posy , text.c_str( ) );
//		cout.SelectObject( old );
//		Brush.DeleteObject( );
//	}
//
//	class WinPos
//	{
//	public:
//		CRect me;
//		CPoint start , end;
//		LONG& xs = start.x;
//		LONG& ys = start.y;
//		LONG& xe = end.x;
//		LONG& ye = end.y;
//		WinPos( ) = default;
//		WinPos( const WinPos& ) = default;
//		WinPos& operator =( const WinPos& r )
//		{
//			me = r.me;
//			start = r.start;
//			end = r.end;
//			return *this;
//		};
//		WinPos( CPoint x , CPoint y ) :start( x ) , end( y ) , me( start , end ) {}
//		CRect setrect( CPoint x , CPoint y ) {
//			start = x;
//			end = y;
//			me = { start , end };
//			return me;
//		}
//		WinPos( CPoint istart , CSize size ) :start( istart ) , end( CPoint { istart.x + size.cx,istart.y + size.cy } ) {		}
//		CRect setrect( CPoint istart , CSize size )
//		{
//			start = istart;
//			end = CPoint { istart.x + size.cx,istart.y + size.cy };
//			me = { start , end };
//			return me;
//		}
//		WinPos( LONG x1 , LONG y1 , LONG x2 , LONG y2 ) :start( CPoint { x1,y1 } ) , end( CPoint { x2 ,y2 } ) , me( CRect { start , end } ) {}
//		CPoint getstart( ) { return start; }
//		CPoint getend( ) { return end; }
//		CPoint getcore( ) { return CPoint { xs + ( xe - xs ) / 2, ye - ( ye - ys ) / 2 }; }
//		CPoint getmidtop( ) { return CPoint { xs + ( xe - xs ) / 2, ys }; }
//		CPoint getmidbottom( ) { return CPoint { xs + ( xe - xs ) / 2,ye }; }
//		CPoint getmidleft( ) { return CPoint { xs,ys + ( ye - ys ) / 2 }; }
//		CPoint getmidright( ) { return CPoint { xe , ye - ( ye - ys ) / 2 }; }
//		CRect  getrect( ) { return me; }
//		CSize  getsize( ) { return me.Size( ); }
//		LONG   getwidth( ) { return me.Size( ).cx; }
//		LONG   gethight( ) { return me.Size( ).cy; }
//		pair<CPoint , CPoint>getPointPair( ) { return pair { start,end }; }
//	};
//
//	void drawLineR2R( CDC& dc , WinPos& up , WinPos& down , int line = 3 , COLORREF c = randomColor( ) )
//	{
//		CPen linePen;
//
//		linePen.CreatePen( PS_SOLID , line , c );
//		auto oldPen = dc.SelectObject( linePen );
//
//		dc.MoveTo( up.getmidbottom( ) );
//		dc.LineTo( down.getmidtop( ) );
//
//		dc.SelectObject( oldPen );
//		linePen.DeleteObject( );
//	}
//
//}
//


