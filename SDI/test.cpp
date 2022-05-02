#include "Pch.h"
#include "PCDC.h"
#include "test.h"
#include <functional>
#include <algorithm>

template<typename ...Args>
void ps( Args...args )
{
	getcout;
	for ( auto &i : { args... } )
		cout << i << sp;
	cout << newl;
}

void test00( PCDC& cout )
{
	ps<int>( 2 , 4 , 8, 9 );



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


void test_funtor( PCDC& cout )
{
	/*sms( start program )
	{
		lcode(
			vector<int>vecta { 0,1,2,3,4,5,6,7,8,9,10 };
		); lcode(
			auto n = std::count_if( vecta.begin( ) , vecta.end( ) , [ = ] ( int a ) {if ( a > 8 )return true; else return false; } );
		); lcode(
			cout << n << newl;
		); lcode(
			cout << std::count_if( vecta.begin( ) , vecta.end( ) , bigto<int>( 6 ) ) << newl;
		); lcode(
			cout << std::count_if( vecta.begin( ) , vecta.end( ) , bigto<int>( 6 , false ) ) << newl;
		); lcode(
			cout << std::count_if( vecta.begin( ) , vecta.end( ) , bigto<int>( ) < ( 8 ) ) << newl;
		); lcode(
			cout << std::count_if( vecta.begin( ) , vecta.end( ) , bigto<int>( ) > ( 7 ) ) << newl;
		); lcode(
			cout << std::count_if( vecta.begin( ) , vecta.end( ) , bigto<int>(false) > ( 7 ) ) << newl;
		);
	}
	sms( end program )*/

}

void test_vector01( PCDC& cout )
{

	//class AV
	//{
	//public:
	//	inline static int id = 1;
	//	int xid;
	//	string name;
	//public:
	//	AV( ) :xid( 0 ) , name( "nonaymous" ) {
	//		getcout;
	//		cout << "born" << sp;
	//	};
	//	AV( int eid , string ename ) :xid( eid ) , name( ename ) {};
	//	AV( const  AV& r ) = default;
	//	AV( AV&& r )
	//	{
	//		xid = r.xid;
	//		name = std::move( r.name );
	//	}
	//	~AV( )
	//	{
	//		getcout;
	//		cout << "die" << sp;
	//	}
	//	int run( ) { return 0; }
	//};
	//class BV
	//{
	//public:
	//	virtual int run( ) { return 0; }
	//};
	//CString str( "ok" );

	//sms( （重载右移变为属性操作符）start program )
	//{
	//	lcode(
	//		array<int , 10>arrone = { 88,77,66,44,33,22,11,01,99,43 };
	//	cout << arrone << tab >> arrone << newl;
	//	); lcode(
	//		initializer_list<int> v = { 3,4,5,6 ,0,9,8,7,2,1 };
	//	cout << v << tab >> v << newl;
	//	); lcode(
	//		vector<int>vecta { 908, 4,33,89,992,8192,8282,1 };
	//	cout << vecta << tab >> vecta << newl;
	//	); lcode(
	//		list<int>lista { 123,456,000,444,213, 24, 25, 86,1 };
	//	cout << lista << tab >> lista << newl;
	//	); lcode(
	//		deque<int>dqa { 13, 24,12,23,82,918,883,898,1 };
	//	cout << dqa << tab >> dqa << newl;
	//	); lcode(
	//		map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{238,8.9399} };
	//	cout << mif << tab >> mif << newl;
	//	); lcode(
	//		multimap<int , float>mmif = { {234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	//	cout << mmif << tab >> mmif << newl;
	//	); lcode(
	//		auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	//	cout << tuplea << tab >> tuplea << newl;
	//	); lcode(
	//		set<int>seta { 3 ,  6 , 2,980,222,888,1024,338,8999,0 };
	//	cout << seta << tab >> seta << newl;
	//	); lcode(
	//		multiset<int>mseta { 13 ,84 ,15 , 336 ,19880,2282,3838,88999,0 };
	//	cout << mseta << tab >> mseta << newl;
	//	);
	//}
	//sms( end program )


	//sms( program start )
	//{
	//	sms( 头部插入 )
	//		lcode(
	//			vector<int>va { 1,2,3 };
	//	va.insert( va.begin( ) , { 3,2,1 } );
	//	cout << va << newl;
	//	); lcode(
	//		cout << std::size( va ) << sp << std::data( va ) << sp << *std::data( va ) << newl;
	//	);
	//	sms( 尾部插入 )
	//		lcode(
	//			vector<int>vb { 4,5,6 };
	//	vb.insert( vb.end( ) , { 3,3,3 } );
	//	cout << vb << newl;
	//	); lcode(
	//		*vb.data( ) = 20;
	//	cout << vb << newl;
	//	); lcode(
	//		cout << std::size( vb ) << sp << std::data( vb ) << sp << *std::data( vb ) << newl;
	//	);
	//	sms( 赋值 )
	//		lcode(
	//			va = vb;
	//	cout << va << newl << vb << newl;
	//	);
	//	sms( 删除 )
	//		lcode(
	//			int ar[20] { 9 };
	//	cout << std::size( ar ) << sp << std::begin( ar ) << sp << *std::begin( ar ) << newl;
	//	); lcode(
	//		cout >> va << sp >> vb << newl;
	//	); lcode(
	//		set sa { 3,2,4,5 };
	//	cout << sa << sp >> sa << newl;
	//	);
	//}
	//sms( program end )
	//comment( program start... );
	//lscode(
	//); lscode(
	//	AV a;
	//); lscode(
	//	vector vav = { a };
	//); lscode(
	//	cout << starline;
	//); lscode(
	//	vav.resize( 5 );
	//cout << starline;
	//vav.clear( );
	//); lscode(
	//	cout << starline;
	//); lscode(
	//	vav.resize( 3 );
	////vav.resize( 1 );
	//); lscode(
	//	cout << starline;//end
	//); lscode(
	//	comment( program end... );
	//);
	//AV a;
	//vector vav { a };
	//vav.resize( 8 );

	//CString str( "ok" );
	//rcode(
	//	vector<int>va { 200,320,999,892,638 };
	//); rcode(
	//	vector vb { str };
	//); rcode(
	//	vector vc { ( 1.2 ) , ( 2.4 ) ,( 3.4 ) };
	//); rcode(
	//	vector vsb( 8 , str );
	//cout << vsb << newl;
	//); rcode(
	//	list la { 1.2 , 2.3 , 3.3 };
	//);
	//rcode( BEGINTEST( 1 ) {
	//	NTIME( 20 )
	//	{
	//		va.push_back( ix * rand( ) % 20 );
	//	}
	//	cout.lmod( 30 ) << va << newl;
	//	lscode(
	//		NTIME( 10 ) {
	//		str.Format( _T( "number%ld" ) , ix * rand( ) % 20 );
	//		vb.push_back( str );
	//	}
	//	); lscode(
	//		cout << vb << newl;
	//	); lscode(
	//		cout << vc << com << la << newl;
	//	); lscode(
	//		vector<int> vd( 3 );
	//	cout << vd << com << vd.size( ) << newl;
	//	); lscode(
	//		auto n = std::count_if( va.begin( ) , va.end( ) , [ = ] ( int a ) { if ( a >= 100 )return true; else return false; } );
	//	cout << n << newl;
	//	); lscode(
	//		auto m = std::count_if( va.begin( ) , va.end( ) , [ = ] ( int a ) { if ( a <= 150 )return true; else return false; } );
	//	cout << m << newl;
	//	);
	//}ENDTEST );


}


void test_is_v( PCDC& cout )
{

	//lcode(
	//	unsigned long long int x = 11;
	//const int cx = 11;
	//int&& rx = 11;
	//int& lx = rx;
	//unsigned long long int sx = 1;
	//size_t y = 1;
	//int* p;
	//);lcode(
	//	AV a;
	//BV b;
	//AV * pva = &a;
	//AV * pvb = (AV*)&b;
	//);

	//lcode(
	//	cout << ( std::is_class_v<decltype( a )> ) << endl;
	//); lcode( cout << std::is_class_v<decltype( x )> << endl;
	//); lcode( cout << std::is_const_v<decltype( cx )> << endl;
	//); lcode( cout << std::is_const_v<decltype( x )> << endl;
	//); lcode( cout << std::is_lvalue_reference<decltype( lx )>::value << endl;
	//); lcode( cout << std::is_lvalue_reference_v<decltype( rx )> << endl;
	//); lcode( cout <<typeid( std::is_member_function_pointer<decltype(pvb)>::value_type ).name() << endl;
	//); lcode( cout <<typeid(AV::id).name() << endl;
	//); lcode( cout <<typeid(&AV::run).name() << endl;
	//); lcode( abstype( &AV::run ); 
	//); lcode( abstype( AV::id ); 
	//)


}

void test_task_time( PCDC& cout )
{
	// /*lscode(
	//CString cs;
	//cs = "1234567890";
	//); lscode(
	//CSize size = cout.GetOutputTextExtent( cs );;
	//); lscode(
	//	cout << size.cx << sp << size.cy << endl;
	//); lscode(
	//	size = cout.GetOutputTextExtent( cs );;
	//); lscode(
	//	cout << size.cx << sp << size.cy << endl;
	//);
	//code(
	//	CRect mrect;
	//)
	//lscode(
	//	cout.m_pwnd->GetClientRect( &mrect );
	//); lscode(
	//	cout << mrect.top << sp << mrect.left << sp << mrect.bottom << sp << mrect.right << endl;
	//); */
		//int i = 1;
		//auto start = clock( );
		//NTIME( 1000  ) {
		//	//cout << 1;
		//	cout << i;
		//	//size = cout.GetOutputTextExtent( cs );
		//	//cout.m_pwnd->GetClientRect( &mrect );
		//	//cout.FillSolidRect( mrect , cout.m_bk );
		//	//cout.flushscreen( );
		//}
		//auto end = clock( );
		//cout << cut;
		//cout << float( ( (float)end - (float)start ) * 1000 / CLOCKS_PER_SEC ) << "ms" << endl;
		//auto start = clock( );
		//vector<int>va { 2,3,4,5,6,7,9,0,8,1 };
		//NTIME( 100 )
		//{
		//	cout << va;
		//	for ( auto& i : va )
		//	{
		//		cout << i << tab;
		//		cout << cut;
		//	}
		//	auto end = clock( );
		//	cout << float( ( (float)end - (float)start ) * 1000 / CLOCKS_PER_SEC ) << "ms" << endl;
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
	//template<template<typename A , typename ...Z> class  C , typename T , typename ...X>
	//auto build( T a , X... args )
	//{
	//	C<T>il { a,args... };
	//	getcout;
	//	cout << "in build " << il << sp << "sizeof args is " << sizeof...( args ) + 1 << endl;
	//	return il;
	//}
	// 	auto il=build< initializer_list>( 1 , 2 , 3 , 5 , 5 );
	//auto ii = build< initializer_list>( 2 , 2 , 3 , 5 , 5 );

	//cout << il << sp << ii << endl;

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
		cout << ix << sp; cout << newl;
	); lscode( ;
	UNTIL( incount )
		cout << ix << sp; cout << newl;
	STEPTO( 2 , 2 , 20 )
		cout << ix << sp; cout << newl;
	); lscode( ;
	STEP( 2 , 2 , 20 )
		cout << ix << sp; cout << newl;
	FORTO( 2 , 8 )
		cout << ix << sp; cout << newl;
	FORDOWNTO( 10 + 2 , 2 )
		cout << ix << sp; cout << newl;
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
	cout << newl;
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


	////code(
	//	const char* str = "中文字符串测试";
	//const char* str2 = "string";
	//auto str3 = _T( "string" );
	//auto str4 = L"string";
	//CString cs;
	//cs = str;
	//cs += _T( "CString" );
	////); lscode(
	////	cout << cs.GetLength( ) << endl;
	////);
	//////code( BEGINTEST( 200 ) {
	////	cout << str << sp;
	////}ENDTEST );

	////lscode(
	////	cout << "中文" << endl;
	////cout << _T( "中文" ) << endl;
	////cout << st( 中文 ) << endl;
	////cout << cs << endl;
	////cout << str << sp << cout.type( str ) << endl;
	////cout << str2 << sp << cout.type( str2 ) << endl;
	////cout << str3 << sp << cout.type( str3 ) << endl;
	////cout << str4 << sp << cout.type( str4 ) << endl;
	////)

}

//inline const CSize& imresizeout( const CString& cs )
//{
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
//	if ( strlen > ( linelen - size.cx ) ) {
//		for ( int i = cslen; i >= 0; i -= tkpos )
//		{
//			heads = news.Mid( 0 , tkpos );
//			tails = news.Mid( tkpos , news.GetLength( ) );
//			imresizeout( heads );
//			news = tails;
//		}
//	}
//	else {
//		if ( p.x + msize.cx >= mrect.right - mrect.left - initalpos )
//		{
//			p.x = mrect.left + initalpos;
//			p.y += step;
//		}
//		if ( p.y >= mrect.bottom - mrect.top - initalpos )
//		{
//			this->FillSolidRect( mrect , m_bk );
//			this->flushscreen( );
//			p.y = mrect.top + initalpos + wbar;
//		}
//		//need recalc ned***
//		TextOut( p.x , p.y , cs );
//		p.x += msize.cx;
//	}
//	return msize;
//}

//template<template<typename B , typename ...D>typename A , typename T , typename ...X>
//auto builda( T a , X... Args )
//{
//	A<T> inita { a , Args... };
//	
//	getcout;
//	cout << "in build " << inita << sp << "sizeof args is " << sizeof...( Args ) + 1 << endl;
//	return inita;
//}
//
//template<template<typename A , typename ...Z> class  C , typename T , typename ...X>
//auto build( T a , X... args )
//{
//	C<T>il { a,args... };
//	getcout;
//	cout << "in build " << il << sp << "sizeof args is " << sizeof...( args ) + 1 << endl;
//	return il;
//}
//
//struct AF
//
//{
//	int af = 7;
//};
//
//class A :public AF {
//public:
//	int getid( ) { return af; }
//};


