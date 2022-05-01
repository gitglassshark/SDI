#include "pch.h"
#include "test.h"
#include "PCDC.h"



void OnPCDCFunctionTest1( PCDC& cout )
{
	//打印整型数据
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
		cout << icount << com << ia << sp << 999 << sp << -1 << sp << 0 << sp << cia << sp << ria << sp << rra << sp << INT_MIN << com << INT_MAX << semi << cla << sp << la << sp << LONG_MAX << com << LONG_MIN << semi << lla << sp << LONGLONG_MAX << com << LONGLONG_MIN << starline;
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
		cout << it << tab << in << tab << inn << tab << rin << tab << rinn << tab << true << tab << false << tab << ( 2 > 1 ) << tab << ( 3 > 5 );
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
			if ( ( i + 1 - c0 ) % 25 == 0 )
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
void OnPCDCFunctionTest2( PCDC& cout )
{
	cout << clear;
	cout << L"中文常量字符串打印指针型字符串功能测试:" << endl;
	lcode(
		CString cs = L"壹贰叁肆伍陆柒捌玖拾佰仟万亿";
	BEGINTEST(200 ) {
		cout << cs;
	}ENDTEST );

};
void OnPCDCFunctionTest3( PCDC& cout )
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
	); lscode(
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
void OnPCDCFunctionTest9( PCDC& cout )
{
	cout << clear;
	cout << "英文字符打印功能运行时间测试" << endl;
	CString cs = _T( "#123456789abcdef01234567890#" );
	lcode( BEGINTEST( 200 ) {
		cout << cs;
	}ENDTEST );

}


void OnTaskRuntimeTest1( PCDC& cout )
{
	int x = 100;
	size_t y = 100;
	int* p;

	cout << clear;
	code( BEGINTEST( 100'000 ) { x++; }ENDTEST );
	code( BEGINTEST( 100'000 ) { ++x; }ENDTEST );
	code( BEGINTEST( 100'000 ) { y--; }ENDTEST );
	code( BEGINTEST( 100'000 ) { --y; }ENDTEST );
	code( BEGINTEST( 100'000 ) { x -= y; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int; delete p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int( 5 ); delete p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int[20]; delete[ ]p; }ENDTEST );
	code( BEGINTEST( 100'000 ) { p = new int[20]( 5 ); delete[ ] p; }ENDTEST );
	code( BEGINTEST( 1000'000 ) { x = 5; }ENDTEST );
	code( BEGINTEST( 1000'000 ) { int z = 5; }ENDTEST );
	code( BEGINTEST( 1000'000 ) { int z { 5 }; }ENDTEST );

}
void OnTaskRuntimeTest2( PCDC& cout )
{
	cout << clear;
	cout << "开始进行基本功能运行时间测试" << cut;
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
	code( BEGINTEST( 100'000 ) { add<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { mul<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { divv<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { sub<int>( x , sx ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { a.run( ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { pva->run( ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { pvb->run( ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { b.run( ); }ENDTEST );


}
void OnTaskRuntimeTest3( PCDC& cout )
{
	cout << clear;
	cout << "API功能运行时间测试" << cut;
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
	CString cs( "#1234567890abcdefghijklmnopqrstuvwxyz`-=~!@#$%^&*()_+[]\{}|;':,./<>?1234567890#" );
	);
	code( BEGINTEST( 100'000 ) { for ( ; sx < 10;) sx++; sx = 1; }ENDTEST );
	code( BEGINTEST( 100'000 ) { while ( x < 10 ) x++; x = 1; }ENDTEST );
	code( BEGINTEST( 100'000 ) { do { x++; } while ( x < 10 ); x = 1; }ENDTEST );
	code( BEGINTEST( 100'000 ) { if ( x > 10000 )--x; else ++x; }ENDTEST );
	code( BEGINTEST( 100'000 ) { x + sx; }ENDTEST );
	code( BEGINTEST( 100'000 ) { sizeof( int ); }ENDTEST );
	code( BEGINTEST( 100'000 ) { sx* sx; }ENDTEST );


}
void OnTaskRuntimeTest4( PCDC& cout )
{
	cout << clear;
	cout << "API功能运行时间测试" << nl << cut;
	code(
		CString cs( "#1234567890abcdefghijklmnopqrstuvwxyz`-=~!@#$%^&*()_+[]\{}|;':,./<>?1234567890#" );
	);
	code( BEGINTEST( 1000 ) { cout.imresizeout( cs ); }ENDTEST );

}
void OnTaskRuntimeTest5( PCDC& cout )
{
	cout << clear;
	cout << "API功能运行时间测试" << nl << cut;
	code(
		CString cs( "#1234567890abcdefghijklmnopqrstuvwxyz`-=~!@#$%^&*()_+[]\{}|;':,./<>?1234567890#" );
	CRect rm;
	);
	code( BEGINTEST( 100'000 ) { CString cs = _T( " " ); }ENDTEST );

	code( BEGINTEST( 100'000 ) { string cs = ( " " ); }ENDTEST );

	code( BEGINTEST( 100'000 ) { wstring cs = _T( " " ); }ENDTEST );

	code( BEGINTEST( 100'000 ) { wstring cs = _T( " " ); }ENDTEST );

	code( BEGINTEST( 100'000 ) { cout.m_pwnd->GetClientRect( &rm ); }ENDTEST );
}

void OnDcTcolorTest1( PCDC& cout )
{
	lscode(
		cout.settcolor( dccr.green2 );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.red1 );
	);
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.mteal ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.lteal ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.hteal ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.gteal ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.xteal ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.tteal ); );
	smn( this is a color , < $ , 5 > :: : );
	cout.setcolor( dccr.whitesmoke , dccr.yellow , cout.m_bk , cout.m_tk );
	smn( this is a color , < $ , 5 > :: : );

}
void OnDcTcolorTest2( PCDC& cout )
{

	lscode( cout.settcolor( dccr.teal ); );
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.white );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.whitesmoke );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.slategray );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.green );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.bluered );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.greenblue );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.yellow );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.midblue );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.midgreen );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.midred );
	);
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.lightred ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.lightblue ); );
	smn( this is a color , < $ , 5 > :: : );
	cout.setcolor( dccr.darkslateblue , dccr.brown , cout.m_bk , cout.m_tk );
	smn( this is a color , < $ , 5 > :: : );



}
void OnDcTcolorTest3( PCDC& cout )
{
	lscode(
		cout.settcolor( dccr.midyellow );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.midgreenblue );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.midbluered );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkgreen );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkyellow );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.azure );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.smokered );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.smokeyellow );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.smokewhite );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.maingreen );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.mainred );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode( cout.settcolor( dccr.mainwhite ); );
	smn( this is a color , < $ , 5 > :: : );

	lscode( cout.settcolor( dccr.lightgreen ); );
	smn( this is a color , < $ , 5 > :: : );
	cout.setcolor( dccr.lightred , dccr.hlightgreen , cout.m_bk , cout.m_tk );
	smn( this is a color , < $ , 5 > :: : );

}
void OnDcTcolorTest4( PCDC& cout )
{
	lscode(
		cout.settcolor( dccr.red );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.azure );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.blue );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.brown );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkcyan );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkgray );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkred );
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.darkslateblue
		);
	);
	smn( this is a color , < $ , 5 > :: : );

	lscode(
		cout.settcolor( dccr.dodgerblue );
	);
	smn( this is a color , < $ , 5 > :: : );
	cout.setcolor( dccr.green2 , dccr.hteal , cout.m_bk , cout.m_tk );

}
void OnDcTcolorTest5( PCDC& cout )
{
	lscode( cout.settcolor( dccr.hlightred ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.hlightblue ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.hlightgreen ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.overlightgreen ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.mheavggreen ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.lbluered ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.mbluered ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.hbluered ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( cout.settcolor( dccr.bluehred ); );
	smn( this is a color , < $ , 5 > :: : );
	lscode( lscode( 0 ) );
	smn( this is a color , < $ , 5 > :: : );
	cout.setcolor( dccr.midyellow , dccr.smokered , cout.m_bk , cout.m_tk );
	smn( this is a color , < $ , 5 > :: : );
}

void OnObjectSize1( PCDC& cout )
{
	cout << cl;
	showtype( CObject );
	showtype( CDC );
	showtype( CPaintDC );
	showtype( LOGFONT );
	showtype( CFont );
	showtype( CFontDialog );
	showtype( CView );
	showtype( CFrameWnd );
	showtype( CWinApp );
	showtype( CSplitterWnd );
	showtype( CDumpContext );
	showtype( CREATESTRUCT );
	showtype( CToolBar );
	showtype( CStatusBar );
	showtype( CCreateContext );
	showtype( CClientDC );
	showtype( CArchive );
	showtype( CFileDialog );
	showtype( CD2DSizeU );
	showtype( CHwndRenderTarget );
	showtype( FILE );
	showtype( LRESULT );
	showtype( HDC );
	showtype( HWND );
	showtype( POINT );
	showtype( RECT );
	showtype( CRect );
	showtype( CSize );
	showtype( CFile );
	showtype( NMHDR );
	showtype( HMODULE );
	showtype( _AFX_THREAD_STATE );
	showtype( WINDOWPLACEMENT );
	showtype( AFX_MSGMAP );
	showtype( AFX_MSGMAP_ENTRY );
	showtype( LPARAM );
	showtype( WPARAM );
	showtype( BYTE );
	showtype( BOOL );
	showtype( LONG );
	showtype( DWORD );
	showtype( WORD );
}
void OnObjectSize2( PCDC& cout )
{
	cout << cl;
	showtype( char );
	showtype( char& );
	showtype( const char );
	showtype( const char& );
	showtype( int );
	showtype( int& );
	showtype( const int );
	showtype( const int& );
	showtype( short );
	showtype( long );
	showtype( long long int );
	showtype( double );
	showtype( float );
	showtype( long double );
	showtype( bool );
	showtype( size_t );
	showtype( void* );
	showtype( int* );
	showtype( const int* );
	showtype( int*& );
	showtype( const int*& );
	showtype( char* );
	showtype( const char* );
	showtype( char*& );
	showtype( uintptr_t );
	showtype( nullptr_t );
	showtype( weak_ptr<int> );
	showtype( intptr_t );
	showtype( shared_ptr<int> );
	showtype( unique_ptr<int> );
	showtype( complex<int> );
	showtype( pair<int , string> );
	showtype( vector<int> );
	showtype( set<int> );
	showtype( multiset<int> );
	showtype( map<int , string> );
	showtype( multimap<int , string> );
	showtype( tuple<int , string , CString> );

}
void OnObjectSize3( PCDC& cout )
{
	showtype( XCout );
	showtype( CColor );
	showtype( dccr.berry );
	showtype( nullptr );
	showtype( NULL );
	showtype( 'a' );
	showtype( 0 );
	showtype( 0L );
	showtype( 8.0f );
	showtype( "a string" );
	showtype( _T( "a string" ) );
	showtype( L"a string" );
	showtype( std::cout );
	showtype( std::cin );
	showtype( std::cerr );
	showtype( _afxThreadState );
	showtype( tuple<> );
	cout.TypeCount( tuple<>( ) ) << endl;
	cout.TypeCount( string( ) ) << endl;
	cout.TypeCount( wstring( ) ) << endl;
	cout.TypeCount( CString( ) ) << endl;
	cout.TypeCount( CAtlString( ) ) << endl;
	cout.type( nullptr , NULL , tuple<>( ) , int( ) );

}

void OnStlTypeTest1( PCDC& cout )
{
	using  ULINT = unsigned long long;
	ULINT y = 22;
	ULINT z = 100;
	ULINT x = 200;
	ULINT& r = x;
	ULINT pr_t = (ULINT)&r;
	ULINT* pr = (ULINT*)pr_t;
	ULINT& r2 = r;
	ULINT* px = &x;
	ULINT&& r3 = 0;
	*pr = y;
	y = 100;
	lscode(
		cout.type( x , r , r2 , r3 );
	);
	lscode(
		cout << sizeof( int ) << tab << sizeof( px ) << endl;
	cout << pr_t << tab << (unsigned int)&r << tab << &x << tab << pr << tab << *pr << tab << px << endl;
	);
	lscode(
		const int c = 4;
	int d = 5;
	int& e = d;
	const long long int ta = 100;
	cout << afunc( y ) << tab;
	cout << afunc( c ) << tab;
	cout << afunc( (int)d ) << tab;
	cout << afunc( (int&&)e ) << tab;
	cout << afunc( 10 ) << semi << tab;
	cout << ( const long long int )ta << tab << nl;
	);
	lscode(
		cout << cut;
	cout.address( x , r , r2 , r3 ) << cut;
	cout << address( x , r , r2 , r3 ) << cut;
	cout << &x << com << &r << com << &r2 << com << &r3 << cut;
	);
	lscode(
		x = 300;
	cout.value( pr , px , &r3 , &r2 , &r , &x , &d , &e , &px , &z , &pr ) << cut;
	cout << gmax( x , r , r2 , r3 , *px , *pr , d , e , z , 100 , 100.2 ) << cut;
	);
}
void OnStlTypeTest2( PCDC& cout )
{
	CString s;
	string s2;
	LONG x;
	bool bcomp = std::is_same_v<decltype( x ) , LONG>;
	LONG y;
	vector<int>va;
	typedef int fun( int , int );
	typedef int ( *pfun )( int , int );
	typedef fun* func;
	func p = f;
	pfun ppf;
	ppf = f;
	fun w;
	fun* pf = f;
	lcode(
		va.push_back( 1 );
	va.push_back( 2 );
	gett( va )::iterator it = va.begin( );
	cout << *it << newl;
	getI( va ) iit = va.begin( );
	cout << *iit << newl;
	cout << cut;
	FORALL( va , itx )
		cout << *itx << tab;
	for ( auto i : va )
		cout << i << tab;
	FORN( va.size( ) , i )
		cout << va.at( i ) << tab;
	FORV( i , va )
		cout << i << tab; cout << newl;
	showtype( va );
	);
	lcode(
		cout << p( 10 , 20 ) << cut;
	cout << pf( 20 , 30 ) << cut;
	cout << ppf( 100 , 200 ) << cut;
	showtype( p );
	showtype( pf );
	showtype( ppf );
	);
}
void OnStlTypeTest3( PCDC& cout )
{
	using  ULINT = unsigned long long;
	ULINT y = 22;
	ULINT z = 100;
	ULINT x = 200;
	ULINT& r = x;
	ULINT pr_t = (ULINT)&r;
	ULINT* pr = (ULINT*)pr_t;
	ULINT& r2 = r;
	ULINT* px = &x;
	ULINT&& r3 = 0;
	*pr = y;
	y = 100;
	CString s;
	string s2;
	bool bcomp = std::is_same_v<decltype( x ) , LONG>;
	vector<int>va;
	typedef int fun( int , int );
	typedef int ( *pfun )( int , int );
	typedef fun* func;
	func p = f;
	pfun ppf;
	ppf = f;
	fun w;
	fun* pf = f;
	lcode(
		cout << bcomp << newl;
	bcomp = std::is_same_v<decltype( s ) , decltype( s2 )>;
	cout << bcomp << newl;
	cout << typeid( decay<decltype( x )>::type ).name( ) << newl;
	cout << &cout << tab << typeid( cout ).name( ) << tab << typeid( &cout ).name( ) << newl;
	cout << ( int* ) nullptr << tab << sizeof( nullptr ) << tab << typeid( nullptr ).name( ) << newl;
	cout << (int*)NULL << tab << sizeof( NULL ) << tab << typeid( NULL ).name( ) << newl;
	cout << (int*)NULL << tab << sizeof( void* ) << tab << typeid( int* ).name( ) << newl;
	);
	lscode(
		cout << &cout << tab << &cout << newl;
	showtype( cout );
	showtype( cout );
	cout << address( cout ) << newl;
	cout << address( std::cout ) << newl;
	cout << tab << &s << tab << &s2 << tab << &x << newl;
	showtype( std::cout );
	);
	lcode(
		if ( typeid( x ).name( ) == typeid( y ).name( ) )
			cout << typeid( x ).name( ) << newl;
	);
}

void OnStlSetTest1( PCDC& cout )
{
	list<int>ilt;
	for ( size_t i = 0; i < 15; i++ )
	{
		ilt.push_back( i + 10 );
	}
	for ( list<int>::iterator it = ilt.begin( ); it != ilt.end( ); ++it )
	{
		*it *= 2;
	}
	CString ssss( '2' , 129 );
	cout << ssss << newl;
	for ( size_t l = 0; l < ssss.GetLength( ); l++ )
	{
		if ( l % 2 == 1 )
			ssss.Insert( l , '3' );
	}
	cout << ssss << newl;
	for ( size_t l = 0; l < ssss.GetLength( ); l++ )
	{
		if ( l % 3 == 2 )
			ssss.Insert( l , '4' );
	}
	cout << ssss << newl;
	list<int> l2( ilt );
	cout.setlinechar( '-' );
	for ( list<int>::iterator it = ilt.begin( ); it != ilt.end( ); ++it )
	{
		*it *= 2;
		cout << *it << tab;
	}
	cout << newl;
	cout.setlinechar( '-' );
	for ( list<int>::iterator it = l2.begin( ); it != l2.end( ); ++it )
	{
		*it *= 2;
		cout << *it << tab;
	}
	cout << newl;
	cout.flushscreen( );
	lcode( ilt.erase( ilt.begin( ) ); cout( ilt ) );
	lcode( ilt.pop_back( ); cout( ilt ) );
	lcode( ilt.pop_front( ); cout( ilt ) );
	lcode( ilt.insert( ilt.begin( ) , 666 ); cout( ilt ) );
	lcode( ilt.insert( ilt.begin( ) , 666 ); ilt.insert( ilt.begin( ) , 666 ); cout( ilt ) );
	lcode( ilt.remove( *ilt.begin( ) ); cout << ilt );
	lcode( ilt.reverse( ); cout << ilt );
	lcode( cout( l2 ) << tab << ilt;);
	lcode( ilt.swap( l2 ); cout( ilt ); cout( l2 ) );
	lcode( ilt.sort( ); ilt.reverse( ); cout( ilt ););
}
void OnStlSetTest2( PCDC& cout )
{
	cout << cl;
	set<int> iset1;
	int mod = 30;
	for ( size_t i = 0; i < 30; i++ )
	{
		iset1.insert( i * rand( ) % mod );
	}
	cout << iset1 << newl;
	iset1.insert( 25 );
	cout << iset1 << newl;

	lcode( cout << iset1.size( ) << tab << iset1.count( 15 ) << tab << iset1.max_size( ) << newl; cout << iset1;);

	lcode( cout << *iset1.begin( ) << tab << tab << iset1.empty( ) << tab << iset1.erase( 5 ) << newl; cout << iset1 << newl;);
	auto it = iset1.find( 8 );
	if ( it == iset1.end( ) )
		cout << "is end" << newl;
	lcode( iset1.insert( 100 ););
	lcode( iset1.insert( 200 ););
	lcode( iset1.insert( 300 ););
	lcode( cout << "find" << tab << *iset1.upper_bound( 20 ) << newl; cout << iset1 << newl;);
	lcode( cout << "find" << tab << *iset1.lower_bound( 10 ) << newl; cout << iset1;);
}
void OnStlSetTest3( PCDC& cout )
{
	icompset a;
	cout << a( st( good ) ) << tab << newl;
	cout << a( 100 ) << tab << newl;

	list<int>ilt;
	for ( size_t i = 0; i < 15; i++ )
	{
		ilt.push_back( ( rand( ) * i * rand( ) ) % 100 );
	}
	cout << ilt << newl;

	vector<int>intvec( 20 ) , empty;
	int i = 0;
	int icount = 1;
	int icountb = i + 1;
	for ( auto& i : intvec )
	{
		i = icount++ * icountb++;
	}

	cout << cl << cut;
	lscode(
		cout << ilt << newl;
	ilt.sort( a );
	cout << ilt << newl;
	);
	lscode(
		a.sortset( true ); ilt.sort( a );
	cout << ilt << newl;
	);
	lscode(
		a.sortset( false ); ilt.sort( a.sortset( false ) );
	cout << ilt << newl;
	);
	cout << cut << st( beging test compar<> ) << cut;
	lscode(
		sort( intvec.begin( ) , intvec.end( ) , compare<int , bigtosmall> );
	cout << intvec << newl;
	);
	lscode(
		sort( intvec.begin( ) , intvec.end( ) , compare<int , smalltobig> );
	cout << intvec << newl;
	);
	lscode(
		sort( intvec.begin( ) , intvec.end( ) , a.sortset( true ) );
	cout << intvec << newl;
	);
	lscode(
		a.sortset( false ); sort( intvec.begin( ) , intvec.end( ) , a );
	cout << intvec << newl;
	);
	lscode(
		ilt.reverse( );
	cout << ilt << newl;
	);
	////	set<int>set1 { 1,2,3 };
////	set<int>set2{11,22,33,9,8,7,6 };
////	set<int>set3(30,0);
////	cout<<set1<<cut<<set2<<newl;
/////*	std::insert_iterator<decltype(set3)> ii (set3,set3.begin());*/
/////*	std::set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),ii,[](int a,int b){ return a>b; } );
//	cout<<set1<<cut<<set2<<cut<<set3<<newl;*/


//typedef void ( *fun )( int , int );
//fun pfun = nullptr;
//CString wstring = _T( "good" );
//pair < CString , fun> w = make_pair( wstring , pfun );
//map<CString , fun> cfmap;
//cfmap.insert( w );
//cfmap.insert( make_pair( CString( wstring += wstring ) , pfun ) );
//cfmap.insert( pair<CString , fun>( CString( wstring = st( go ) ) , pfun ) );
//cfmap.insert( map<CString , fun>::value_type( CString( st( bad ) ) , pfun ) );
//cout << cfmap.size( ) << newl;


//pair<int , float>x = make_pair( 10 , 2.3 );
//cout << x << newl;
//auto* p = &x;
//map<int , float>imap;
//imap.insert( make_pair( 10 , 2.2 ) );
//imap.insert( x );
//map<int , float>::iterator iit = imap.begin( );
//lcode( cout << *iit << newl;);
//lcode( iit = imap.end( ); iit--; cout << *p << newl;);
//lcode( iit = imap.begin( ); cout << *iit << newl;);
}




