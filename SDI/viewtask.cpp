#include "pch.h"
#include "test.h"
#include "muse.h"



void OnPCDCFunctionTest1( PCDC& cout )
{
	////打印整型数据
	cout.flushscreen( );
	cout << "打印整型数据" << newl;
	code(
		int ia = 10;
	size_t icount = 100;
	int& ria = ia;
	const int cia = ia;
	int&& rra = 19;
	long la = 50;
	const long cla = 50;
	long long lla = 256;
	); lcode(
		cout << icount << com << ia << sp << 999 << sp << -1 << sp << 0 << sp << cia << sp << ria << sp << rra << sp << INT_MIN << com << INT_MAX << semi << cla << sp << la << sp << LONG_MAX << com << LONG_MIN << semi << lla << sp << LONGLONG_MAX << com << LONGLONG_MIN << separtor;
	);

	//打印布尔数据
	cout << "打印布尔型数据" << newl;
	code(
		bool it = true;
	bool in = false;
	bool& rin = in;
	const bool inn = false;
	const bool& rinn = it;
	); lcode(
		cout << it << tab << in << tab << inn << tab << rin << tab << rinn << tab << true << tab << false << tab << ( 2 > 1 ) << tab << ( 3 > 5 ) << sp;
	cout << bools( true , false , 2 < 3 , 3 > 5 , 0 , 100 ) << nl;
	);

	// "打印字符型数据：" 
	cout << "打印字符型数据" << newl;
	code(
		char c0 = '!';
	char ca = 'A';
	const char cca = 'A';
	char cz = 'z';
	char ce = '~';
	); lscode(
		for ( char i = c0; i <= ce; ++i )
		{
			cout << i << tab;
			if ( ( i + 1 - c0 ) % 15 == 0 )
				cout << newl;
		}
	cout << ca << tab << cca << sp << 'a' << sp << 'z' << endl;
	);

	// "打印浮点型数据：" 
	cout << "打印浮点型数据" << newl;
	code(
		float fa = 34795431.1;
	double da = 9587215662.444;
	long double lda = 82827451262.844;
	const long double clda = 9990324262.8;
	); lscode(
		cout << fa << sp << da << sp << lda << sp << clda << sp << 0.999 << sp << -100.01 << sp << 2 / 3.0 << sp << 100.88 << sp << -35.22 << endl;
	);
};
void OnPCDCFunctionTest3( PCDC& cout )
{
	cout << clear;
	cout << L"中文常量字符串打印指针型字符串功能测试:" << endl;
	lcode(
		CString cs = L"壹贰叁肆伍陆柒捌玖拾";
	BEGINTEST( 280 ) {
		cout << cs;
	}ENDTEST );

};
void OnPCDCFunctionTest9( PCDC& cout )
{
	cout.flushscreen( );
	//字符串打印测试
	cout << st( 字符串打印测试 ) << newl;
	CAtlString catlstr = st( a CAtlString... );
	code(
		CString cstr = st( a CString... );
	std::string cs = "a string...";
	std::wstring wcs = L"a wstring...";
	const char* chp = "a const char []";
	const char chpa[ ] = "a const char []";
	char cpa[ ] = "a char []";
	); lscode(
		cout << chpa << endl;
	); lscode(
		cout << cpa << endl;
	); lscode(
		cout << chp << endl;
	); lscode(
		cout << catlstr << endl;
	); lscode(
		cout << cstr << endl;
	); lscode(
		cout << "const string" << endl;
	); lscode(
		cout << cs << endl;
	); lscode(
		cout << wcs << endl;
	);
};
void OnPCDCFunctionTest4( PCDC& cout )
{
	//容器打印测试
	cout << clear << st( 容器打印测试 ) << endl;
	code(
		array<int , 10>arrone = { 88,77,66,44,33,22,11,01,99,43 };
	initializer_list<int> v = { 3,4,5,6 ,0,9,8,7,2,1 };
	vector<int>vecta { 3, 4, 5, 6,33,89,992,8192,8282,1 };
	deque<int>dqa { 13, 24, 25, 86,12,23,82,918,883,898,1 };
	list<int>lista { 123,456,789,000,444,213, 24, 25, 86,1 };
	vector<int>va = { 12,234,56,78,892,8,235,86 ,18,998,888,999,928 };
	map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{233,839.81392},{238,8.9399} };
	multimap<int , float>mmif = { {2,4.3},{234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	pair<int , string>paone { 100,"pair" };
	complex <int>complexa( 2 , 5 );
	set<int>seta { 3 , 4 , 5 , 6 , 2,980,222,888,1024,338,8999,0 };
	multiset<int>mseta { 13 ,84 ,15 , 336 , 22,19880,2282,888,10824,3838,88999,0 };
	); lscode(
		cout << "对组（pair)" << tab( 2 ) << paone << tab( 4 );
	); lscode(
		cout << "复数（complex)" << tab( 2 ) << complexa << newl;
	); lscode(
		cout << "数组(array)" << tab( 3 ) << arrone << newl;
	cout << "vector:" << tab( 4 ) << vecta << newl;
	); lscode(
		cout << "列表(list)：" << tab( 6 ) << lista << newl;
	cout << "双端列表(deque)：" << tab( 5 ) << dqa << newl;
	); lscode(
		cout << "初始化列表(initializer_list)" << tab << v << newl;
	); lscode(
		cout << "图(map)" << tab( 4 ) << mif << newl;
	cout << "图(multimap)" << tab( 2 ) << mmif << newl;
	); lscode(
		cout << "tuple:" << tab( 4 ) << tuplea << tab << tab;
	); lscode(
		cout << "集合 (set)" << tab( 4 ) << seta << newl;
	cout << "集合 (multiset)" << tab( 2 ) << mseta << newl;
	);
};
void OnPCDCFunctionTest5( PCDC& cout )
{
	cout.flushscreen( );
	//变参、多参数打印功能测试
	cout << "变参、多参数功能测试" << endl;
	int ia = 10;
	size_t icount = 100;
	int& ria = ia;
	const int ca = ia;
	int&& rra = 19;
	long la = 50;
	const long cla = 50;
	long long lla = 256;
	double da = 22.2;
	float fa = 1222.32;
	CString cstr = st( a CString... );
	vector<int>va = { 12,234,56,78,892,8,235,86 ,18,998,888,999,928 };
	map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{233,839.81392},{238,8.9399} };
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	struct A {};
	A emptyA;
	int length = tuple_size<decltype( tuplea )>::value;

	lscode(
		cout << std::is_integral<decltype( length )>::value << sp;
	cout << is_empty<tuple<>>::value << tab;
	cout << " " << tuple_size<decltype( tuplea )>::value << newl;
	); lscode(
		cout.type( ia );
	cout.type( ria , rra , cout , ca , ia , tuplea , rra );
	cout.type( ( std::move( ia ) ) , ( std::move( ria ) ) , ( std::move( rra ) ) );
	); lscode(
		cout.pb( 3 , 6.0 , "good" , icount , ca , ia , fa , la , lla , da , cstr );
	cout.pc( 3 , 6.0 , "good" , icount , ca , ia , fa , la , lla , da , cstr );
	cout.pt( 3 , 6.0 , "good" , icount , ca , ia , fa , la , lla , da );
	); lscode(
		cout.address( icount , ca , ia , la , lla , da );
	); lscode(
		cout.pt( va , mif ) << sp;
	cout.pb( va , mif ) << sp;
	cout.pc( va , mif );
	); lscode(
		cout << gsum( 3 , 4 , 5 , 6 , 345.896 ) << tab;
	cout << sum( { 3, 4, 5, 6,345 } ) << tab;
	); lscode(
		cout << gmax( 3 , 4 , 5 , 6 , 8.88 , 8908.99 , 345 ) << tab;
	);
};
void OnPCDCFunctionTest6( PCDC& cout )
{
	//成员函数地址打印功能测试
	cout << clear << "类类型、成员函数指针地址打印功能测试" << endl;

	code(
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
	A a;
	B b;
	);
	lscode(
		cout << address( a , b , a.id ) << tab;
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

	// "打印指针型数据：" 
	cout << nl << "打印指针型数据" << endl;
	code(
		int ia = 10;
	char   ca = 'c';
	long la = 50;
	long long lla = 256;
	double da = 22.2;
	int* ip = &ia;
	char* cp = &ca;
	const char* ccp = &ca;
	long* lp = &la;
	long long* llp = &lla;
	double* dp = &da;
	); lscode(
		cout << ip << sp << *ip << semi;
	cout << *cp << sp << *ccp << semi;
	cout << lp << sp << *lp << semi;
	cout << llp << sp << *llp << semi;
	cout << dp << sp << *dp << tab;
	); lcode(
		cout << nullptr << com << sizeof( nullptr ) << tab << NULL << tab << 0 << sp << NULL( 0 ) << sp << std::nullptr_t( 0 ) << sp << (void*)0 << newl;
	);
};
void OnPCDCFunctionTest7( PCDC& cout )
{
	cout.flushscreen( );

	//文件打印测试
	cout << "文件打印功能测试" << endl;
	lscode(
		CString dfile;
	dfile = _T( "D:\\demo.txt" );
	cout.displayfile( dfile ) << newl;
	);
	lscode(
		CFile ofile( _T( "D:/VS2022/MFC/SDI/SDI/test.txt" ) , CFile::modeCreate | CFile::modeReadWrite );
	string str = "If you wish to succeed, you should use persistence as your good friend, experience as your reference, prudence as your brother and hope as your sentry.\n";
	NTIME( 100 )
		ofile.Write( str.c_str( ) , str.length( ) );
	);

	//文件测试
	lscode(
		char strr[256] {};
	size_t len = ofile.Read( strr , 256 );
	cout << ofile.m_hFile << tab << ofile.GetFileName( ) << tab << ofile.GetFilePath( ) << tab
		<< ofile.GetFileTitle( ) << tab << ofile.GetLength( ) << tab << ofile.GetPosition( )
		<< newl;
	string strt( strr );
	cout << strt << newl;
	cout << showv( ofile.GetFileName( ) ) << semi;
	cout << showv( ofile.GetFilePath( ) ) << semi;
	cout << showv( ofile.GetLength( ) ) << semi;
	cout << showv( ofile.GetFileTitle( ) ) << semi;
	cout << showv( ofile.GetPosition( ) ) << nl << cut;
	);

	//控制符打印测试
	cout << "控制符打印测试" << endl;
	lscode(
		cout << cut << 'a' << tab << com << sp << semi << sp << dash << sp << sp << star;
	);
	//排序功能测试
	cout << "排序功能测试" << endl;
	code(
		vector<int>vecta { 3, 4, 5, 6,33,89,992,8192,8282,1 };
	vector<int>va = { 12,234,56,78,892,8,235,86 ,18,998,888,999,928 };
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	set<int , std::greater<> >setb { 3 , 4 , 5 , 6 , 2,6 , 2,980,222,888,1024,338,8999, };
	);
	lscode(
		cout << setb << newl;
	std::sort( vecta.begin( ) , vecta.end( ) , compare<int , true> );
	std::sort( vecta.begin( ) , vecta.end( ) , [ ] ( int a , int b ) {return a > b; } );
	cout << vecta << newl;
	std::sort( vecta.begin( ) , vecta.end( ) , [ ] ( int a , int b ) {return a < b; } );
	cout << vecta << newl;
	auto iit = std::find_if( vecta.begin( ) , vecta.end( ) , [ ] ( int a )->bool {return a == 6; } );
	cout << vecta << tab << *iit << newl;
	);
}
void OnPCDCFunctionTest8( PCDC& cout )
{
	cout.flushscreen( );
	//复合类型类型数量打印功能测试
	cout << "复合类型类型数量打印功能测" << nl;
	code(
		array<int , 10>arrone = { 88,77,66,44,33,22,11,01,99,43 };
	initializer_list<int> v = { 3,4,5,6 ,0,9,8,7,2,1 };
	vector<int>vecta { 908, 4,33,89,992,8192,8282,1 };
	deque<int>dqa { 13, 24,12,23,82,918,883,898,1 };
	list<int>lista { 123,456,000,444,213, 24, 25, 86,1 };
	vector<int>va = { 12,234,78,892,8,235,86 ,18,928 };
	map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{238,8.9399} };
	multimap<int , float>mmif = { {234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	pair<int , string>paone { 100,"pair" };
	complex <int>complexa( 2 , 5 );
	set<int>seta { 3 ,  6 , 2,980,222,888,1024,338,8999,0 };
	multiset<int>mseta { 13 ,84 ,15 , 336 ,19880,2282,3838,88999,0 };

	); lscode(
		cout.TypeCount( vecta ) << newl;
	); lscode(
		cout.TypeCount( dqa ) << newl;
	); lscode(
		cout.TypeCount( lista ) << newl;
	); lscode(
		cout.TypeCount( mmif ) << newl;
	); lscode(
		cout.TypeCount( seta ) << newl;
	); lscode(
		cout.TypeCount( CString( ) ) << newl;
	); lscode(
		cout.TypeCount( string( ) ) << newl;
	); lscode(
		cout.TypeCount( string( ) ) << endl;
	);
};
void OnPCDCFunctionTest2( PCDC& cout )
{
	cout << clear;
	cout << "英文字符打印功能运行时间测试" << endl;
	CString cs = _T( "12345678ab123456" );
	cs.MakeLower( );
	//using namespace std::chrono_literals;
	//auto start = std::chrono::high_resolution_clock::now( );
	lcode( BEGINTEST( 350 ) {
		cout << cs;
	}ENDTEST );
	//auto end = std::chrono::high_resolution_clock::now( );
	//auto itcount = end - start;
	//cout << itcount.count( ) << newl;

}

void OnTaskRuntimeTest1( PCDC& cout )
{
	int x = 100;
	size_t y = 100;
	int* p;

	cout << clear;
	code( BEGINTEST( 10'000'000 ) { x++; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { ++x; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { y--; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { --y; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { x -= y; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int; delete p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int( 5 ); delete p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int[20]; delete[ ]p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int[20]( 5 ); delete[ ] p; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { x = 5; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { int z = 5; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { int z { 5 }; }ENDTEST );

}
void OnTaskRuntimeTest2( PCDC& cout )
{
	cout << clear;
	cout << "开始进行基本功能运行时间测试" << newl;
	code(
		class AV
	{
	public:
		int run( ) { return 0; }
	};
	); code(
		class BV
	{
	public:
		virtual int run( ) { return 0; }
	};
	); code(
		unsigned long long int x = 11;
	unsigned long long int sx = 1;
	size_t y = 1;
	int* p;
	); code(
		AV a;
	BV b;
	AV * pva = &a;
	AV * pvb = (AV*)&b;
	CRect rm;
	);
	code( BEGINTEST( 1000'000 ) { add<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 1000'000 ) { mul<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { divv<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { sub<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { a.run( ); }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { pva->run( ); }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { pvb->run( ); }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { b.run( ); }ENDTEST );


}
void OnTaskRuntimeTest3( PCDC& cout )
{
	cout << clear;
	cout << "API控制结构功能运行时间测试" << newl;
	code(
		unsigned long long int x = 11;
	unsigned long long int sx = 1;
	size_t y = 1;
	int* p;
	);
	code( BEGINTEST( 100'000 ) { for ( ; sx < 10;) sx++; sx = 1; }ENDTEST );
	code( BEGINTEST( 100'000 ) { while ( x < 10 ) x++; x = 1; }ENDTEST );
	code( BEGINTEST( 100'000 ) { do { x++; } while ( x < 10 ); x = 1; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { if ( x > 10000 )--x; else ++x; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { x + sx; }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { sizeof( int ); }ENDTEST );
	code( BEGINTEST( 10'000'000 ) { sx* sx; }ENDTEST );
	code( BEGINTEST( 1000 ) { cout<<y; }ENDTEST );


}
void OnTaskRuntimeTest4( PCDC& cout )
{
	cout << clear;
	cout << "API功能运行时间测试" << newl;
	code(
		CString cs;
	cs = "1234567890abcdez*=-+";
	);
	code( BEGINTEST( 100'000 ) { CString cs = _T( " " ); }ENDTEST );
	code( BEGINTEST( 200 ) { cout << cs; }ENDTEST );

}
void OnTaskRuntimeTest5( PCDC& cout )
{
	cout << clear;
	cout << "API功能运行时间测试" << newl;
	code(
		CRect rm;
	);
	code( BEGINTEST( 100'000 ) { string cs = ( " " ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { wstring cs = _T( " " ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { wstring cs = _T( " " ); }ENDTEST );
	code( BEGINTEST( 1'000'000 ) { cout.m_pwnd->GetClientRect( &rm ); }ENDTEST );
	code( BEGINTEST( 1'000 ) { cout.TextOutW( 50 , 1000 , _T( "a textout string " ) ); }ENDTEST );
}




