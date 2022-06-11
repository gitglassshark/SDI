#pragma once
#include "pch.h"
#include "muse.h"


class PCDC;
class CColor;
using XCout = PCDC;

extern class CColor dccr;
extern PCDC* pcout;

PCDC& com( PCDC& dc );
PCDC& semi( PCDC& dc );
PCDC& dash( PCDC& dc );
PCDC& sp( PCDC& dc );
PCDC& tab( PCDC& dc );
PCDC& cut( PCDC& dc );
PCDC& star( PCDC& dc );
PCDC& separtor( PCDC& dc );
PCDC& nl( PCDC& dc );
PCDC& newl( PCDC& dc );
PCDC& endl( PCDC& dc );
PCDC& cl( PCDC& dc );
PCDC& clear( PCDC& dc );

CString hex( );
CString HEX( );
CString oct( );
CString udec( );
CString address( );
CString bools( );
CString tab( size_t Ntimes = 1 );
CString sp( size_t Ntimes = 1 );
CString letters( char lc , size_t Ntimes = 1 );
CString tasktimestr( clock_t start , clock_t end , size_t itimes = 1 );

std::chrono::time_point<std::chrono::steady_clock> timestart( bool isstart = true );
CString timeend( size_t itimes = 1 );

class CColor {
public:
	COLORREF red = RGB( 255 , 0 , 0 );
	COLORREF midred = RGB( 128 , 0 , 0 );
	COLORREF yellow = RGB( 255 , 255 , 0 );
	COLORREF midyellow = RGB( 255 , 255 , 128 );
	COLORREF green = RGB( 0 , 255 , 0 );
	COLORREF midgreen = RGB( 0 , 128 , 0 );
	COLORREF greenblue = RGB( 0 , 255 , 255 );
	COLORREF midgreenblue = RGB( 128 , 255 , 255 );
	COLORREF mainred = RGB( 255 , 139 , 139 );
	COLORREF maingreen = RGB( 139 , 255 , 139 );
	COLORREF mainwhite = RGB( 139 , 139 , 255 );
	COLORREF blue = RGB( 0 , 0 , 255 );
	COLORREF midblue = RGB( 0 , 0 , 128 );
	COLORREF bluered = RGB( 255 , 0 , 255 );
	COLORREF lbluered = RGB( 225 , 25 , 225 );
	COLORREF mbluered = RGB( 225 , 55 , 225 );
	COLORREF hbluered = RGB( 225 , 125 , 225 );
	COLORREF bluehred = RGB( 255 , 105 , 255 );
	COLORREF midbluered = RGB( 255 , 128 , 255 );
	COLORREF black = RGB( 0 , 0 , 0 );
	COLORREF white = RGB( 255 , 255 , 255 );
	COLORREF darkred = RGB( 139 , 0 , 0 );
	COLORREF darkyellow = RGB( 139 , 139 , 0 );
	COLORREF darkgreen = RGB( 0 , 139 , 0 );
	COLORREF darkblue = RGB( 0 , 0 , 139 );
	COLORREF darkcyan = RGB( 0 , 139 , 139 );
	COLORREF fgreen = RGB( 34 , 139 , 34 );
	COLORREF red1 = RGB( 139 , 34 , 34 );
	COLORREF green2 = RGB( 34 , 34 , 139 );
	COLORREF chocolate = RGB( 238 , 118 , 33 );
	COLORREF dodgerblue = RGB( 16 , 78 , 139 );
	COLORREF grey = RGB( 28 , 28 , 28 );
	COLORREF teal = RGB( 0 , 128 , 128 );
	COLORREF mteal = RGB( 55 , 128 , 128 );
	COLORREF lteal = RGB( 105 , 128 , 128 );
	COLORREF hteal = RGB( 20 , 128 , 255 );
	COLORREF gteal = RGB( 20 , 255 , 128 );
	COLORREF tteal = RGB( 20 , 155 , 155 );
	COLORREF xteal = RGB( 20 , 200 , 200 );
	COLORREF gray = RGB( 128 , 128 , 128 );
	COLORREF darkgray = RGB( 128 , 128 , 139 );
	COLORREF darkslateblue = RGB( 72 , 61 , 128 );
	COLORREF slategray = RGB( 112 , 128 , 144 );
	COLORREF berry = RGB( 135 , 38 , 87 );
	COLORREF brown = RGB( 128 , 42 , 42 );
	COLORREF azure = RGB( 131 , 139 , 139 );
	COLORREF whitesmoke = RGB( 205 , 205 , 205 );
	COLORREF smokered = RGB( 205 , 0 , 205 );
	COLORREF smokewhite = RGB( 0 , 205 , 205 );
	COLORREF smokeyellow = RGB( 205 , 205 , 0 );
	COLORREF silver = RGB( 192 , 192 , 192 );
	COLORREF lightgreen = RGB( 55 , 255 , 55 );
	COLORREF hlightgreen = RGB( 105 , 255 , 105 );
	COLORREF midlightgreen = RGB( 155 , 255 , 155 );
	COLORREF overlightgreen = RGB( 188 , 255 , 188 );
	COLORREF heavgyellow = RGB( 205 , 205 , 20 );
	COLORREF heavggreen = RGB( 20 , 205 , 20 );
	COLORREF mheavggreen = RGB( 155 , 205 , 155 );
	COLORREF lightred = RGB( 255 , 55 , 55 );
	COLORREF hlightred = RGB( 255 , 105 , 105 );
	COLORREF lightblue = RGB( 55 , 55 , 255 );
	COLORREF hlightblue = RGB( 105 , 105 , 255 );
};

template<typename T>
concept enumc = requires( T a )
{
	std::is_enum_v<T>;
};
template<typename S>
concept PS = requires ( S s )
{
	s.length( );
	s.at( );
	s.c_str( );
};

class PCDC : public CDC
{
public:
	bool isurerecode = true;
	bool icreate = false;
	unsigned short maxrecode = 100;
	//size_t id = 0;
	//inline static size_t icount = 0;
	//int iargs = 0;
	bool ibegin = true;

public:
	//inline static const LONG wbar = 8;
	LONG step = 36;
	inline static const LONG initalpos = 40;
	//const LONG initalstep = 20;
	inline static POINT p = { initalpos, initalpos };
	CRect mrect;
	CSize msize;
	size_t ilinemod = 20;
	//bool icutline = false;

public:
	COLORREF m_bk = dccr.grey;
	COLORREF m_tk = dccr.chocolate;
	COLORREF m_tksource = dccr.smokewhite;
	COLORREF m_bark = dccr.lteal;
	COLORREF m_linek = dccr.azure;
	int mfontsize = 118;
	CFont font , * pfont = nullptr;

public:
	//CDC* m_cdc = nullptr;
	inline static PCDC* pXCout = nullptr;
	CWnd* m_pwnd = nullptr;

public:
	char mlinechar = _T( '-' );
	char mmarkchar = '=';
	CString spchar = _T( "  " );
	CString ms = _T( "" );
	size_t mtabs = 4;
	inline static vector<CString>mvlogs;
	inline static CString sms = _T( "" );
	CString opstr = _T( "" );

public:
	PCDC( CWnd* pwnd = nullptr );
	inline bool Create( CWnd* pwnd );
	inline bool Release( );
	~PCDC( );


public:
	PCDC& operator<<( const char c );
	PCDC& operator<<( signed char c ) { return ( *this ) << (const char)c; };
	PCDC& operator<<( unsigned char c ) { return ( *this ) << (const char)c; };
	PCDC& operator<<( char* p );
	PCDC& operator<<( char const* p );
	PCDC& operator<<( signed char const* p ) { return *this << (char const*)p; };
	PCDC& operator<<( unsigned char const* p ) { return *this << (char const*)p; };
	PCDC& operator<<( LPCTSTR s );
	PCDC& operator<<( const std::string& s );
	PCDC& operator<<( const std::wstring& s );
	PCDC& operator<<( const CString& s );
	PCDC& operator<<( const CString&& s );
	PCDC& operator<<( const CAtlString& s );
	PCDC& operator<<( const bool b );
	PCDC& operator<<( const int n );
	PCDC& operator<<( const unsigned int n );
	PCDC& operator<<( const long int n );
	PCDC& operator<<( const unsigned long int n );
	PCDC& operator<<( const long long n );
	PCDC& operator<<( const float n );
	PCDC& operator<<( const double n );
	PCDC& operator<<( const long double n );
	PCDC& operator<<( const size_t n );
	template <typename A , typename ...X , typename R> PCDC& operator<<( R( A::* p )( X... ) );
	PCDC& operator<<( std::nullptr_t p );
	PCDC& operator<<( std::thread::id tid )
	{
		//_Thrd_t t = *(_Thrd_t*)(char*)&tid;
		//unsigned int  nId = t._Id;
		//*this << "ThreadID=[" << nId << "] ";
		//*this << "ThreadID=[" << std::hash<std::thread::id>( )( tid ) << "] ";
		std::stringstream sin;
		sin << tid;
		string sidstr = sin.str( );
		*this << "ThreadID=[" << sidstr << "] ";
		return *this;
	}
	PCDC& operator<<( PCDC& dc ) {
		if ( this == &dc )
		{
			return *this;
		}
		else
		{
			return dc;
		}
	};

	//template <typename P> PCDC& operator <<( P p )
	//{
	//	if ( std::is_member_pointer<decltype( p )>::value )
	//	{
	//		if ( p == nullptr )
	//		{
	//			ms = "nullptr";
	//		}
	//		else
	//		{
	//			ms.Format( _T( "[0x%p]" ) , p );
	//		}
	//		imresizeout( ms );
	//		return *this;
	//	}
	//	return *this;
	//};
public:
	PCDC& operator<< ( PCDC& ( *op ) ( PCDC& dc ) );

public:
	inline PCDC& printid( )
	{
		*this << this_thread::get_id( ) << tab << "PID:[" << _getpid( ) << "] ";
		return *this;
	}
	inline size_t getmaxline( bool getmax = true )
	{
		m_pwnd->GetClientRect( &mrect );
		size_t retn = 0;
		if ( getmax == true )
		{
			retn = ( mrect.bottom - mrect.top - initalpos ) / step;
		}
		else
		{
			retn = ( mrect.bottom - initalpos - mrect.top - p.y ) / step;
		}
		return retn;
	}
	inline size_t getmaxcows( bool getmax = true )
	{
		CString cs = L"1234567890abcdefghijklmnopqrstABCDEFGHIJKLMNOPQRST";
		size_t cslen = cs.GetLength( );

		m_pwnd->GetClientRect( &mrect );
		msize = this->GetOutputTextExtent( cs );

		auto acharsize = msize.cx / cslen;
		auto linelength = mrect.right - mrect.left - 2 * initalpos;
		auto maxcows = linelength * cslen / msize.cx;

		if ( getmax == true )
		{
			return maxcows;
		}
		else
		{
			size_t reline = maxcows - ( p.x - mrect.left - initalpos ) * cslen / msize.cx;
			return reline;
		}
	}
	inline CRect& resetmrect( )
	{
		m_pwnd->GetClientRect( &mrect );
		return mrect;
	}
	inline void rinitx( bool initset = true , long x = 0 )
	{
		m_pwnd->GetClientRect( &mrect );
		if ( initset == true )
		{
			p.x = mrect.left + initalpos;
		}
		else
		{
			p.x = max( x , initalpos );
			p.x = min( x , ( mrect.right - initalpos ) );
		}
	};
	inline void rinity( bool initset = true , long y = 0 )
	{
		m_pwnd->GetClientRect( &mrect );
		if ( initset == true )
		{
			p.y = mrect.top + initalpos;
		}
		else
		{
			p.y = max( y , initalpos );
			p.y = min( y , ( mrect.bottom - initalpos ) );
		}
	};
	inline void rinitxy( bool initset = true , long x = 0 , long y = 0 )
	{
		m_pwnd->GetClientRect( &mrect );
		if ( initset == true )
		{
			p.x = mrect.left + initalpos;
			p.y = mrect.top + initalpos;
		}
		else
		{
			p.x = max( x , initalpos );
			p.x = min( x , ( mrect.right - initalpos ) );
			p.y = max( y , initalpos );
			p.y = min( y , ( mrect.bottom - initalpos ) );
		}
	};
	inline bool recode( const CString& cs )
	{
		if ( isurerecode )
		{
			sms += cs;
		}
		else
		{
			return false;
		}
		return true;
	}
	inline size_t setmaxlog( bool isreset = false , size_t max = 0 )
	{
		if ( ( isreset == true ) && ( max >= 0 ) ) {
			maxrecode = max;
			mvlogs.resize( getmaxline( ) * maxrecode );
			mvlogs.shrink_to_fit( );
		}
		return maxrecode;
	}
	inline void clearlog( size_t max = 0 )
	{
		if ( max >= 0 ) {
			maxrecode = max;
		}
		mvlogs.clear( );
		mvlogs.resize( getmaxline( ) * maxrecode );
		mvlogs.shrink_to_fit( );
	}
	inline bool stoprecode( ) { return isurerecode = false; }
	inline bool startrecode( ) { return isurerecode = true; }
	inline size_t* storesms( bool isstorecomand = true )
	{
		size_t maxline = getmaxline( );
		size_t totalmaxline = maxline * maxrecode;
		auto start = clock( );
		static size_t nstore[14] {};
		nstore[0]++;//总调用次数
		if ( !isstorecomand )
			return nstore;
		if ( isurerecode )
		{
			if ( !sms.IsEmpty( ) ) {
				if ( mvlogs.size( ) >= totalmaxline )
				{
					mvlogs.erase( mvlogs.begin( ) , mvlogs.begin( ) + totalmaxline / 2 );
					mvlogs.reserve( totalmaxline );
					nstore[1]++;//调整次数
				}
				mvlogs.push_back( sms );
				sms.Empty( );
				nstore[2]++;//存储次数
			}
			nstore[3]++;//字符串为空调用次数
		}
		auto end = clock( );
		nstore[10] += end - start;
		return nstore;
	}
	void status_head( bool ishow = true , size_t nline = 0 , bool ishowtail = true );
	void status( bool ibshowrecode = true , size_t nline = 45 );
	size_t showlogn( size_t start , size_t end );
	auto timestart( bool isstart = true )
	{
		auto static start = std::chrono::steady_clock::now( );
		//clock_t static start {};
		if ( isstart == true ) {
			start = std::chrono::steady_clock::now( );
		}
		return start;
		/*	using namespace std::chrono_literals;
			auto st = std::chrono::high_resolution_clock::now( );
			auto en = std::chrono::high_resolution_clock::now( );
			auto itcount = en - st;
			auto ns=itcount.count( );*/
	}
	CString timeend( size_t itimes = 1 )
	{
		auto static end = std::chrono::steady_clock::now( );
		static size_t times = 0;
		end = std::chrono::steady_clock::now( );
		auto start = timestart( false );
		static auto dtime = end - start;
		dtime += end - start;

		times += itimes >= 1 ? itimes : 1;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>( dtime ).count( );
		auto us = std::chrono::duration_cast<std::chrono::microseconds>( dtime ).count( );
		auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>( dtime ).count( );

		CString cs;
		cs.Format( _T( "%zu's " ) , times );
		cs += "Totaltimes: ";
		cs.AppendFormat( _T( "%5ld" ) , ms );
		cs += "\'ms.  Once: ";
		cs.AppendFormat( _T( "%ld" ) , ms / times );
		cs += "\'ms  ";
		cs.AppendFormat( _T( "%ld" ) , us / times );
		cs += "\'us  ";
		cs.AppendFormat( _T( "%ld" ) , ns / times );
		cs += "\'ns.";
		*this << cs << newl;

		return cs;
	}

	PCDC& settcolor( COLORREF tk );
	PCDC& setcolor( COLORREF line , COLORREF bar , COLORREF bk , COLORREF tk );
	PCDC& lmod( unsigned char imod = 30 );
	template <typename T = CString>inline PCDC& title( T t , bool ib = true );
	char setlinechar( const char& c = '=' );
	inline PCDC& resettcolor( );
	inline PCDC& printX( auto...x )
	{
		( ( ( *this << "- " ) , type( x ) , ( *this << "+" ) ) , ... );
		( ( *this << x << sp ) , ... );
		return *this;
	}
	inline PCDC& sourcemode( )
	{
		this->settcolor( dccr.smokewhite );
		return *this;
	};
	inline PCDC& flushscreen( const CRect* r = nullptr , const COLORREF* cr = nullptr );
	inline PCDC& tb( size_t t = 1 , char c = '\t' ) { NTIME( t )* this << c; return *this; }
	inline PCDC& location( auto s )//s=source_location::current( )
	{
		CString strloc;
		strloc += "当前位置{ 文件：";
		strloc += s.file_name( );
		strloc += " 函数：";
		strloc += s.function_name( );
		strloc += " 行号：";
		strloc.AppendFormat( _T( "%ld" ) , s.line( ) );
		strloc += " } ";
		return *this << strloc;
	};
	inline PCDC& cut( CString t = CString( ) , char c = '-' , bool ib = true )
	{
		m_pwnd->GetClientRect( &mrect );
		CSize charsize = GetOutputTextExtent( CString( mlinechar ) );
		long w;
		if ( ib )
		{
			w = mrect.right - initalpos - p.x;
		}
		else
		{
			w = mrect.right - ( mrect.left + initalpos * 2 );
		};
		auto icount = w / charsize.cx;
		CString line( mlinechar , icount );
		imresizeout( line );
		storesms( );
		return *this;
	};
	void inline settab( size_t n )
	{
		mtabs = n;
	}
	PCDC& tabs( size_t n = 1 )
	{
		size_t maxwords = getmaxcows( true );
		size_t rwords = getmaxcows( false );
		size_t currentwords = maxwords - rwords;
		size_t mtab = currentwords % mtabs;
		size_t ptabs = mtab ? ( mtabs - mtab ) : mtabs;
		ptabs = min( ptabs , rwords );
		CString cs;
		NTIME( ptabs )cs += ' ';
		imresizeout( cs );
		return *this;
	}

	//template<typename S> inline void imresizeout( S& cs ) //requires Xstring<S&>
	//{
	//	auto start = clock( );
	//	static size_t* pnstore = storesms( false );
	//	pnstore[9]++;//打印调用次数统计
	//	if ( cs.IsEmpty( ) ) {
	//		pnstore[4]++;//空打印输出次数统计 
	//		return;
	//	}
	//	m_pwnd->GetClientRect( &mrect );
	//	msize = this->GetOutputTextExtent( cs );
	//	auto linelen = mrect.right - initalpos - p.x;
	//	auto strlen = msize.cx;

	//	if ( strlen <= linelen ) {
	//		if ( p.y >= mrect.bottom - mrect.top - initalpos ) {
	//			pnstore[7]++;//满屏打印输出次数统计
	//			flushscreen( );
	//		}
	//		pnstore[5]++;//小行打印输出次数统计
	//		//need recalc position***
	//		if ( p.x == mrect.left + initalpos ) {
	//			storesms( );
	//		}
	//		auto tstart = clock( );
	//		this->TextOutW( p.x , p.y , cs );
	//		pnstore[13]++;//系统API调用次数
	//		auto tend = clock( );
	//		pnstore[12] += tend - tstart;
	//		recode( cs );
	//		p.x += msize.cx;

	//		//need check position***
	//		if ( p.x >= ( mrect.right - initalpos * 2 ) ) {
	//			pnstore[6]++;//换行打印输出次数统计
	//			storesms( );
	//			rinitx( );
	//			//p.x = mrect.left + initalpos;
	//			p.y += step;
	//		}

	//	}
	//	else {
	//		pnstore[8]++;//分行打印输出次数统计
	//		auto cslen = cs.GetLength( );
	//		auto tkpos = linelen * cslen / strlen;
	//		imresizeout( (S&&)cs.Mid( 0 , tkpos ) );
	//		imresizeout( (S&&)cs.Mid( tkpos , cslen - tkpos ) );
	//	}
	//	auto end = clock( );
	//	pnstore[11] += end - start;
	//}
	template<typename S> inline void imresizeout( S&& cs ) //requires Xstring<S&>
	{
		auto start = clock( );
		static size_t* pnstore = storesms( false );
		pnstore[9]++;//打印调用次数统计
		if ( cs.IsEmpty( ) ) {
			pnstore[4]++;//空打印输出次数统计 
			return;
		}
		m_pwnd->GetClientRect( &mrect );
		msize = this->GetOutputTextExtent( cs );
		auto linelen = mrect.right - initalpos - p.x;
		auto strlen = msize.cx;

		if ( strlen <= linelen ) {
			if ( p.y >= mrect.bottom - mrect.top - initalpos ) {
				pnstore[7]++;//满屏打印输出次数统计
				flushscreen( );
			}
			pnstore[5]++;//小行打印输出次数统计
			//need recalc position***
			if ( p.x == mrect.left + initalpos ) {
				storesms( );
			}
			auto tstart = clock( );
			this->TextOutW( p.x , p.y , cs );
			pnstore[13]++;//系统API调用次数
			auto tend = clock( );
			pnstore[12] += tend - tstart;
			recode( cs );
			p.x += msize.cx;

			//need check position***
			if ( p.x >= ( mrect.right - initalpos * 2 ) ) {
				pnstore[6]++;//换行打印输出次数统计
				storesms( );
				rinitx( );
				//p.x = mrect.left + initalpos;
				p.y += step;
			}

		}
		else {
			pnstore[8]++;//分行打印输出次数统计
			auto cslen = cs.GetLength( );
			auto tkpos = linelen * cslen / strlen;
			imresizeout( (S&&)cs.Mid( 0 , tkpos ) );
			imresizeout( (S&&)cs.Mid( tkpos , cslen - tkpos ) );
		}
		auto end = clock( );
		pnstore[11] += end - start;
	}

public:
	template <typename A> PCDC& operator%( const tuple<A>& tup )
	{
		return( *this ) << "  :" << get<0>( tup ) << "  ;";
	}
	template <typename A , typename... Args> PCDC& operator%( const tuple<A , Args...>& tup )
	{
		*this << "  :" << get<0>( tup );
		return ( *this ) % ( tup._Get_rest( ) );
	}
	template <typename A , typename B> PCDC& operator||( const tuple<A , B>& tup );
	template <typename... Args> PCDC& operator||( const tuple<Args...>& tup );
	template <typename A , typename B> PCDC& operator|( const tuple<A , B>& tup );
	template <typename A , typename... Args> PCDC& operator|( const tuple<A , Args...>& tup );
	template <typename T> PCDC& operator [] ( const tuple<T>& tupa );
	template <typename... Args> PCDC& operator [] ( const tuple<Args...>& tupa );

	template <typename M>
	PCDC& operator <<( typename M it ) requires requires ( M m ) { m._Ptr; }
	{
		return *this << it._Ptr;
	};
	template <typename X> PCDC& operator <<( const unique_ptr<X>& ptr )
	{
		return *this << ptr.get( ) << "<-(s)";
	};
	template <typename X> PCDC& operator <<( const shared_ptr<X>& ptr )
	{
		return *this << ptr.get( ) << "<-(s): " << ptr.use_count( );
	};
	template <typename X> PCDC& operator <<( const weak_ptr<X>& ptr )
	{
		return *this << ptr.lock( ) << "<-(w): " << ptr.use_count( );
	};
	template <typename T> PCDC& operator ()( T t , string name )
	{
		*this << "Variable " << name << " type traits test is: " << separtor;
		TypeCount( t ) << nl;
		lstraits( t );
		return ( *this );
	};
	template <typename T> PCDC& operator ()( initializer_list<T> c );
	template <typename... Args> PCDC& operator<<( tuple<Args...> tup );
	template <typename... Args> PCDC& operator>>( tuple<Args...>& tup )
	{
		PCDC& cout = *this;
		cout << std::tuple_size< tuple<Args...>>::value << sp;
		cout << "Args...is: " << ( sizeof...( Args ) ) << tab;
		return *this;
	}
	template <>	PCDC& operator<<( tuple<> tup ) { ibegin = true; return ( *this ) << " }"; }
	template <typename T> PCDC& operator <<( const complex<T>& z );
	template <typename P> PCDC& operator <<( P* p );
	template <typename P> PCDC& operator <<( const P* p );
	template <typename T> PCDC& operator <<( initializer_list<T> c );
	template <typename T> PCDC& operator >>( initializer_list<T>& c )
	{
		PCDC& cout = *this;
		SHOW( c.size( ) );
		return *this;
	}
	template <typename T> PCDC& operator <<( const list<T>& l );
	template <typename T> PCDC& operator >>( const list<T>& l )
	{
		PCDC& cout = *this;
		SHOW( l.size( ) );
		SHOW( l.max_size( ) );
		return *this;
	}
	template <typename T , size_t len> PCDC& operator <<( const array< T , len>& a );
	template <typename T , size_t len> PCDC& operator >>( const array< T , len>& a )
	{
		PCDC& cout = *this;
		SHOW( a.size( ) );
		SHOW( a.max_size( ) );
		SHOW( a.data( ) );
		return *this;
	}
	template <typename A , typename B> PCDC& operator <<( const pair<A , B>& i );
	template <typename... X> inline PCDC& operator <<( const vector<X...>& v );
	template <typename... X> inline PCDC& operator >>( const vector<X...>& v )
	{
		PCDC& cout = *this;
		SHOW( v.size( ) );
		SHOW( v.capacity( ) );
		SHOW( v.max_size( ) );
		SHOW( v.data( ) );
		return *this;
	}
	template <typename... T> PCDC& operator <<( const multiset<T...>& s );
	template <typename... T> PCDC& operator >>( const multiset<T...>& s )
	{
		PCDC& cout = *this;
		SHOW( s.size( ) );
		SHOW( s.max_size( ) );
		return *this;
	}
	template <typename ...T> PCDC& operator <<( const deque<T...>& d );
	template <typename ...T> PCDC& operator >>( const deque<T...>& d )
	{
		PCDC& cout = *this;
		SHOW( d.size( ) );
		SHOW( d.max_size( ) );
		return *this;
	}
	template <typename ...T> PCDC& operator <<( const set<T...>& s );
	template <typename ...T> PCDC& operator >>( const set<T...>& s )
	{
		PCDC& cout = *this;
		SHOW( s.size( ) );
		SHOW( s.max_size( ) );
		return *this;
	}
	template <typename T , typename X> PCDC& operator <<( const map<T , X>& m );
	template <typename T , typename X> PCDC& operator >>( const map<T , X>& m )
	{
		PCDC& cout = *this;
		SHOW( m.size( ) );
		SHOW( m.max_size( ) );
		return *this;
	}
	template <typename T , typename X> PCDC& operator <<( const multimap<T , X>& m );
	template <typename T , typename X> PCDC& operator >>( const multimap<T , X>& m )
	{
		PCDC& cout = *this;
		SHOW( m.size( ) );
		SHOW( m.max_size( ) );
		return *this;
	}
	template <typename  int N = 64> PCDC& operator <<( bitset<N>& bits );
	template <typename  int N = 64> PCDC& operator >>( bitset<N>& bits )
	{
		PCDC& cout = *this;
		SHOW( bits.size( ) );
		SHOW( bits.max_size( ) );
		SHOW( bits.none( ) );
		SHOW( bits.flip( ) );
		SHOW( bits.all( ) );
		return *this;

	}
	template <typename  int N = 64> PCDC& operator <<( const bitset<N>& bits );

public:
	template <typename T> T& MakeEleRandom( T& rc , const size_t elesize = 20 , const int mod = 10 );
	template <typename S = size_t> inline void linemod( S l , S linemod , PCDC& ( *op )( PCDC& ) = newl , char* stail = nullptr );
	template <typename T , size_t N = std::tuple_size<T>::value> PCDC& disptup( T t );
	template <typename A , typename B> bool comp( A a , B b ) { return a > b; };

	template <typename T> inline PCDC& forprintv( const T& v );
	template <typename T> inline PCDC& forprinta( const T* arr , size_t len );

	PCDC& adress( )
	{
		*this << st( address( ) ) << sp;
		return *this;
	};
	template <typename X> PCDC& address( X& a );
	template <typename T , typename ...X> PCDC& address( T& a , X&...args );
	template <typename X> PCDC& value( X* a );
	template <typename T , typename ...X> PCDC& value( T* a , X*...args );

	template<typename T> T lstraits( T t )
	{
		auto& cout = *this;
#define showtrait(type)  cout<<"is "#type"? : "<<tab(2)<<is_##type<T>::value<<nl;
#define showtraits(type)  cout<<#type"? : "<<tab(2)<<type<T>::value<<nl;
		showtrait( void );
		showtrait( null_pointer );
		showtrait( integral );
		showtrait( floating_point );
		showtrait( array );
		showtrait( enum );
		showtrait( union );
		showtrait( class );
		showtrait( function );
		showtrait( pointer );
		showtrait( lvalue_reference );
		showtrait( rvalue_reference );
		showtrait( member_object_pointer );
		showtrait( member_function_pointer );
		showtrait( fundamental );
		showtrait( arithmetic );
		showtrait( scalar );
		showtrait( object );
		showtrait( compound );
		showtrait( reference );
		showtrait( member_pointer );
		showtrait( const );
		showtrait( volatile );
		showtrait( trivial );
		showtrait( trivially_copyable );
		showtrait( standard_layout );
		showtrait( empty );
		showtrait( polymorphic );
		showtrait( abstract );
		showtrait( final );
		showtrait( aggregate );
		showtrait( signed );
		showtrait( unsigned );
		showtrait( bounded_array );
		showtrait( unbounded_array );
		showtrait( constructible );
		showtrait( default_constructible );
		showtrait( copy_constructible );
		showtrait( move_constructible );
		showtrait( copy_assignable );
		showtrait( move_assignable );
		showtrait( destructible );
		showtraits( has_virtual_destructor );
		showtraits( has_unique_object_representations );
		showtraits( alignment_of );
		return T( );
	};
	PCDC& type( ) { return *this; };
	//template <typename T > PCDC& type( T a );
	template <typename T > PCDC& type( T& a );
	template <typename T > PCDC& type( T&& a );
	//template <typename T , typename ...X> PCDC& type( T a , X...args );
	template <typename T , typename ...X> PCDC& type( T& a , X&...args );
	template <typename T , typename ...X> PCDC& type( T&& a , X&&...args );
	template<typename A , typename ...T > PCDC& TypeCount( A& a , T&... t );
	template <typename ...A , template<typename ...T> typename B> PCDC& TypeCount( B<A...>& a );
	template<typename A , typename ...T > PCDC& TypeCount( A&& a , T&&... t );
	template <typename ...A , template<typename ...T> typename B> PCDC& TypeCount( B<A...>&& a );

	template <typename X> PCDC& pt( X a );
	template <typename T , typename ...X> PCDC& pt( T a , X...args );
	template <typename X> PCDC& pc( X a );
	template <typename T , typename ...X> PCDC& pc( T a , X...args );
	template <typename X> PCDC& pb( X a );
	template <typename T , typename ...X> PCDC& pb( T a , X...args );
	PCDC& pl( ) { return *this; }
	template <typename T , typename ...X> PCDC& pl( T a , X...args );
	template<typename ...A>	PCDC& ps( A...args )
	{
		( ( *this << args << sp ) , ... );//	( cout << ...<< args);
		return *this;
	}

public:
	PCDC& displayfile( CString filename );
	template <typename T , typename ...X> PCDC& prints( T a , X...args );

public:
	void showsplitwindow( bool isleft = true , CRect* prect = nullptr )
	{
		CRect rect;
		if ( prect == nullptr )
		{
			rect.top = 0;
			rect.left = 0;
			rect.right = 1928;
			rect.bottom = 2112;
		}
		else
		{
			rect = *prect;
		}
		AfxGetApp( )->m_pMainWnd->SetWindowPos( &CWnd::wndTop , rect.left , rect.top , rect.right , rect.bottom , SWP_SHOWWINDOW );
		AfxGetApp( )->m_pMainWnd->UpdateWindow( );
		AfxGetApp( )->m_pMainWnd->ShowWindow( SW_SHOW );
	}

	template<typename T>
	PCDC& operator<<( const std::ranges::min_max_result<T>& mm )
	{
		return *this << "[max]: " << *mm.max << sp << "[min]: " << *mm.min << sp;
	}
	PCDC& modline( size_t n , PCDC& ( *op ) ( PCDC& ) = nullptr )
	{
		static size_t nline = 0;
		nline++;
		if ( nline % n == 0 )
			*this << nl;
		else
			*this << op;
		return *this;
	}

	PCDC& circle( size_t mod , bool isclear = false , PCDC& ( *tp )( PCDC& ) = tab , PCDC& ( *op )( PCDC& ) = nl , size_t ntimes = 1 ) {
		static size_t mark = 0;
		if ( isclear == true ) {
			mark = 0;
		}
		else {
			++mark;
			if ( mark % mod == 0 )
				*this << op;
			else
			{
				NTIME( ntimes )
					* this << tp;
			}
		}
		return *this;
	}

	//template<typename A>
//concept Xstring = requires( A s) {
//	s.IsEmpty( );
//	s.GetLength( );
//	s.Mid( );
//	requires std::same_as<A,CString>||same_as<A,CAtlString>;
//};
	//template<typename S>
	//requires Xstring<S>
	//PCDC& operator <<( S& s )
	//{
	//	*this << "Xstring";
	//	if ( !s.IsEmpty( ) )
	//	{
	//		imresizeout( s );
	//	}
	//	else
	//	{
	//		ms = "null(0)";
	//		imresizeout( ms );
	//	}
	//	return *this;
	//};
};

template <typename A , typename B>
PCDC& PCDC::operator||( const tuple<A , B>& tup )
{
	return ( *this ) << get<0>( tup ) << '|' << get<1>( tup ) << '|';
}

template <typename... Args>
PCDC& PCDC::operator||( const tuple<Args...>& tup )
{
	*this << '|' << get<0>( tup );
	return ( *this ) || ( tup._Get_rest( ) );
}

template <typename A , typename B>
PCDC& PCDC::operator|( const tuple<A , B>& tup )
{
	return ( *this ) << "{" << get<0>( tup ) << "}|{" << get<1>( tup ) << "}";
}

template <typename A , typename... Args>
PCDC& PCDC::operator|( const tuple<A , Args...>& tup )
{
	*this << "{" << get<0>( tup ) << "}|";
	return ( *this ) | ( tup._Get_rest( ) );
}

template<typename T>
PCDC& PCDC::operator [] ( const tuple<T>& tupa )
{
	return ( *this ) << "[" << tupa._Myfirst._Val << "]";
}

template <typename... Args>
PCDC& PCDC::operator [] ( const tuple<Args...>& tupa )
{
	*this << "[" << tupa._Myfirst._Val << "], ";
	return ( *this )[tupa._Get_rest( )];
};

template <typename A , typename ...X , typename R>
PCDC& PCDC::operator<<( R( A::* p )( X... ) )
{
	//( __thiscall A::*p )| ( __cdecl A::*p )
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template<typename P>
PCDC& PCDC::operator <<( const P* p )
{
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template<typename P>
PCDC& PCDC::operator <<( P* p )
{
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template <typename A , typename B>
PCDC& PCDC::operator <<( const pair<A , B>& i )
{
	auto& [first , second] = i;
	*this << "{ " << first << ", " << second << "}   ";
	return *this;
}

template <typename T , size_t len>
PCDC& PCDC::operator <<( const array<T , len>& a )
{
	if ( len == 0 || &a == nullptr )
		return *this;
	else
		return forprintv( a );
}

template <typename... X>
PCDC& PCDC::operator <<( const vector<X...>& v )
{
	if ( v.empty( ) )
		return *this;
	else
		return forprintv( v );
}

template <typename... T>
inline PCDC& PCDC::operator <<( const deque<T...>& d )
{
	if ( d.empty( ) )
		return *this;
	else
		return forprintv( d );
}

template <typename T , typename X>
PCDC& PCDC::operator <<( const map<T , X>& m )
{
	if ( !m.size( ) )
		return *this;
	else
		return forprintv( m );
}

template <typename T , typename X>
PCDC& PCDC::operator <<( const multimap<T , X>& m )
{
	if ( !m.size( ) )
		return *this;
	else
		return forprintv( m );
}

template <typename...T>
PCDC& PCDC::operator <<( const multiset<T...>& s )
{
	if ( !s.size( ) )
		return *this;
	else
		return forprintv( s );
}

template <typename ...T>
PCDC& PCDC::operator <<( const set<T...>& s )
{
	if ( !s.size( ) )
		return *this;
	else
		return forprintv( s );
}

template <typename T>
PCDC& PCDC::operator <<( const list<T>& l )
{
	if ( !l.size( ) )
		return *this;
	else
		return forprintv( l );
}

template <typename T >
PCDC& PCDC::operator <<( const complex<T>& z )
{
	return ( *this ) << z.real( ) << '+' << z.imag( ) << 'i';
};

template <typename... Args>
PCDC& PCDC::operator<<( tuple<Args...> tup )
{
	if ( ibegin == true ) {
		*this << "{ ";
		ibegin = false;
	}
	*this << "{" << tup._Myfirst._Val;
	if constexpr ( tuple_size<decltype( tup )>::value == 1 )
	{
		*this << '}';
	}
	else
	{
		*this << "}, ";
	}
	return ( *this ) << ( tup._Get_rest( ) );
}

template<typename T >
PCDC& PCDC::operator ()( initializer_list<T> c )
{
	T ibegin = *c.begin( ) - *c.begin( );
	forprintv( c );
	return *this;
}

template<typename T >
PCDC& PCDC::operator<<( initializer_list<T> c )
{
	T ibegin = *c.begin( ) - *c.begin( );
	forprintv( c );
	return *this;
}

template <typename  int N>
PCDC& PCDC::operator <<( bitset<N>& bits )
{
	string str = bits.to_string( );
	ms = str.c_str( );
	imresizeout( ms );
	return *this;
}

template <typename  int N>
PCDC& PCDC::operator <<( const bitset<N>& bits )
{
	string str = bits.to_string( );
	ms = str.c_str( );
	imresizeout( ms );
	return *this;
};

template<typename T , size_t N>
PCDC& PCDC::disptup( T t )
{
	constexpr size_t M = std::tuple_size<T>::value;
	constexpr size_t I = M - N;
	if constexpr ( N == 1 )
	{
		*this << "{" << std::get<I>( t ) << " }";
		return *this;
	}
	else
	{
		*this << " {" << std::get<I>( t ) << " },";
		disptup<T , N - 1>( t );
	}
	return *this;
};

template<typename T>
T& PCDC::MakeEleRandom( T& rc , const size_t elesize , const int mod )
{
	srand( time( nullptr ) );
	if ( rc.size( ) < elesize )
		rc.resize( elesize );
	for ( auto& i : rc )
		i = rand( ) % mod;
	return rc;
}

template <typename X>
PCDC& PCDC::address( X& a )
{
	//*this << st( T& ) << sp;
	if ( &a == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , &a );
	}
	imresizeout( ms );
	*this << '\t';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::address( T& a , X&...args )
{
	//*this << ( sizeof...( args ) ) << st( T... ) << sp;
	if ( &a == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , &a );
	}
	imresizeout( ms );
	return address( args... );
}

template <typename T >
PCDC& PCDC::type( T& a )
{

	std::string sc = "";
	if ( std::is_const<decltype( a )>::value )
		sc = "const ";
	sc += typeid( a ).name( );
	if ( std::is_reference<decltype( a )>::value )
		sc += "&";
	*this << "type:  " << sc << "  size:  ";
	settcolor( dccr.gteal );
	*this << sizeof( a );
	resettcolor( );
	*this << "  HASH: " << typeid( a ).hash_code( ) << newl;
	return *this;
};

template <typename T , typename ...X>
PCDC& PCDC::type( T& a , X&...args )
{
	type( a );
	return type( args... );
}

template <typename T , typename ...X>
PCDC& PCDC::type( T&& a , X&&...args )
{
	type( a );
	return type( args... );
}

template <typename T >
PCDC& PCDC::type( T&& a )
{
	std::string sc = "";
	if ( std::is_const<decltype( a )>::value )
		sc = "const ";
	sc += typeid( a ).name( );
	if ( std::is_reference<decltype( a )>::value )
		sc += "&";
	*this << "type:  " << sc << "  size:  ";
	settcolor( dccr.gteal );
	*this << sizeof( a );
	resettcolor( );
	*this << "  HASH: " << typeid( a ).hash_code( ) << newl;
	return *this;
};

template<typename ...A , template<typename ...T> typename B>
PCDC& PCDC::TypeCount( B<A...>& a )
{
	*this << "type:  " << typeid( a ).name( );
	*this << "  size:  " << sizeof( a );
	*this << "  HASH: " << typeid( a ).hash_code( );
	settcolor( dccr.midyellow );
	*this << " A<T...> T...count is :" << sizeof...( A ) << sp;
	resettcolor( );
	return *this;
}

template<typename A , typename ...T >
PCDC& PCDC::TypeCount( A& a , T&... t )
{
	TypeCount( a );
	*this << endl;
	if constexpr ( sizeof...( T ) == 1 )
	{
		TypeCount( a );
	}
	else
	{
		TypeCount( t... );
	}
	return *this;
}

template <typename ...A , template<typename ...T> typename B>
PCDC& PCDC::TypeCount( B<A...>&& a )
{
	*this << "type:  " << typeid( a ).name( );
	*this << "  size:  " << sizeof( a );
	*this << "  HASH: " << typeid( a ).hash_code( );
	settcolor( dccr.midyellow );
	*this << " A<T...> T...count is :" << sizeof...( A ) << sp;
	resettcolor( );
	return *this;
};

template<typename A , typename ...T >
PCDC& PCDC::TypeCount( A&& a , T&&... t )
{
	TypeCount( a );
	*this << endl;
	if constexpr ( sizeof...( T ) == 1 )
	{
		TypeCount( a );
	}
	else
	{
		TypeCount( t... );
	}
	return *this;
};

template <typename T>
PCDC& PCDC::title( T t , bool i )
{
	CString ts( t );
	if ( ts.IsEmpty( ) )
	{
		ts = _T( "BEGIN TEST" );
	};
	if ( i == UPPER )
	{
		ts.MakeUpper( );
	}
	else {
		ts.MakeLower( );
	}
	CString cs;
	cs = mmarkchar;
	PCDC& dc = *this;
	CSize size = dc.GetOutputTextExtent( cs );
	dc.m_pwnd->GetClientRect( &dc.mrect );
	auto w = dc.mrect.right - ( dc.mrect.left + dc.initalpos * 2 );
	size_t icount = w / size.cx - ts.GetLength( ) - 2;
	for ( size_t i = 0; i < ( icount / 2 ); ++i )
	{
		cs += this->mlinechar;
	}
	cs += ts;
	for ( size_t i = 0; i < ( icount - icount / 2 ); ++i )
	{
		cs += this->mlinechar;
	}
	cs += mmarkchar;
	if ( dc.p.x > dc.mrect.left + dc.initalpos )
		*this << endl;
	imresizeout( cs );
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pl( T a , X...args )
{
	*this << a << '\n';
	pl( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pt( X a )
{
	*this << a << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pt( T a , X...args )
{
	*this << a << '\t';
	pt( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pc( X a )
{
	*this << a << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pc( T a , X...args )
{
	*this << a << ", ";
	pc( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pb( X a )
{
	*this << '{' << a << "}" << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::prints( T a , X...args )
{
	*this << a;
	if constexpr ( ( sizeof...( X ) ) == 0 )
	{
		return *this;
	}
	else
	{
		return prints( args... );
	}
}

template <typename T , typename ...X>
PCDC& PCDC::pb( T a , X...args )
{
	*this << '{' << a << "},";
	return pb( args... );
}

template <typename X>
PCDC& PCDC::value( X* a )
{
	*this << *a << sp;
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::value( T* a , X*...args )
{
	//*this << ( sizeof...( args ) ) << st( T... ) << sp;
	*this << *a << sp;
	return value( args... );
}

template <typename S>
inline void PCDC::linemod( S l , S linemod , PCDC& ( *op )( PCDC& ) , char* stail )
{
	if ( l % linemod == 0 )
	{
		( *op )( *this );
		if ( stail )
			*this << stail;
	}
}

template<typename T>
inline PCDC& PCDC::forprintv( const T& v )
{
	size_t il = 0;
	for ( const auto& i : v )
	{
		*this << i << tab;// spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template<typename T>
inline PCDC& PCDC::forprinta( const T* arr , size_t len )
{
	size_t il = 0;
	for ( size_t i = 0; i < len; ++i )
	{
		*this << *( arr + i ) << tab;// spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template <typename T = int , bool isort = bigtosmall>
class icompset {
public:
	bool miset = true;
	T ivalset = 0;
	void* iptset = nullptr;
	bool ichceknull = false;

public:
	icompset( ) :miset( isort ) {
	};
	icompset& revese( bool set = true , bool toset = true )
	{
		if ( set )
			miset = !miset;
		else
			miset = toset;
		return *this;
	}
	icompset& sortset( bool set , T valset = 0 )
	{
		miset = set;
		ivalset = valset;
		return *this;
	}

	bool operator()( T c )const
	{
		if ( miset )
		{
			return c > ivalset;
		}
		else
		{
			return c < ivalset;
		}
	}

	bool operator()( T a , T b )const
	{
		if ( miset )
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}

	bool compare( T a , T b )const
	{
		if ( miset )
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}

	PCDC& operator()( CString name = _T( "noname" ) )
	{
		getcout;
		cout << name << tab << miset;
		return cout;
	};
};



