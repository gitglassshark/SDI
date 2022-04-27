#include "Pch.h"
#include "PCDC.h"
#include "test.h"


class A
{
public:
	A( int a ) :id( a ) {};
	A( ) = default;
	virtual int getid( ) { return id; }
	int getid2( ) { return id; }
	void operator =( A ) {};
	~A( ) = default;
public:
	int id = 0;
	int a;
	int c;
};
class B :public A
{
public:
	B( ) :A( ) {};
	~B( ) {};
	void operator =( A ) {};
	void getid( int a ) {  }
	virtual int getid2( ) { return id * 2; }
	int getid3( ) { return id * 2; }
};

void test00( PCDC& cout )
{
	code( A a;	B b;);
	lscode(
		cout << address( a , b , a.id ) << endl;
	); lscode(
		cout.type( a , b );
	); lscode(
		cout << typeid( &A::getid ).name( ) << endl;
	cout << typeid( &B::getid2 ).name( ) << endl;
	); lscode(
		cout << typeid( &B::getid ).name( ) << endl;
	cout << typeid( &B::getid2 ).name( ) << endl;
	); lscode(
		cout << &A::getid << tab << &A::getid2 << tab << &A::operator= << tab << &B::getid << tab << &B::getid2 << tab << &B::getid3 << tab << test00 << tab << *( long long int** )( &b ) << endl;
	); lscode(
		cout.prints( "a address is :" , &a , tab( ) , " b address is " , address( b ) , tab( ) , " a sizeof is  " , sizeof( a ) , tab( ) , " b sizeof is " , sizeof( b ) , tab( ) , letters( '*' , 8 ) );
	);

	//); lscode( 
	//); lscode( 
	//);
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

}


