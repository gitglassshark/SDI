#pragma once
#include "pch.h"
#include "SDI.h"



class PCDC;
using XCout = PCDC;

class CColor {
public:
	COLORREF red = RGB( 255 , 0 , 0 );
	COLORREF midred = RGB( 128 , 0 , 0 );
	COLORREF yellow = RGB( 255 , 255 , 0 );
	COLORREF midyellow = RGB( 255 , 255 , 128 );
	COLORREF green = RGB( 0 , 255 , 0 );
	COLORREF midgreen = RGB( 0 , 128 , 0 );
	COLORREF greenblue = RGB( 0 , 255 , 255 );
	COLORREF midgreenblue = RGB( 128 , 255 , 255 );
	COLORREF mainred = RGB( 255 , 139 , 139 );
	COLORREF maingreen = RGB( 139 , 255 , 139 );
	COLORREF mainwhite = RGB( 139 , 139 , 255 );
	COLORREF blue = RGB( 0 , 0 , 255 );
	COLORREF midblue = RGB( 0 , 0 , 128 );
	COLORREF bluered = RGB( 255 , 0 , 255 );
	COLORREF lbluered = RGB( 225 , 25 , 225 );
	COLORREF mbluered = RGB( 225 , 55 , 225 );
	COLORREF hbluered = RGB( 225 , 125 , 225 );
	COLORREF bluehred = RGB( 255 , 105 , 255 );
	COLORREF midbluered = RGB( 255 , 128 , 255 );
	COLORREF black = RGB( 0 , 0 , 0 );
	COLORREF white = RGB( 255 , 255 , 255 );
	COLORREF darkred = RGB( 139 , 0 , 0 );
	COLORREF darkyellow = RGB( 139 , 139 , 0 );
	COLORREF darkgreen = RGB( 0 , 139 , 0 );
	COLORREF darkblue = RGB( 0 , 0 , 139 );
	COLORREF darkcyan = RGB( 0 , 139 , 139 );
	COLORREF fgreen = RGB( 34 , 139 , 34 );
	COLORREF red1 = RGB( 139 , 34 , 34 );
	COLORREF green2 = RGB( 34 , 34 , 139 );
	COLORREF chocolate = RGB( 238 , 118 , 33 );
	COLORREF dodgerblue = RGB( 16 , 78 , 139 );
	COLORREF grey = RGB( 28 , 28 , 28 );
	COLORREF teal = RGB( 0 , 128 , 128 );
	COLORREF mteal = RGB( 55 , 128 , 128 );
	COLORREF lteal = RGB( 105 , 128 , 128 );
	COLORREF hteal = RGB( 20 , 128 , 255 );
	COLORREF gteal = RGB( 20 , 255 , 128 );
	COLORREF tteal = RGB( 20 , 155 , 155 );
	COLORREF xteal = RGB( 20 , 200 , 200 );
	COLORREF gray = RGB( 128 , 128 , 128 );
	COLORREF darkgray = RGB( 128 , 128 , 139 );
	COLORREF darkslateblue = RGB( 72 , 61 , 128 );
	COLORREF slategray = RGB( 112 , 128 , 144 );
	COLORREF berry = RGB( 135 , 38 , 87 );
	COLORREF brown = RGB( 128 , 42 , 42 );
	COLORREF azure = RGB( 131 , 139 , 139 );
	COLORREF whitesmoke = RGB( 205 , 205 , 205 );
	COLORREF smokered = RGB( 205 , 0 , 205 );
	COLORREF smokewhite = RGB( 0 , 205 , 205 );
	COLORREF smokeyellow = RGB( 205 , 205 , 0 );
	COLORREF silver = RGB( 192 , 192 , 192 );
	COLORREF lightgreen = RGB( 55 , 255 , 55 );
	COLORREF hlightgreen = RGB( 105 , 255 , 105 );
	COLORREF midlightgreen = RGB( 155 , 255 , 155 );
	COLORREF overlightgreen = RGB( 188 , 255 , 188 );
	COLORREF heavgyellow = RGB( 205 , 205 , 20 );
	COLORREF heavggreen = RGB( 20 , 205 , 20 );
	COLORREF mheavggreen = RGB( 155 , 205 , 155 );
	COLORREF lightred = RGB( 255 , 55 , 55 );
	COLORREF hlightred = RGB( 255 , 105 , 105 );
	COLORREF lightblue = RGB( 55 , 55 , 255 );
	COLORREF hlightblue = RGB( 105 , 105 , 255 );
};

extern class CColor dccr;
extern PCDC* pcout;

PCDC& cl( PCDC& dc );
PCDC& com( PCDC& dc );
PCDC& semi( PCDC& dc );
PCDC& dash( PCDC& dc );
PCDC& star( PCDC& dc );
PCDC& cut( PCDC& dc );
PCDC& tab( PCDC& dc );
PCDC& sp( PCDC& dc );
PCDC& el( PCDC& dc );
PCDC& nl( PCDC& dc );
PCDC& endl( PCDC& dc );
PCDC& starline( PCDC& dc );
void newl( );
void cut( );

CString hex( );
CString HEX( );
CString oct( );
CString udec( );
CString address( );

CString bools( );
CString tab( size_t Ntimes = 1 );
CString sp( size_t Ntimes = 1 );
CString letters( char lc , size_t Ntimes = 1 );

#define LOG(objectname)  {\
		CString strmessage;\
		static unsigned long icount = 0;\
		++icount;\
		strmessage.Format(_T("Run Path in %ldth times,The Class:$"), icount);\
		strmessage += " @";\
		strmessage += __func__;\
		strmessage += "()";\
		strmessage += " file: *";\
		strmessage += __FILE__;\
		objectname##.messagelog.push_back(strmessage);\
		}
#define LOGMESSAGE(objectname)  {\
		CString strmessage;\
		static unsigned long icount = 0;\
		++icount;\
		strmessage.Format(_T("Run Path in %ldth times,The Class:$"), icount);\
		strmessage += typeid(*this).name();\
		strmessage += " @";\
		strmessage += __func__;\
		strmessage += "()";\
		strmessage += " file: *";\
		strmessage += __FILE__;\
		objectname##.messagelog.push_back(strmessage);\
		}

#define SHOWSPLITLWINDOW(objectname)  {\
		objectname.m_pMainWnd->ShowWindow(SW_SHOW);\
		RECT rect;\
		rect.left = 0;\
		rect.top = 0;\
		rect.right = 1932;\
		rect.bottom = 2112;\
		objectname.m_pMainWnd->SetWindowPos(&CWnd::wndTop, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);\
		objectname.m_pMainWnd->UpdateWindow();\
		}
#define SHOWSPLITRWINDOW(objectname)  {\
		objectname.m_pMainWnd->ShowWindow(SW_SHOW);\
		RECT rect;\
		rect.left = 1932;\
		rect.top = 0;\
		rect.right = 1932;\
		rect.bottom = 2112;\
		objectname.m_pMainWnd->SetWindowPos(&CWnd::wndTop, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);\
		objectname.m_pMainWnd->UpdateWindow();\
		}

#define TEXTOUTDC(pdc,x,y,strmessage,text) {\
		CDC* pdc= this->GetWindowDC();\
		CDC& dc = *pdc;\
		int ix=x;\
		int iy=y;\
		CAtlString strmessage;\
		strmessage.Format(_T(#text));\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		dc.TextOut(ix, iy, strmessage);\
		}
#define TEXTFORMATOUTDC(dc,x,y,ftstr,value) {\
		int ix=x;\
		int iy=y;\
		CAtlString strmessage;\
		strmessage.Format(_T(#ftstr),value);\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		dc.TextOut(ix, iy, strmessage);\
		}
#define TEXTOUTCSTR(pdc,x,y,Cstrmessage) {\
		CDC* pdc= this->GetWindowDC();\
		CDC& dc = *pdc;\
		int ix=x;\
		int iy=y;\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		dc.TextOut(ix, iy, Cstrmessage);\
		}
#define PRINTSCREEN(x,y,strmessage) {\
		CDC* pdc= this->GetWindowDC();\
		int ix=x;\
		int iy=y;\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		pdc->TextOut(ix, iy, CString(_T(#strmessage)));\
		}
#define COUTTS(str) {\
		CDC* pdc= this->GetWindowDC();\
		CAtlString strmessage;\
		strmessage=_T(str);\
		int ix=position.x;\
		int iy=position.y;\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		pdc->TextOut(ix, iy,strmessage);\
		}
#define COUTCS(dc,strmessage) {\
		int ix=position.x;\
		int iy=position.y;\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		dc.TextOut(ix, iy,strmessage);\
		}
#define SFOUT(dc,ftstr,value) {\
		int ix=position.x;\
		int iy=position.y;\
		CAtlString strmessage;\
		strmessage.Format(_T(#ftstr),value);\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		dc.TextOut(ix, iy, strmessage);\
		}
#define MAKEMENUITEM(fname,menumap)  { string str=#fname;\
					pfunc p=fname;\
					menumap.insert(make_pair(str,p));}

//²âÊÔ×Ö·û´®ÊÇ·ñÎª¿ÕµÄºê
#ifndef isempty
#define isempty(astr) ((astr) == (_T("")))
#endif // !empty

//²¼¶û²âÊÔºê

#ifndef isok
#define isok(a) ((a)==true)
#endif	

#define errmessage(err)  {\
		CAtlString strmessage=_T("#err:");\
		strmessage +=_T(#err"in ");\
		strmessage += __func__;\
		strmessage += _T("()");\
		AfxMessageBox(strmessage);\
		}

#define locationmessage  cout<<st( file is:)<<__FILE__<<sp<<st( line# is :)<< __LINE__<<sp<<st(function is :) <<__func__<<endl;

#ifndef st

#define st(...)		(_T(#__VA_ARGS__))

#define xsms(...)	getcout;cout.settcolor(dccr.midgreenblue);\
					cout<<#__VA_ARGS__<<endl;\
					cout.resettcolor( );
#define sms(...)	cout.settcolor(dccr.midgreenblue);\
					cout<<#__VA_ARGS__<<endl;\
					cout.resettcolor( );
#define smi(...)	cout<<st(__VA_ARGS__)<<endl;
#define smn(...)	cout<<st(__VA_ARGS__)<<sp;


#endif	

#ifndef strbox

#define strbox(OK) AfxMessageBox(_T(#OK))

#endif	

#define vec(T) vector<T> 

#define bigtosmall true
#define smalltobig false
#define UP true
#define UPPER true
#define LOWER false
#define LOW false
#define DOWN false
#define RESET -1
#define REVERSE -2
#define KEEPSTATUS -3
#define NOT !
#define nonull(v) (( (v )!=nullptr )&&((&v)!=nullptr ) )

#define NTIME(N)  for(size_t ix=0;ix<(N);++ix)
#define STEP(I,STEP,N)  for(size_t (ix)=I;(ix)<(N);ix+=(STEP))
#define STEPTO(I,STEP,N)  for(size_t (ix)=I;(ix)<=(N);ix+=(STEP))
#define UNTIL(N) for(size_t ix=0;ix++<(N);)
#define FORTO(I,N) for(size_t ix=(I);ix<=(N);++ix)
#define FORDOWNTO(N,I) for(size_t ix=(N);ix>=(I);--ix)
#define pointer *
#define NOTHING
#define EMPTY(...) 
#define ref &

#define gett(name)  decltype(name)
#define getI(name)  gett(name.begin())
#define getCI(name)  gett(name)::const_iterator
#define ALL(V)  V.begin(),V.end()
#define FORALL(V,iterator)  for(getCI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORALLW(V,iterator)  for(getCI(V) V##iterator = V.begin(); V##iterator != V.end();++V##iterator)
#define FORN(N,icountn)  for(size_t icountn=0;icountn<(N);++icountn)
#define FORV(ielement,V)  for(const auto &ielement:V)
#define FORW(ielement,V)  for(auto &ielement:V)

#define makedc(cout)  unique_ptr<PCDC> me_unique_dc=make_unique<PCDC>((CWnd*)this); PCDC & cout=*me_unique_dc;
#define makemedc(DC)  unique_ptr<PCDC> pdcxxx(new PCDC(this));PCDC& DC = *pdcxxx;
#define SimulationStdCout  auto cout_me_ptr=make_unique<PCDC>((CWnd*)this);auto& cout= *cout_me_ptr;pcout=&*cout_me_ptr;cout.resettcolor();
#define coutExtSetSimulation  SimulationStdCout;pcout=&cout;
#define getcout PCDC &cout=*pcout;

#define sst(code,...)  #code##","#__VA_ARGS__;

#define code(...)	cout.settcolor(dccr.smokewhite);\
					cout<<"{ "#__VA_ARGS__<<L" }"<<el;\
					cout.resettcolor();\
					__VA_ARGS__;
#define lcode(...)	cout.settcolor(dccr.smokewhite);\
					cout.title(L"sourece codes",LOWER);\
					cout<<"{ "#__VA_ARGS__<<L" }"<<el;\
					cout.title(L"run result",LOWER);\
					cout.resettcolor();\
					__VA_ARGS__;

#define showcode(...)	lcode(__VA_ARGS__)
#define showcodes(...)	lcode(__VA_ARGS__)
#define lscode(...)  lcode(__VA_ARGS__)

#define SHOW(name) cout<<st(name)<<_T("  is: ")<<name<<tab
#define showv(vname) cout<<st(vname)<<_T(" value: ")<<vname<<sp<<_T(" type: ")<<(typeid(vname).name())<<sp
#define showtype(...)  cout<<#__VA_ARGS__<<":  type: ";\
						cout<< typeid( ##__VA_ARGS__ ).name( );\
						cout<<"  size: ";\
						cout.settcolor( dccr.gteal );\
						cout<<sizeof(##__VA_ARGS__);\
						cout.resettcolor();\
						cout<<"  HASH :"<<typeid(##__VA_ARGS__).hash_code()<<el

#define RUNTEST(message)		cout.clearscreen();TITLE(message);
#define TITLE(message)      cout.title(CString(st(message)));

#define Mptr(va,tp) unique_ptr<tp>va=make_unique<tp>();
#define Msptr(va,tp) shared_ptr<tp>va=make_shared<tp>();
#define Mptrs(va,tp,n) unique_ptr<tp[]>va=make_unique<tp[]>(n);
#define Msptrs(va,tp,n) shared_ptr<tp[]>va=make_shared<tp[]>(n);

//printsource(¡ª__FILE__,__LINE__);
	//#define comment printsource(__FILE__,__LINE__);
	//#define comments(nline) printsource(¡ª__FILE__,__LINE__,nline);
	//#define endcomment printsourceend((__FILE__,__LINE__);


class PCDC : public CDC
{
public:
	bool icreate = false;
	size_t id = 0;
	static size_t icount;
	int iargs = 0;
	bool ibegin = true;

public:
	LONG wbar = 8;
	const LONG initalpos = wbar + 35;
	const LONG initalstep = 20;
	LONG step = initalstep;
	POINT p = { initalpos, initalpos };
	CRect mrect;
	CSize msize;
	int ilinemod = 20;
	bool icutline = false;

public:
	COLORREF m_bk = dccr.grey;
	//COLORREF m_tk = dccr.greenblue;
	COLORREF m_tk = dccr.chocolate;
	//COLORREF m_tk = dccr.bluered;
	//COLORREF m_bark = dccr.chocolate;
	//COLORREF m_bark = dccr.mteal;
	COLORREF m_bark = dccr.lteal;
	//COLORREF m_bark = dccr.bluered;
	//COLORREF m_bark = dccr.smokered;
	//COLORREF m_bark = dccr.lbluered;
	COLORREF m_linek = dccr.azure;
	int mfontsize = 120;
	CFont font , * pfont;

public:
	CDC* m_cdc = nullptr;
	CWnd* m_pwnd = nullptr;

public:
	char mlinechar = _T( '-' );
	char mmarkchar = '=';
	CString spchar = _T( "  " );
	CString ms;
	CString opstr;

public:
	PCDC( CWnd* pwnd = nullptr );
	PCDC& Create( CWnd* pwnd );
	PCDC& Release( );
	~PCDC( );

	//explicit operator char *() const;

public:
	PCDC& operator<<( const char c );
	PCDC& operator<<( signed char c ) { return ( *this ) << (const char)c; };
	PCDC& operator<<( unsigned char c ) { return ( *this ) << (const char)c; };
	PCDC& operator<<( char cs[ ] );
	PCDC& operator<<( char const cs[ ] );
	PCDC& operator<<( signed char const cs[ ] ) { return ( *this ) << (const char*)cs; };
	PCDC& operator<<( unsigned char const cs[ ] ) { return ( *this ) << (const char*)cs; };
	PCDC& operator<<( LPCTSTR s );
	PCDC& operator<<( const std::string& s );
	PCDC& operator<<( const std::wstring& s );
	PCDC& operator<<( const CString& s );
	PCDC& operator<<( const CAtlString& s );
	PCDC& operator<<( const bool b );
	PCDC& operator<<( const int n );
	PCDC& operator<<( const unsigned int n );
	PCDC& operator<<( const long int n );
	PCDC& operator<<( const unsigned long int n );
	PCDC& operator<<( const long long n );
	PCDC& operator<<( const float n );
	PCDC& operator<<( const double n );
	PCDC& operator<<( const long double n );
	PCDC& operator<<( const size_t n );
	template <typename A , typename ...X , typename R>
	PCDC& operator<<( R( A::* p )( X... ) );
	PCDC& operator<<( std::nullptr_t p );

	PCDC& operator<<( PCDC& dc ) {
		if ( this == &dc )
		{
			return *this;
		}
		else
		{
			return dc;
		}
	};

public:
	PCDC& operator<< ( PCDC& ( *op ) ( PCDC& dc ) );

public:
	inline const CSize& imresizeout( const CString& cs )
	{
		m_pwnd->GetClientRect( &mrect );
		msize = GetOutputTextExtent( cs );

		CString news( 'x' );
		auto size = GetOutputTextExtent( news );

		LONG linelen = mrect.right - mrect.left - initalpos * 2;
		LONG strlen = msize.cx;
		int cslen = cs.GetLength( );
		news = cs;
		CString heads;
		CString tails;
		int tkpos = cslen * linelen / strlen - 1;
		if ( strlen > ( linelen - size.cx ) ) {
			for ( int i = cslen; i >= 0; i -= tkpos )
			{
				heads = news.Mid( 0 , tkpos );
				tails = news.Mid( tkpos , news.GetLength( ) );
				imresizeout( heads );
				news = tails;
			}
		}
		else {
			if ( p.x + msize.cx >= mrect.right - mrect.left - initalpos )
			{
				p.x = mrect.left + initalpos;
				p.y += step;
			}
			if ( p.y >= mrect.bottom - mrect.top - initalpos )
			{
				this->FillSolidRect( mrect , m_bk );
				this->clearscreen( );
				p.y = mrect.top + initalpos + wbar;
			}
			//need recalc ned***
			TextOut( p.x , p.y , cs );
			p.x += msize.cx;
		}
		return msize;
	}
	PCDC& resettcolor( );
	PCDC& tb( size_t t = 1 , char c = '\t' ) { NTIME( t )* this << c; return *this; }
	PCDC& settcolor( COLORREF tk );
	PCDC& setcolor( COLORREF line , COLORREF bar , COLORREF bk , COLORREF tk );
	PCDC& setimod( int imod );
	template <typename T = CString>
	PCDC& title( T t , bool ib = true );
	char setlinechar( const char& c = '=' );
	PCDC& clearscreen( const CRect* r = nullptr , const COLORREF* cr = nullptr );
	PCDC& location( )
	{
		return *this << __FILE__ << sp << __LINE__ << sp << __func__ << endl;
	};

public:
	template <typename A>
	PCDC& operator%( const tuple<A>& tup )
	{
		return( *this ) << "  :" << get<0>( tup ) << "  ;";
	}
	template <typename A , typename... Args>
	PCDC& operator%( const tuple<A , Args...>& tup )
	{
		*this << "  :" << get<0>( tup );
		return ( *this ) % ( tup._Get_rest( ) );
	}

	template <typename A , typename B> PCDC& operator||( const tuple<A , B>& tup );
	template <typename... Args> PCDC& operator||( const tuple<Args...>& tup );

	template <typename A , typename B> PCDC& operator|( const tuple<A , B>& tup );
	template <typename A , typename... Args> PCDC& operator|( const tuple<A , Args...>& tup );

	template <typename T> PCDC& operator [] ( const tuple<T>& tupa );
	template <typename... Args> PCDC& operator [] ( const tuple<Args...>& tupa );
	template <typename... Args> PCDC& operator<<( tuple<Args...> tup );
	template <>
	PCDC& operator<<( tuple<> tup ) { ibegin = true; return ( *this ) << " }"; }

	template <typename T> PCDC& operator ()( T t ) { return ( *this ) << t; };
	template <typename X> PCDC& operator <<( const unique_ptr<X>& unptr );
	template <typename T> PCDC& operator <<( const complex<T>& z );
	template <typename T> PCDC& operator ()( initializer_list<T> c );
	template <typename P> PCDC& operator <<( P* p );
	template <typename P> PCDC& operator <<( const P* p );
	template <typename T> PCDC& operator<<( initializer_list<T> c );
	template <typename T> PCDC& operator <<( const list<T>& l );
	template <typename T , size_t len> PCDC& operator <<( const array< T , len>& a );
	template <typename A , typename B> PCDC& operator <<( const pair<A , B>& i );
	template <typename... X> PCDC& operator <<( const vector<X...>& v );
	template <typename ...T> PCDC& operator <<( const deque<T...>& d );
	template <typename T , typename X> PCDC& operator <<( const map<T , X>& m );
	template <typename T , typename X> PCDC& operator <<( const multimap<T , X>& m );
	template <typename ...T> PCDC& operator <<( const set<T...>& s );
	template <typename... T> PCDC& operator <<( const multiset<T...>& s );
	template <typename  int N = 64> PCDC& operator <<( bitset<N>& bits );
	template <typename  int N = 64> PCDC& operator <<( const bitset<N>& bits );

public:
	template <typename T> T& MakeEleRandom( T& rc , const size_t elesize = 20 , const int mod = 10 );
	template <typename S = size_t> void linemod( S l , S linemod , PCDC& ( *op )( PCDC& ) = el , char* stail = nullptr );
	template <typename T , size_t N = std::tuple_size<T>::value> PCDC& disptup( T t );
	template <typename A , typename B> bool comp( A a , B b ) { return a > b; };

	template <typename T> PCDC& forprintr( const T* b , const T* e );
	template <typename T> PCDC& forprintv( const T& v );
	template <typename T> PCDC& forprintm( const T& m );
	template <typename T> PCDC& forprinta( const T* arr , size_t len );

	PCDC& adress( ) { *this << st( address( ) ) << sp; return *this; };

	template <typename X> PCDC& address( X& a );
	template <typename T , typename ...X> PCDC& address( T& a , X&...args );
	template <typename X> PCDC& value( X* a );
	template <typename T , typename ...X> PCDC& value( T* a , X*...args );

	PCDC& type( ) { return *this; };
	template <typename T > PCDC& type( T& a );
	template <typename T > PCDC& type( T&& a );
	template <typename T , typename ...X> PCDC& type( T& a , X&...args );
	template <typename T , typename ...X> PCDC& type( T&& a , X&&...args );
	template <typename ...A , template<typename ...T> typename B> PCDC& TypeCount( B<A...> a );

	template <typename X> PCDC& pt( X a );
	template <typename T , typename ...X> PCDC& pt( T a , X...args );
	template <typename X> PCDC& pc( X a );
	template <typename T , typename ...X> PCDC& pc( T a , X...args );
	template <typename X> PCDC& pb( X a );
	template <typename T , typename ...X> PCDC& pb( T a , X...args );
	PCDC& pl( ) { return *this; }
	template <typename T , typename ...X> PCDC& pl( T a , X...args );

public:
	PCDC& displayfile( CString filename );
	template <typename T , typename ...X> PCDC& prints( T a , X...args );

public:
	PCDC& args( )
	{
		*this << __func__ << "  args4#" << iargs++ << el;
		return *this;
	}
	template <typename X>
	PCDC& args( X&& a )
	{
		*this << __func__ << "  args3#" << iargs++ << el;
		return *this;
	}
	template <typename... X>
	PCDC& args( X&&...Args )
	{
		*this << __func__ << "  args2#" << iargs++ << " sizeof is: " << sizeof...( Args ) << el;
		args( (X&&)Args... );
		return *this;
	}
	template <typename T , typename... X>
	PCDC& args( T a , X&&...Args )
	{
		*this << __func__ << " args1# " << iargs++ << " sizeof is: " << sizeof...( Args ) << el;
		args( (X&&)Args... );
		return *this;
	}

public:

};

template <typename A , typename B>
PCDC& PCDC::operator||( const tuple<A , B>& tup )
{
	return ( *this ) << get<0>( tup ) << '|' << get<1>( tup ) << '|';
}

template <typename... Args>
PCDC& PCDC::operator||( const tuple<Args...>& tup )
{
	*this << '|' << get<0>( tup );
	return ( *this ) || ( tup._Get_rest( ) );
}

template <typename A , typename B>
PCDC& PCDC::operator|( const tuple<A , B>& tup )
{
	//*this << "tuple<AB>";// << sizeof(tuple<>) << tab << sizeof(tup) << tab << tuple_size<decltype(tup)>::value << el;
	return ( *this ) << "{" << get<0>( tup ) << "}|{" << get<1>( tup ) << "}";
}

template <typename A , typename... Args>
PCDC& PCDC::operator|( const tuple<A , Args...>& tup )
{
	*this << "{" << get<0>( tup ) << "}|";
	return ( *this ) | ( tup._Get_rest( ) );
}

template<typename T>
PCDC& PCDC::operator [] ( const tuple<T>& tupa )
{
	return ( *this ) << "[" << tupa._Myfirst._Val << "]";
}

template <typename... Args>
PCDC& PCDC::operator [] ( const tuple<Args...>& tupa )
{
	*this << "[" << tupa._Myfirst._Val << "], ";
	return ( *this )[tupa._Get_rest( )];
};

template <typename A , typename ...X , typename R>
PCDC& PCDC::operator<<( R( A::* p )( X... ) )
{
	//( __thiscall A::*p )| ( __cdecl A::*p )
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template<typename P>
PCDC& PCDC::operator <<( const P* p )
{
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template<typename P>
PCDC& PCDC::operator <<( P* p )
{
	if ( p == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , p );
	}
	imresizeout( ms );
	return *this;
}

template <typename X>
PCDC& PCDC::operator <<( const unique_ptr<X>& unptr )
{
	ms.Format( _T( "%p" ) , unptr.get( ) );
	imresizeout( ms );
	return *this;
}

template <typename A , typename B>
PCDC& PCDC::operator <<( const pair<A , B>& i )
{
	*this << "{ " << i.first << ", " << i.second << "}   ";
	return *this;
}

template <typename T , size_t len>
PCDC& PCDC::operator <<( const array<T , len>& a )
{
	if ( len == 0 || &a == nullptr )
		return *this;
	else
		return forprintv( a );
}

template <typename... X>
PCDC& PCDC::operator <<( const vector<X...>& v )
{
	if ( v.empty( ) )
		return *this;
	else
		return forprintv( v );
}

template <typename... T>
PCDC& PCDC::operator <<( const deque<T...>& d )
{
	if ( d.empty( ) )
		return *this;
	else
		return forprintv( d );
}

template <typename T , typename X>
PCDC& PCDC::operator <<( const map<T , X>& m )
{
	if ( !m.size( ) )
		return *this;
	else
		return forprintm( m );
}

template <typename T , typename X>
PCDC& PCDC::operator <<( const multimap<T , X>& m )
{
	if ( !m.size( ) )
		return *this;
	else
		return forprintm( m );
}

template <typename...T>
PCDC& PCDC::operator <<( const multiset<T...>& s )
{
	if ( !s.size( ) )
		return *this;
	else
		return forprintv( s );
}

template <typename ...T>
PCDC& PCDC::operator <<( const set<T...>& s )
{
	if ( !s.size( ) )
		return *this;
	else
		return forprintv( s );
}

template <typename T>
PCDC& PCDC::operator <<( const list<T>& l )
{
	if ( !l.size( ) )
		return *this;
	else
		return forprintv( l );
}

template <typename T >
PCDC& PCDC::operator <<( const complex<T>& z )
{
	return ( *this ) << z.real( ) << '+' << z.imag( ) << 'i';
};

template <typename... Args>
PCDC& PCDC::operator<<( tuple<Args...> tup )
{
	if ( ibegin == true ) {
		*this << "{ ";
		ibegin = false;
	}
	*this << "{" << tup._Myfirst._Val;
	if constexpr ( tuple_size<decltype( tup )>::value == 1 )
	{
		*this << '}';
	}
	else
	{
		*this << "}, ";
	}
	return ( *this ) << ( tup._Get_rest( ) );
}

template<typename T >
PCDC& PCDC::operator ()( initializer_list<T> c )
{
	T ibegin = *c.begin( ) - *c.begin( );
	forprintv( c );
	return *this;
}

template<typename T >
PCDC& PCDC::operator<<( initializer_list<T> c )
{
	T ibegin = *c.begin( ) - *c.begin( );
	forprintv( c );
	return *this;
}

template <typename  int N>
PCDC& PCDC::operator <<( bitset<N>& bits )
{
	string str = bits.to_string( );
	ms = str.c_str( );
	imresizeout( ms );
	return *this;
}

template <typename  int N>
PCDC& PCDC::operator <<( const bitset<N>& bits )
{
	string str = bits.to_string( );
	ms = str.c_str( );
	imresizeout( ms );
	return *this;
};

template<typename T , size_t N>
PCDC& PCDC::disptup( T t )
{
	constexpr size_t M = std::tuple_size<T>::value;
	constexpr size_t I = M - N;
	if constexpr ( N == 1 )
	{
		*this << "{" << std::get<I>( t ) << " }";
		return *this;
	}
	else
	{
		*this << " {" << std::get<I>( t ) << " },";
		disptup<T , N - 1>( t );
	}
	return *this;
};

template<typename T>
T& PCDC::MakeEleRandom( T& rc , const size_t elesize , const int mod )
{
	srand( time( nullptr ) );
	if ( rc.size( ) < elesize )
		rc.resize( elesize );
	for ( auto& i : rc )
		i = rand( ) % mod;
	return rc;
}

template <typename T >
PCDC& PCDC::type( T& a )
{
	*this << "type:  " << typeid( (T&&)a ).name( ) << "  size:  ";
	settcolor( dccr.gteal );
	*this << sizeof( a );
	resettcolor( );
	*this << "  HASH: " << typeid( (T&&)a ).hash_code( ) << el;
	return *this;
};

template <typename T >
PCDC& PCDC::type( T&& a )
{
	*this << "type:  " << typeid( (T&&)a ).name( ) << "  size:  ";
	settcolor( dccr.gteal );
	*this << sizeof( (T&&)a );
	resettcolor( );
	*this << "  HASH: " << typeid( (T&&)a ).hash_code( ) << el;
	return *this;
};

template<typename ...A , template<typename ...T> typename B>
PCDC& PCDC::TypeCount( B<A...> a )
{
	*this << "type:  " << typeid( a ).name( );
	*this << "  size:  " << sizeof( a );
	*this << "  HASH: " << typeid( a ).hash_code( );
	settcolor( dccr.midyellow );
	*this << " A<T...> T...count is :" << sizeof...( A ) << sp;
	resettcolor( );
	return *this;
}

template <typename T>
PCDC& PCDC::title( T t , bool i )
{
	CString ts( t );
	if ( ts.IsEmpty( ) )
	{
		ts = _T( "BEGIN TEST" );
	};
	if ( i == UPPER )
	{
		ts.MakeUpper( );
	}
	else {
		ts.MakeLower( );
	}
	CString cs;
	cs = mmarkchar;
	PCDC& dc = *this;
	CSize size = dc.GetOutputTextExtent( cs );
	dc.m_pwnd->GetClientRect( &dc.mrect );
	auto w = dc.mrect.right - ( dc.mrect.left + dc.initalpos * 2 );
	size_t icount = w / size.cx - ts.GetLength( ) - 2;
	//icount /= 2;
	for ( size_t i = 0; i < ( icount / 2 ); ++i )
	{
		cs += this->mlinechar;
	}
	cs += ts;
	for ( size_t i = 0; i < ( icount - icount / 2 ); ++i )
	{
		cs += this->mlinechar;
	}
	cs += mmarkchar;
	imresizeout( cs );
	( *this ) << el;
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pl( T a , X...args )
{
	*this << a << '\n';
	pl( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pt( X a )
{
	*this << a << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pt( T a , X...args )
{
	*this << a << '\t';
	pt( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pc( X a )
{
	*this << a << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::pc( T a , X...args )
{
	*this << a << ", ";
	pc( args... );
	return *this;
}

template <typename X>
PCDC& PCDC::pb( X a )
{
	*this << '{' << a << "}" << '\n';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::prints( T a , X...args )
{
	*this << a;
	if constexpr ( ( sizeof...( X ) ) == 0 )
	{
		return *this;
	}
	else
	{
		return prints( args... );
	}
}

template <typename T , typename ...X>
PCDC& PCDC::pb( T a , X...args )
{
	*this << '{' << a << "},";
	return pb( args... );
}

template <typename X>
PCDC& PCDC::value( X* a )
{
	//*this << st( T* ) << sp;
	*this << *a << sp;
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::value( T* a , X*...args )
{
	//*this << ( sizeof...( args ) ) << st( T... ) << sp;
	*this << *a << sp;
	return value( args... );
}

template <typename X>
PCDC& PCDC::address( X& a )
{
	//*this << st( T& ) << sp;
	if ( &a == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , &a );
	}
	imresizeout( ms );
	*this << '\t';
	return *this;
}

template <typename T , typename ...X>
PCDC& PCDC::address( T& a , X&...args )
{
	//*this << ( sizeof...( args ) ) << st( T... ) << sp;
	if ( &a == nullptr )
	{
		ms = "nullptr";
	}
	else
	{
		ms.Format( _T( "[0x%p]" ) , &a );
	}
	imresizeout( ms );
	return address( args... );
}

template <typename T , typename ...X>
PCDC& PCDC::type( T& a , X&...args )
{
	type( (T&&)a );
	return type( (X&&)args... );
}

template <typename T , typename ...X>
PCDC& PCDC::type( T&& a , X&&...args )
{
	type( (T&&)a );
	return type( (X&&)args... );
}

template <typename S>
void PCDC::linemod( S l , S linemod , PCDC& ( *op )( PCDC& ) , char* stail )
{
	if ( l % linemod == 0 )
	{
		( *op )( *this );
		if ( stail )
			*this << stail;
	}
}

template<typename T>
PCDC& PCDC::forprintr( const T* b , const T* e )
{
	int il = 0;
	for ( const auto* it = b; it != e; ++it )
	{
		*this << *it << spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template<typename T>
PCDC& PCDC::forprintv( const T& v )
{
	int il = 0;
	for ( const auto& i : v )
	{
		*this << i << spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template<typename T>
PCDC& PCDC::forprintm( const T& m )
{
	int il = 0;
	for ( const auto& i : m )
	{
		*this << i;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template<typename T>
PCDC& PCDC::forprinta( const T* arr , size_t len )
{
	int il = 0;
	for ( size_t i = 0; i < len; ++i )
	{
		*this << *( arr + i ) << spchar;
		linemod( ++il , ilinemod );
	}
	return *this;
}

template <typename T>
CString address( T* p )
{
	//getcout;
	//cout << st( T* ) << sp;
	CString cs;
	if ( p == nullptr )
	{
		cs = "nullptr";
	}
	else
	{
		cs.Format( _T( "[0x%p]" ) , p );
	}
	return cs;
}

template <typename T , typename ...X>
CString address( T& a , X&...args )
{
	static CString cs;
	CString ms = address( &a );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ',' + address( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
}

template <typename T >
CString udec( T& t )
{
	CString cs;
	cs.Format( _T( "%lu" ) , t );
	return cs;
}

template <typename T , typename...X>
CString udec( T& t , X&...args )
{
	static CString cs;
	CString ms = udec( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + udec( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString oct( T& t )
{
	CString cs;
	cs.Format( _T( "%#lo" ) , t );
	return cs;
}

template <typename T , typename...X>
CString oct( T& t , X&...args )
{

	static CString cs;
	CString ms = oct( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + oct( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString HEX( T& t )
{
	CString cs;
	cs.Format( _T( "%#lX" ) , t );
	return cs;
}

template <typename T , typename...X>
CString HEX( T& t , X&...args )
{

	static CString cs;
	CString ms = HEX( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + HEX( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename B >
CString bools( B b )
{
	CString cs;
	if ( (bool)b == true )
	{
		cs = "true";
	}
	else
	{
		cs = "false";
	}
	return cs;
}

template <typename B , typename...X>
CString bools( B b , X...args )
{
	CString cs;
	cs += bools( b );
	if ( cs.GetLength( ) >= 4 )
	{
		cs += "  ";
	}
	cs += bools( args... );
	return cs;
};

template <typename T >
CString sizeos( T& t )
{
	CString cs;
	cs.Format( _T( "%lu" ) , sizeof( t ) );
	return cs;
}

template <typename T , typename...X>
CString sizeos( T& t , X&...args )
{
	static CString cs;
	CString ms = sizeos( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + sizeos( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T >
CString hex( T& t )
{
	CString cs;
	cs.Format( _T( "%#lx" ) , t );
	return cs;
}

template <typename T , typename...X>
CString hex( T& t , X&...args )
{
	static CString cs;
	CString ms = hex( t );
	if ( !ms.IsEmpty( ) )
	{
		cs += ms;
	}
	if constexpr ( ( sizeof...( args ) ) != 0 )
	{
		cs += ' ' + hex( args... );
	}
	ms = cs;
	cs.Empty( );
	return ms;
};

template <typename T>
bool swap( T& a , T& b )
{
	if ( ( a != nullptr ) && ( b != nullptr ) && ( &a != nullptr ) && ( &b != nullptr ) && ( &a != &b ) )
	{
		T c;
		c = a;
		a = b;
		b = c;
		return true;
	}
	return false;
}

template<typename T>
T gsum( initializer_list<T> v )
{
	T isum {};
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			isum += i;
		}
	}
	return isum;
}

template<typename A = long double , typename ...X>
auto gsum( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gsum<T>( il );
}

template<typename T>
T gmin( initializer_list<T> v )
{
	T imin = *v.begin( );
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			imin = min( imin , i );
		}
	}
	return imin;
}

template<typename A = long double , typename ...X>
auto gmin( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gmin<T>( il );
}

template<typename T>
T gmax( initializer_list<T> v )
{
	T imax = *v.begin( );
	if ( v.size( ) ) {
		for ( const auto& i : v )
		{
			imax = max( imax , i );
		}
	}
	return imax;
}

template<typename A = long double , typename ...X>
auto gmax( A a , X...args )
{
	using T = common_type_t<A , X...>;
	initializer_list<T>il { (T)a,(T)( args )... };
	return gmax<T>( il );
}

template<typename T = int , typename ...X>
T imax( X...args )
{
	initializer_list<T>il { (T)( args )... };
	return gmax<T>( il );
}

template<typename T = int>
bool itiszero( T a = T( ) )
{
	return a == T( );
}

template<typename T>
bool itisnull( T p )
{
	return ( ( nullptr == &p ) || ( p == T( ) ) );
}

template<typename T>
bool itisnull( T* p )
{
	return ( ( nullptr == p ) || ( *p == T( ) ) );
}

template<typename T = int>
bool itisempty( T a = T( ) )
{
	return a == T( );
}

template<typename T = int>
T lex( T a = T( ) )
{
	using O = decltype( T( ) );
	return O( a );
}

template<typename T = int>
T lexzero( T a = T( ) )
{
	return T( );
}

template<typename int ic = 100 , typename C>
auto sum( C c )
{
	C t;
	auto a = ( *c.begin( ) - *c.begin( ) );
	for ( size_t icount = 0; icount < ic; ++icount )
		t.insert( t.end( ) , *c.begin( ) );
	for ( auto i : t )
		a += i;
	return a;
}

template<typename T >
auto sum( vector<T> c )
{
	T isum = *c.begin( ) - *c.begin( );
	for ( auto i : c )
		isum += i;
	return isum;
}

template<typename T >
auto sum( initializer_list<T> c )
{
	T isum = *c.begin( ) - *c.begin( );
	for ( auto i : c )
		isum += i;
	return isum;
}

template<typename ...A , template<typename ...T> typename B>
size_t tpcount( B<A...> a )
{
	return  sizeof...( A );
}

template<typename T>
T& MakeSingleEleRandom( T& r , const int mod )
{
	return r = rand( ) % mod;
}

template<typename T>
bool MakeEleRandom( T& v , const int mod )
{
	srand( time( nullptr ) );
	if ( v.empty( ) )
		return false;
	for ( auto& i : v )
		MakeSingleEleRandom( i , mod );
	return true;
}
typedef int ( *pfunc )( PCDC& , string );

template <typename T , bool isup = true>
bool compare( T a , T b )
{
	static bool iset = false;
	if ( isup )
	{
		return a > b;
	}
	else
	{
		return a < b;
	}
}

template <typename T = int , bool isort = bigtosmall>
class icompset {
public:
	bool miset = true;
	T ivalset = 0;
	void* iptset = nullptr;
	bool ichceknull = false;

public:
	icompset( ) :miset( isort ) {
	};
	icompset& revese( bool set = true , bool toset = true )
	{
		if ( set )
			miset = !miset;
		else
			miset = toset;
		return *this;
	}
	icompset& sortset( bool set , T valset = 0 )
	{
		miset = set;
		ivalset = valset;
		return *this;
	}

	bool operator()( T c )const
	{
		if ( miset )
		{
			return c > ivalset;
		}
		else
		{
			return c < ivalset;
		}
	}

	bool operator()( T a , T b )const
	{
		if ( miset )
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}

	bool compare( T a , T b )const
	{
		if ( miset )
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}

	PCDC& operator()( CString name = _T( "noname" ) )
	{
		getcout;
		cout << name << tab << miset;
		return cout;
	};
};



