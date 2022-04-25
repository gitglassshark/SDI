#pragma once
#include "PCDC.h"
#include "pch.h"

void test00( PCDC& dc );
void test01( PCDC& dc );
void test02( PCDC& dc );
void test03( PCDC& dc );
void test04( PCDC& dc );
void test05( PCDC& dc );
void test_build_container( );
void test_build_vector( );
class ptr;

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

template<typename A , typename ...T>
auto makevector( A a , T...args )
{
	getcout;
	vector<A>c { a,args... };
	cout << c << el;
	return c;
}
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

template<typename T>
T xadd( T a , T b )
{
	return a + b;
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

template <typename T>
T( *pt )( T a , T b );

void runexcept( int ia = 1 , float fa = 2.1 , char* ps = nullptr )throw( int , float , double , char* , char , CString );


template<typename X>
X value( X a )
{
	return a;
}

template<typename ...X>
int  argsvalue( X...args )
{
	int i = 0;
	int ai[ ] = { ( value( args ),0 )... };
	return i;
}

class A {
public:
	template<typename T >
	auto operator<<( initializer_list<T> c )
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
};

class clist;

class clist {
public:
	clist* pnext = nullptr;
	int* pdata = nullptr;
public:
	clist( int d = 0 )
	{
		pdata = new int;
		*pdata = d;
	}
	~clist( )
	{
		delete pdata;
		pnext = nullptr;
	}
	clist* getnextp( )
	{
		return pnext->pnext;
	};
	clist* setnextporaddnew( clist* p = nullptr )
	{
		if ( p == nullptr ) {
			pnext = new clist( 0 );
		}
		else
		{
			pnext = p;
		}
		return pnext->pnext;
	}
	int setdata( int d )
	{
		return *pdata = d;
	}
};// CSDIView 消息处理程序

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

template<typename T , typename E , typename int ic = 1000 * 1000>
auto cinsert( T t , E e )
{
	NTIME( ic )
		t.insert( t.end( ) , e );
	return e;
}

template<template <class> class C , typename t >
auto con( C<t> v )
{
	t a = *v.begin( );
	return *v.begin( );
}

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

template<class T>
struct typestruct {
	typedef map<int , T> mytype;
};

int f( int a , int b );


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
		cout << " boring is " << isborn << sp << " kill is " << ikill << el;
	}
};

