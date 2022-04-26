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

/*
size_t linelen = 80;

class clist;

class clist {
public:
	clist* pnext = nullptr;
	int* pdata = nullptr;
public:
	clist( int d = 0 )
	{
		pdata = new int;
		*pdata = d;
	}
	~clist( )
	{
		delete pdata;
		pnext = nullptr;
	}
	clist* getnextp( )
	{
		return pnext->pnext;
	};
	clist* setnextporaddnew( clist* p = nullptr )
	{
		if ( p == nullptr ) {
			pnext = new clist( 0 );
		}
		else
		{
			pnext = p;
		}
		return pnext->pnext;
	}
	int setdata( int d )
	{
		return *pdata = d;
	}
};// CSDIView 消息处理程序

class cre
{
public:
	cre( int m ) :int_mit( m )
	{
		me.push_back( &cre::one );
		menu.push_back( &( &cre::one ) );
		auto i = me[0];
		cout << "start mfun ......" << __func__ << endl;
		cout << "typeid(pFmp).name()" << typeid( pFmp ).name( ) << endl;
		cout << "typeid(pf).name()" << typeid( pf ).name( ) << endl;

		cout << "typeid(Fmp).name()" << typeid( Fmp ).name( ) << endl;
		cout << "typeid(&cre::one).name()" << typeid( &cre::one ).name( ) << endl;
		cout << "typeid(me[0]).name() " << typeid( me[0] ).name( ) << endl;
		cout << "typeid(i).name()" << typeid( i ).name( ) << endl;
		( *this.*me[0] )( );
		( this->*me[0] )( );

		( this->*i )( );
		( *this.*i )( );
		( this->*me.back( ) )( );
		cout << "*this.*i id is " << typeid( this ).name( ) << endl;
		cout << "end mfun ......" << __func__ << endl;
		system( "pause" );
	}
	void one( )
	{
		cout << "start " << __func__ << endl;
	}
	void two( )
	{
		cout << __func__ << endl;
	};
public:
	const int int_mit;
	static const int maxint_mit = 100;
	typedef decltype( &cre::one )* pFmp;
	typedef decltype( &cre::one ) Fmp;
	typedef void ( *pf )( );
	vector<pFmp> menu;
	vector<Fmp> me;
};

class Spk
{
public:
	Spk( ) :mcint( 0 )
	{
		name = "  null";
		cout << "start mfun ......" << __func__ << name << endl;
	}
	Spk( int m ) :mcint( m ) , mint( m )
	{
		name = "  null";
		cout << "start  mfun ......" << __func__ << "(int m)" << name << "#" << mint << endl;
	}
	Spk( string  nm ) :mcint( 0 ) , name( nm ) , mint( 0 )
	{
		cout << "start mfun ......" << __func__ << "(name)" << name << endl;
	}
	Spk( const Spk& r ) :mcint( r.mcint )
	{
		cout << "start mfun ......" << __func__ << "(const Spk&)" << name << endl;
	}
	Spk& operator =( const Spk& r )
	{
		cout << "start mfun ......" << __func__ << "=(const Spk&) " << name << endl;
		return *this;
	}
	~Spk( )
	{
		cout << "start mfun ......" << __func__ << name << endl;
	}
	void one( )
	{
		cout << "start mfun ......" << __func__ << name << endl;
	}
	void two( )
	{
		cout << "start mfun ......" << __func__ << name << endl;
	};
	void speak( string str )
	{
		cout << str << "  start mfun ......" << __func__ << " adress is " << this << name << " #" << mint << endl;
	};
	void setname( string nm )
	{
		name = nm;
		cout << "start mfun ......" << __func__ << name << endl;
	}
	void setm( int n )
	{
		mint = n;
		//cout << "start mfun ......" << __func__ << name << " #"<<mint << endl;
	}
public:
	int mint;
	const int mcint;
	string name;
	static const int mstint = 100;
	typedef decltype( &cre::one ) Fmp;
	vector<Fmp> me;
};

class NewMan;

class NewMan
{

public:
	NewMan( int age ) :meage( age )
	{

	}
	static int sayage( class NewMan* me )
	{
		cout << me->meage << endl;
		return me->meage;
	}
	void say( )
	{
		sayage( this );
	}

private:
	int meage;
};

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

using fPF = int ( * )( int , char** );
using ffP = int( int , char** );

inline const char* datenow( int i = 1 )
{
	if ( i == 1 )
		cout << __DATE__ << endl;
	return __DATE__;
}

inline const char* timenow( int i = 1 )
{
	if ( i == 1 )
		cout << __TIME__ << endl;
	return __TIME__;
}

inline const int  line( int i = 1 )
{
	if ( i == 1 )
		cout << __LINE__ << endl;
	return __LINE__;
}

inline const char* filename( int i = 1 )
{
	if ( i == 1 )
		cout << __FILE__ << endl;
	return __FILE__;
}

inline const char* funname( int i = 1 )
{
	if ( i == 1 )
		cout << __func__ << endl;
	return __func__;
}
template <typename T>
T* arrayset( T* const ar , const size_t size , const T x )
{
    for ( size_t i = 0; i < size; ++i )
        ar[i] = x;
    return ar;
}

template <typename T>
void arrayprintadress( T* ar , size_t size )
{
    for ( size_t i = 0; i < size; ++i )
    {
        cout << "ar[i] adress is " << &ar[i] << '\t' << "value is " << ar[i] << endl;
        cout << "ar+i adress is " << ar + i << '\t' << "value is " << *( ar + i ) << endl;
    }
}

template <typename T>
void arrayprint( T* ar , size_t size , int lc = 10 )
{
    int l = 0;
    if ( ar == nullptr )
        return;
    for ( size_t i = 0; i < size; ++i )
    {
        cout << ar[i] << '\t';
        if ( ++l % lc == 0 )
            cout << endl;
    }
    cout << endl;
}

template <typename T>
T* safemalloc( size_t memsize , size_t elesize = 1 )
{
    void* p = nullptr;
    p = malloc( memsize * elesize );
    if ( !p )
        cout << "malloc fail..." << endl;
    else
        cout << "in adress: " << p << " malloc " << memsize * elesize << "  byte memory in " << __func__ << " T size is " << sizeof( T ) << endl;
    return (T*)p;
}

template <typename T>
T*& safefree( T*& p )
{
    cout << "safefree " << p << __func__ << endl;
    if ( p )
        free( p );
    p = nullptr;
    return p;
}

template <typename T>
T foreach( T* b , T* e , bool ( *Fun )( T* r ) )
{
    for ( auto i = b; i != e; ++i )
        Fun( i );
    return *b;
}

template <typename T>
void MakeSingleEleRandom( T& r , const int mod )
{
    r = rand( ) % mod;
}

template <class X , class Y>
class Lion
{
public:
    int teeth;
    string* name;
    unsigned age;
    Lion( )
    {
        cout << typeid( *this ).name( ) << tab << "lion is borning no argument constroator...." << endl;
        name = nullptr;
        age = 0;
    }
    Lion( X oname , Y oage )
    {
        cout << typeid( *this ).name( ) << tab << "lion is borning ...." << endl;
        name = new string( oname );
        age = oage;
    }
    Lion( const Lion& r )
    {
        cout << typeid( *this ).name( ) << tab << "Lion(const Lion &r)" << endl;
        this->teeth = r.teeth;
        this->age = r.age;
        name = new string( *r.name );
    }
    Lion& operator=( const Lion& r )
    {
        cout << typeid( *this ).name( ) << tab << "Lion=" << endl;
        this->teeth = r.teeth;
        this->age = r.age;
        this->sex = r.sex;
        if ( name != nullptr )
            delete name;
        name = new string( *r.name );
        return *this;
    }
    ~Lion( )
    {
        cout << typeid( *this ).name( ) << tab << "~lion is vanish...." << endl;
        delete name;
    }
    void yell( )
    {
        cout << typeid( *this ).name( ) << tab << "OwOw....." << endl;
    }
    void yell( const Lion& r )
    {
        cout << "r sex is  " << r.sex << endl;
    }
protected:
    int killn;
private:
    int sex;
};

template <class X>
class demoArray
{
private:
    X* h_ArrayMem;
    unsigned int maxsize = 1000;
protected:
    unsigned int memsize;
    unsigned int currentsize;

public:
    demoArray( ) :currentsize( 0 ) , memsize( 10 ) , h_ArrayMem( nullptr )
    {
        h_ArrayMem = new X[memsize];
        for ( int i = 0; i < memsize; ++i )
            h_ArrayMem[i] = 0;
        cout << __func__ << endl;
    }

    demoArray( const unsigned int isize )
    {
        if ( isize >= maxsize )
            memsize = maxsize;
        else
            memsize = isize;
        h_ArrayMem = new X[memsize];
        for ( int i = 0; i < memsize; ++i )
            h_ArrayMem[i] = 0;
        currentsize = 0;
        cout << __func__ << endl;
    }

    demoArray( const demoArray& r )
    {
        h_ArrayMem = new X[r.memsize];
        for ( int i = 0; i < r.currentsize; ++i )
            h_ArrayMem[i] = r.h_ArrayMem[i];
        cout << __func__ << endl;
    }

    demoArray& operator=( const demoArray& r )
    {
        if ( h_ArrayMem != nullptr )
            delete[ ]h_ArrayMem;
        currentsize = r.currentsize;
        memsize = r.memsize;
        maxsize = r.maxsize;
        h_ArrayMem = new X[memsize];
        for ( int i = 0; i < r.currentsize; ++i )
            h_ArrayMem[i] = r.h_ArrayMem[i];
        cout << __func__ << endl;
        return *this;
    }

    ~demoArray( )
    {
        cout << __func__ << endl;
        if ( h_ArrayMem )
            delete[ ] h_ArrayMem;
    }

    X& operator=( const X r )
    {
        cout << __func__ << endl;
        return r;
    }

    X& operator[]( const unsigned int i )const
    {
        cout << __func__ << endl;
        if ( i < memsize )
            return h_ArrayMem[i];
    }

    bool list( const unsigned int start = 0 , const unsigned int end = 0 )
    {
        if ( end == 0 )
        {
            for ( int i = 0; i < memsize; ++i )
            {
                cout << h_ArrayMem[i] << " ";
                if ( ( i + 1 ) % 10 == 0 )
                    cout << endl;
            }
            cout << endl;
        }
        return true;
    }

    bool pushback( X iu )
    {
        bool isscusses = false;
        if ( currentsize < memsize )
        {
            h_ArrayMem[currentsize] = iu;
            ++currentsize;
            isscusses = true;
        }
        else
        {
            X* h = h_ArrayMem;
            if ( memsize <= maxsize - 10 )
            {
                memsize += 10;
                h_ArrayMem = new X[memsize];
                for ( int i = 0; i < currentsize; ++i )
                    h_ArrayMem[i] = h[i];
                h_ArrayMem[currentsize] = iu;
                ++currentsize;
                delete[ ] h;
                isscusses = true;
            }
        }
        return isscusses;
    }

    bool popback( unsigned int i )
    {
        bool isscusses = false;
        if ( currentsize == 0 )
        {
            return isscusses;
        }
        else
        {
            --currentsize;
            isscusses = true;
        }
        return isscusses;
    }
    bool setallrandom( )
    {
        bool isscusses = false;
        if ( memsize != 0 )
        {
            for ( int i = 0; i < memsize; ++i )
                h_ArrayMem[i] = rand( ) % 1000;
            isscusses = true;
        }
        return isscusses;
    }

    unsigned int getmaxsize( )const
    {
        return maxsize;
    }

    unsigned int getmemsize( )const
    {
        return  memsize;
    }

    unsigned int  getcurrentsize( )const
    {
        return   currentsize;
    }
};
template <typename T>
void MakeConRandom( T& r , int mod )
{
    for ( auto& i : r )
        i = rand( ) % mod;
}

template <typename T>
void PrintContainer( const T& r )
{
    for ( const auto& i : r )
        cout << i << '\t';
    cout << endl;
}

*/
