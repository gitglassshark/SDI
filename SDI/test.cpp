#include "Pch.h"
#include "PCDC.h"
#include <chrono>
#include "test.h"


void test00( PCDC& cout )
{
	//test inital c11
	class A
	{
	public:
		A( int a ) :id( a ) {};
		A( ) = default;
		virtual int getid( ) 
		{
			return id;
		}
		void operator =( A ) {};
		~A( ) = default;

	public:
		int id;
	};
	class B :public A
	{
	public:
		B( ) :A( 1 ) {};
		~B( ) {};
		void operator =( A ) {};
		int getid() { return id * 2; }
	};

	A a {};
	B b;
	cout << a.getid( ) << tab << b.getid( ) << endl; 
	A* pa = &a;
	A* pb = &b;
	cout<<pa->getid( )<<tab<<pb->getid()<<nl;
	a = b;
	b = a;
	lscode( ;
	cout<<pa->getid( )<<tab<<pb->getid()<<nl;
	); lscode(
	);
	lscode( ;
	); lscode( ;
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
	getcout;
	static size_t imod = 0;
	++imod;
	if ( imod == 3 )
		imod = 1;

	cout << ( 0 == NULL ) << tab << ( 0 == nullptr ) << tab << ( NULL == nullptr ) << endl;
	sms( print a message , , , for test sms macro , ; .*<>[ ] { }\ , / ~!^ %$#@ - +*'"?:' / 0123456789... );
	//
	if ( imod == 1 )
	{
	}
	//
	if ( imod == 2 )
	{
	}
}


