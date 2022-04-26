#include "Pch.h"
#include "PCDC.h"
#include "test.h"



void test00( PCDC& cout )
{

	lscode( ;
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
	cout.pt( p1 , p2 , p3 , p4 );
	cout.value( p1 , p2 , p3 , p4 ) << endl;
	); lscode( ;
	cout << delptr( p1 , p2 , p3 , p4 ) << el;
	); lscode( ;
	cout.pt( p1 , p2 , p3 , p4 );
	cout << ( unsigned long long int )p1 << tab;
	cout << ( unsigned long long int )p2 << tab;
	cout << ( unsigned long long int )p3 << tab;
	cout << ( unsigned long long int )p4 << el;
	);
	cout << nullptr <<com<<sizeof(nullptr)<<tab << NULL << tab << 0 << sp << NULL( 0 ) << sp << std::nullptr_t( 0 ) << sp << (void*)0 << el;


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
	//class A
	//{
	//public:
	//	A( int a ) :id( a ) {};
	//	A( ) = default;
	//	virtual int getid( )
	//	{
	//		return id;
	//	}
	//	void operator =( A ) {};
	//	~A( ) = default;
	//public:
	//	int id;
	//};
	//class B :public A
	//{
	//public:
	//	B( ) :A( 1 ) {};
	//	~B( ) {};
	//	void operator =( A ) {};
	//	int getid( ) { return id * 2; }
	//};

}


