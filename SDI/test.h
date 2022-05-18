#pragma once
#include "pch.h"
#include "PCDC.h"


void OnStlSetTest1( PCDC& cout );
void OnStlSetTest2( PCDC& cout );
void OnStlSetTest3( PCDC& cout );

void OnStlTypeTest1( PCDC& cout );
void OnStlTypeTest2( PCDC& cout );
void OnStlTypeTest3( PCDC& cout );

void OnObjectSize1( PCDC& cout );
void OnObjectSize2( PCDC& cout );
void OnObjectSize3( PCDC& cout );

void OnDcTcolorTest1( PCDC& cout );
void OnDcTcolorTest2( PCDC& cout );
void OnDcTcolorTest3( PCDC& cout );
void OnDcTcolorTest4( PCDC& cout );
void OnDcTcolorTest5( PCDC& cout );

void OnPCDCFunctionTest1( PCDC& dc );
void OnPCDCFunctionTest2( PCDC& dc );
void OnPCDCFunctionTest3( PCDC& dc );
void OnPCDCFunctionTest4( PCDC& dc );
void OnPCDCFunctionTest5( PCDC& dc );
void OnPCDCFunctionTest6( PCDC& dc );
void OnPCDCFunctionTest7( PCDC& dc );
void OnPCDCFunctionTest8( PCDC& dc );
void OnPCDCFunctionTest9( PCDC& dc );

void OnTaskRuntimeTest1( PCDC& dc );
void OnTaskRuntimeTest2( PCDC& dc );
void OnTaskRuntimeTest3( PCDC& dc );
void OnTaskRuntimeTest4( PCDC& dc );
void OnTaskRuntimeTest5( PCDC& dc );

void test00( PCDC& dc );
void test01( PCDC& dc );
void test02( PCDC& dc );
void test03( PCDC& dc );
void test04( PCDC& dc );
void test05( PCDC& dc );

void test_build_container( );
void test_build_vector( );

int adfunc( const int a );
int  afunc( unsigned  long long int& a );
int  afunc( int a );
int  afunc( int& a );
void fun( int& a );
void fun( const int& a );
void fun( int&& a );
void fun( const int&& a );
void fun( int* a );
int ntest( PCDC& dc , string p );
int f( int a , int b );
template <typename T>
T( *pt )( T a , T b );
void runexcept( int ia = 1 , float fa = 2.1 , char* ps = nullptr )throw( int , float , double , char* , char , CString );

class ptr;

template<typename T>
struct bigto
{
	T ia = T( );
	bool ibig = true;
	bigto( ) {};
	bigto( bool is ) :ibig( is ) {};
	bigto( T iset , bool is = true ) :ia( iset ) , ibig( is ) {}
	bool operator()( T icomp )
	{
		bool iret = true;
		if ( ibig ) {
			iret = icomp > ia;
		}
		else {
			iret = icomp < ia;
		}
		return iret;
	}
	bool operator()( T a , T b )
	{
		bool iret = true;
		if ( ibig ) {
			iret = a > b;
		}
		else {
			iret = a < b;
		}
		return iret;
	}
	bool set( bool is = true , T icomp = T( ) )
	{
		ibig = is;
		ia = icomp;
		return ibig;
	}
	bool up( ) { ibig = false; return !ibig; }
	bool down( ) { ibig = true; return ibig; }
	bigto& operator >( T icomp )
	{
		ia = icomp;
		return *this;
	}
	bigto& operator <( T icomp )
	{
		ia = icomp;
		return *this;
	}
};

template <typename T , typename ...Args>
auto build_vector( T first , Args... args )
{
	vector<T>v { first ,( args )... };
	return v;
}

template <template<typename A , typename ...B> typename Container , typename T , typename ...Args >
auto build_container( T first , Args... args )
{
	Container<T>c { (T&&)first ,(Args&&)args ... };
	return c;
}

template<typename A , typename ...T>
auto makevector( A a , T...args )
{
	getcout;
	vector<A>c { a,args... };
	cout << c << newl;
	return c;
}

template<typename P>
bool delptr( P*& p )
{
	//getcout; cout << "P*" << sp;
	if ( p != nullptr ) {
		delete p;
		p = nullptr;
		return true;
	}
	return false;
}

template<typename P , typename ...Args>
bool delptr( P*& p , Args&...args )
{
	constexpr size_t N = sizeof...( Args );
	//getcout; cout << "A*..." << N << sp;
	delptr( p );
	if constexpr ( N == 0 )
	{
		auto iret = delptr( p );
		return iret;
	}
	else
	{
		delptr( args... );
	}
	return false;
}

template<typename A , typename B>
bool comp( A a , B b )
{
	getcout;
	cout << "a > b is : ";
	return a > b;

}

template<typename ...Args>
void print( Args... args )
{
	getcout;
	cout << " in print()" << endl;
}

template<typename A , typename ...Args>
void print( A a , Args...args ) {
	getcout;
	cout << a << sp;
	print( args... );
}

template <typename T>
T add( T a , T b )
{
	return a + b;
}

template <typename T>
T sub( T a , T b )
{
	return a - b;
}

template <typename T>
T mul( T a , T b )
{
	return a * b;
}

template <typename T>
T divv( T a , T b )
{
	return a / b;
}

template <typename X , typename T>
X sub( X a , T b )
{
	cout << "temp x sub" << endl;
	X c;
	c = a - (X)b;
	return c;
}

template<typename T>
void funt( T&& a )
{
	getcout;
	cout << typeid( std::forward<T>( a ) ).name( ) << tab << a << tab << typeid( T&& ).name( );
}

template <typename T>
void callf( T v )
{
	getcout;
	fun( v );
	fun( (T&&)( v ) );
	fun( std::forward<T>( v ) );
	cout << cut;
}

template <typename T = int , int N = 1>
T returnt( )
{
	T ib = 2.2;
	for ( size_t i = 0; i < N; i++ )
	{
		ib = i + ib + 1;
	}
	return 100.22 * ib;
};

namespace type {
	typedef int INT;
	typedef double DOUB;
	using CHPtr = char*;
}

struct sType {
	typedef int INT;
	typedef double DOUB;
#define LNT  INT
	using CHPtr = char*;
};

template<typename ...T>
class base {};

template<typename ...T>
class bbase :public base<T...>
{};

template<typename ...T>
class basef {};

template<typename T>
class dbasef :public T
{};

template<class T>
struct typestruct {
	typedef map<int , T> mytype;
};

class ptr
{
public:
	CString name = _T( "anonymous " );
	//PCDC& cout = *pcout;
	getcout;
	bool isborn = true;
	int mid = 0;
	static int iall;
public:
	ptr( ) {
		static int ianon = 0;
		++ianon;
		++iall;
		mid = iall;
		cout << name << " is  #" << ianon << " born , iall is  " << iall << " , mid is " << mid << endl;
	}
	ptr( int id ) {
		++iall;
		isborn = false;
		CString s;
		s.Format( _T( "#%ld" ) , id );
		name += s;
		cout << name << " is born in id,iall is  " << iall << ",  mid is " << mid << endl;
	}
	ptr( CString s ) : name( s )
	{
		static int icreate = 0;
		++icreate;
		++iall;
		mid = iall;
		isborn = false;
		cout << name << " is create,iall is  " << iall << ",  mid is " << mid << endl;
	}
	bool set( int id , CString s = CString( "noname" ) )
	{
		mid = id;
		name = s;
		return true;
	}
	~ptr( )
	{
		static int ikill = 0;
		++ikill;
		--iall;
		cout << name << " is destory,iall is  " << iall << ",  mid is " << mid;
		cout << " boring is " << isborn << sp << " kill is " << ikill << newl;
	}
};

/*
*/

