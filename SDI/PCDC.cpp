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

			//����ȱʡ����
			LOGFONT lf;
			// zero out structure
			memset( &lf , 0 , sizeof( LOGFONT ) );
			font.CreatePointFont( this->mfontsize , _T( "Cascadia Code SemiLight" ) );
			pfont = dc.SelectObject( &font );
			if ( pfont != nullptr )
			{
				//���ô��ڱ�����ɫ
				dc.SetBkColor( m_bk );
				//����������ɫ
				dc.SetTextColor( m_tk );
				flushscreen( );

				//���������С��������
				font.GetLogFont( &lf );
				step = abs( lf.lfHeight + lf.lfHeight / 2 );

				//������־��¼����
				size_t maxline = getmaxline( );
				size_t totalmaxline = maxline * maxrecode;
				mvlogs.reserve( totalmaxline );

				//������λ��
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
	//׼�����뻺����
	const int imaxcount = 1024;
	int iretcount = 1023;
	char pbufRead[imaxcount] {};
	memset( pbufRead , 0 , sizeof( pbufRead ) );
	pbufRead[imaxcount - 1] = '\0';
	ASSERT( sizeof( pbufRead ) == imaxcount );

	cfile.SeekToBegin( );
	string readline;

	//��ʼ�������ݣ���������ֽ���С�����ö����ֽڣ�����ֵ����˵�������ļ�ĩβ���˳���ȡѭ����
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
	CAtlString str = _T( "��ʾ�豸XCout����״̬" );
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
	cout << "XCout��¼״̬:" << tab;
	cout << "��ǰ�����¼���� " << cout.mvlogs.size( ) << sp;
	cout << "��¼������ " << cout.mvlogs.capacity( ) << sp;
	cout << "��¼����ڴ�ռ�" << double( maxl * maxc * size * cout.maxrecode ) / ( 1024 * 1024 ) << "M" << sp;
	cout << "��ǰռ���ڴ�" << (double)( totallength * size ) / ( 1024 * 1024 ) << "M" << sp;
	cout << "�ַ�" << totallength << sp;
	cout << "���ַ�ռ���ֽ�" << size << sp;
	cout << "ʵ�ʼ�¼ " << pnstore[2];

	cout << newl << "XCout��������:" << tab;
	cout << "��¼���� " << pnstore[0] << sp;
	cout << "��¼���� " << pnstore[1] << sp;
	cout << "�ռ�¼���� " << pnstore[3] - pnstore[2] << sp;
	cout << "��������� " << pnstore[4] << sp;
	cout << "������� " << pnstore[5] << sp;
	cout << "���� " << pnstore[6] << sp;
	cout << "���� " << pnstore[7] << sp;
	cout << "���д�ӡ " << pnstore[8] << sp;
	cout << "����ܵ��� " << pnstore[9] << sp;
	cout << "��¼�ܺ�ʱ " << pnstore[10] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "����ܺ�ʱ " << pnstore[11] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API�ܺ�ʱ " << pnstore[12] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API���� " << pnstore[13];

	cout << newl << "XCout��ʾ״̬:" << tab;
	cout << "�������� " << cout.getmaxline( ) << sp;
	cout << "�������� " << cout.getmaxcows( ) << sp;
	cout << "���� " << CString( l.lfFaceName ) << sp;
	cout << "��ǰλ�ã�XY) " << p.x << com << p.y << sp;
	cout << "����/�и� " << step << sp;
	cout << "�� " << mrect.left << sp;
	cout << "�� " << mrect.right << sp;
	cout << "�� " << mrect.top << sp;
	cout << "�� " << mrect.bottom << sp;
	cout << "ʣ������ " << getmaxline( false ) << sp;
	cout << "ʣ������ " << getmaxcows( false );

	if ( ishowtail == true ) {
		cout << separtor;
		str = _T( " [��ʷ��¼]-β�� " );
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
	if ( op == nl || op == cl )
	{
		if ( p.x == mrect.left + initalpos )
			return *this;
	}
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
		ms = "    ";
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
	cs.AppendFormat( _T( "%ld" ) , ns / ( 1000 ) );
	cs += "\'ms.  Once: ";
	cs.AppendFormat( _T( "%ld" ) , ns / ( times ) );
	cs += "\'us  ";
	cs.AppendFormat( _T( "%ld" ) , ns * 1000 / times );
	cs += "\'ns.";
	cout << cs << newl;
	return cs;
}




