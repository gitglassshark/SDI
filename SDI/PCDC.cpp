#include "pch.h"
#include "PCDC.h"
#include "SDI.h"
#include "muse.h"

//size_t PCDC::icount = 0;
extern class CColor dccr;

CString hex( ) { return CString( ); }
CString HEX( ) { return CString( ); }
CString oct( ) { return CString( ); }
CString udec( ) { return CString( ); }
CString address( ) { CString cs; return cs; }

PCDC& sp( PCDC& dc ) { return  dc << "  "; }
PCDC& star( PCDC& dc ) { return dc << "*"; }
PCDC& dash( PCDC& dc ) { return dc << "-";; }
PCDC& com( PCDC& dc ) { return dc << ','; }
PCDC& tab( PCDC& dc ) { return dc << '\t'; }
PCDC& semi( PCDC& dc ) { return dc << ';'; }

PCDC& nl( PCDC& dc ) {
	if ( dc.p.x == dc.mrect.left + dc.initalpos )
		return dc;
	return  dc << '\n';
}
PCDC& newl( PCDC& dc )
{
	return  dc << '\n';
}
PCDC& endl( PCDC& dc )
{
	if ( dc.p.x == dc.mrect.left + dc.initalpos )
		return dc;
	return  dc << '\n';
}
PCDC& cut( PCDC& dc )
{
	dc.settcolor( dccr.xteal ).cut( ).resettcolor( );
	return dc;
}
PCDC& cl( PCDC& dc )
{
	dc.flushscreen( );
	return dc;
}
PCDC& clear( PCDC& dc )
{
	dc.flushscreen( );
	return dc;
}

PCDC& starline( PCDC& dc )
{
	if ( dc.p.x != dc.mrect.left + dc.initalpos )
		dc << nl;
	dc.cut( );
	return 	dc;
}

PCDC::PCDC( CWnd* pwnd ) :m_pwnd( pwnd )
{
	if ( m_pwnd ) {
		id = icount;
		++icount;
		Create( m_pwnd );
	}
}

PCDC::~PCDC( )
{
	--icount;
	this->Release( );
}

PCDC& PCDC::Create( CWnd* pwnd )
{
	if ( pwnd != nullptr )
		m_pwnd = pwnd;
	if ( icreate )
		return *this;
	this->m_hDC = m_pwnd->GetWindowDC( )->m_hDC;
	CDC& dc = *this;
	auto tcolor = dccr.chocolate;
	auto bcolor = dccr.grey;

	//���ô��ڱ�����ɫ
	m_pwnd->GetClientRect( &mrect );
	p.x = mrect.left + initalpos;
	p.y = mrect.top + initalpos;
	dc.FillSolidRect( mrect , m_bk );

	//����������ɫ
	dc.SetBkColor( m_bk );
	dc.SetTextColor( m_tk );

	//����ȱʡ����
	LOGFONT lf;
	// zero out structure
	memset( &lf , 0 , sizeof( LOGFONT ) );
	font.CreatePointFont( this->mfontsize , _T( "Cascadia Mono" ) );
	pfont = dc.SelectObject( &font );

	//���������С��������
	font.GetLogFont( &lf );
	step = abs( lf.lfHeight + lf.lfHeight / 2 );

	//������λ��
	if ( !dc.PtVisible( p ) ) {
		p.x = initalpos;
		p.y = initalpos;
	}
	//*this << cl;
	icreate = true;
	mvlogs.reserve( getmaxline( ) * 10 );
	return *this;
}

PCDC& PCDC::Release( )
{
	if ( !icreate )
		return *this;
	CDC& dc = *this;
	dc.SelectObject( pfont );
	m_pwnd->ReleaseDC( this );
	font.DeleteObject( );
	m_pwnd = nullptr;
	m_cdc = nullptr;
	icreate = false;
	return *this;
}

PCDC& PCDC::resettcolor( )
{
	SetTextColor( m_tk );
	return *this;
}

PCDC& PCDC::settcolor( COLORREF tk )
{
	SetTextColor( tk );
	return *this;
}

PCDC& PCDC::setcolor( COLORREF line , COLORREF bar , COLORREF bk , COLORREF tk )
{
	m_bk = bk;
	m_tk = tk;
	m_bark = bar;
	m_linek = line;
	return *this;
}

PCDC& PCDC::setimod( int imod )
{
	ilinemod = imod;
	return *this;
}

char PCDC::setlinechar( const char& c )
{
	char rc = mlinechar;
	mlinechar = c;
	return rc;
}

PCDC& PCDC::flushscreen( const CRect* r , const COLORREF* cr )
{
	auto iwbar = wbar;
	m_pwnd->GetClientRect( &mrect );
	CRect rect( mrect );
	if ( r != nullptr )
	{
		mrect = *r;
	}
	else
	{
		cr != nullptr ? m_bk = *cr : true;
		p.x = mrect.left + initalpos;
		p.y = mrect.top + initalpos;
		rect.left = 0;
		rect.top = 0;
		FillSolidRect( rect , m_bark );

		rect.bottom -= iwbar;
		rect.left += iwbar;
		rect.right -= iwbar;
		rect.top += iwbar;
		FillSolidRect( rect , m_linek );
	}

	iwbar = 12;
	rect.bottom -= iwbar;
	rect.left += iwbar;
	rect.right -= iwbar;
	rect.top += iwbar;
	FillSolidRect( rect , m_bk );
	return *this;
}

PCDC& PCDC::displayfile( CString filename )
{
	if ( filename.IsEmpty( ) )
		return *this;

	CFile cfile;
	bool iresult = cfile.Open( filename , CFile::modeRead );
	if ( !iresult )
		return *this;
	//׼�����뻺����
	const int imaxcount = 1024;
	int iretcount = 1023;
	char pbufRead[imaxcount] {};
	memset( pbufRead , 0 , sizeof( pbufRead ) );
	pbufRead[imaxcount - 1] = '\0';
	ASSERT( sizeof( pbufRead ) == imaxcount );

	cfile.SeekToBegin( );
	string readline;

	//��ʼ�������ݣ���������ֽ���С�����ö����ֽڣ�����ֵ����˵�������ļ�ĩβ���˳���ȡѭ����
	while ( iretcount == imaxcount - 1 )
	{
		iretcount = cfile.Read( pbufRead , imaxcount - 1 );
		pbufRead[iretcount] = '\0';
		readline.append( pbufRead , iretcount );
		*this << readline;
		readline = "";
	}
	//ASSERT(0 == memcmp(pbufWrite, pbufRead, sizeof(pbufWrite)));
	cfile.Close( );
	return *this;
}

void PCDC::status( bool ibshowrecode )
{
	auto& cout = *this;
	LOGFONT l;
	CAtlString str = _T( "��ʾ�豸XCout����״̬" );
	RECT rect;
	cout.stoprecode( );
	size_t* pnstore = cout.storesms( false );
	font.GetLogFont( &l );
	m_pwnd->GetWindowRect( &rect );
	theApp.m_pMainWnd->SetWindowText( str );
	cout << clear;
	cout.sourcemode( );
	cout << "XCout״̬�������¼ " << cout.mvlogs.size( ) << sp;
	cout << "�������� " << cout.getmaxline( ) << sp;
	cout << "��¼���� " << cout.mvlogs.capacity( ) << sp;
	cout << "��¼���� " << pnstore[0] << sp;
	cout << "��¼���� " << pnstore[1] << sp;
	cout << "ʵ�ʼ�¼ " << pnstore[2] << sp;
	cout << "�ռ�¼���� " << pnstore[3] - pnstore[2] << sp;
	cout << "�մ�ӡ���� " << pnstore[4] << sp;
	cout << "���ڴ�ӡ " << pnstore[5] << sp;
	cout << "���� " << pnstore[6] << sp;
	cout << "���� " << pnstore[7] << sp;
	cout << "���д�ӡ " << pnstore[8] << sp;
	cout << "��ӡ�ܵ��� " << pnstore[9] << sp;
	cout << "��¼�ܺ�ʱ " << pnstore[10] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "��ӡ�ܺ�ʱ " << pnstore[11] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API�ܺ�ʱ " << pnstore[12] * 1000 / CLOCKS_PER_SEC << "\'ms" << sp;
	cout << "API���� " << pnstore[13] << sp;
	cout << "step " << step << sp;
	cout << "rect.left " << rect.left << sp;
	cout << "rect.right " << rect.right << sp;
	cout << "rect.top " << rect.top << sp;
	cout << "rect.bottom " << rect.bottom << sp;
	cout << "p.x " << p.x << sp;
	cout << "p.y " << p.y << sp;
	cout << "���� " << CString( l.lfFaceName );
	if ( ibshowrecode ) {
		str = _T( " [��ʷ��¼]-β�� " );
		cout << str << nl;
		cout << starline;
		cout.resettcolor( );
		for ( int i = cout.mvlogs.size( ) - cout.getmaxline( ) + 6; i < cout.mvlogs.size( ); i++ )
			cout << cout.mvlogs[i] << nl;
	}
	cout.resettcolor( );
	cout.startrecode( );
}

PCDC& PCDC::operator << ( PCDC& ( *op ) ( PCDC& ) )
{
	if ( op == nl || op == cl )
	{
		if ( p.x == mrect.left + initalpos )
			return *this;
	}
	return ( *op ) ( *this );
}

PCDC& PCDC::operator <<( LPCTSTR p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( char* p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const char* p )
{
	if ( ( p != nullptr ) && ( *p != '\0' ) )
	{
		ms = p;
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const CAtlString& s )
{
	if ( s.IsEmpty( ) )
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	else
	{
		imresizeout( s );
	}
	return *this;
}

PCDC& PCDC::operator <<( const std::wstring& s )
{
	if ( ( s.length( ) ) && ( s.at( 0 ) != '\0' ) ) {
		ms = s.c_str( );
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const std::string& s )
{
	if ( ( s.length( ) ) && ( s.at( 0 ) != '\0' ) )
	{
		ms = s.c_str( );
	}
	else
	{
		ms = "null(0)";
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const CString& s )
{
	if ( !s.IsEmpty( ) )
	{
		imresizeout( s );
	}
	else
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	return *this;
}

PCDC& PCDC::operator <<( const CString&& s )
{
	if ( !s.IsEmpty( ) )
	{
		imresizeout( s );
	}
	else
	{
		ms = "null(0)";
		imresizeout( ms );
	}
	return *this;
}

PCDC& PCDC::operator <<( const int n )
{
	ms.Format( _T( "%ld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator<<( const char c )
{
	if ( c == 0 ) { ms = "null(0)"; }
	if ( c == '\n' ) {
		p.y += step;
		p.x = initalpos;
		storesms( );
		return *this;
	}
	if ( c == '\t' )
	{
		ms = "    ";
	}
	if ( isprint( c ) ) {
		ms = c;
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const float n )
{
	ms.Format( _T( "%4.2lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const double n )
{
	ms.Format( _T( "%lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long double n )
{
	ms.Format( _T( "%lf" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long int n )
{
	ms.Format( _T( "%ld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const long long n )
{
	ms.Format( _T( "%lld" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const size_t n )
{
	ms.Format( _T( "%zu" ) , n );
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator <<( const bool b )
{
	if ( b == true )
	{
		ms = st( true );
	}
	else {
		ms = st( false );
	}
	imresizeout( ms );
	return *this;
}

PCDC& PCDC::operator<<( const unsigned long int n )
{
	ms.Format( _T( "%lu" ) , n );
	imresizeout( ms );
	return *this;
};

PCDC& PCDC::operator<<( const unsigned int n )
{
	//( *this ) << (const int)n; return *this; 
	ms.Format( _T( "%lu" ) , n );
	imresizeout( ms );
	return *this;
};

PCDC& PCDC::operator<<( std::nullptr_t p )
{
	ms = "nullptr";
	imresizeout( ms );
	return *this;
}

CString bools( )
{
	CString cs;
	cs = "}";
	return cs;
}

CString tab( size_t Ntimes )
{
	CString cs;
	NTIME( Ntimes )
		cs += "    ";
	return cs;
}

CString sp( size_t Ntimes )
{
	CString cs;
	NTIME( Ntimes )
		cs += ' ';
	return cs;
}

CString letters( char lc , size_t Ntimes )
{
	CString cs;
	if ( isprint( lc ) )
		NTIME( Ntimes )
		cs += lc;
	return cs;
}



