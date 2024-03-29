#pragma once

#include "PCDC.h"


class PCDC;
class CColor;
using XCout = PCDC;

extern class CColor dccr;
extern PCDC* pcout;


using namespace std;

#define LOGMESSAGE(objectname)  {\
		CString strmessage;\
		static unsigned long icount = 0;\
		++icount;\
		strmessage.Format(_T("Run Path in %ldth times,The Class:$"), icount);\
		strmessage += typeid(*this).name();\
		strmessage += " @";\
		strmessage += __func__;\
		strmessage += "()";\
		strmessage += " file: *";\
		strmessage += __FILE__;\
		objectname##.messagelog.push_back(strmessage);\
		}

#define SHOWSPLITLWINDOW(objectname)  {\
		objectname.m_pMainWnd->ShowWindow(SW_SHOW);\
		RECT rect;\
		rect.left =1918;\
		rect.top = 0;\
		rect.right = 1928;\
		rect.bottom = 2112;\
		objectname.m_pMainWnd->SetWindowPos(&CWnd::wndTop, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);\
		objectname.m_pMainWnd->UpdateWindow();\
		}
#define SHOWSPLITRWINDOW(objectname)  {\
		objectname.m_pMainWnd->ShowWindow(SW_SHOW);\
		RECT rect;\
		rect.left =1918;\
		rect.top = 0;\
		rect.right = 1928;\
		rect.bottom = 2112;\
		objectname.m_pMainWnd->SetWindowPos(&CWnd::wndTop, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);\
		objectname.m_pMainWnd->UpdateWindow();\
		}
//#define currlocation cout.location( std::source_location::current( ) );

//�����ַ����Ƿ�Ϊ�յĺ�
#ifndef isempty
#define isempty(astr) ((astr) == (_T("")))
#endif // !empty

//�������Ժ�

#ifndef isok
#define isok(a) ((a)==true)
#endif	

#define errmessage(err)  {\
		CAtlString strmessage=_T("#err:");\
		strmessage +=_T(#err"in ");\
		strmessage += __func__;\
		strmessage += _T("()");\
		AfxMessageBox(strmessage);\
		}

#define locationmessage  cout<<st( file is:)<<__FILE__<<sp<<st( line# is :)<< __LINE__<<sp<<st(function is :) <<__func__<<endl;

#ifndef st

#define st(...)		(_T(#__VA_ARGS__))

#define xsms(...)	getcout;cout.settcolor(dccr.midgreenblue);\
					cout<<#__VA_ARGS__<<endl;\
					cout.resettcolor( );
#define sms(...)	cout.settcolor(dccr.midgreenblue);\
					cout<<#__VA_ARGS__<<endl;\
					cout.resettcolor( );
#define smi(...)	cout<<st(__VA_ARGS__)<<endl;
#define smn(...)	cout<<st(__VA_ARGS__)<<sp;


#endif	

#ifndef strbox

#define strbox(OK) AfxMessageBox(_T(#OK))

#endif	

#define vec(T) vector<T> 

#define comment(...) cout<<"//"#__VA_ARGS__;

#define SNint unsigned char
#define SSint unsigned short int

#define bigtosmall true
#define smalltobig false
#define UP true
#define UPPER true
#define LOWER false
#define LOW false
#define DOWN false
#define RESET -1
#define REVERSE -2
#define KEEPSTATUS -3
#define NOT !
#define nonull(v) (( (v )!=nullptr )&&((&v)!=nullptr ) )

#define NTIME(N)  for(size_t ix=0;ix<(N);++ix)
#define STEP(I,STEP,N)  for(size_t (ix)=I;(ix)<(N);ix+=(STEP))
#define STEPTO(I,STEP,N)  for(size_t (ix)=I;(ix)<=(N);ix+=(STEP))
#define UNTIL(N) for(size_t ix=0;ix++<(N);)
#define FORTO(I,N) for(size_t ix=(I);ix<=(N);++ix)
#define FORDOWNTO(N,I) for(size_t ix=(N);ix>=(I);--ix)
#define pointer *
#define NOTHING
#define EMPTY(...) 
#define ref &

#define gett(name)  decltype(name)
#define getI(name)  gett(name.begin())
#define getCI(name)  gett(name)::const_iterator
#define ALL(V)  V.begin(),V.end()
#define FORALL(V,iterator)  for(getI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORALLW(V,iterator)  for(getCI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORN(N,icountn)  for(size_t icountn=0;icountn<(N);++icountn)
#define FORV(ielement,V)  for(const auto &ielement:V)
#define FORW(ielement,V)  for(auto &ielement:V)

#define SimulationStdCout  if(PCDC::pXCout==nullptr){PCDC::pXCout=new PCDC((CWnd*)this);};PCDC& cout=*PCDC::pXCout;
#define getcout PCDC& cout=*PCDC::pXCout;

#define sst(code,...)  #code##","#__VA_ARGS__;

#define rcode(...)	cout.settcolor(dccr.smokewhite);\
					cout<<"{ "#__VA_ARGS__<<L" }";\
					cout<<separtor;\
					cout.resettcolor();\
					__VA_ARGS__ 

#define code(...)	__VA_ARGS__\
					cout.settcolor(dccr.smokewhite);\
					cout<<separtor;\
					cout<<"{ "#__VA_ARGS__<<L" }"<<newl;\
					cout.resettcolor();

#define lcode(...)	cout.settcolor(dccr.smokewhite);\
					cout.title(L"sourcecodes",LOWER);\
					cout<<"{ "#__VA_ARGS__<<L" }";\
					cout.title(L"outresult",LOWER);\
					cout.resettcolor();\
					__VA_ARGS__

#define showcode(...)	lcode(__VA_ARGS__)
#define showcodes(...)	lcode(__VA_ARGS__)
#define lscode(...)  lcode(__VA_ARGS__)

#define SHOW(name) cout<<st(name)<<_T("  is: ")<<name<<tab
#define showv(vname) cout<<st(vname)<<_T(" value: ")<<vname<<sp<<_T(" type: ")<<(typeid(vname).name())<<sp
#define showtype(...)  cout<<#__VA_ARGS__<<":  type: ";\
						cout<< typeid( ##__VA_ARGS__ ).name( );\
						cout<<"  size: ";\
						cout.settcolor( dccr.gteal );\
						cout<<sizeof(##__VA_ARGS__);\
						cout.resettcolor();\
						cout<<"  HASH :"<<typeid(##__VA_ARGS__).hash_code()<<newl

#define RUNTEST(message)		cout.flushscreen();TITLE(message);
#define TITLE(message)      cout.title(CString(st(message)));

#define Mptr(va,tp) unique_ptr<tp>va=make_unique<tp>();
#define Msptr(va,tp) shared_ptr<tp>va=make_shared<tp>();
#define Mptrs(va,tp,n) unique_ptr<tp[]>va=make_unique<tp[]>(n);
#define Msptrs(va,tp,n) shared_ptr<tp[]>va=make_shared<tp[]>(n);
#define BEGINTEST(times)  {size_t itimes=times;\
					auto start = clock( );\
					NTIME( itimes){

#define ENDTEST 	}auto end = clock( );\
					cout<<separtor;\
					cout <<itimes<<"'s Totaltimes: ";\
					cout<<long double( ( (long double)end - (long double)start ) * 1000 / CLOCKS_PER_SEC ) << "\'ms.";\
					cout<<"   Once: ";\
					cout<<long double( ( (long double)end - (long double)start ) * 1000*1000) / (CLOCKS_PER_SEC *itimes);\
					cout<<"\'us, ";\
					cout<<long double( ( (long double)end - (long double)start ) * 1000*1000*1000) / (CLOCKS_PER_SEC *itimes);\
					cout<<"\'ns.   Total clock: "<<end-start<<sp;\
					cout<<st(CLOCKS_PER_SEC :)<<CLOCKS_PER_SEC<<'.'<<endl;}

#define abstype(a)		{ std::string sc = "";\
						if ( std::is_const<decltype( a )>::value )\
						sc = "const ";\
						sc += typeid( a ).name( );\
						if ( std::is_reference<decltype( a )>::value )\
						sc += "&";\
						if ( std::is_rvalue_reference<decltype( a )>::value )\
						sc += "&";\
						cout << "type:  " << sc << "  size:  ";\
						cout<< sizeof( a );\
						cout<<"  HASH: " << typeid( a ).hash_code( ) << newl;}

//printsource(��__FILE__,__LINE__);
	//#define comment printsource(__FILE__,__LINE__);
	//#define comments(nline) printsource(��__FILE__,__LINE__,nline);
	//#define endcomment printsourceend((__FILE__,__LINE__);

template <typename... T>
auto remulti( T&...args )
{
	return std::make_tuple( args... );
}

template <typename... T>
auto remulti( T&&...args )
{
	return std::make_tuple( args... );
}

template <typename T>
bool swap( T& a , T& b )
{
	if ( ( a != nullptr ) && ( b != nullptr ) && ( &a != nullptr ) && ( &b != nullptr ) && ( &a != &b ) )
	{
		T c;
		c = a;
		a = b;
		b = c;
		return true;
	}
	return false;
}

template<typename T>
T gsum( initializer_list<T> v )
{
	T isum {};
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			isum += i;
		}
	}
	return isum;
}

template<typename A = long double , typename ...X>
auto gsum( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gsum<T>( il );
}

template<template<typename A , typename ...B >typename C , typename T , typename ...X>
auto gsum( C<T , X...> c )
{
	if ( c.empty( ) )
		return T( );
	T isum = *c.begin( );
	for ( auto& i : c )
	{
		isum += i;
	}
	return isum;
}

template<typename T >
auto sum( vector<T> c )
{
	T isum = *c.begin( ) - *c.begin( );
	for ( auto i : c )
		isum += i;
	return isum;
}

template<typename T >
auto sum( initializer_list<T> c )
{
	T isum = *c.begin( ) - *c.begin( );
	for ( auto i : c )
		isum += i;
	return isum;
}

template<typename ...A , template<typename ...T> typename B>
size_t tpcount( B<A...> a )
{
	return  sizeof...( A );
}

template<typename T>
T gmin( initializer_list<T> v )
{
	T imin = *v.begin( );
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			imin = min( imin , i );
		}
	}
	return imin;
}

template<typename A = long double , typename ...X>
auto gmin( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gmin<T>( il );
}

template<typename T>
T gmax( initializer_list<T> v )
{
	T imax = *v.begin( );
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			imax = max( imax , i );
		}
	}
	return imax;
}

template<typename A = long double , typename ...X>
auto gmax( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gmax<T>( il );
}

template<typename T , typename ...A >
auto gmax( vector<T , A...> v )
{
	if ( v.empty( ) )
		return A( );
	A imax = *v.begin( );
	for ( auto it = v.begin( ) + 1; it != v.end( ); ++it )
	{
		if ( imax < *it )
			imax = *it;
	}
	return imax;
}

template<template<typename A , typename ...B >typename C , typename T , typename ...X>
auto gmax( C<T , X...> c )
{
	if ( c.empty( ) )
		return T( );
	T imax = *c.begin( );
	for ( auto& i : c )
	{
		if ( imax < i )
			imax = i;
	}
	return imax;
}

template<template<typename A , typename ...B >typename C , typename T , typename ...X>
auto gmin( C<T , X...> c )
{
	if ( c.empty( ) )
		return T( );
	T imin = *c.begin( );
	for ( auto& i : c )
	{
		if ( imin > i )
			imin = i;
	}
	return imin;
}

template<typename T = int , typename ...X>
auto imin( X...args )
{
	initializer_list<T>il { (T)( args )... };
	return *ranges::min_element( il );
}

template<typename T = int , typename ...X>
auto imax( X...args )
{
	initializer_list<T>il { (T)( args )... };
	return *ranges::max_element( il );
}

template<typename T = int>
bool itiszero( T a = T( ) )
{
	return a == T( );
}

template<typename T>
bool itisnull( T p )
{
	return ( ( nullptr == &p ) || ( p == T( ) ) );
}

template<typename T>
bool itisnull( T* p )
{
	return ( ( nullptr == p ) || ( *p == T( ) ) );
}

template<typename T = int>
bool itisempty( T a = T( ) )
{
	return a == T( );
}

template<typename T = int>
T lex( T a = T( ) )
{
	using O = decltype( T( ) );
	return O( a );
}

template<typename T = int>
T lexzero( T a = T( ) )
{
	return T( );
}

//template<typename T >
//auto sum( vector<T> c )
//{
//	T isum = *c.begin( ) - *c.begin( );
//	for ( auto i : c )
//		isum += i;
//	return isum;
//}

//template<typename T >
//auto sum( initializer_list<T> c )
//{
//	T isum = *c.begin( ) - *c.begin( );
//	for ( auto i : c )
//		isum += i;
//	return isum;
//}

//template<typename ...A , template<typename ...T> typename B>
//size_t tpcount( B<A...> a )
//{
//	return  sizeof...( A );
//}

template<typename T>
T& MakeSingleEleRandom( T& r , const int mod )
{
	return r = rand( ) % mod;
}

template<typename T>
bool MakeEleRandom( T& v , const int mod )
{
	srand( time( nullptr ) );
	if ( v.empty( ) )
		return false;
	for ( auto& i : v )
		MakeSingleEleRandom( i , mod );
	return true;
}
typedef int ( *pfunc )( PCDC& , string );

template <typename T , bool isup = true>
bool compare( T a , T b )
{
	static bool iset = false;
	if ( isup )
	{
		return a > b;
	}
	else
	{
		return a < b;
	}
}

template <typename T>
CString address( T* p )
{
	CString cs;
	if ( p == nullptr )
	{
		cs = "nullptr";
	}
	else
	{
		cs.Format( _T( "[0x%p]" ) , p );
	}
	return cs;
}

template <typename T , typename ...X>
CString address( T& a , X&...args )
{
	static CString cs;
	CString ms = address( &a );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ',' + address( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
}

template <typename T >
CString udec( T& t )
{
	CString cs;
	cs.Format( _T( "%lu" ) , t );
	return cs;
}

template <typename T , typename...X>
CString udec( T& t , X&...args )
{
	static CString cs;
	CString ms = udec( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + udec( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString oct( T& t )
{
	CString cs;
	cs.Format( _T( "%#lo" ) , t );
	return cs;
}

template <typename T , typename...X>
CString oct( T& t , X&...args )
{
	static CString cs;
	CString ms = oct( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + oct( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString HEX( T& t )
{
	CString cs;
	cs.Format( _T( "%#lX" ) , t );
	return cs;
}

template <typename T , typename...X>
CString HEX( T& t , X&...args )
{
	static CString cs;
	CString ms = HEX( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + HEX( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename B >
CString bools( B b )
{
	CString cs;
	if ( (bool)b == true )
	{
		cs = "true";
	}
	else
	{
		cs = "false";
	}
	return cs;
}

template <typename B , typename...X>
CString bools( B b , X...args )
{
	CString cs;
	cs += bools( b );
	if ( cs.GetLength( ) >= 4 )
	{
		cs += "  ";
	}
	cs += bools( args... );
	return cs;
};

template <typename T >
CString sizeos( T& t )
{
	CString cs;
	cs.Format( _T( "%lu" ) , sizeof( t ) );
	return cs;
}

template <typename T , typename...X>
CString sizeos( T& t , X&...args )
{
	static CString cs;
	CString ms = sizeos( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + sizeos( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString hex( T& t )
{
	CString cs;
	cs.Format( _T( "%#lx" ) , t );
	return cs;
}

template <typename T , typename...X>
CString hex( T& t , X&...args )
{
	static CString cs;
	CString ms = hex( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + hex( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};




//template <typename T >
//PCDC& PCDC::type( T a )
//{
//
//	std::string sc = "";
//	if ( std::is_const<decltype( a )>::value )
//		sc = "const ";
//	sc += typeid( a ).name( );
//	if ( std::is_reference<decltype( a )>::value )
//		sc += "&";
//	*this << "type:  " << sc << "  size:  ";
//	settcolor( dccr.gteal );
//	*this << sizeof( a );
//	resettcolor( );
//	*this << "  HASH: " << typeid( a ).hash_code( ) << newl;
//	return *this;
//};
//
//template <typename T , typename ...X>
//PCDC& PCDC::type( T a , X...args )
//{
//	type( a );
//	return type(args... );
//}
//
//template<typename T>
//PCDC& PCDC::forprintr( const T* b , const T* e )
//{
//	int il = 0;
//	for ( const auto* it = b; it != e; ++it )
//	{
//		*this << *it << spchar;
//		linemod( ++il , ilinemod );
//	}
//	return *this;

//const CSize& msout( const CString& cs )
//{
//	//this->GetTextExtent
//	m_pwnd->GetClientRect( &mrect );
//	msize = GetOutputTextExtent( cs );
//
//	CString news( 'x' );
//	auto size = GetOutputTextExtent( news );
//
//	LONG linelen = mrect.right - mrect.left - initalpos * 2;
//	LONG strlen = msize.cx;
//	int cslen = cs.GetLength( );
//	news = cs;
//	CString heads;
//	CString tails;
//	int tkpos = cslen * linelen / strlen - 1;
//	if ( strlen > ( linelen - size.cx ) )
//	{
//		for ( int i = cslen; i >= 0; i -= tkpos )
//		{
//			heads = news.Mid( 0 , tkpos );
//			tails = news.Mid( tkpos , news.GetLength( ) );
//			msout( heads );
//			news = tails;
//		}
//	}
//	else
//	{
//		if ( p.x + msize.cx >= mrect.right - mrect.left - initalpos )
//		{
//			p.x = mrect.left + initalpos;
//			p.y += step;
//		}
//		if ( p.y >= mrect.bottom - mrect.top - initalpos )
//		{
//			this->FillSolidRect( mrect , m_bk );
//			this->flushscreen( );
//			p.y = mrect.top + initalpos;
//		}
//		//need recalc ned***
//		TextOut( p.x , p.y , cs );
//		p.x += msize.cx;
//	}
//	return msize;
//}

//PCDC& args( )
//{
//	*this << __func__ << "  args4#" << iargs++ << newl;
//	return *this;
//}
//template <typename X>
//PCDC& args( X&& a )
//{
//	*this << __func__ << "  args3#" << iargs++ << newl;
//	return *this;
//}
//template <typename... X>
//PCDC& args( X&&...Args )
//{
//	*this << __func__ << "  args2#" << iargs++ << " sizeof is: " << sizeof...( Args ) << newl;
//	args( (X&&)Args... );
//	return *this;
//}
//template <typename T , typename... X>
//PCDC& args( T a , X&&...Args )
//{
//	*this << __func__ << " args1# " << iargs++ << " sizeof is: " << sizeof...( Args ) << newl;
//	args( (X&&)Args... );
//	return *this;
//}


	//inline void imresizeout( CString&& cs )
	//{
	//	if ( cs.IsEmpty( ) )
	//	{
	//		return;
	//	}
	//	m_pwnd->GetClientRect( &mrect );
	//	msize = this->GetOutputTextExtent( cs );
	//	long linelen = mrect.right - initalpos - p.x;
	//	long strlen = msize.cx;
	//	long tkpos;

	//	if ( strlen <= linelen )
	//	{
	//		//need recalc position***
	//		TextOut( p.x , p.y , cs );
	//		p.x += msize.cx;
	//		//need check position***
	//		if ( p.x >= ( mrect.right - initalpos * 2 ) )
	//		{
	//			p.x = mrect.left + initalpos;
	//			p.y += step;
	//		}
	//		if ( p.y >= mrect.bottom - mrect.top - initalpos )
	//		{
	//			this->quickclear( );
	//			p.y = mrect.top + initalpos;
	//		}
	//	}
	//	else
	//	{
	//		long cslen = cs.GetLength( );
	//		tkpos = linelen * cslen / strlen;
	//		imresizeout( cs.Mid( 0 , tkpos ) );
	//		imresizeout( cs.Mid( tkpos , cslen ) );
	//	}
	//	if ( p.x == initalpos ) imresizeout( CString( "<&&>" ) );
	//}

	//inline void imresizeout( const CString& cs )
	//{
	//	if ( cs.IsEmpty( ) )
	//	{
	//		return;
	//	}
	//	m_pwnd->GetClientRect( &mrect );
	//	msize = this->GetOutputTextExtent( cs );
	//	long linelen = mrect.right - initalpos - p.x;
	//	long strlen = msize.cx;
	//	long tkpos , cslen;

	//	if ( strlen <= linelen )
	//	{
	//		//need recalc position***
	//		TextOut( p.x , p.y , cs );
	//		p.x += msize.cx;
	//		//need check position***
	//		if ( p.x >= ( mrect.right - initalpos * 2 ) )
	//		{
	//			p.x = mrect.left + initalpos;
	//			p.y += step;
	//		}
	//		if ( p.y >= mrect.bottom - mrect.top - initalpos )
	//		{
	//			this->quickclear( );
	//			p.y = mrect.top + initalpos;
	//		}
	//	}
	//	else
	//	{
	//		cslen = cs.GetLength( );
	//		tkpos = linelen * cslen / strlen;
	//		imresizeout( cs.Mid( 0 , tkpos ) );
	//		imresizeout( cs.Mid( tkpos , cslen ) );
	//	}
	//	if ( p.x == initalpos ) imresizeout( CString( "<&>" ) );
	//}

	//inline void quickclear( )
	//{
	//	CRect rect;
	//	m_pwnd->GetClientRect( &rect );
	//	rect.bottom -= initalpos;
	//	rect.left += initalpos ;
	//	rect.right -= initalpos ;
	//	rect.top += initalpos ;
	//	p.x = rect.left + initalpos;
	//	p.y = rect.top + initalpos;
	//	FillSolidRect(rect , m_bk );
	//	storesms( );
	//};