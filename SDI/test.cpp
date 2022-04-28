#include "Pch.h"
#include "PCDC.h"
#include "test.h"


template<template<typename A,typename ...Z> class  C,typename T , typename ...X>
auto build( T a , X... args )
{
	C<T>il { a,args... };
	getcout;
	cout <<"in build "<< il<<sp<<"sizeof args is "<<sizeof...(args)+1 << endl;
	return il;
}

class A {
public:
	void getid( ) {}
};

void test00( PCDC& cout )
{
	code(
		auto il = build<list>( 1 , 2 , 3 , 4 , 5 , 6 , 7 );
	); code(
		auto iv = build<vector>( 2 , 2 , 3 , 4 , 5 , 6 , 7 );
	); code(
		cout << iv << endl;
	); lcode(
		cout << il << endl;
	);
}

void test06( PCDC& cout )
{
	map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{233,839.81392},{238,8.9399} };
	multimap<int , float>mmif = { {2,4.3},{234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	pair<int , string>paone { 100,"pair" };
	auto& [i , x] = paone;

	lscode(
		cout << i << com << x << endl;
	); lscode(
		for ( const auto& [first , second] : mif )
			cout << first << com << second << semi << sp;
	cout << endl;
	); lscode(
		for ( const auto& [first , second] : mmif )
			cout << first << com << second << semi << sp;
	cout << endl;
	);

}

void test01( PCDC& cout )
{


}

void test02( PCDC& cout )
{

}

void test03( PCDC& cout )
{

}

void test04( PCDC& cout )
{

}

void test05( PCDC& cout )
{

}

void macrotest( )
{
	//lcode(
	//	example( 1 , 2 , 3 , 5 , 0 );
	//);
	//code(
	//	int i;
	//const int ci = 6;
	//const int& ri = ci;
	//const int& const cri = ci;
	//int&& rri = 8;
	//); lcode(
	//	abstype( i );
	//); lcode(
	//	abstype( ci );
	//); lcode(
	//	abstype( ri );
	//); lcode(
	//	abstype( cri );
	//); lcode(
	//	abstype( rri );
	//); code(
	//	void ( A:: * p )( ) = &A::getid;
	//int* pp = &i;
	//const int* cp = &i;
	//const int* const pc = &i;
	//); lcode(
	//	if ( std::is_pointer<decltype( cp )>::value )
	//		cout << "is pointer" << endl;
	//); lcode(
	//	if ( std::is_member_pointer<decltype( p )>::value )
	//		cout << "is member_pointer" << endl;
	//cout << p << sp;
	//abstype( p );
	//); lcode(
	//	abstype( pp );
	//); lcode(
	//	abstype( cp );
	//); lcode(
	//	abstype( pc );
	//);
	////成功，在堆上构造，成功避免了错误
//template<typename A , typename ...T >
//auto* build( A a , T...args )
//{
//	auto* p = new initializer_list<A> { a , args... };
//	return p;
//}
	//template<template<typename , typename ...>typename A , typename T , typename ...X>
	//auto build( T a , X...Args )
	//{
	//	A<T> inita { a,Args... };
	//	return inita;
	//}
	////template<typename T , typename ...Args>
	//auto buildtuple( T a , Args...args )
	//{
	//	constexpr size_t N = sizeof...( Args );
	//	//return tuple<T , Args...>( a,args... );
	//	//return tuple<T , Args...>{ a , args... };
	//	tuple<T , Args...>tuplea { a,args... };
	//	return tuplea;
	//}
	//getcout;
	//static size_t imod = 0;
	//++imod;
	//if ( imod == 3 )
	//	imod = 1;

	//cout << ( 0 == NULL ) << tab << ( 0 == nullptr ) << tab << ( NULL == nullptr ) << endl;
	////sms( print a message , , , for test sms macro , ; .*<>[ ] { }\ , / ~!^ %$#@ - +*'"?:' / 0123456789... );
	////
	//if ( imod == 1 )
	//{
	//}
	////
	//if ( imod == 2 )
	//{
	//}
	//////test inital c11


	/*lscode( ;
	size_t incount = 10;
	NTIME( incount )
		cout << ix << sp; cout << el;
	); lscode( ;
	UNTIL( incount )
		cout << ix << sp; cout << el;
	STEPTO( 2 , 2 , 20 )
		cout << ix << sp; cout << el;
	); lscode( ;
	STEP( 2 , 2 , 20 )
		cout << ix << sp; cout << el;
	FORTO( 2 , 8 )
		cout << ix << sp; cout << el;
	FORDOWNTO( 10 + 2 , 2 )
		cout << ix << sp; cout << el;
	); lscode( ;
	int pointer pa = new int( 10 );
	int ref ra = *pa;
	cout << pa << tab << *pa << tab << ra << tab << &ra << nl;
	); lscode( ;
	unsigned long long int array1[10] { 5 };
	unsigned char init = 4;
	memset( array1 , init , sizeof( array1 ) );
	for ( const auto& i : array1 )
		cout << hex( i ) << sp;
	cout << el;
	); lscode( ;
	int* p1 = new int( 2 ) , *p2 = new int( 3 );
	char* p3 = new char( 90 );
	char* p4 = new char( 80 );
	cout.pt( p1 , p2 );
	cout.value( p1 , p2 , p3 , p4 ) << tab;
	); lscode( ;
	cout << delptr( p1 , p2 , p3 , p4 ) << tab;
	); lscode( ;
	cout.pt( p1 , p2 , p3 , p4 );
	); lscode( ;
	);*/


	//class A
	//{
	//public:
	//	A( int a ) :id( a ) {};
	//	A( ) = default;
	//	virtual int getid( ) { return id; }
	//	int getid2( ) { return id; }
	//	void operator =( A ) {};
	//	~A( ) = default;
	//public:
	//	int id = 0;
	//	int a;
	//	int c;
	//};
	//class B :public A
	//{
	//public:
	//	B( ) :A( ) {};
	//	~B( ) {};
	//	void operator =( A ) {};
	//	void getid( int a ) {  }
	//	virtual int getid2( ) { return id * 2; }
	//	int getid3( ) { return id * 2; }
	//};

	//		code( A a;	B b;);
	//	lscode(
	//		cout << address( a , b , a.id ) << endl;
	//	); lscode(
	//		cout.type( a , b );
	//	); lscode(
	//		cout << typeid( &A::getid ).name( ) << endl;
	//	cout << typeid( &B::getid2 ).name( ) << endl;
	//	); lscode(
	//		cout << typeid( &B::getid ).name( ) << endl;
	//	cout << typeid( &B::getid2 ).name( ) << endl;
	//	); lscode(
	//		cout << &A::getid << tab << &A::getid2 << tab << &A::operator= << tab << &B::getid << tab << &B::getid2 << tab << &B::getid3 << tab << test00 << tab << *( long long int** )( &b ) << endl;
	//	); lscode(
	//		cout.prints( "a address is :" , &a , tab( ) , " b address is " , address( b ) , tab( ) , " a sizeof is  " , sizeof( a ) , tab( ) , " b sizeof is " , sizeof( b ) , tab( ) , letters( '*' , 8 ) );
	//	);
//int* retvalue1( int& a ) { int x; x = a + 1; return &x; }
//int* retvalue2( int& a ) { int x; x = a + 2; return &x; }
//template<typename ...A>
//int tpexample( A... a );
//
////template<typename A>
////int tpexample( A a )
////{
////	getcout;
////	cout << "1<A>" << sp;
////	return 2;
////};
//
//template<typename T , typename ...Args>
//int tpexample( T a , Args...args )
//{
//	getcout;
//	static int i = 1;
//	//tpexample( a );
//	if constexpr ( ( sizeof...( args ) ) == 0 )
//	{
//
//		cout << "2<T,A...>:" << 1 << sp;
//	}
//	else
//	{
//		i += tpexample( args... );
//		cout << "2<T,A...>:" << i << sp;
//	}
//	return i;
//}
//
//template<>
//int  tpexample( )
//{
//	getcout;
//	cout << "0<>" << sp;
//	return 0;
//}
//

	//	//); lscode( 
	//	//); lscode( 
	//	//);
}

