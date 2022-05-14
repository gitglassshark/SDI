#include "pch.h"
#include "test.h"
#include "PCDC.h"


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

void OnObjectSize2( PCDC& cout )
{
	cout << cl;
	showtype( CObject );
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
	showtype( HWND );
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
void OnObjectSize3( PCDC& cout )
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
	showtype( nullptr );
	showtype( void* );
	showtype( int* );
	showtype( const int* );
	showtype( int*& );
	showtype( const int*& );
	showtype( char* );
	showtype( const char* );
	showtype( char*& );
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
	showtype( tuple<> );
	showtype( tuple<int , string , CString> );

}
void OnObjectSize1( PCDC& cout )
{
	showtype( XCout );
	showtype( std::cout );
	showtype( std::cin );
	showtype( std::cerr );
	showtype( CDC );
	showtype( CPaintDC );
	showtype( CColor );
	showtype( dccr.berry );
	showtype( RECT );
	showtype( POINT );
	showtype( LOGFONT );
	showtype( CFont );
	showtype( HDC );
	showtype( CSize );
	showtype( CRect );
	showtype( uintptr_t );
	showtype( NULL );
	showtype( 'a' );
	showtype( 0 );
	showtype( 0L );
	showtype( 8.0f );
	showtype( "a string" );
	showtype( _T( "a string" ) );
	showtype( L"a string" );
	showtype( _afxThreadState );
	list<int>la;
	cout.TypeCount( la ) << endl;
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
	lcode( ilt.erase( ilt.begin( )) );
	lcode( ilt.pop_back( )  );
	lcode( ilt.pop_front( )  );
	lcode( ilt.insert( ilt.begin( ) , 666 );  );
	lcode( ilt.insert( ilt.begin( ) , 666 ); ilt.insert( ilt.begin( ) , 666 );  );
	lcode( ilt.remove( *ilt.begin( ) ); cout << ilt );
	lcode( ilt.reverse( ); cout << ilt );
	lcode( ilt.swap( l2 );   );
	lcode( ilt.sort( ); ilt.reverse( ); )
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

