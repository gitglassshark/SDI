#include "Pch.h"
#include "PCDC.h"
#include "test.h"

int ptr::iall = 0;
int igi = 88;

void test_build_vector( )
{
	getcout;
	cout << build_vector( 2 , 3 , 4 , 8 , -1 , 0 );
}
void test_build_container( )
{
	getcout;
	int a = 10;
	cout << build_container<vector>( a , 3 , 4 , 8 , -1 , 0 ) << el << cut;
	cout << build_container<deque>( a , 3 , 3 , 4 , 4 , 8 , -1 , 0 ) << el << cut;
	cout << build_container<set>( a , 3 , 3 , 4 , 4 , 8 , -1 , 0 ) << el << cut;
	cout << build_container<list>( a , 3 , 3 , 4 , 4 , 8 , -1 , 0 ) << el << cut;
}

class AB
{
public:
	AB( ) = default;
	AB( int eid )
	{
		this->id = eid;
	}
	~AB( )
	{
	}
public:
	int id;
#define inamemax  10
	char icname[inamemax] { 0 };
public:
	auto setid( int eid )
	{
		return id = eid;
	};
	auto getid( )
	{
		return id;
	};
	auto returnthis( ) {
		return this;
	}
};

void test00( PCDC& cout )
{
	int x , y , z , w;

	lscode(
	); lscode(
		AB ab { 2 };
	AB * pab = nullptr;
	AB * paa = &ab;
	); lscode(
		cout << ab.getid( ) << sizeof( ab ) << tab;
	cout.address( ab , ab.id );
	); lscode(
		cout << address( ab , ab.id ) << tab << ab.returnthis( ) << tab;
	); lscode(
		ab.setid( 100 );
	cout << sizeof( char* ) << tab << sizeof( cout ) << tab << sizeof( PCDC ) << tab << sizeof( PCDC* ) << tab << sizeof( int* ) << endl;;
	cout << ab.getid( ) << tab << cout.type( ab ) << endl;
	); lscode(
		int array[3] { 2 , 3 , 4 };
	cout.pt( array , &array[0] , &array[1] , &array[2] ) << endl;
	); lscode(
		cout << sizeof( pab ) << tab << sizeof( paa ) << tab << sizeof( *pab ) << tab << sizeof( *paa ) << endl;
	int arrb[256] { 2 };
	int* iip = arrb;
	NTIME( inamemax )
		cout << *iip << sp << iip++;
	iip = arrb; NTIME( inamemax ) * ( iip++ ) = ix;
	cout << endl;
	iip = arrb; NTIME( inamemax ) cout << *( iip++ ) << sp;
	cout << cut;
	char data[ ] { 1,2,3,4,5,6,7,8,9,10 };
	int* pdata = (int*)data;
	); lscode(
		cout.address( x , y , z , w );
	cout << hex( *pdata++ , *pdata , data[1] , data[2] ) << endl;
	cout << HEX( *pdata++ , *pdata , data[1] , data[2] ) << endl;
	cout << oct( *pdata++ , *pdata , data[1] , data[2] ) << endl;
	);

}


void test01( PCDC& cout )
{
	//sms( print a message,,, for test sms macro ,;.*<>[]{}\ ,/~!^%$#@-+*'"?:' / 0123456789... );

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

int adfunc( const int a )
{
	return 1;
}

int  afunc( unsigned  long long int& a )
{
	return 3;
}
int  afunc( int a )
{
	return 2;
}
int  afunc( int& a )
{
	return 4;
}

void fun( int& a )
{
	getcout;
	cout << "int a" << tab << a;
}

void fun( const int& a )
{
	getcout;
	cout << "const int a" << tab << a;
}

void fun( int&& a )
{
	getcout;
	cout << "int &&a " << tab << a;
}

void fun( const int&& a )
{
	getcout;
	cout << "const int &&a " << tab << a;
}

void fun( int* a )
{
	getcout;
	cout << "int* a " << tab << a;
}

int ntest( PCDC& dc , string p )
{
	dc << p << el;
	return 0;
}
int f( int a , int b )
{
	return a + b;
}

void runexcept( int ia , float fa , char* ps )throw( int , float , double , char* , char , CString )
{
	if ( ia == 1 ) { int e = ia; throw e; }
	if ( ia == 2 ) { float e = fa; throw e; }
	if ( ia == 3 ) { double e = 8.888; throw e; }
	//if (ia == 4) { char* e = "is error"; throw e; }
	if ( ia == 5 ) { char e = 'a'; throw e; }
	if ( ia == 6 ) { CString e; e = _T( "somthing is error " ); e += __func__; throw e; }
};
