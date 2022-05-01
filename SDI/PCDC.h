#pragma once
#include "pch.h"
#include "SDI.h"
#include "muse.h"


class PCDC;
using XCout = PCDC;

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

extern class CColor dccr;
extern PCDC* pcout;

PCDC& cl( PCDC& dc );
PCDC& clear( PCDC& dc );
PCDC& com( PCDC& dc );
PCDC& semi( PCDC& dc );
PCDC& dash( PCDC& dc );
PCDC& star( PCDC& dc );
PCDC& cut( PCDC& dc );
PCDC& tab( PCDC& dc );
PCDC& sp( PCDC& dc );
PCDC& newl( PCDC& dc );
PCDC& nl( PCDC& dc );
PCDC& endl( PCDC& dc );
PCDC& starline( PCDC& dc );

CString hex( );
CString HEX( );
CString oct( );
CString udec( );
CString address( );
CString bools( );
CString tab( size_t Ntimes = 1 );
CString sp( size_t Ntimes = 1 );
CString letters( char lc , size_t Ntimes = 1 );


class PCDC : public CDC
{
public:
	bool isurerecode = true;
	bool icreate = false;
	size_t id = 0;
	inline static size_t icount = 0;
	int iargs = 0;
	bool ibegin = true;

public:
	inline static const LONG wbar = 8;
	inline static const LONG initalpos = wbar + 35;
	const LONG initalstep = 20;
	LONG step = initalstep;
	inline static POINT p = { initalpos, initalpos };
	CRect mrect;
	CSize msize;
	int ilinemod = 20;
	bool icutline = false;

public:
	COLORREF m_bk = dccr.grey;
	COLORREF m_tk = dccr.chocolate;
	COLORREF m_bark = dccr.lteal;
	COLORREF m_linek = dccr.azure;
	int mfontsize = 120;
	CFont font , * pfont;

public:
	CDC* m_cdc = nullptr;
	CWnd* m_pwnd = nullptr;

public:
	char mlinechar = _T( '-' );
	char mmarkchar = '=';
	CString spchar = _T( "  " );
	CString ms = _T( "" );
	inline static vector<CString>mvlogs;
	inline static CString sms = _T( "" );
	CString opstr = _T( "" );

public:
	PCDC( CWnd* pwnd = nullptr );
	PCDC& Create( CWnd* pwnd );
	PCDC& Release( );
	~PCDC( );

	//explicit operator char *() const;

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
	PCDC& operator<<( std::nullptr_t p );
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

public:
	PCDC& operator<< ( PCDC& ( *op ) ( PCDC& dc ) );

public:
	inline size_t getmaxline( ) { return ( mrect.bottom - mrect.top - initalpos ) / step; }
	inline PCDC& resettcolor( );
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
	inline bool stoprecode( ) { return isurerecode = false; }
	inline bool startrecode( ) { return isurerecode = true; }
	inline size_t storesms( bool isstorecomand = true )
	{
		static size_t nstore = 0;
		if ( !isstorecomand )
			return nstore;
		if ( isurerecode )
		{
			if ( !sms.IsEmpty( ) ) {
				if ( mvlogs.size( ) >= getmaxline( ) * 10 - 2 )
				{
					mvlogs.erase( mvlogs.begin( ) , mvlogs.begin( ) + getmaxline( ) * 5 );
					mvlogs.shrink_to_fit( );
					mvlogs.reserve( getmaxline( ) * 10 );
				}
				mvlogs.push_back( sms );
				nstore++;
				sms.Empty( );
			}
		}
		return nstore;
	}
	inline size_t showsms( size_t n )
	{
		size_t maxn = getmaxline( );
		size_t logsize = mvlogs.size( );
		size_t nshow = gmin( n , maxn , logsize );
		auto itend = mvlogs.end( );
		auto itstart = itend - nshow;

		isurerecode = false;
		for ( ; itstart != mvlogs.end( ); itstart++ )
			*this << *itstart << endl;
		isurerecode = true;
		return nshow;
	}
	PCDC& settcolor( COLORREF tk );
	 PCDC& setcolor( COLORREF line , COLORREF bar , COLORREF bk , COLORREF tk );
	PCDC& setimod( int imod );
	template <typename T = CString>inline PCDC& title( T t , bool ib = true );
	char setlinechar( const char& c = '=' );
	inline PCDC& flushscreen( const CRect* r = nullptr , const COLORREF* cr = nullptr );
	inline PCDC& tb( size_t t = 1 , char c = '\t' ) { NTIME( t )* this << c; return *this; }
	inline PCDC& location( )
	{
		return *this << __FILE__ << sp << __LINE__ << sp << __func__ << endl;
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
	inline void quickclear( )
	{
		CRect rect = mrect;
		rect.bottom -= wbar;
		rect.bottom -= initalpos / 2;
		rect.left += wbar;
		rect.left += initalpos / 2;
		rect.right -= wbar;
		rect.right -= initalpos / 2;
		rect.top += wbar;
		rect.top += initalpos / 2;
		//m_pwnd->InvalidateRect( rect , true );
		p.x = mrect.left + initalpos;
		p.y = mrect.top + initalpos;
		FillSolidRect( rect , m_bk );
		storesms( );
	};
	template<typename Tstring> inline void imresizeout( Tstring cs )
	{
		if ( cs.IsEmpty( ) )
		{
			return;
		}
		m_pwnd->GetClientRect( &mrect );
		msize = this->GetOutputTextExtent( cs );
		auto linelen = mrect.right - initalpos - p.x;
		auto strlen = msize.cx;

		if ( strlen <= linelen )
		{
			//need recalc position***
			TextOut( p.x , p.y , cs );
			recode( cs );
			p.x += msize.cx;

			//need check position***
			if ( p.x >= ( mrect.right - initalpos * 2 ) )
			{
				storesms( );
				p.x = mrect.left + initalpos;
				p.y += step;
			}

			if ( p.y >= mrect.bottom - mrect.top - initalpos )
			{
				storesms( );
				this->quickclear( );
				p.y = mrect.top + initalpos;
			}
		}
		else
		{
			auto cslen = cs.GetLength( );
			auto tkpos = linelen * cslen / strlen;
			imresizeout( (Tstring&&)cs.Mid( 0 , tkpos ) );
			storesms( );
			imresizeout( (Tstring&&)cs.Mid( tkpos , cslen - tkpos ) );
		}
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
	template <typename T> PCDC& operator ()( T t ) { return ( *this ) << t; };
	template <typename T> PCDC& operator ()( initializer_list<T> c );

	template <typename... Args> PCDC& operator<<( tuple<Args...> tup );
	template <>	PCDC& operator<<( tuple<> tup ) { ibegin = true; return ( *this ) << " }"; }
	template <typename X> PCDC& operator <<( const unique_ptr<X>& unptr );
	template <typename T> PCDC& operator <<( const complex<T>& z );
	template <typename P> PCDC& operator <<( P* p );
	template <typename P> PCDC& operator <<( const P* p );
	template <typename T> PCDC& operator<<( initializer_list<T> c );
	template <typename T> PCDC& operator <<( const list<T>& l );
	template <typename T , size_t len> PCDC& operator <<( const array< T , len>& a );
	template <typename A , typename B> PCDC& operator <<( const pair<A , B>& i );
	template <typename... X> inline PCDC& operator <<( const vector<X...>& v );
	template <typename... T> PCDC& operator <<( const multiset<T...>& s );
	template <typename ...T> PCDC& operator <<( const deque<T...>& d );
	template <typename ...T> PCDC& operator <<( const set<T...>& s );
	template <typename T , typename X> PCDC& operator <<( const map<T , X>& m );
	template <typename T , typename X> PCDC& operator <<( const multimap<T , X>& m );
	template <typename  int N = 64> PCDC& operator <<( bitset<N>& bits );
	template <typename  int N = 64> PCDC& operator <<( const bitset<N>& bits );

public:
	template <typename T> T& MakeEleRandom( T& rc , const size_t elesize = 20 , const int mod = 10 );
	template <typename S = size_t> inline void linemod( S l , S linemod , PCDC& ( *op )( PCDC& ) = newl , char* stail = nullptr );
	template <typename T , size_t N = std::tuple_size<T>::value> PCDC& disptup( T t );
	template <typename A , typename B> bool comp( A a , B b ) { return a > b; };

	//template <typename T> PCDC& forprintr( const T* b , const T* e );
	template <typename T> inline PCDC& forprintv( const T& v );
	template <typename T> PCDC& forprinta( const T* arr , size_t len );

	PCDC& adress( ) { *this << st( address( ) ) << sp; return *this; };
	template <typename X> PCDC& address( X& a );
	template <typename T , typename ...X> PCDC& address( T& a , X&...args );
	template <typename X> PCDC& value( X* a );
	template <typename T , typename ...X> PCDC& value( T* a , X*...args );

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

public:
	PCDC& displayfile( CString filename );
	template <typename T , typename ...X> PCDC& prints( T a , X...args );

public:

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

template <typename X>
PCDC& PCDC::operator <<( const unique_ptr<X>& unptr )
{
	ms.Format( _T( "%p" ) , unptr.get( ) );
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
	//*this << st( T* ) << sp;
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
	int il = 0;
	for ( const auto& i : v )
	{
		*this << i << spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template<typename T>
PCDC& PCDC::forprinta( const T* arr , size_t len )
{
	int il = 0;
	for ( size_t i = 0; i < len; ++i )
	{
		*this << *( arr + i ) << spchar;
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



