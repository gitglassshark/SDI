#include "pch.h"



//namespace metapro {
//	template<size_t N>
//	constexpr size_t tplvalue( )
//	{
//		if constexpr ( N == 1 || N == 0 )
//			return N;
//		else
//			return tplvalue<N - 1>( ) + tplvalue<N - 2>( );
//	}
//	class single
//	{
//	public:
//		inline static const single* GetOnlyOne( )
//		{
//			return OnlyOne;// = new single( );
//		}
//		~single( );
//
//	private:
//		single( );
//
//		//private:
//	public:
//		static single const* const OnlyOne;
//	};
//
//	single const* const single::OnlyOne = new single;
//
//	single::single( )
//	{
//	}
//
//	single::~single( )
//	{
//		using namespace metapro;
//		const single* const p = single::GetOnlyOne( );
//		cout << p << nl;
//		cout << p << nl;
//		cout << p << nl;
//		cout << separtor;
//		cout << single::OnlyOne << nl;
//		cout << separtor;
//		cout << single::OnlyOne << nl;
//	}
//	template<typename ...Args >
//	auto sadd( Args...args )
//	{
//		return ( args - ... - 10 );
//	}
//}
namespace datastruct {

	//	CString shortPointerString( void* p )
	//	{
	//		CString ms;
	//		ms.Format( _T( "%p" ) , p );
	//		ms = ms.Right( ms.GetLength( ) / 2 );
	//		ms.Insert( 0 , '[' );
	//		ms += ']';
	//		return ms;
	//	}
	//
	//	template<typename T>
	//	struct Node {
	//		shared_ptr<T> pData = nullptr;
	//		shared_ptr<Node<T>> pLeft = nullptr;
	//		shared_ptr<Node<T>> pRight = nullptr;
	//		Node( ) {
	//			pData = nullptr;
	//			pLeft = nullptr;
	//			pRight = nullptr;
	//		}
	//		void addData( T t )
	//		{
	//			if ( pData == nullptr )
	//			{
	//
	//				pData = make_shared<T>( );
	//				*pData = t;
	//			}
	//			else
	//			{
	//				if ( compare( t ) )
	//				{
	//					if ( pLeft == nullptr )
	//						pLeft = make_shared<Node<T>>( );
	//					pLeft->addData( t );
	//				}
	//				else
	//				{
	//					if ( pRight == nullptr )
	//						pRight = make_shared<Node<T>>( );
	//					pRight->addData( t );
	//				}
	//			}
	//		}
	//		bool compare( T t )
	//		{
	//			return *pData >= t;
	//		}
	//		const auto getData( )
	//		{
	//			if ( pData )
	//				return *pData;
	//			else
	//				return T( );
	//		}
	//		void info( )
	//		{
	//			static int rl = 0;
	//			CString This;
	//			getcout;
	//			This = shortPointerString( this );
	//			SHOW( This );
	//			CString left;
	//			left = shortPointerString( pLeft.get( ) );
	//			SHOW( left );
	//			CString right;
	//			right = shortPointerString( pRight.get( ) );
	//			SHOW( right );
	//			CString pdata;
	//			pdata = shortPointerString( pData.get( ) );
	//			SHOW( pdata );
	//			if ( rl % 2 )
	//				cout << nl;
	//			else
	//				cout << tab( 2 );
	//			++rl;
	//		}
	//		~Node( ) { }
	//	};
	//
	//	template<typename T>
	//	void RorderPrint( Node<T>* root )
	//	{
	//		getcout;
	//		if ( root )
	//		{
	//			RorderPrint( root->pRight.get( ) );
	//			root->info( );
	//			RorderPrint( root->pLeft.get( ) );
	//		}
	//	}
	//	template<typename T>
	//	void LorderPrint( Node<T>* root )
	//	{
	//		getcout;
	//		static size_t i = 0;
	//		if ( root )
	//		{
	//			LorderPrint( root->pLeft.get( ) );
	//			cout << ++i << ": ";
	//			root->info( );
	//			LorderPrint( root->pRight.get( ) );
	//		}
	//	}
	//	template<typename T>
	//	void MorderPrint( Node<T>* root )
	//	{
	//		if ( root )
	//		{
	//			root->info( );
	//			MorderPrint( root->pLeft.get( ) );
	//			MorderPrint( root->pRight.get( ) );
	//		}
	//	}
	//	template<typename T>
	//	void orderPrint( Node<T>* root )
	//	{
	//		getcout;
	//		LorderPrint( root );
	//		//cout << separtor;
	//	/*	MorderPrint( root );
	//		cout << separtor;
	//		RorderPrint( root );*/
	//	}
	//
	//	template<typename T >
	//	void vis( T p )
	//	{
	//		/*getcout;
	//		static size_t i = 0;
	//		cout << ++i << ": ";
	//		cout << p->getData( ) << sp << p.get( ) << sp << p->pLeft << sp << p->pRight << sp << p->pData << nl;*/
	//		p->info( );
	//	}
	//
	//	template<typename T , typename Fun>
	//	void DequeOrdVis( T root , Fun vis )
	//	{
	//		std::deque<T> s;
	//		auto e = root;
	//		s.push_back( e );
	//		while ( s.empty( ) != true )
	//		{
	//			e = s.front( );
	//			vis( e );
	//			s.pop_front( );
	//			if ( e->pLeft )s.push_back( e->pLeft );
	//			if ( e->pRight )s.push_back( e->pRight );
	//		}
	//	}
	//
	//	template<typename T , typename Fun>
	//	void StackOrdVisRL( T root , Fun vis )
	//	{
	//		stack<T> s;
	//		auto e = root;
	//		s.push( e );
	//		while ( s.empty( ) != true )
	//		{
	//			e = s.top( );
	//			vis( e );
	//			s.pop( );
	//			if ( e->pRight )s.push( e->pRight );
	//			if ( e->pLeft )s.push( e->pLeft );
	//		}
	//	}
	//
	//	template<typename T , typename Fun>
	//	auto StackOrdVis( T root , Fun vis )
	//	{
	//		stack<T> s;
	//		T newRoot = make_shared<typename T::element_type>( );
	//		while ( ( root != nullptr ) || ( !s.empty( ) ) )
	//		{
	//			if ( root != nullptr )
	//			{
	//				s.push( root );
	//				root = root->pLeft;
	//			}
	//			else
	//			{
	//				root = s.top( );
	//				vis( root );
	//				newRoot->addData( *root->pData );
	//				s.pop( );
	//				root = root->pRight;
	//			}
	//		}
	//		return newRoot;
	//	}
	// //using namespace WindowsBar;
		//using namespace datastruct;
		//auto pRoot = make_shared<Node<double>>( );
		//const size_t cap = 12;
		//for ( size_t i = 1; i <= cap; ++i )
		//{
		//	pRoot->addData( std::rand( ) * i % 300 / 3.0 );
		//}
		//cout.title( st( orderPrint ) );
		//orderPrint( pRoot.get( ) );
		//sleep( 1000 );
		//cout.title( st( StackOrdVisRL ) );
		//StackOrdVisRL( pRoot , vis<shared_ptr<Node<double>>> );
		//sleep( 1000 );
		//cout.title( st( StackOrdVisRL ) );
		//auto newRoot = StackOrdVis( pRoot , vis<shared_ptr<Node<double>>> );
		//cout.title( st( NewRoot StackOrdVis ) );
		//StackOrdVis( newRoot , vis<shared_ptr<Node<double>>> );
		//sleep( 1000 );
		//cout.title( st( DequeOrdVis ) );
		//DequeOrdVis( newRoot , vis<shared_ptr<Node<double>>> );
	// 
	//}
	//
	//namespace WindowsBar
	//{
	//	template<typename T>
	//	struct ret
	//	{
	//		bool ok;
	//		T rvalue;
	//		T& value = rvalue;
	//		T& returnvalue = rvalue;
	//	};
	//	using llong = long long;
	//	template<typename T>
	//	T sort( T& a , T& b )
	//	{
	//		if ( a > b )
	//		{
	//			T c = a;
	//			a = b;
	//			b = c;
	//		}
	//		return a;
	//	}
	//	auto fact( llong n , llong m )
	//	{
	//		long double sum = 1;
	//		sort( n , m );
	//		getcout;
	//		for ( size_t i = n; i <= m; i++ )
	//		{
	//			cout << sum << '*' << i;
	//			sum *= i;
	//			cout << " = " << sum << semi << tab;
	//			cout.circle( 4 );
	//		}
	//		return ret<long double>{true , sum};
	//	}
	//	bool IsPrime( llong x )
	//	{
	//		for ( size_t i = 2; i < x; ++i )
	//		{
	//			if ( x % i == 0 )
	//				return false;
	//		}
	//		return true;
	//	}
	//
	//	inline bool sleep( size_t ms )
	//	{
	//		std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
	//		return true;
	//	}
	//	inline bool wait( size_t ms )
	//	{
	//		return sleep( ms );
	//	}
	//
	//	template<typename T>
	//	T getMiddle( T up , T down , T m )
	//	{
	//		sort( down , up );
	//		if ( m >= up )
	//			return up;
	//		if ( m <= down )
	//			return down;
	//		return m;
	//	}
	//
	//	CPoint GetRandomPoint( CRect& WindowsRectLimitRect )
	//	{
	//		CPoint t;
	//		getcout;
	//		auto& r = WindowsRectLimitRect;
	//		t.x = cout.initalpos + rand( ) % ( r.right - cout.initalpos * 2 );
	//		//t.x = getMiddle( r.right - cout.initalpos , r.left + cout.initalpos , t.x );
	//		t.y = cout.initalpos + rand( ) % ( r.bottom - cout.initalpos * 2 );
	//		//t.y = getMiddle( r.bottom - cout.initalpos , r.top + cout.initalpos , t.y );
	//		return t;
	//	}
	//
	//	void drawLineP2P( CDC& dc , CPoint& startPoint , CPoint& endPoint )
	//	{
	//		dc.MoveTo( startPoint );
	//		dc.LineTo( endPoint );
	//	}
	//
	//	COLORREF randomColor( )
	//	{
	//		return COLORREF( RGB( rand( ) % 255 , rand( ) % 255 , rand( ) % 255 ) );
	//	}
	//
	//	template<typename T>
	//	T tplround( T t )
	//	{
	//		return static_cast<long long>( t + 0.5 );
	//	}
	//
	//	auto _randomColor( )
	//	{
	//		CColor c;
	//		auto cc = c.chocolate;
	//		vector <decltype( cc )> crv;
	//		auto* pc = &c.red;
	//		size_t numcc = sizeof( c ) / sizeof( cc );
	//		for ( size_t i = 0; i < numcc; ++i )
	//		{
	//			crv.push_back( *( pc + i ) );
	//		}
	//		static size_t cindex = 0;
	//		cindex = rand( ) % numcc;
	//		return crv.at( cindex );
	//	}
	//
	//	void DrawTriangleCircle( size_t numTriangle , size_t numCircle , size_t sleepTriangle , size_t sleepCircle )
	//	{
	//		getcout;
	//		CRect WindowsRect = cout.GetDCWindowsRect( );
	//
	//		CPoint startPoint;
	//		CPoint secondPoint;
	//		CPoint endPoint;
	//
	//		CBrush Brush;
	//
	//		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
	//		auto oldPen = cout.SelectObject( Brush );
	//		startPoint = GetRandomPoint( WindowsRect );
	//		secondPoint = GetRandomPoint( WindowsRect );
	//		for ( size_t j = 1; j <= numCircle; ++j )
	//		{
	//			for ( size_t i = 1; i <= numTriangle; ++i )
	//			{
	//				Brush.DeleteObject( );
	//				auto clor = randomColor( );
	//				Brush.CreateSolidBrush( clor );
	//				cout.SelectObject( Brush );
	//				endPoint = GetRandomPoint( WindowsRect );
	//				CPoint pt[3] = { startPoint,secondPoint,endPoint };
	//				cout.Polygon( pt , 3 );
	//				startPoint = secondPoint;
	//				secondPoint = endPoint;
	//				sleep( sleepTriangle );
	//			}
	//
	//			sleep( sleepCircle );
	//			cout << clear;
	//		}
	//		cout.SelectObject( oldPen );
	//		Brush.DeleteObject( );
	//	}
	//
	//	void DrawLineCircle( size_t numline , size_t numCircle , size_t sleepLine , size_t sleepCircle )
	//	{
	//		getcout;
	//		CRect WindowsRect = cout.GetDCWindowsRect( );
	//
	//		CPoint startPoint;
	//		CPoint endPoint;
	//
	//		CPen linePen;
	//
	//		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
	//		auto oldPen = cout.SelectObject( linePen );
	//		startPoint = GetRandomPoint( WindowsRect );
	//		for ( size_t j = 1; j <= numCircle; ++j )
	//		{
	//			for ( size_t i = 1; i <= numline; ++i )
	//			{
	//				linePen.CreatePen( PS_SOLID , 5 , randomColor( ) );
	//				cout.SelectObject( linePen );
	//				endPoint = GetRandomPoint( WindowsRect );
	//
	//				drawLineP2P( cout , startPoint , endPoint );
	//				startPoint = endPoint;
	//				sleep( sleepLine );
	//			}
	//
	//			sleep( sleepCircle );
	//			cout << clear;
	//		}
	//		cout.SelectObject( oldPen );
	//		linePen.DeleteObject( );
	//	}
	//
	//	void DrawEllipseCircle( size_t numEllipse , size_t numCircle , size_t sleepEllipse , size_t sleepCircle )
	//	{
	//		getcout;
	//		CRect WindowsRect = cout.GetDCWindowsRect( );
	//
	//		CPoint startPoint;
	//		CPoint endPoint;
	//
	//		CBrush Brush;
	//
	//		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
	//		auto oldPen = cout.SelectObject( Brush );
	//		startPoint = GetRandomPoint( WindowsRect );
	//		for ( size_t j = 1; j <= numCircle; ++j )
	//		{
	//			for ( size_t i = 1; i <= numEllipse; ++i )
	//			{
	//				Brush.CreateSolidBrush( randomColor( ) );
	//				cout.SelectObject( Brush );
	//				endPoint = GetRandomPoint( WindowsRect );
	//				cout.Ellipse( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
	//				startPoint = endPoint;
	//				sleep( sleepEllipse );
	//			}
	//			sleep( sleepCircle );
	//			cout << clear;
	//		}
	//		cout.SelectObject( oldPen );
	//		Brush.DeleteObject( );
	//	}
	//
	//	void DrawRectangleCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
	//	{
	//		getcout;
	//		CRect WindowsRect = cout.GetDCWindowsRect( );
	//
	//		CPoint startPoint;
	//		CPoint endPoint;
	//
	//		CBrush Brush;
	//
	//		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
	//		auto oldPen = cout.SelectObject( Brush );
	//		startPoint = GetRandomPoint( WindowsRect );
	//		for ( size_t j = 1; j <= numCircle; ++j )
	//		{
	//			for ( size_t i = 1; i <= numRectangle; ++i )
	//			{
	//				auto clor = randomColor( );
	//				Brush.CreateSolidBrush( clor );
	//				cout.SelectObject( Brush );
	//				endPoint = GetRandomPoint( WindowsRect );
	//				cout.Rectangle( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
	//				startPoint = endPoint;
	//				sleep( sleepRectangle );
	//			}
	//			sleep( sleepCircle );
	//			cout << clear;
	//		}
	//		cout.SelectObject( oldPen );
	//		Brush.DeleteObject( );
	//	}
	//
	//	void DrawSnakeCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
	//	{
	//		getcout;
	//		CRect WindowsRect = cout.GetDCWindowsRect( );
	//
	//		auto width = 50;
	//
	//		CPoint startPoint;
	//		CPoint endPoint;
	//
	//		CBrush Brush;
	//
	//		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
	//		auto oldPen = cout.SelectObject( Brush );
	//		startPoint = GetRandomPoint( WindowsRect );
	//		for ( size_t j = 1; j <= numCircle; ++j )
	//		{
	//			for ( size_t i = 1; i <= numRectangle; ++i )
	//			{
	//				Brush.CreateSolidBrush( randomColor( ) );
	//				cout.SelectObject( Brush );
	//				endPoint = GetRandomPoint( WindowsRect );
	//				sort( startPoint.x , endPoint.x );
	//				sort( startPoint.y , endPoint.y );
	//				cout.Rectangle( startPoint.x , startPoint.y , startPoint.x + width , endPoint.y );
	//				cout.Rectangle( startPoint.x , endPoint.y - width , endPoint.x , endPoint.y );
	//				startPoint = endPoint;
	//				sleep( sleepRectangle );
	//			}
	//			sleep( sleepCircle );
	//			cout << clear;
	//		}
	//		cout.SelectObject( oldPen );
	//		Brush.DeleteObject( );
	//	}
	//
	//	CRect SortWindowsRect( CRect WindowsRect )
	//	{
	//		sort( WindowsRect.top , WindowsRect.bottom );
	//		sort( WindowsRect.left , WindowsRect.right );
	//		return WindowsRect;
	//	}
	//
	//	CRect MoveWindowsRect( CRect WindowsRect , int xMove , int yMove )
	//	{
	//		SortWindowsRect( WindowsRect );
	//
	//		auto h = WindowsRect.bottom - WindowsRect.top;
	//		auto v = WindowsRect.right - WindowsRect.left;
	//
	//		WindowsRect.top += yMove;
	//		WindowsRect.bottom += yMove;
	//		WindowsRect.left += xMove;
	//		WindowsRect.right += xMove;
	//		return WindowsRect;
	//	}
	//
	//	CRect ZoomWindowsRect( CRect WindowsRect , int vZoomRate , int hZoomRate )
	//	{
	//		SortWindowsRect( WindowsRect );
	//		auto h = WindowsRect.bottom - WindowsRect.top;
	//		auto v = WindowsRect.right - WindowsRect.left;
	//
	//		WindowsRect.top = WindowsRect.top + h * ( 100 - hZoomRate ) / 200;
	//		WindowsRect.bottom = WindowsRect.bottom - h * ( 100 - hZoomRate ) / 200;
	//		WindowsRect.left = WindowsRect.left + v * ( 100 - vZoomRate ) / 200;
	//		WindowsRect.right = WindowsRect.right - v * ( 100 - vZoomRate ) / 200;
	//		return WindowsRect;
	//	}
	//	CRect vaildWindowRect( CRect rect , CRect WindowsRect )
	//	{
	//		SortWindowsRect( WindowsRect );
	//		SortWindowsRect( rect );
	//		rect.bottom = min( rect.bottom , WindowsRect.bottom );
	//		rect.top = min( rect.bottom , rect.top );
	//		rect.right = min( rect.right , WindowsRect.right );
	//		rect.left = min( rect.left , rect.right );
	//		return rect;
	//	}
	//
	//	CRect PutWindowsRect( CRect WindowsRect , int xMove , int yMove , int vZoomRate , int hZoomRate )
	//	{
	//		CRect rect;
	//		rect = ZoomWindowsRect( WindowsRect , vZoomRate , hZoomRate );
	//		rect = MoveWindowsRect( rect , xMove , yMove );
	//		rect = vaildWindowRect( rect , WindowsRect );
	//		return rect;
	//	}
	//
	//	template<typename DT>
	//	void DrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
	//	{
	//		auto width = BarWidth;
	//
	//		auto drawWidth = DrawRect.right - DrawRect.left;
	//		auto drawHeight = DrawRect.bottom - DrawRect.top;
	//
	//		auto dataItems = data.size( );
	//		auto itemWidth = drawWidth / ( dataItems * 2 + 1 );
	//		auto maxhight = gmax( data );
	//		if ( BarWidth )
	//			itemWidth = BarWidth;
	//
	//		CBrush Brush;
	//		Brush.CreateSolidBrush( randomColor( ) );
	//		auto saveoldBrush = dc.SelectObject( Brush );
	//		for ( size_t i = 0; i < dataItems; ++i )
	//		{
	//			auto itemData = data.at( i );
	//			double size = drawHeight - itemData * drawHeight / maxhight;
	//
	//			dc.Rectangle( DrawRect.left + 2 * i * itemWidth , DrawRect.top + size , DrawRect.left + ( 2 * i + 1 ) * itemWidth , DrawRect.bottom );
	//			Brush.DeleteObject( );
	//			Brush.CreateSolidBrush( randomColor( ) );
	//			dc.SelectObject( Brush );
	//			//sleep( 30 );
	//		}
	//		dc.SelectObject( saveoldBrush );
	//		Brush.DeleteObject( );
	//	}
	//
	//
	//	template<typename DT>
	//	void VDrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
	//	{
	//		auto width = BarWidth;
	//
	//		auto drawWidth = DrawRect.right - DrawRect.left;
	//		auto drawHeight = DrawRect.bottom - DrawRect.top;
	//
	//		auto dataItems = data.size( );
	//		auto itemHeight = drawHeight / ( dataItems * 2 + 1 );
	//		auto maxWidth = gmax( data );
	//		if ( BarWidth )
	//			itemHeight = BarWidth;
	//
	//		CBrush Brush;
	//		Brush.CreateSolidBrush( randomColor( ) );
	//		auto saveoldBrush = dc.SelectObject( Brush );
	//		for ( size_t i = 0; i < dataItems; ++i )
	//		{
	//			auto itemData = data.at( i );
	//			double size = drawWidth - itemData * drawWidth / maxWidth;
	//
	//			dc.Rectangle( DrawRect.left , DrawRect.top + 2 * i * itemHeight , DrawRect.left + size , DrawRect.top + ( 2 * i + 1 ) * itemHeight );
	//			Brush.DeleteObject( );
	//			Brush.CreateSolidBrush( randomColor( ) );
	//			dc.SelectObject( Brush );
	//			sleep( 30 );
	//		}
	//		dc.SelectObject( saveoldBrush );
	//		Brush.DeleteObject( );
	//	}
	//
	//	string colorValue( COLORREF c )
	//	{
	//		string ret;
	//		ret = "R:";
	//		int r = (int)GetRValue( c );
	//		int g = (int)GetGValue( c );
	//		int b = (int)GetBValue( c );
	//		ret.append( std::to_string( r ) );
	//		ret += " G:";
	//		ret.append( std::to_string( g ) );
	//		ret += " B:";
	//		ret.append( std::to_string( b ) );
	//		return ret;
	//	}
		//using namespace WindowsBar;
		//CRect rect { 50,500,1850,1200 };
		//CRect WindowsRect = cout.GetDCWindowsRect( );

		//rcode(
		//	int ncData = 30;
		//cout.lmod( ncData + 5 );
		//auto vectorBarData = makector<vector<int>>( ncData , 58 , 6 );
		//auto color = randomColor( );
		//cout << colorValue( color ) << nl;
		//); rcode(
		//	NTIME( 3 )
		//{
		//	VDrawDataBarCircle( cout , PutWindowsRect( WindowsRect , -500 , 200 , 30 , 70 ) , vectorBarData , 0 );
		//	DrawDataBarCircle( cout , PutWindowsRect( WindowsRect , 800 , 200 , 80 , 40 ) , vectorBarData , 0 ); );
		////sleep( 300 );
		//}
		//cout << st( 数值集为： ) << vectorBarData << tab << st( 柱图形： ) << nl;
}

template <typename T>
class moveC
{
public:
	T* pointer = nullptr;
	int mid = 0;
	moveC( int mid = 0 )
	{
		if ( mid )
			pointer = new T[mid];
	}
	moveC( moveC&& r )
	{
		if ( ( &r == this ) || ( r.pointer == nullptr ) )
			return;
		if ( pointer != nullptr )
		{
			delete pointer;
		}
		pointer = r.pointer;
		mid = 0;
		r.pointer = nullptr;
		r.~moveC( );
	}
	void info( )
	{
		getcout;
		cout << mid << tab << pointer << nl;
	}
	~moveC( ) {
		if ( pointer == nullptr )delete pointer;
	}
};



namespace result
{
	template<typename T>
	struct ret
	{
		bool ok;
		T rvalue;
		T& value = rvalue;
		T& returnvalue = rvalue;
	};
}

namespace fun
{
	using namespace result;
	using llong = long long;
	template<typename T>
	T sort( T& a , T& b )
	{
		if ( a > b )
		{
			T c = a;
			a = b;
			b = c;
		}
		return a;
	}
	auto fact( llong n , llong m )
	{
		long double sum = 1;
		sort( n , m );
		getcout;
		for ( size_t i = n; i <= m; i++ )
		{
			cout << sum << '*' << i;
			sum *= i;
			cout << " = " << sum << semi << tab;
			cout.circle( 4 );
		}
		return ret<long double>{true , sum};
	}
	bool IsPrime( llong x )
	{
		for ( size_t i = 2; i < x; ++i )
		{
			if ( x % i == 0 )
				return false;
		}
		return true;
	}

	inline bool sleep( size_t ms )
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
		return true;
	}
	inline bool wait( size_t ms )
	{
		return sleep( ms );
	}

	template<typename T>
	T getMiddle( T up , T down , T m )
	{
		sort( down , up );
		if ( m >= up )
			return up;
		if ( m <= down )
			return down;
		return m;
	}

	CPoint GetRandomPoint( CRect& WindowsRectLimitRect )
	{
		CPoint t;
		getcout;
		auto& r = WindowsRectLimitRect;
		t.x = cout.initalpos + rand( ) % ( r.right - cout.initalpos * 2 );
		//t.x = getMiddle( r.right - cout.initalpos , r.left + cout.initalpos , t.x );
		t.y = cout.initalpos + rand( ) % ( r.bottom - cout.initalpos * 2 );
		//t.y = getMiddle( r.bottom - cout.initalpos , r.top + cout.initalpos , t.y );
		return t;
	}

	void drawLineP2P( CDC& dc , CPoint& startPoint , CPoint& endPoint )
	{
		dc.MoveTo( startPoint );
		dc.LineTo( endPoint );
	}

	COLORREF randomColor( )
	{
		return COLORREF( RGB( rand( ) % 255 , rand( ) % 255 , rand( ) % 255 ) );
	}

	template<typename T>
	T tplround( T t )
	{
		return static_cast<long long>( t + 0.5 );
	}

	auto _randomColor( )
	{
		CColor c;
		auto cc = c.chocolate;
		vector <decltype( cc )> crv;
		auto* pc = &c.red;
		size_t numcc = sizeof( c ) / sizeof( cc );
		for ( size_t i = 0; i < numcc; ++i )
		{
			crv.push_back( *( pc + i ) );
		}
		static size_t cindex = 0;
		cindex = rand( ) % numcc;
		return crv.at( cindex );
	}

	void DrawTriangleCircle( size_t numTriangle , size_t numCircle , size_t sleepTriangle , size_t sleepCircle )
	{
		getcout;
		CRect WindowsRect = cout.GetDCWindowsRect( );

		CPoint startPoint;
		CPoint secondPoint;
		CPoint endPoint;

		CBrush Brush;

		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
		auto oldPen = cout.SelectObject( Brush );
		startPoint = GetRandomPoint( WindowsRect );
		secondPoint = GetRandomPoint( WindowsRect );
		for ( size_t j = 1; j <= numCircle; ++j )
		{
			for ( size_t i = 1; i <= numTriangle; ++i )
			{
				Brush.DeleteObject( );
				auto clor = randomColor( );
				Brush.CreateSolidBrush( clor );
				cout.SelectObject( Brush );
				endPoint = GetRandomPoint( WindowsRect );
				CPoint pt[3] = { startPoint,secondPoint,endPoint };
				cout.Polygon( pt , 3 );
				startPoint = secondPoint;
				secondPoint = endPoint;
				sleep( sleepTriangle );
			}

			sleep( sleepCircle );
			cout << clear;
		}
		cout.SelectObject( oldPen );
		Brush.DeleteObject( );
	}

	void DrawLineCircle( size_t numline , size_t numCircle , size_t sleepLine , size_t sleepCircle )
	{
		getcout;
		CRect WindowsRect = cout.GetDCWindowsRect( );

		CPoint startPoint;
		CPoint endPoint;

		CPen linePen;

		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
		auto oldPen = cout.SelectObject( linePen );
		startPoint = GetRandomPoint( WindowsRect );
		for ( size_t j = 1; j <= numCircle; ++j )
		{
			for ( size_t i = 1; i <= numline; ++i )
			{
				linePen.CreatePen( PS_SOLID , 5 , randomColor( ) );
				cout.SelectObject( linePen );
				endPoint = GetRandomPoint( WindowsRect );

				drawLineP2P( cout , startPoint , endPoint );
				startPoint = endPoint;
				sleep( sleepLine );
			}

			sleep( sleepCircle );
			cout << clear;
		}
		cout.SelectObject( oldPen );
		linePen.DeleteObject( );
	}

	void DrawEllipseCircle( size_t numEllipse , size_t numCircle , size_t sleepEllipse , size_t sleepCircle )
	{
		getcout;
		CRect WindowsRect = cout.GetDCWindowsRect( );

		CPoint startPoint;
		CPoint endPoint;

		CBrush Brush;

		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
		auto oldPen = cout.SelectObject( Brush );
		startPoint = GetRandomPoint( WindowsRect );
		for ( size_t j = 1; j <= numCircle; ++j )
		{
			for ( size_t i = 1; i <= numEllipse; ++i )
			{
				Brush.CreateSolidBrush( randomColor( ) );
				cout.SelectObject( Brush );
				endPoint = GetRandomPoint( WindowsRect );
				cout.Ellipse( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
				startPoint = endPoint;
				sleep( sleepEllipse );
			}
			sleep( sleepCircle );
			cout << clear;
		}
		cout.SelectObject( oldPen );
		Brush.DeleteObject( );
	}

	void DrawRectangleCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
	{
		getcout;
		CRect WindowsRect = cout.GetDCWindowsRect( );

		CPoint startPoint;
		CPoint endPoint;

		CBrush Brush;

		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
		auto oldPen = cout.SelectObject( Brush );
		startPoint = GetRandomPoint( WindowsRect );
		for ( size_t j = 1; j <= numCircle; ++j )
		{
			for ( size_t i = 1; i <= numRectangle; ++i )
			{
				auto clor = randomColor( );
				Brush.CreateSolidBrush( clor );
				cout.SelectObject( Brush );
				endPoint = GetRandomPoint( WindowsRect );
				cout.Rectangle( startPoint.x , startPoint.y , endPoint.x , endPoint.y );
				startPoint = endPoint;
				sleep( sleepRectangle );
			}
			sleep( sleepCircle );
			cout << clear;
		}
		cout.SelectObject( oldPen );
		Brush.DeleteObject( );
	}

	void DrawSnakeCircle( size_t numRectangle , size_t numCircle , size_t sleepRectangle , size_t sleepCircle )
	{
		getcout;
		CRect WindowsRect = cout.GetDCWindowsRect( );

		auto width = 50;

		CPoint startPoint;
		CPoint endPoint;

		CBrush Brush;

		//linePen.CreatePen( PS_SOLID , 1 , randomColor( ) );
		auto oldPen = cout.SelectObject( Brush );
		startPoint = GetRandomPoint( WindowsRect );
		for ( size_t j = 1; j <= numCircle; ++j )
		{
			for ( size_t i = 1; i <= numRectangle; ++i )
			{
				Brush.CreateSolidBrush( randomColor( ) );
				cout.SelectObject( Brush );
				endPoint = GetRandomPoint( WindowsRect );
				sort( startPoint.x , endPoint.x );
				sort( startPoint.y , endPoint.y );
				cout.Rectangle( startPoint.x , startPoint.y , startPoint.x + width , endPoint.y );
				cout.Rectangle( startPoint.x , endPoint.y - width , endPoint.x , endPoint.y );
				startPoint = endPoint;
				sleep( sleepRectangle );
			}
			sleep( sleepCircle );
			cout << clear;
		}
		cout.SelectObject( oldPen );
		Brush.DeleteObject( );
	}

	CRect SortWindowsRect( CRect WindowsRect )
	{
		sort( WindowsRect.top , WindowsRect.bottom );
		sort( WindowsRect.left , WindowsRect.right );
		return WindowsRect;
	}

	CRect MoveWindowsRect( CRect WindowsRect , int xMove , int yMove )
	{
		SortWindowsRect( WindowsRect );

		auto h = WindowsRect.bottom - WindowsRect.top;
		auto v = WindowsRect.right - WindowsRect.left;

		WindowsRect.top += yMove;
		WindowsRect.bottom += yMove;
		WindowsRect.left += xMove;
		WindowsRect.right += xMove;
		return WindowsRect;
	}

	CRect ZoomWindowsRect( CRect WindowsRect , int vZoomRate , int hZoomRate )
	{
		SortWindowsRect( WindowsRect );
		auto h = WindowsRect.bottom - WindowsRect.top;
		auto v = WindowsRect.right - WindowsRect.left;

		WindowsRect.top = WindowsRect.top + h * ( 100 - hZoomRate ) / 200;
		WindowsRect.bottom = WindowsRect.bottom - h * ( 100 - hZoomRate ) / 200;
		WindowsRect.left = WindowsRect.left + v * ( 100 - vZoomRate ) / 200;
		WindowsRect.right = WindowsRect.right - v * ( 100 - vZoomRate ) / 200;
		return WindowsRect;
	}
	CRect vaildWindowRect( CRect rect , CRect WindowsRect )
	{
		SortWindowsRect( WindowsRect );
		SortWindowsRect( rect );
		rect.bottom = min( rect.bottom , WindowsRect.bottom );
		rect.top = min( rect.bottom , rect.top );
		rect.right = min( rect.right , WindowsRect.right );
		rect.left = min( rect.left , rect.right );
		return rect;
	}

	CRect PutWindowsRect( CRect WindowsRect , int xMove , int yMove , int vZoomRate , int hZoomRate )
	{
		CRect rect;
		rect = ZoomWindowsRect( WindowsRect , vZoomRate , hZoomRate );
		rect = MoveWindowsRect( rect , xMove , yMove );
		rect = vaildWindowRect( rect , WindowsRect );
		return rect;
	}

	template<typename DT>
	void DrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
	{
		auto width = BarWidth;

		auto drawWidth = DrawRect.right - DrawRect.left;
		auto drawHeight = DrawRect.bottom - DrawRect.top;

		auto dataItems = data.size( );
		auto itemWidth = drawWidth / ( dataItems * 2 + 1 );
		auto maxhight = gmax( data );
		if ( BarWidth )
			itemWidth = BarWidth;

		CBrush Brush;
		Brush.CreateSolidBrush( randomColor( ) );
		auto saveoldBrush = dc.SelectObject( Brush );
		for ( size_t i = 0; i < dataItems; ++i )
		{
			auto itemData = data.at( i );
			double size = drawHeight - itemData * drawHeight / maxhight;

			dc.Rectangle( DrawRect.left + 2 * i * itemWidth , DrawRect.top + size , DrawRect.left + ( 2 * i + 1 ) * itemWidth , DrawRect.bottom );
			Brush.DeleteObject( );
			Brush.CreateSolidBrush( randomColor( ) );
			dc.SelectObject( Brush );
			//sleep( 30 );
		}
		dc.SelectObject( saveoldBrush );
		Brush.DeleteObject( );
	}


	template<typename DT>
	void VDrawDataBarCircle( PCDC& dc , CRect DrawRect , const vector<DT>& data , size_t BarWidth = 0 )
	{
		auto width = BarWidth;

		auto drawWidth = DrawRect.right - DrawRect.left;
		auto drawHeight = DrawRect.bottom - DrawRect.top;

		auto dataItems = data.size( );
		auto itemHeight = drawHeight / ( dataItems * 2 + 1 );
		auto maxWidth = gmax( data );
		if ( BarWidth )
			itemHeight = BarWidth;

		CBrush Brush;
		Brush.CreateSolidBrush( randomColor( ) );
		auto saveoldBrush = dc.SelectObject( Brush );
		for ( size_t i = 0; i < dataItems; ++i )
		{
			auto itemData = data.at( i );
			double size = drawWidth - itemData * drawWidth / maxWidth;

			dc.Rectangle( DrawRect.left , DrawRect.top + 2 * i * itemHeight , DrawRect.left + size , DrawRect.top + ( 2 * i + 1 ) * itemHeight );
			Brush.DeleteObject( );
			Brush.CreateSolidBrush( randomColor( ) );
			dc.SelectObject( Brush );
			sleep( 30 );
		}
		dc.SelectObject( saveoldBrush );
		Brush.DeleteObject( );
	}

	string colorValue( COLORREF c )
	{
		string ret;
		ret = "R:";
		int r = (int)GetRValue( c );
		int g = (int)GetGValue( c );
		int b = (int)GetBValue( c );
		ret.append( std::to_string( r ) );
		ret += " G:";
		ret.append( std::to_string( g ) );
		ret += " B:";
		ret.append( std::to_string( b ) );
		return ret;
	}
}

void test_01( PCDC& cout )
{
	using namespace fun;
	CRect rect { 50,500,1850,1200 };
	CRect WindowsRect = cout.GetDCWindowsRect( );

	rcode(
		int ncData = 30;
	cout.lmod( ncData + 5 );
	auto vectorBarData = makector<vector<int>>( ncData , 58 , 6 );
	auto color = randomColor( );
	cout << colorValue( color ) << nl;
	); rcode(
		NTIME( 3 )
	{
		VDrawDataBarCircle( cout , PutWindowsRect( WindowsRect , -500 , 200 , 30 , 70 ) , vectorBarData , 0 );
		DrawDataBarCircle( cout , PutWindowsRect( WindowsRect , 800 , 200 , 80 , 40 ) , vectorBarData , 0 ); );
	//sleep( 300 );
	}
	cout << st( 数值集为： ) << vectorBarData << tab << st( 柱图形： ) << nl;
}

namespace pythonm {

	template<typename T>
	auto range( T start , T end , T step = 1 , bool reverse = false )
	{
		list<T> Ret;
		if ( step < 0 )
			step = -step;
		if ( step == 0 )
			step = 1;
		if ( start <= end )
		{
			for ( ; start < end; start += step )
				Ret.push_back( start );
		}
	}

	template<typename T>
	T randomint( T a , T b )
	{
		if ( a > b )
			std::swap( a , b );
		T c = b - a;
		return a + rand( ) % ( c + 1 );
	}
}

void test_02( PCDC& cout )
{
	rcode(
		unsigned char  low4bit = 0x0F;
	cout << bitset<8>( low4bit ) << nl;
	); rcode(
		unsigned char high4bit = 0xF0;
	cout << bitset<8>( high4bit ) << nl;
	); rcode(
		unsigned int high8bit = 0xFF00;
	cout << bitset<16>( high8bit ) << nl;
	); rcode(
		unsigned int low8bit = 0x00FF;
	cout << bitset<16>( low8bit ) << nl;
	); rcode(
		unsigned long high16bit = 0xFFFF0000;
	cout << bitset<32>( high16bit ) << nl;
	); rcode(
		unsigned long low16bit = 0x00FFFF;
	cout << bitset<32>( low16bit ) << nl;
	); rcode(
		unsigned long long high32bit = 0xFFFFFFFF00000000;
	cout << bitset<64>( high32bit ) << nl;
	); rcode(
		unsigned long long low32bit = 0x00FFFFFFFF;
	cout << bitset<64>( low32bit ) << nl;
	cout << bitset<512>( low32bit ) << nl;
	);

}

namespace testunion {
	unsigned char  l4bit = 0x0F;
	unsigned char h4bit = 0xF0;
	unsigned int h8bit = 0xFF00;
	unsigned int l8bit = 0x00FF;
	unsigned long h16bit = 0xFFFF0000;
	unsigned long l16bit = 0x0000FFFF;
	unsigned long long h32bit = 0xFFFFFFFF00000000;
	unsigned long long l32bit = 0x00000000FFFFFFFF;
	union alignas( 1 ) bitunion {
		union byte {
			unsigned char value;
			struct {
				unsigned char low4 : 4;
				unsigned char high4 : 4;
			};
			struct {
				unsigned char bit0 : 1;
				unsigned char bit1 : 1;
				unsigned char bit2 : 1;
				unsigned char bit3 : 1;
				unsigned char bit4 : 1;
				unsigned char bit5 : 1;
				unsigned char bit6 : 1;
				unsigned char bit7 : 1;
			};
			byte( ) :value( 0 ) {}
			inline static constexpr auto size( )
			{
				return 8;
			}
			auto getvalue( )
			{
				return value;
			}
			auto& set( size_t pos , bool iset )
			{
				return value = bitset<size( )>( value ).set( pos , iset ).to_ulong( );
			}
			auto& setbitn( size_t bitpos , bool iset = true )
			{
				if ( iset )
				{
					switch ( bitpos )
					{
					case 0:bit0 = 1;  break;
					case 1:bit1 = 1;  break;
					case 2:bit2 = 1;  break;
					case 3:bit3 = 1;  break;
					case 4:bit4 = 1;  break;
					case 5:bit5 = 1;  break;
					case 6:bit6 = 1;  break;
					case 7:bit7 = 1;  break;
					default:
						break;
					}
				}
				else
				{
					switch ( bitpos )
					{
					case 0:bit0 = 0;  break;
					case 1:bit1 = 0;  break;
					case 2:bit2 = 0;  break;
					case 3:bit3 = 0;  break;
					case 4:bit4 = 0;  break;
					case 5:bit5 = 0;  break;
					case 6:bit6 = 0;  break;
					case 7:bit7 = 0;  break;
					default:
						break;
					}
				}
				return value;
			}
			void set( )
			{
				value = 0xFF;
			}
			void reset( )
			{
				value = 0;
			}
			void setl( )
			{
				value = 0x0F;
			}
			void seth( )
			{
				value = 0xF0;
			}
			auto getl( )
			{
				return low4;
			}
			auto geth( )
			{
				return high4;
			}
			auto bit( )
			{
				return bitset<size( )>( value );
			}
			auto lbit( )
			{
				return bitset<4>( low4 );
			}
			auto hbit( )
			{
				return bitset<4>( high4 );
			}
		};
		byte bytev[sizeof( long long ) / sizeof( byte )];
		union word {
			unsigned short int value;
			struct {
				byte low8;
				byte high8;
			};

			word( ) :value( 0 ) {}
			inline static constexpr auto  size( )
			{
				return byte::size( ) * 2;
			}
			auto getvalue( )
			{
				return value;
			}
			auto& set( size_t pos , bool iset )
			{
				return value = bitset<size( )>( value ).set( pos , iset ).to_ulong( );
			}
			void set( )
			{
				value = 0xFFFF;
			}
			void setl( )
			{
				value = 0x00FF;
			}
			void seth( )
			{
				value = 0xFF00;
			}
			auto& getl( )
			{
				return low8;
			}
			auto& geth( )
			{
				return high8;
			}
			void reset( )
			{
				value = 0;
			}
			auto bit( )
			{
				return bitset<size( ) >( value );
			}
			auto lbit( )
			{
				return low8.bit( );
			}
			auto hbit( )
			{
				return high8.bit( );
			}
		};
		word wordv[sizeof( long long ) / sizeof( word )];
		union dword {
			unsigned int value;
			struct {
				word low16;
				word high16;
			};
			dword( ) {}
			inline static constexpr auto  size( )
			{
				return  word::size( ) * 2;
			}
			auto getvalue( )
			{
				return value;
			}
			auto& set( size_t pos , bool iset )
			{
				return value = bitset<size( )>( value ).set( pos , iset ).to_ullong( );
			}
			void set( )
			{
				value = 0xFFFFFFFF;
			}
			void setl( )
			{
				value = 0x0000FFFF;
			}
			void seth( )
			{
				value = 0xFFFF0000;
			}
			auto& getl( )
			{
				return low16;
			}
			auto& geth( )
			{
				return high16;
			}
			void reset( )
			{
				value = 0;
			}
			auto bit( )
			{
				return bitset<size( ) >( value );
			}
			auto lbit( )
			{
				return low16.bit( );
			}
			auto hbit( )
			{
				return high16.bit( );
			}
		};
		dword dwordv[sizeof( long long ) / sizeof( dword )];
		union the
		{
			unsigned long long value;
			void* pointer;
			struct {
				dword low32;
				dword high32;
			};
			the( unsigned long long i = 0 ) :value( i ) {}
			inline static constexpr auto  size( )
			{
				return dword::size( ) * 2;
			}
			template<typename R , typename T>
			R* setp( T* rp )
			{
				pointer = reinterpret_cast<void*>( rp );
				return reinterpret_cast<R*>( rp );
			}
			template<typename T>
			T* getp( )
			{
				return reinterpret_cast<T*>( pointer );
			}
			template<typename T>
			auto getderef( )
			{
				if ( pointer )
					return *reinterpret_cast<T*>( pointer );
				else
					return T( );
			}
			void set( )
			{
				value = 0XFFFFFFFFFFFFFFFF;
			}
			auto getvalue( )
			{
				return value;
			}
			auto& set( size_t pos , bool iset )
			{
				return value = bitset<size( )>( value ).set( pos , iset ).to_ulong( );
			}
			void setl( )
			{
				value = 0X00000000FFFFFFFF;
			}
			void seth( )
			{
				value = 0XFFFFFFFF00000000;
			}
			auto& getl( )
			{
				return low32;
			}
			auto& geth( )
			{
				return high32;
			}
			void reset( )
			{
				value = 0;
			}
			auto bit( )
			{
				return bitset<size( ) >( value );
			}
			auto lbit( )
			{
				return low32.bit( );
			}
			auto hbit( )
			{
				return high32.bit( );
			}
		}me;
		bitunion( unsigned long long i = 0 ) :me( i ) { }
		inline static constexpr auto  size( )
		{
			return the::size( );
		}
		template<typename R , typename T>
		R* setp( T* rp )
		{
			me.pointer = reinterpret_cast<void*>( rp );
			return reinterpret_cast<R*>( rp );
		}
		template<typename T>
		T* getp( )
		{
			return reinterpret_cast<T*>( me.pointer );
		}
		template<typename T>
		auto getderef( )
		{
			if ( me.pointer )
				return *reinterpret_cast<T*>( me.pointer );
			else
				return T( );
		}
		void set( )
		{
			me.value = 0xFFFFFFFFFFFFFFFF;
		}
		auto getvalue( )
		{
			return me.value;
		}
		auto& set( size_t pos , bool iset )
		{
			return me.value = bitset<size( )>( me.value ).set( pos , iset ).to_ulong( );
		}
		void setl( )
		{
			me.high32.reset( );
			me.low32.set( );
		}
		void seth( )
		{
			me.high32.set( );
			me.low32.reset( );
		}
		auto& getl( )
		{
			return me.low32;
		}
		auto& geth( )
		{
			return me.high32;
		}
		void reset( )
		{
			me.value = 0;
		}
		auto bit( )
		{
			return bitset<size( ) >( me.value );
		}
		auto lbit( )
		{
			return me.low32.bit( );
		}
		auto hbit( )
		{
			return me.high32.bit( );
		}

		struct seq
		{
			int a;
			int b;
		};
	};
}

void test_03( PCDC& cout )
{
	using namespace testunion;
	rcode(
		bitunion BitUnionX( 3 );
	cout << BitUnionX.me.bit( ) << tab << BitUnionX.me.value << tab;
	BitUnionX.reset( );
	cout << BitUnionX.me.bit( ) << tab << BitUnionX.me.value << tab;
	BitUnionX.set( );
	cout << BitUnionX.me.bit( ) << tab << BitUnionX.me.value << tab;
	); rcode(
		cout << sizeof( BitUnionX.bytev[0] ) << tab;
	BitUnionX.bytev[0].set( );
	cout << BitUnionX.bytev[0].bit( ) << tab;
	BitUnionX.bytev[0].setl( );
	cout << BitUnionX.bytev[0].bit( ) << tab;
	BitUnionX.bytev[0].seth( );
	cout << BitUnionX.bytev[0].bit( ) << tab;
	BitUnionX.bytev[0].reset( );
	cout << BitUnionX.bytev[0].bit( ) << tab;
	); rcode(
		cout << sizeof( BitUnionX.wordv[0] ) << tab;
	BitUnionX.wordv[0].seth( );
	cout << BitUnionX.wordv[0].bit( ) << tab;
	BitUnionX.wordv[0].setl( );
	cout << BitUnionX.wordv[0].bit( ) << tab;
	BitUnionX.wordv[0].reset( );
	cout << BitUnionX.wordv[0].bit( ) << tab;
	BitUnionX.wordv[0].set( );
	cout << BitUnionX.wordv[0].bit( ) << tab;
	); rcode(
		cout << sizeof( BitUnionX.dwordv[0] ) << tab;
	BitUnionX.dwordv[0].seth( );
	cout << BitUnionX.dwordv[0].bit( ) << tab << BitUnionX.dwordv[0].value << tab;
	BitUnionX.dwordv[0].setl( );
	cout << BitUnionX.dwordv[0].bit( ) << tab << BitUnionX.dwordv[0].value << tab;
	BitUnionX.dwordv[0].set( );
	cout << BitUnionX.dwordv[0].bit( ) << tab << BitUnionX.dwordv[0].value << tab;
	BitUnionX.dwordv[0].reset( );
	cout << BitUnionX.dwordv[0].bit( ) << tab << BitUnionX.dwordv[0].value << tab;
	); rcode(
		cout << sizeof( BitUnionX ) << tab;
	BitUnionX.setl( ); cout << BitUnionX.bit( ) << tab;
	BitUnionX.seth( ); cout << BitUnionX.bit( ) << tab;
	); rcode(
		BitUnionX.set( ); cout << BitUnionX.bit( ) << tab;
	BitUnionX.reset( ); cout << BitUnionX.bit( ) << tab;
	); rcode( BitUnionX.geth( ).geth( ).seth( ); cout << BitUnionX.bit( ) << tab;
	); rcode( BitUnionX.geth( ).geth( ).setl( ); cout << BitUnionX.bit( ) << tab;
	); rcode( BitUnionX.geth( ).geth( ).getl( ).seth( ); cout << BitUnionX.bit( ) << tab;
	); rcode( BitUnionX.reset( ); BitUnionX.geth( ).geth( ).geth( ).setbitn( 7 ); cout << BitUnionX.bit( ) << tab;
	);
}

namespace datastruct {

	CString shortPointerString( void* p )
	{
		CString ms;
		ms.Format( _T( "%p" ) , p );
		ms = ms.Right( ms.GetLength( ) / 2 );
		ms.Insert( 0 , '[' );
		ms += ']';
		return ms;
	}

	template<typename T>
	struct Node {
		shared_ptr<T> pData = nullptr;
		shared_ptr<Node<T>> pLeft = nullptr;
		shared_ptr<Node<T>> pRight = nullptr;
		Node( ) {
			pData = nullptr;
			pLeft = nullptr;
			pRight = nullptr;
		}
		void addData( T t )
		{
			if ( pData == nullptr )
			{

				pData = make_shared<T>( );
				*pData = t;
			}
			else
			{
				if ( compare( t ) )
				{
					if ( pLeft == nullptr )
						pLeft = make_shared<Node<T>>( );
					pLeft->addData( t );
				}
				else
				{
					if ( pRight == nullptr )
						pRight = make_shared<Node<T>>( );
					pRight->addData( t );
				}
			}
		}
		bool compare( T t )
		{
			return *pData >= t;
		}
		const auto getData( )
		{
			if ( pData )
				return *pData;
			else
				return T( );
		}
		void info( )
		{
			static int rl = 0;
			CString This;
			getcout;
			This = shortPointerString( this );
			SHOW( This );
			CString left;
			left = shortPointerString( pLeft.get( ) );
			SHOW( left );
			CString right;
			right = shortPointerString( pRight.get( ) );
			SHOW( right );
			CString pdata;
			pdata = shortPointerString( pData.get( ) );
			SHOW( pdata );
			if ( rl % 2 )
				cout << nl;
			else
				cout << tab( 2 );
			++rl;
		}
		~Node( ) { }
	};

	template<typename T>
	void RorderPrint( Node<T>* root )
	{
		getcout;
		if ( root )
		{
			RorderPrint( root->pRight.get( ) );
			root->info( );
			RorderPrint( root->pLeft.get( ) );
		}
	}
	template<typename T>
	void LorderPrint( Node<T>* root )
	{
		getcout;
		static size_t i = 0;
		if ( root )
		{
			LorderPrint( root->pLeft.get( ) );
			cout << ++i << ": ";
			root->info( );
			LorderPrint( root->pRight.get( ) );
		}
	}
	template<typename T>
	void MorderPrint( Node<T>* root )
	{
		if ( root )
		{
			root->info( );
			MorderPrint( root->pLeft.get( ) );
			MorderPrint( root->pRight.get( ) );
		}
	}
	template<typename T>
	void orderPrint( Node<T>* root )
	{
		getcout;
		LorderPrint( root );
		//cout << separtor;
	/*	MorderPrint( root );
		cout << separtor;
		RorderPrint( root );*/
	}

	template<typename T >
	void vis( T p )
	{
		/*getcout;
		static size_t i = 0;
		cout << ++i << ": ";
		cout << p->getData( ) << sp << p.get( ) << sp << p->pLeft << sp << p->pRight << sp << p->pData << nl;*/
		p->info( );
	}

	template<typename T , typename Fun>
	void DequeOrdVis( T root , Fun vis )
	{
		std::deque<T> s;
		auto e = root;
		s.push_back( e );
		while ( s.empty( ) != true )
		{
			e = s.front( );
			vis( e );
			s.pop_front( );
			if ( e->pLeft )s.push_back( e->pLeft );
			if ( e->pRight )s.push_back( e->pRight );
		}
	}

	template<typename T , typename Fun>
	void StackOrdVisRL( T root , Fun vis )
	{
		stack<T> s;
		auto e = root;
		s.push( e );
		while ( s.empty( ) != true )
		{
			e = s.top( );
			vis( e );
			s.pop( );
			if ( e->pRight )s.push( e->pRight );
			if ( e->pLeft )s.push( e->pLeft );
		}
	}

	template<typename T , typename Fun>
	auto StackOrdVis( T root , Fun vis )
	{
		stack<T> s;
		T newRoot = make_shared<typename T::element_type>( );
		while ( ( root != nullptr ) || ( !s.empty( ) ) )
		{
			if ( root != nullptr )
			{
				s.push( root );
				root = root->pLeft;
			}
			else
			{
				root = s.top( );
				vis( root );
				newRoot->addData( *root->pData );
				s.pop( );
				root = root->pRight;
			}
		}
		return newRoot;
	}
}

void test_04( PCDC& cout )
{
	using namespace fun;
	using namespace datastruct;
	auto pRoot = make_shared<Node<double>>( );
	const size_t cap = 12;
	for ( size_t i = 1; i <= cap; ++i )
	{
		pRoot->addData( std::rand( ) * i % 300 / 3.0 );
	}
	cout.title( st( orderPrint ) );
	orderPrint( pRoot.get( ) );
	sleep( 1000 );
	cout.title( st( StackOrdVisRL ) );
	StackOrdVisRL( pRoot , vis<shared_ptr<Node<double>>> );
	sleep( 1000 );
	cout.title( st( StackOrdVisRL ) );
	auto newRoot = StackOrdVis( pRoot , vis<shared_ptr<Node<double>>> );
	cout.title( st( NewRoot StackOrdVis ) );
	StackOrdVis( newRoot , vis<shared_ptr<Node<double>>> );
	sleep( 1000 );
	cout.title( st( DequeOrdVis ) );
	DequeOrdVis( newRoot , vis<shared_ptr<Node<double>>> );
}

namespace metapro {
	template<size_t N>
	constexpr size_t tplvalue( )
	{
		if constexpr ( N == 1 || N == 0 )
			return N;
		else
			return tplvalue<N - 1>( ) + tplvalue<N - 2>( );
	}
	class single
	{
	public:
		inline static const single* GetOnlyOne( )
		{
			return OnlyOne;// = new single( );
		}
		~single( );

	private:
		single( );

		//private:
	public:
		static single const* const OnlyOne;
	};

	single const* const single::OnlyOne = new single;

	single::single( )
	{
	}

	single::~single( )
	{
		using namespace metapro;
		const single* const p = single::GetOnlyOne( );
		cout << p << nl;
		cout << p << nl;
		cout << p << nl;
		cout << separtor;
		cout << single::OnlyOne << nl;
		cout << separtor;
		cout << single::OnlyOne << nl;
	}
}

namespace templatevar
{
	template<typename ...Args >
	auto sadd( Args...args )
	{
		return ( args - ... - 10 );
	}


}

void test_05( PCDC& cout )
{
	using namespace templatevar;
	//cout << sadd( 1 ,  4 ,1,2 ) << nl;
	rcode(
		CTime t = CTime::GetCurrentTime( );
	cout << t.FormatGmt( "%F" ) << tab;
	cout << t.FormatGmt( "%D" ) << tab;
	); rcode(
		cout << t.FormatGmt( "%#c" ) << tab;
	cout << t.FormatGmt( "%c" ) << tab;
	); rcode(
		cout << t.FormatGmt( "%#x" ) << tab;
	cout << t.FormatGmt( "%T" ) << tab;
	); rcode(
		cout << t.FormatGmt( "%x" ) << tab;
	cout << t.FormatGmt( "%X" ) << tab;
	cout << t.FormatGmt( "%R" ) << tab;
	); rcode(
		cout << t.FormatGmt( "%z" ) << tab;
	cout << t.GetYear( ) << sp;
	cout << t.GetMonth( ) << sp;
	cout << t.GetDay( ) << sp;
	cout << t.GetHour( ) << sp;
	cout << t.GetMinute( ) << sp;
	cout << t.GetSecond( ) << sp;
	); rcode(
		tm ltm;
	auto lt = t.GetLocalTm( &ltm );
	cout.pt( ltm.tm_year + 1900 , string( "年" ) , ltm.tm_mon + 1 , string( "月" ) , ltm.tm_mday , ltm.tm_wday , ltm.tm_hour , ltm.tm_min , ltm.tm_sec );
	);



}

namespace pythonm {

	template<typename T>
	auto range( T start , T end , T step = 1 , bool reverse = false )
	{
		list<T> Ret;
		if ( step < 0 )
			step = -step;
		if ( step == 0 )
			step = 1;
		if ( start <= end )
		{
			for ( ; start < end; start += step )
				Ret.push_back( start );
		}
	}


	/*template<typename T>
	auto range( T start , T end , T step = 1 , bool reverse = false )
	{
		list<T> Ret;
		if ( step < 0 )
			step = -step;
		if ( step == 0 )
			step = 1;
		if ( start <= end )
		{
			for ( ; start < end; start += step )
				Ret.push_back( start );
		}
		else
		{
			for ( ; end < start; start -= step )
				Ret.push_back( start );
		}
		if ( reverse == true )
			Ret.reverse( );
		return Ret;
	}

	template<typename T>
	T randomint( T a , T b )
	{
		if ( a > b )
			std::swap( a , b );
		T c = b - a;
		return a + rand( ) % ( c + 1 );
	}*/
}


void test_02( PCDC& cout )
{
	using namespace fun;
	using namespace pythonm;
	//rcode(
	//	const char* p = "12345";
	//cout << p[0] << sp << p[2];
	//); rcode(
	//	float x = 7.8;
	//int y = 8.3;
	//cout << round( x ) << tab << round( x - 0.3 ) << nl;
	//cout << tplround( x ) << tab << tplround( x - 0.3 ) << nl;
	//); rcode(
	//	auto c = range( 1 , 8 );
	//auto d = range( 1.0 , 8.5 , -2.2 );
	//auto e = range( 1.0 , 8.5 , -2.2 , true );
	//cout << c << nl;
	//cout << d << nl;
	//cout << e << nl;
	//); rcode(
	//	cout << ceil( x ) << tab << floor( x ) << nl;
	//cout << ceil( y ) << tab << floor( y ) << nl;
	//); rcode(
	//	cout << sqrt( y ) << tab << pow( y , x ) << nl;
	//); rcode(
	//	NTIME( 10 )
	//	cout << randomint<bool>( true , false ) << sp;
	//); rcode(
	//	cout << getMiddle( 1 , 3 , 9 ) << sp;
	//cout << getMiddle( 11 , 13 , 29 ) << sp;
	//cout << getMiddle( 21 , 43 , 39 ) << sp;
	//)

}

void test_03( PCDC& cout )
{
	using namespace fun;
	//auto pdc = cout.GetWindow( )->GetDC( );
	//auto& dc = *pdc;

	//CRect  WindowsRectLimitRect;
	//dc.GetWindow( )->GetWindowRect( WindowsRectLimitRect );
	////DrawSnakeCircle( 80 , 2 , 50 , 500 )	;
	//CPoint start = GetRandomPoint( WindowsRectLimitRect );
	//CPoint end = GetRandomPoint( WindowsRectLimitRect );
	//CPoint three = GetRandomPoint( WindowsRectLimitRect );
	//CPoint four = GetRandomPoint( WindowsRectLimitRect );

	//CRect c { start,four };

	//CPen pen( PS_DASH , 5 , randomColor( ) );
	//CBrush brush( randomColor( ) );
	//auto old = dc.SelectObject( pen );
	//auto oldbrush = dc.SelectObject( brush );

	////draw line
	//dc.MoveTo( start.x , start.y );
	//dc.LineTo( end.x , end.y );
	//dc.LineTo( three );

	////draw rectangle
	//dc.Rectangle( start.x , start.y , end.x , end.y );

	////draw ellipse
	//dc.Ellipse( end.x , end.y , three.x , three.y );

	////fill rect
	//dc.FillRect( c , &brush );

	////TEXT 
	//dc.SetTextColor( randomColor( ) );
	//dc.TextOut( start.x , start.y , _T( "yellow" ) );
	//dc.DrawText( _T( "yellow" ) , c , DT_RIGHT );

	//dc.SelectObject( old );
	//dc.SelectObject( oldbrush );
	//pen.DeleteObject( );
	//brush.DeleteObject( );
	//cout.GetWindow( )->ReleaseDC( pdc );



}

namespace tdeminsion
{
	using ldouble = long double;
	class Mdeminsion
	{
	public:
		Mdeminsion( ldouble  ix , ldouble iy , ldouble iz ) :mp_ix( ix ) , mp_iy( iy ) , mp_iz( iz ) {}
		Mdeminsion( ) {}
		string makeinfo( string&& to = string( ) )
		{
			std::format_to( std::back_inserter( to ) , "x:{0:.3f},y:{1:.3f},z:{2:.3f}" , mp_ix , mp_iy , mp_iz );
			return to;
		}
		~Mdeminsion( ) { }

	private:
		ldouble mp_ix = 1;
		ldouble mp_iy = 1;
		ldouble mp_iz = 1;
	};
}

namespace concepts
{
	template<typename T , typename X>
	concept samt = std::same_as<T , X> && sizeof( T ) <= 4 && sizeof( X ) <= 4;

	template<typename T , typename X>
		requires samt<T , X>
	bool  samett( T t , X x )
	{
		return true;;
	}

	template<typename T , typename X>
	bool  samett( T t , X x )
	{
		return false;
	}

	template<typename T , typename X>
	bool  lsamett( T t , X x )
		requires std::is_same_v<T , X> && ( sizeof( T ) > 4 )
	{
		return true;
	}


}

namespace fun
{
	inline bool sleep( size_t ms )
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
		return true;
	}
	inline bool wait( size_t ms )
	{
		return sleep( ms );
	}
	auto findchar( const string& s , char c ) {
		size_t counts = 0;
		int firstloc = -1;
		int endloc = -1;
		for ( size_t i = 0; i < s.size( ); ++i )
		{
			if ( s.at( i ) == c )
			{
				if ( firstloc == -1 )
				{
					firstloc = i;
				}
				endloc = i;
				++counts;
			}
		}
		return tuple { counts , firstloc , endloc ,endloc };
	}
	char ntochar( int c )
	{
		return static_cast<char>( c );
	}
	int charton( char c )
	{
		return static_cast<int>( c );
	}
	void bits( int a )
	{
		getcout;
		cout << a << sp << bitset<32>( a ) << tab;
	}
	void bits( bool a )
	{
		getcout;
		cout << a << sp << bitset<32>( a ) << tab;
	}
	void bit( int a )
	{
		getcout;
		cout << a << sp << bitset<32>( a ) << tab;
	}
}

void test_01( PCDC& cout )
{
	using namespace fun;
	rcode(
		cout.outinput( );
	); rcode(
		shared_ptr p = make_shared<int[100]>( 10 );
	for ( size_t i = 0; i < 100; ++i )
	{
		cout << p[i] << sp;
	}
	); rcode(
		int ic = 253;
	int id = 127;
	bits( ic );
	bits( id );
	); rcode(
		bits( compl ic );
	bits( compl id );
	); rcode(
		bits( ( id bitand ic ) );
	bits( ( id bitor ic ) );
	); rcode(
		bits( not ic );
	bits( not id );
	); rcode(
		bits( ic not_eq id );
	bits( ic xor_eq id );
	bits( ic or_eq id );
	); rcode(
		bits( id or ic );
	); rcode(
		auto lfbits = [ ]<typename A>( A a , int c ) {
		a( c );
	};
	); rcode(
		void( *bsi )( int ) = bits;
	lfbits( bsi , ic );
	); rcode(
		auto lf = [ ] ( int a ) {bits( a ); };
	lfbits( lf , id );
	); rcode(
		std::function<void( int )> l = lf;
	lfbits( l , id );
	); rcode(
		std::function<void( int )> lt = bit;
	lfbits( lt , id );
	);

}

namespace sizefun {
	template<typename T>
	void psize( )
	{
		T t;
		getcout;
		cout << typeid( T ).name( ) << tab << sizeof( T ) << tab;
	}
}

void test_02( PCDC& cout )
{
	using namespace sizefun;
	rcode(
		psize<char>( );
	psize<char8_t>( );
	psize<char16_t>( );
	psize<char32_t>( );
	psize<wchar_t>( );
	); rcode(
		psize<bool>( );
	psize<int>( );
	psize<decltype( NULL )>( );
	psize<short>( );
	psize<long>( );
	psize<long long>( );
	); rcode(
		psize<float>( );
	psize<double>( );
	psize<long double>( );
	psize<void*>( );
	psize<nullptr_t>( );
	); rcode(
		cout << alignof( long double ) << tab;
	cout << alignof( long long ) << tab;
	cout << alignof( short ) << tab;
	cout << alignof( char ) << tab;
	cout << alignof( char8_t ) << tab;
	cout << alignof( char16_t ) << tab;
	cout << alignof( char32_t ) << tab;
	cout << alignof( wchar_t ) << tab;
	); rcode(
		volatile int i = 0;
	int&& ir = 0;
	cout.type( i );
	cout.type( ir );
	); rcode(
		auto ai = i;
	cout.type( ai );
	);


}

namespace nedel {

	class My
	{
	public:
		int a[20];
		My( );
		~My( );
		void* operator new( size_t size ) noexcept {
			getcout;
			auto p = malloc( size + 1 );
			*( (char*)p + size ) = 10;
			cout << st( My::new ) << sp << size << tab << int( *( (char*)p + size ) ) << nl;
			return p;
		}
		void* operator new( size_t size , int n ) noexcept {
			getcout;
			auto p = malloc( size + 2 );
			*( (char*)p + size ) = n;
			*( (char*)p + size + 1 ) = size;
			cout << st( My::new , n ) << sp << size << tab << int( *( (char*)p + size ) ) << nl;
			return p;
		}
		void operator delete( void* p , int n ) noexcept {
			getcout;
			::operator delete( p );
			cout << st( My::delete * p , n ) << sp << tab << int( *( (char*)p + sizeof( My ) ) ) << sp << int( *( (char*)p + sizeof( My ) + 1 ) ) << nl;
		}
		void* operator new( size_t size , void* place )  noexcept {
			return place;
		}
		void operator delete( void* p , size_t size ) noexcept
		{
			getcout;
			::operator delete( p );
			cout << st( My::delete ) << sp << p << tab << int( *( (char*)p + sizeof( My ) ) ) << sp << stnv( size ) << nl;
		}

	private:

	};

	My::My( )
	{
		getcout;
		cout << __func__ << nl;
	}

	My::~My( )
	{
		getcout;
		cout << __func__ << nl;
	}
}

void test_03( PCDC& cout )
{
	cout.timestart( );
	using namespace nedel;
	int heap[1024] { };
	auto p = new( sizeof( My ) ) My( );
	delete p;
	cout << __STDCPP_DEFAULT_NEW_ALIGNMENT__ << nl;

	cout << separtor;
	cout.timeend( );
}
namespace trait {

	template <typename A , typename B>
	bool is_same_v( A a , B b )
	{
		return false;
	}

	template<typename A>
	bool is_same_v( A a , A b )
	{
		return true;
	}

	template<typename T>
	bool is_pointer_v( T p )
	{
		return false;
	}

	template<typename T>
	bool is_pointer_v( T* p )
	{
		return true;
	}

	template <typename T>
	constexpr bool is_double_v( T t )
	{
		return false;
	}

	template<>
	constexpr bool is_double_v( double t )
	{
		return true;
	}

	template<typename...X>
	struct sametype {
		static constexpr bool value = false;
	};

	template<typename T>
	struct sametype<T , T> {
		static constexpr bool value = true;
	};

	template<typename T>
	struct is_bool {
		constexpr inline static bool value = false;
	};

	template<>
	struct is_bool<bool> {
		constexpr inline static bool value = true;
	};

	template<typename T>
	constexpr bool is_bool_v = is_bool<T>::value;

	template<typename T>
	struct typeID { constexpr inline static const int name = 00; };

	template<>
	struct typeID<int> { constexpr inline static const auto name = "int"; };

	template<typename T>
	struct isvoid :std::false_type { };
	template<> struct isvoid<void> :std::true_type { };
	template<> struct isvoid<void const> :std::true_type { };
	template<> struct isvoid<void volatile> :std::true_type { };
	template<> struct isvoid<void const volatile> :std::true_type { };

	template<typename T>
	struct is_point :std::false_type { };
	template<typename T>
	struct is_point<T*> :std::true_type { };

	template<typename T>
	auto type_name_is( T t )
	{
		if constexpr ( is_same_v<T , char > ) return "char";
		if constexpr ( is_same_v<T , bool> ) return "bool";

		if constexpr ( is_same_v<T , short> ) return "short";
		if constexpr ( is_same_v<T , int> ) return "int";
		if constexpr ( is_same_v<T , long> ) return "long";
		if constexpr ( is_same_v<T , long long> ) return "long long";

		if constexpr ( is_same_v<T , float> ) return "float";
		if constexpr ( is_same_v<T , double > ) return "double";

		if constexpr ( is_same_v<T , string > ) return "string";

		return "anonymous";
	}

};

namespace vTax {
	class taxprice {
	public:
		double m_tax = 0;
		double m_price = 0;
		double m_netprice = 0;
		double m_TaxRate = 0;
		double m_TaxOPRate = 0;
		taxprice( ) { }
		taxprice( double price , double tax ) :m_price( price ) , m_tax( tax ) , m_netprice( price - tax ) , m_TaxRate( tax / price ) , m_TaxOPRate( tax / ( price - tax ) ) { 	};
		string setTaxPrice( double price , double tax )
		{
			m_price = price;
			m_tax = tax;
			m_netprice = ( price - tax );
			m_TaxRate = ( tax / price );
			m_TaxOPRate = ( tax / ( price - tax ) );
			return FormatItemToString( );
		}
		string setNetPriceTax( double netprice , double tax )
		{
			m_price = netprice + tax;
			m_tax = tax;
			m_netprice = netprice;
			m_TaxRate = tax / ( netprice + tax );
			m_TaxOPRate = ( tax / netprice );
			return FormatItemToString( );
		}
		string setTaxRateNetPrice( double netprice , double ratetax )
		{
			m_netprice = netprice;
			m_TaxRate = ratetax;
			m_price = netprice * ( 1 + ratetax );
			m_tax = netprice * ratetax;
			m_TaxOPRate = ratetax / ( 1 + ratetax );
			return FormatItemToString( );
		}
		string FormatItemToString( ) {
			string str;
			str = format( "Price: {:6}, Tax: {:6}, NetPrice: {:^#6} ,TaxRate(t/n): {:6.2f}% ,TaxOutPriceRate(t/p): {:6.2f}% ." , m_price , m_tax , m_netprice , m_TaxRate * 100 , m_TaxOPRate * 100 );
			return str;
		}
	};
};

namespace test01 {
	class Tclass {
	public:
		Tclass( ) { }
		explicit Tclass( int ti ) :i( ti ) , name( std::to_string( ti ) ) , d( ti ) { }
	public:
		int i { };
		string name { "Tclass Empaty" };
		double d { };
	};
	auto f( Tclass t ) {
		getcout;
		cout << t.i << tab( 2 ) << t.name << tab( 2 ) << t.d << nl;
		return t;
	}

	struct Tstruct {
		int i {  };
		char a { };
		double d { };
	};
	auto rettuple( ) {
		return tuple { true,2,3,false,nullptr,"good",8.88 };
	}

};

void test_01( PCDC& cout )
{
	rcode(
		using namespace vTax;
	taxprice atax( 100.10 , 20.8 );
	); rcode(
		cout << atax.FormatItemToString( ) << nl;
	); rcode(
		cout << atax.setTaxPrice( 48 , 13 ) << nl;
	); rcode(
		cout << atax.setTaxRateNetPrice( 100 , 0.2 ) << nl;
	); rcode(
		int i = 64;
	double idb = 82.29;
	cout << std::format( "{:#x},{:+6b},{:#o}  ,  {},{},{}  " , i , i , -i , idb , idb , idb ) << nl;
	); rcode(
		using namespace test01;
	Tclass a;
	cout << a.i << tab( 2 ) << a.name << tab( 2 ) << a.d << nl;
	); rcode(
		Tclass b { };
	cout << b.i << tab( 2 ) << b.name << tab( 2 ) << b.d << nl;
	); rcode(
		Tclass c { 100 };
	cout << c.i << tab( 2 ) << c.name << tab( 2 ) << c.d << tab;
	cout << f( Tclass( 8 ) ).name << nl;
	); rcode(
		Tstruct t { .i = 10,.a = 'c',.d = 6.0 };
	cout << t.i << tab( 2 ) << t.a << tab( 2 ) << t.d << tab;
	); rcode(
		cout << rettuple( ) << nl;
	); rcode(
		cout << std::format( "3#: {3:#x} ,2#: {2:#b} , 1#: {1}, 0#: {0} ." , 1 , 2 , 483 , 124 ) << nl;
	); rcode(
		auto va = makector<deque<int>>( 30 , 20 , 10 );
	cout.lmod( 30 );
	cout << va << nl;
	std::ranges::sort( va );
	cout << va << nl;
	); rcode(
		cout << std::ranges::count_if( va , [ ] ( auto a ) {
			if ( ( a > 15 ) )
				return true;
			else
				return false;
			} ) << nl;
	);


}

void test_02( PCDC& cout )
{
	rcode(
		auto sp1 = make_unique<int>( 3 );
	cout << sp1 << tab << *sp1 << tab;
	); rcode(
		auto lf = [ ] ( auto p ) {
			getcout;
			cout << p << tab << *p << tab;
		};
	lf( std::move( sp1 ) );
	); rcode(
		auto sp2 = std::make_shared<int>( 20 );
	auto sp4 = sp2;
	lf( sp4 );
	cout << sp2.use_count( ) << nl;
	lf( sp4 );
	); rcode(
		cout << sp2.use_count( ) << nl;
	); rcode(
		auto temp = sp2;
	cout << sp2.use_count( ) << nl;
	); rcode(
		{
			auto temp = sp2;
		cout << sp2.use_count( ) << nl;
		}
	); rcode(
		cout << sp2.use_count( ) << nl;
	); rcode(
		auto temp2 = sp2;
	cout << sp2.use_count( ) << nl;
	);
}

template<typename T , size_t size = sizeof( T )>
auto sizeofarr( T( &arr )[size] )
{
	getcout;
	cout << size << nl;
	return sizeof( arr );
}

void test_03( PCDC& cout )
{
	cout.lmod( 30 );
	rcode(
		auto xa = makector<vector<int>>( 10 , 20 , 50 );
	); rcode(
		cout << xa << tab << &xa << nl;
	); rcode(
		for ( auto& i : xa )
		{
			cout << i << com << &i << semi << nl;
		}
	cout << nl;
	); rcode(
		std::ranges::sort( xa );
	cout << xa << nl;
	); rcode(
		for ( auto& i : xa )
		{
			cout << i << com << &i << semi << nl;
		}
	cout << nl;
	); rcode(
		cout << sizeof( xa[0] ) << tab << sizeof( short ) << tab << sizeof( int* ) << tab << sizeof( double ) << tab << sizeof( char ) << nl;
	); rcode(
		int arrint[88];
	double arrdouble[100];
	cout << sizeof( arrint ) << nl;
	cout << sizeofarr( arrint ) << nl;
	cout << sizeofarr( arrdouble ) << nl;
	); rcode(
		auto puq = std::make_shared<int>( 80 );
	cout << puq << tab << *puq << nl;
	); rcode(
		array<int , 10> aone { 10 };
	cout << aone.size( ) << tab << aone << nl;
	);

}

template <typename T>
T exp( T x , int ex )
{
	T sum = 1;
	if ( ex >= 0 ) {
		for ( size_t i = 0; i < ex; i++ )
		{
			sum *= x;
		}
	}
	else {
		for ( size_t i = 0; i < -ex; i++ )
		{
			sum /= x;
		}
	}
	return sum;
}

void test_04( PCDC& cout )
{
	rcode(
	); rcode(
		int* pn = nullptr;
	cout << pn << tab;
	); rcode(
		const size_t length = 10; int pa[length] = { 1,2,3,4,5,6,7,8,9,10 }; pn = pa; size_t i = 0;
	for ( i = 0; i < length; ++pn , ++i )
	{
		cout << pn << tab << *pn << semi;
	}
	cout << nl;
	cout << i << tab << pn << tab << *pn << nl;
	); rcode(
		string str = "12345abcd";
	auto va = makector<vector<int>>( 10 , 20 , 30 );
	cout << std::ssize( va ) << tab << sizeof( va ) << tab;
	cout << std::ssize( str ) << tab << sizeof( str ) << nl;
	); rcode(
		double const& rd = 3;
	cout << rd << nl;
	); rcode(
		cout << exp( 2.0 , 3 ) << tab;
	cout << exp( 3 , 2 ) << tab;
	cout << exp( 8 , 2 ) << tab;
	cout << exp( 2 , 4 ) << tab;
	cout << exp( -2 , 3 ) << tab;
	cout << exp( 2.0 , -3 ) << tab;
	cout << exp( 2.0 , 3 ) << tab;
	cout << exp( 8.0 , 3 ) << tab;
	cout << exp( 8 , 3 ) << tab;
	cout << exp( 9 , 3 ) << tab;
	cout << exp( 10 , 3 ) << tab;
	cout << exp( 4 , 3 ) << tab;
	cout << exp( 10.0 , -3 ) << tab;
	); rcode(
		cout.format( "3#: {3:#x} ,2#: {2:#b} , 1#: {1}, 0#: {0} ." , 1 , 2 , 483 , 124 );
	); rcode(
		cout.format( "3#: {3} ,2#: {2} , 1#: {1}, 0#: {0} ." , 256 , str , rd , 100 );
	);
}

template<size_t N>
struct tp
{
	static void say( ) {
		getcout;
		if  constexpr ( N >= 1 )
			tp<N - 1>::say( );
		cout << N << "*" << tab;
	}
};

template<>
struct tp<1>
{
	static void say( ) {
		getcout;
		cout << 1 << tab;
	}
};

template<typename T>
struct tp1
{
	T id;
	tp1( )
	{
		id = T( );
	}
};

template<typename T , typename T2>
struct tp2 :public tp1<T2>
{
	T id2;
	tp2( )
	{
		id2 = T( ) + 2;
	}
	template<typename T2>
	struct tp3 {
		T2 id3;
		tp3( )
		{
			id3 = T2( ) + 3;
		}
	};
	tp3<T2> tid;
};

template<typename T>
struct tp4
{
	inline static T id = T( 8 );
	inline static int id2 = 8;
	tp4( int i ) {
		id2 = i;
		id = id2 * id;
	}
};

template<typename T>
auto type_name_is( T t )
{
	if constexpr ( is_same_v<T , char > ) return "char";
	if constexpr ( is_same_v<T , bool> ) return "bool";

	if constexpr ( is_same_v<T , short> ) return "short";
	if constexpr ( is_same_v<T , int> ) return "int";
	if constexpr ( is_same_v<T , long> ) return "long";
	if constexpr ( is_same_v<T , long long> ) return "long long";

	if constexpr ( is_same_v<T , float> ) return "float";
	if constexpr ( is_same_v<T , double > ) return "double";
	if constexpr ( is_same_v<T , long double > ) return "long double";

	if constexpr ( is_same_v<T , string > ) return "string";
	return "anonymous";
}

void test_05( PCDC& cout )
{
	rcode(
		cout << type_name_is( "" ) << tab;
	tp<10>::say( );
	); rcode(
		tp2<int , double> t3;
	); rcode(
		cout << t3.id << tab << t3.id2 << tab << t3.tid.id3 << nl;
	); rcode(
		tp4<double> t4( 3 );
	cout << t4.id << tab << t4.id2 << nl;
	); rcode(
		long long i;
	short si;
	long double ld;
	string str;
	cout << type_name_is( 8 ) << tab;
	cout << type_name_is( ' ' ) << tab;
	cout << type_name_is( "" ) << tab;
	cout << type_name_is( 8.8 ) << tab;
	cout << type_name_is( i ) << tab;
	cout << type_name_is( si ) << tab;
	cout << type_name_is( ld ) << tab;
	cout << type_name_is( str ) << tab;
	); rcode(
		auto start = std::chrono::steady_clock::now( );
	std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
	auto end = std::chrono::steady_clock::now( );
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
	cout << time.count( ) << nl;
	);
}

//
//template<typename LINE>
//int triangle( LINE a , LINE b , LINE c )
//{
//	int ret = 0;
//	if ( a < 0 || b < 0 || c < 0 )
//	{
//		ret = 0; //不是三角形
//	}
//	else
//	{
//		if ( ( a >= b + c ) || ( b >= a + c ) || ( c >= a + b ) )
//		{
//			ret = 0;//不是三角形
//		}
//		else
//		{
//			ret += 1;//三角形
//			if ( a == b || b == c || a == c )
//			{
//				ret += 2;//等腰三角形
//				if ( a == c && a == b )
//				{
//					ret += 4;//等边三角形
//				}
//			}
//			if ( a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a )
//				ret += 8;//直角三角形
//		}
//	}
//	return ret;
//}
//
//template<typename T , typename F>
//bool tsort( T& a , T& b , F f )
//{
//	if ( f( a , b ) )
//		tswap( a , b );
//	return true;
//}
//
//template<typename T>
//bool tswap( T& a , T& b )
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//	return true;
//}
//
//template<typename T>
//bool comp( T a , T b )
//{
//	return a >= b;
//}
//
//template<typename T>
//bool tsort( T a , T c )
//{
//	T temp = a;
//	return true;
//}
//
//template<typename T>
//T epow( T n , int exp )
//{
//	T result = 1;
//	if ( exp < 0 )
//	{
//		result = 1 / epow( n , -exp );
//	}
//	else
//	{
//		for ( size_t i = 0; i < exp; ++i )
//		{
//			result *= n;
//		}
//	}
//	return result;
//}

//void test_10( PCDC& cout )
//{

//	rcode(
//		int n;
//	bool is = true;
//	cout << isbool<decltype( n )>::value << tab << isbool<decltype( true )>::value << tab;
//	cout << isbool<decltype( 3 > 2 )>::value << tab << isbool<double>::value << tab;
//	cout << isboolv<decltype( is )> << tab;
//	cout << isboolv<decltype( 3 > 2 )> << tab << isboolv<double> << nl;
//	); rcode(
//		cout << typeID<int>::ID << tab << typeID<double>::ID << tab;
//	cout << isvoid<int>{} << tab << isvoid<void>( ) << tab;
//	cout << isvoid<void volatile>{} << tab << isvoid<void const>( ) << nl;
//	); rcode(
//		cout << typeid( std::conditional<true , int , double>::type ).name( ) << tab( 2 );
//	cout << typeid( std::conditional<false , int , double>::type ).name( ) << tab;
//	int arrint[10];
//	int* pint;
//	cout << is_array_v<decltype( arrint )> << tab << is_pointer_v<decltype( pint )> << tab;
//	cout << is_array_v<decltype( pint )> << tab << is_pointer_v<decltype( arrint )> << tab;
//	); rcode(
//		int* np = nullptr;
//	cout << std::is_null_pointer_v<decltype( nullptr )> << tab;
//	const int ccin = 0;
//	cout << ispoint<decltype( arrint )>::value << tab;
//	cout << ispoint<decltype( np )>::value << tab;
//	cout << ispoint<decltype( pint )>::value << tab;
//	cout << ispoint<decltype( &n )>::value << tab;
//	);
//}


///	rcode(
//		string strmessage = "abcdefgABCDEFG";
//	cout << strmessage << tab;
//	ranges::for_each( strmessage , [ ] ( char& s ) {
//		s = std::tolower( s );
//		} );
//	cout << strmessage << nl;
//	);

//template<typename T>
//class toolT
//{
//public:
//	T I = T( );
//	bool isgreater = false;
//	bool operator()( T l , T r ) {
//		if ( !isgreater )
//			return l < r;
//		else
//			return l > r;
//	}
//	bool operator()( T l )
//	{
//		if ( !isgreater )
//			return l < I;
//		else
//			return l > I;
//	}
//	toolT& greater( )
//	{
//		isgreater = true;
//		return *this;
//	}
//	toolT& less( )
//	{
//		return *this;
//	}
//	auto& rlessandnegative( auto r ) {
//		auto lf = [ = ] ( auto& cr ) {
//			if ( cr < r )
//				cr = -r;
//		};
//		return lf;
//	}
//};
//
//template<typename T>
//struct asum {
//	inline static T sum = T( );
//	void operator()( T t ) {
//		sum += t;
//	}
//};


//void test_02( PCDC& cout )
//{
//	rcode(
//		auto va = makector<vector<char>>( 90 - 64 , 90 - 65 , 65 );
//	cout.lmod( 35 );
//	cout << va << nl;
//	); rcode(
//		toolT <int>t;
//	sort( va.begin( ) , va.end( ) , t.less( ) );
//	cout << va << nl;
//	); rcode(
//		sort( va.begin( ) , va.end( ) , t.greater( ) );
//	cout << va << nl;
//	); rcode(
//		sort( va.begin( ) , va.end( ) , toolT<int>( ).less( ) );
//	cout << va << nl;
//	); rcode(
//		for_each( va.begin( ) , va.end( ) , t.rlessandnegative( 20 ) );
//	cout << va << nl;
//	); rcode(
//		auto vb = makector<vector<int>>( 10 , 10 , 0 );
//	cout << vb << nl;
//	); rcode(
//		asum<int> a;
//	for_each( vb.begin( ) , vb.end( ) , a );
//	cout << a.sum << nl;
//	); rcode(
//		for ( int sum = 0; const auto i:vb )
//		{
//			sum += i;
//			cout << sum << tab << com << tab;
//		}
//	cout << nl;
//	); rcode(
//		for ( size_t i = 0 , isum { }; i < vb.size( ); i++ )
//		{
//			isum += vb[i];
//			cout << isum << tab << com << tab;
//		}
//	cout << nl;
//	); rcode(
//		for ( size_t i = 0 , isum {}; i < vb.size( ); i++ )
//		{
//			isum += vb.at( i );
//			cout << isum << tab << com << tab;
//		}
//	cout << nl;
//	); rcode(
//		std::shuffle( va.begin( ) , va.end( ) , std::rand( ) );
//	cout << va << nl;
//
//	);
//
//}

//namespace clonetest {
//	class can {
//	public:
//		int id = 0;
//		can( ) = default;
//		can( const can& e )
//		{
//			id = e.id;
//		}
//		virtual can* clone( )
//		{
//			return new can( *this );
//		}
//		virtual string say( ) { return "can"; }
//	};
//	class cane :public can {
//	public:
//		int ide = 0;
//		cane( ) = default;
//		cane( int i ) :ide( i ) {};
//		cane( const cane& e )
//		{
//			ide = e.ide;
//		}
//		virtual cane* clone( )
//		{
//			return new cane( *this );
//		}
//		virtual string say( ) { return "cane"; }
//	};
//	class cana :public can {
//	public:
//		int ida = 0;
//		cana( ) = default;
//		cana( int i ) :ida( i ) {};
//		cana( const cana& e )
//		{
//			ida = e.ida;
//		}
//		virtual cana* clone( )
//		{
//			return new cana( *this );
//		}
//		virtual string say( ) { return "cana"; }
//	};
//}
//
////void test_03( PCDC& cout )
////{
////	rcode(
////		using namespace clonetest;
////	); rcode(
////		cane e( 3 );
////	cana a( 4 );
////	can * pe = &e;
////	); rcode(
////		can * pa = &a;
////	auto ca = pa->clone( );
////	cout << ca->say( );
////	); rcode(
////		auto cb = pe->clone( );
////	cout << cb->say( );
////	); rcode(
////		cout.address( a , e );
////	cout.pt( pe , pa , ca , cb )
////		);
////}
//
////void test_08( PCDC& cout )
////{
////	rcode(
////		struct node {
////		int m_id = 0;
////		node* p_next = nullptr;
////		node( ) = default;
////		node( int id , node* pnext = nullptr ) :m_id( id ) , p_next( pnext ) {}
////		~node( ) {
////			p_next = nullptr;
////			m_id = -1;
////		}
////	};
////	node* head , * pn;
////	head = new node( 7 );
////	head->p_next = new node( 8 );
////	head->p_next->p_next = new node( 9 );
////	cout << head << tab << head->p_next << tab << head->m_id << nl;
////	); rcode(
////		cout << head->p_next->m_id << tab << head->p_next->p_next << tab( 3 );
////	pn = head->p_next;
////	cout << pn << tab << pn->m_id << tab << pn->p_next << tab << nl;
////	); rcode(
////		pn = head->p_next->p_next;
////	cout << pn << tab << pn->m_id << tab << pn->p_next << tab << nl;
////	); rcode(
////		pn->p_next = new node( 10 );
////	pn = pn->p_next;
////	cout << pn << tab << pn->m_id << tab << pn->p_next << tab << nl;
////	); rcode(
////		int n = 0;
////	auto maxid = head->m_id;
////	auto minid = head->m_id;
////	for ( auto it = head; it; it = it->p_next )
////	{
////		maxid = maxid > it->m_id ? maxid : it->m_id;
////		minid = minid < it->m_id ? minid : it->m_id;
////		cout << ++n << "# : " << it << tab << it->m_id << tab << it->p_next << sp << semi;
////	}
////	cout << "max is: " << maxid << tab << "min is: " << minid << nl;
////	); rcode(
////		for ( auto itd = head; itd; itd = itd->p_next )
////		{
////			auto temp = itd->p_next;
////			cout << itd << tab << temp << tab;
////			delete itd;
////			itd = temp;
////		}
////	); rcode(
////		n = 0;
////	for ( auto it = head; it; it = it->p_next )
////		cout << ++n << "# : " << it << tab << it->m_id << tab << it->p_next << nl;
////	);
////}
////
////void test_09( PCDC& cout )
////{
////	rcode(
////		auto va = makector<vector<int>>( 10 , 18 , 30 );
////	); rcode(
////		auto da = makector<deque<int>>( 10 , 20 , 20 );
////	); rcode(
////		int a;
////	int b;
////	long c;
////	long* p = nullptr;
////	long l;
////	); rcode(
////		double id;
////	void* voida;
////	const int ci = 0;
////	const int& rci = ci;
////	); rcode(
////		cout << std::is_pointer_v<decltype( voida )> << tab << semi;
////	cout << std::is_void_v<decltype( voida )> << tab << semi;
////	); rcode(
////		cout << std::is_const_v<decltype( ci )> << tab << semi;
////	cout << std::is_const_v<decltype( rci )> << tab << semi;
////	); rcode(
////		cout << std::is_reference_v<decltype( rci )> << tab << semi;
////	); rcode(
////		std::remove_cvref<decltype( rci )>::type rmcvr;
////	cout << typeid( rmcvr ).name( ) << tab( 2 );
////	cout << typeid( decltype( ( rci ) ) ).name( ) << nl;
////	); rcode(
////		std::remove_pointer_t<decltype( p )> tp;
////	cout << typeid( p ).name( ) << tab << semi << typeid( tp ).name( ) << nl;
////	); rcode(
////		cout << typeid( std::add_const<decltype( p )>::type ).name( ) << tab << semi << typeid( std::add_pointer<decltype( tp )>::type ).name( ) << nl;
////	);
////}

//void test_02( PCDC& cout )
//{
//	rcode(
//		enum class E { ONE = 1 , TWO , THREE };
//	E ec = E::ONE;
//	const int  cint = 100;
//	int* ci = const_cast<int*>( &cint );
//	*ci = 200;
//	); rcode(
//		cout << static_cast<int>( ec ) << tab;
//	cout << ci << sp << *ci << tab;
//	); rcode(
//		cout << ci << sp << *ci << tab;
//	cout << reinterpret_cast<int>( &ec ) << nl;
//	); rcode(
//		bool bx = false;
//	cout << alignof( Pack<int> ) << sp << ( 2 > 3 || 2 < 3 ) << sp;
//	cout << ( 2 > 3 && 2 < 3 ) << sp << ( !( 2 < 3 ) ) << sp;
//	); rcode(
//		cout << ( 2 != 3 ) << sp;
//	cout << ( bx |= ( 3 > 2 ) ) << sp;
//	cout << bx << sp;
//	); rcode(
//		vector<int> va { 2,3,5,6,7 };
//	auto cb = ranges::cbegin( va );
//	auto ce = ranges::cend( va );
//	ce--;
//	cout << *cb << tab << *ce << nl;
//	); rcode(
//		string hurdred = "100";
//	string twohurdred = "200";
//	cout << stol( hurdred ) * 2 + stol( twohurdred ) << nl;;
//	);
//}
//
//class tf {
//public:
//	class comp {
//	public:
//		bool updown = true;
//		bool setless( bool iset = false )
//		{
//			updown = iset;
//		}
//	} up;
//	void operator ()( ) {
//		getcout;
//		cout << __func__ << nl;
//	}
//
//};
//

//
////template<typename fun,typename T,typename X>
//
//void test_03( PCDC& cout )
//{
//	int i;
//	int& ri = i;
//	rcode(
//		cout << sametype<decltype( cout ) , int>::is << tab;
//	cout << sametype<decltype( i ) , int>::is << tab;
//	cout << sametype<decltype( 0 ) , int>::is << nl;
//	); rcode(
//		cout << sametype<decltype( ri ) , int>::is << tab;
//	cout << rametype<decltype( ( ri ) ) , decltype( i )>::is << tab;
//	cout << sametype<decltype( ( ri ) ) , decltype( i )>::is << nl;
//	); rcode(
//		cout << sametype<std::remove_cvref<decltype( ri )>::type , decltype( i )>::is << tab;
//	cout << sametype<decltype( ri ) , decltype( 0 )>::is << nl;
//	);
//
//}
//
//void test_04( PCDC& cout )
//{
//	rcode(
//		Pack<double>  pa( 8.8 , 6 );
//	pa.print( );
//	); rcode(
//		pa.resetsize( 8 , 3 );
//	pa.print( true );
//	); rcode(
//		pa.add( 5 );
//	pa.display( );
//	); rcode(
//		pa.resetsize( 4 , 3 );
//	pa.display( );
//	); rcode(
//		pa.add( 6 , 7 , 11 , 13 , 15 );
//	sort( pa.begin( ) , pa.end( ) , greater<int>( ) );
//	pa.display( );
//	); rcode(
//		int ie;
//	NTIME( 6 )
//	{
//		ie = rand( ) % 20;
//		pa.add( ie , ie * 2 );
//	}
//	sort( pa.begin( ) , pa.end( ) , less<int>( ) );
//	pa.display( false , 32 );
//	); rcode(
//		sort( pa.begin( ) , pa.end( ) , greater<int>( ) );
//	pa.display( false , 33 );
//	);
//}
//
//void af( )
//{
//	getcout;
//	rcode(
//		int a1;
//	int a2;
//	int a3;
//	); rcode(
//		cout.address( a1 , a2 , a3 );
//	);
//}
//
//int* plstack( int n )
//{
//	int a = 0;
//	getcout;
//	if ( n >= 0 ) {
//		cout << "#" << a << sp << &a << nl;
//		auto p = plstack( n - 1 );
//		cout << "p= " << p << nl;
//	}
//	return &a;
//}
//
//void test_05( PCDC& cout )
//{
//	rcode(
//		int a1;
//	int a2;
//	int a3;
//	); rcode(
//		cout.address( a1 , a2 , a3 );
//	); rcode(
//		int* p = new int[3];
//	cout.pt( p , p + 1 , p + 2 );
//	); rcode(
//		delete[ ]p;
//	); rcode(
//		cout << separtor;
//	af( );
//	); rcode(
//		cout << separtor;
//	plstack( 5 );
//	);
//
//}
//void test_07( PCDC& cout )
//{
//	class mother {
//	public:
//		mother( ) {
//			getcout;
//			cout << __func__ << nl;
//		}
//	};
//	class father {
//	public:
//		father( ) {
//			static int id = 0;
//			getcout;
//			cout << __func__ << "#" << id++ << nl;
//		}
//		//virtual string say( string name ) const {
//		//	name += " is father";
//		//	return name;
//		//}
//		virtual ~father( )
//		{
//			getcout;
//			cout << __func__ << nl;
//		}
//	};
//
//	class son :public father {
//	public:
//		son( ) {
//			getcout;
//			cout << __func__ << nl;
//		}
//		//virtual string say( string name ) const override {
//		//	name += " is son";
//		//	return name;
//		//}
//		void speak( ) {
//			getcout; cout << "speak()" << nl;
//		};
//		void speak( )const {
//			getcout; cout << "speak() const" << nl;
//		};
//		~son( )
//		{
//			getcout;
//			cout << __func__ << nl;
//		}
//	};
//
//	rcode(
//		//	father a;
//		//cout << a.say( "a" );
//		//); rcode(
//		//	son b;
//		//cout << b.say( "b" );
//		//); rcode(
//		//	father * p = &a;
//		//cout << p->say( "p" );
//		//); rcode(
//		//	p = &b;
//		//cout << p->say( "p" );
//		//); rcode(
//		//	auto l = [ = ] ( father& f , string name ) {getcout; cout << f.say( name ); };
//		//l( a , "l+a" );
//		//); rcode(
//		//	l( b , "l+b" );
//		//); rcode(
//		//	auto lp = [ = ] ( father* f , string name ) {getcout; cout << f->say( name ); };
//		//lp( &a , "lpa" );
//		//); rcode(
//		//	lp( &b , "lpb" );
//		//); rcode(
//		father * pf = new son;
//	cout << sizeof( *pf ) << nl;
//	delete pf;
//
//	);
//
//}
//
//
//void test_08( PCDC& cout )
//{
//	rcode(
//		class A {
//		const int ga = 0;
//		int a;
//		int c;
//		int& b = a;
//	};
//	class B {
//		int a;
//		int& b = a;
//	};
//	); rcode(
//		cout << sizeof( A ) << tab;
//	cout << sizeof( B ) << nl;
//	); rcode(
//		stringstream num;
//	double ix = 45.3;
//	double iy = 33.2;
//	auto iz = ix / iy;
//	num << iz;
//	cout << num.str( ) << tab( 3 );
//	num.str( "" );
//	bool ib = true;
//	num << boolalpha;
//	num << ib;
//	cout << num.str( ) << nl;
//	); rcode(
//		vector va { 0,0,1,7, 1,2,3,4,5,6,9,8,7 };
//	cout << va.size( ) << tab << va.end( ) - va.begin( ) << tab( 3 );
//	cout << *( va.end( ) - 3 ) << tab << *( va.begin( ) + 1 ) << tab( 2 );
//	cout << va.empty( ) << tab << va.size( ) << tab << va.max_size( ) << tab( 2 );
//	cout << ( va.end( ) == va.begin( ) ) << tab << ( va.end( ) != va.begin( ) ) << nl;
//	); rcode(
//		auto it = va.begin( );
//	auto ite = va.end( );
//	auto cit = va.cbegin( );
//	auto cite = va.cend( );
//	cout << it << sp << *it << tab << ++it << sp << *it << tab << --ite << sp << *ite << tab << --ite << sp << *ite << nl;
//	); rcode(
//		cout << cit << sp << *cit << tab << ++cit << sp << *cit << tab << --cite << sp << *cite << tab << --cite << sp << *cite << nl;
//	); rcode(
//		cout << va << nl;
//	cout << typeid( it ).name( ) << tab( 2 );
//	cout << typeid( ite ).name( ) << tab( 2 );
//	cout << typeid( cit ).name( ) << tab( 2 );
//	cout << typeid( ite ).name( ) << tab;
//	); rcode(
//		vector vb( va.begin( ) , va.end( ) - 3 );
//	cout << vb << nl;
//	); rcode(
//		vector vc( va );
//	cout << va << nl;
//	); rcode(
//		ranges::sort( va );
//	cout << va << nl;
//	); rcode(
//		auto iun = std::unique( va.begin( ) , va.end( ) );
//	vector vu( iun , va.end( ) );
//	cout << va << tab << *iun << nl;
//	); rcode(
//		cout << vu << nl;
//	);
//
//};
//
//void test_09( PCDC& cout )
//{
//	rcode(
//		vector va { 0,0,1,7, 1,2,3,4,5,6,9,8,7 };
//	vector vb { 12,23,33 };
//	cout << va << nl;
//	cout << vb << nl;
//	); rcode(
//		std::ostream_iterator<int>os( std::cout , "," );
//	std::copy( va.begin( ) , va.end( ) , os );
//	); rcode(
//		cout << va.size( ) << tab << vb.size( ) << tab;
//	vb.resize( va.size( ) + vb.size( ) );
//	cout << vb.size( ) << nl;
//	); rcode(
//		copy( va.begin( ) , va.end( ) , std::back_inserter( vb ) );
//	cout << vb << nl;
//	);
//
//};
//
//void test_10( PCDC& cout )
//{
//	rcode(
//		vector va { 0,0,1,7, 1,2,3,4,5,6,9,8,7 };
//	cout << va << nl;
//	); rcode(
//		ranges::sort( ranges::reverse_view( va ) );
//	cout << va << nl;
//	); rcode(
//		std::sort( va.begin( ) , va.end( ) , std::less<int>( ) );
//	cout << va << nl;
//	); rcode(
//		auto lf = [ ] ( auto a , auto b ) { return a > b; };
//	std::sort( va.begin( ) , va.end( ) , lf );
//	cout << va;
//	); rcode(
//		auto gf = [ ] ( auto& a , auto& b ) { return a < b; };
//	std::sort( va.begin( ) , va.end( ) , gf );
//	cout << va;
//	); rcode(
//		auto cf = [ ] ( auto& a ) { a++; };
//	std::for_each( va.begin( ) , va.end( ) , cf );
//	cout << va;
//	); rcode(
//		auto fl = [=] <int k = 10>( auto a ) { return a == k; };
//	auto fi = std::find_if( va.begin( ) , va.end( ) , fl );
//	cout << fi << tab << *fi << nl;
//	);
//
//};

void test_sleep_chrono_cast02( PCDC& cout )
{
	/*auto start = std::chrono::steady_clock::now( );
	std::this_thread::sleep_for( std::chrono::milliseconds( 40 ) );
	std::this_thread::sleep_for( std::chrono::microseconds( 30000 ) );
	std::this_thread::sleep_for( std::chrono::nanoseconds( 30000000 ) );
	auto end = std::chrono::steady_clock::now( );
	std::chrono::duration<double> es = std::chrono::duration<double>( end - start );
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start );
	std::chrono::microseconds us = std::chrono::duration_cast<std::chrono::microseconds>( end - start );
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
	cout << "elapsed time: " << es.count( ) << "s" << tab( 2 );
	cout << "elapsed time: " << ms.count( ) << "ms" << tab( 2 );
	cout << "elapsed time: " << us.count( ) << "us" << tab( 2 );
	cout << "elapsed time: " << ns.count( ) << "ns" << nl;*/

}

void test_chrono_time01( PCDC& cout )
{
	//code(
	//	auto start = std::chrono::steady_clock::now( );
	//); code(
	//	std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
	//); code(
	//	auto end = std::chrono::steady_clock::now( );
	//); code(
	//	std::chrono::duration<double> ps = std::chrono::duration<double>( end - start );
	//); lcode(
	//	cout << "time is: " << ps.count( ) << " seconds." << nl;
	//); code(
	//	std::chrono::duration<double , std::milli> ls = std::chrono::duration<double>( end - start );
	//); code(
	//	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
	////std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
	//); lcode(
	//	cout << "time is: " << ms.count( ) << "ms." << nl;
	//cout << "time is: " << ls.count( ) << "ms." << nl;
	//); code(
	//	std::chrono::microseconds us = std::chrono::duration_cast<std::chrono::microseconds>( end - start );
	//); code(
	//	//std::chrono::duration<double , std::micro> lus = std::chrono::duration<double>( end - start );
	//	std::chrono::duration<double , std::micro> lus = end - start;
	//); lcode(
	//	cout << "time is: " << lus.count( ) << "us." << nl;
	//cout << "time is: " << us.count( ) << "us." << nl;
	//); code(
	//	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start );
	//); code(
	//	std::chrono::duration<double , std::nano> lns = std::chrono::duration<double>( end - start );
	//); lcode(
	//	cout << "time is: " << lns.count( ) << "ns." << nl;
	//cout << "time is: " << ns.count( ) << "ns." << nl;
	//); lcode(
	//	cout.timestart( );
	//std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	//cout.timeend( 2 );
	//);

}

void test_ranges_maxcontainer01( PCDC& cout )
{
	//cout.settab( 5 );
	//lscode(
	//	int ia = 1;
	//int ib = -100;
	//int ic = 0;
	//cout << abs( ia ) << tab << abs( ib ) << tab << abs( ic ) << nl;
	//cout << separtor;
	//); lscode(
	//	float fa = 2.3 , fb = 0 , fc = -4.5;
	//cout << abs( fa ) << tab << abs( fb ) << tab << abs( fc ) << nl;
	//); lscode(
	//	cout << gmax( ia , ib , ic ) << tab << gmax( fa , fb , fc ) << nl;
	//); lscode(
	//	cout << gmin( ia , ib , ic ) << tab << gmin( fa , fb , fc ) << nl;
	//cout << separtor;
	//); lscode(
	//	auto va = makevector<int>( 20 , 30 );
	//cout << va << nl;
	//); lscode(
	//	ranges::sort( va ); cout << va << nl;
	//); lscode(
	//	ranges::for_each( va , [ ] ( int a ) {getcout; cout << a * 2 << tab; } ); cout << nl;
	//cout << ranges::count_if( va , [ ] ( int a ) {if ( a == 7 )return true; else return false; } );
	//cout << tab;
	//cout << ranges::count( va , 7 );
	//); lscode(
	//	cout << to_string( 100 ) << tab << ( to_string( 100000 ) ).length( ) << tab << stol( "1000" ) * 2 - stol( "500" ) << nl;
	//); lscode(
	//	cout << gmax( va ) << tab << gmin( va ) << nl;
	//); lscode(
	//	deque <int> da { 3,8,9,11 };
	//cout << gmax( da ) << tab << gmin( da ) << nl;
	//);
}

void test_ranges_minmax01( PCDC& cout )
{
	/*cout.lmod( 30 );
	lscode(
		for ( size_t i = 1; i < 10; i++ )
		{
			for ( size_t j = 0; j < 10; j++ )
			{
				cout << i << "*" << j << "=" << i * j << tab;
			}
			cout << nl;
		}
	cout << nl;
	); lscode(
		for ( size_t i = 0; i < 4; i++ )
		{
			cout << binfun( i , i * 2 ) << nl;
		}
	); lscode(
		auto va = makevector<int>( 30 , 100 );
	cout >> va;
	); lscode(
		auto ret = ranges::minmax( va );
	cout.type( ret );
	); lscode(
		cout << ret.max << tab << ret.min << nl;
	ranges::sort( va | views::reverse );
	cout << va << nl;
	); lscode(
		auto [minp , maxp] = minmax_element( va.begin( ) , va.end( ) );
	cout << *minp << tab << *maxp << tab;
	cout << *max_element( va.begin( ) , va.end( ) ) << tab << *min_element( va.begin( ) , va.end( ) ) << tab;
	cout << *ranges::max_element( va ) << tab << *ranges::min_element( va ) << tab;
	cout << ranges::size( va ) << tab;
	cout << ranges::ssize( va ) << tab;
	);*/
}

void test_tab_01( PCDC& cout )
{
	//cout.settab( 6 );
	//vector va { 0 };
	//NTIME( 99 )
	//	va.push_back( ix * 10 );
	//lscode(
	//	ranges::sort( va );
	//cout << va.size( ) << nl;
	//cout << separtor;
	//); lscode(
	//	size_t imod = 0;
	//for ( auto& i : va )
	//{
	//	cout << i << tab;
	//	if ( ++imod % 21 == 0 )
	//		cout << nl;
	//}
	//); lscode(
	//	cout << separtor;
	//cout.lmod( 20 );
	//ranges::sort( va | views::reverse );
	//cout << va << nl;
	//cout << separtor;
	//);
}

void test_struct_calss_01( PCDC& cout )
{
	/*struct S {
		int i : 3;
		int j : 5;
		int x : 3;
		int y : 5;
		struct s {
			int i : 3;
			int j : 5;
			int x : 3;
			int y : 5;
			struct z {
				int i : 3 = 3;
				int j : 5;
				int x : 3;
				int y : 5;
			}b;
		}d;
	};

	struct X {
		int i = 1;
		int j = 2;
		int x = 3;
	};

	class CX :public X {
	public:
		int id = 0;
	};
	lscode(
		S a;
	cout << sizeof( S ) << tab << a.d.b.i << tab << sizeof( S::s ) << tab << sizeof( S::s::z ) << tab << nl;
	); lscode(
		auto l = [ ]<typename T1 , typename T2> ( T1 i , T2 j ) { getcout; cout << i << tab << j << com << tab; };
	l( 4 , "good" );
	l( 5.0 , 'c' );
	l( 5 , 8 );
	); lscode(
		vector va { 3,8,9,9,10 };
	deque da { 8.8,9.8,8.98 };
	l( va , da );
	); lscode(
		X zt { .i{3},.x {8 } };
	cout << zt.i << tab << zt.j << tab << zt.x << nl;
	); lscode(
		auto vb = makevector<float>( 10 , 10 );
	for ( int i = 0; auto x:vb )
		cout << ++i << '#' << sp << x << sp( 4 );
	); lscode(
		CX cx;
	cout << cx.i << tab << cx.j << tab << cx.x << tab << cx.id << nl;
	);*/
}

void test_foeach_count( PCDC& cout )
{
	//template<typename Container , typename OP>
	//void foreachx( Container& c , OP op )
	//{
	//	for ( auto& i : c )
	//		op( i );
	//}
	//
	//template<typename Container , typename OP , typename IFOP>
	//void foreachif( Container& c , OP op , IFOP ifop )
	//{
	//	for ( auto& i : c )
	//		if ( ifop( i ) == true )op( i );
	//}
	//
	//template<typename Container , typename IFOP>
	//size_t countifx( Container& c , IFOP ifop )
	//{
	//	size_t n = 0;
	//	for ( auto& i : c )
	//		if ( ifop( i ) == true )n++;
	//	return n;
	//}
	//	timestart( true );
	//	cout.lmod( 20 );
	//
	//	lscode(
	//		auto va = makevector<int>( 20 , 20 );
	//	cout << va << nl;
	//	); lscode(
	//		deque vd { 1,0,2,3,5,6,6,7,8,9,10,11,23,38,25,48,99,100 };
	//	cout << vd << nl;
	//	); lscode(
	//		foreachx( va , [ ] ( int& a ) {a -= 1; } );
	//	cout << va << nl;
	//	); lscode(
	//		foreachif( va , [ ] ( int& a ) {a -= 1; } , [ ] ( int a ) {return a > 5; } );
	//	cout << va << nl;
	//	); lscode(
	//		cout << countifx( va , [ ] ( int a ) {return a > 14; } ) << nl;
	//	); lscode(
	//		foreachx( vd , [ ] ( int& a ) {a += 1; } );
	//	cout << vd << nl;
	//	); lscode(
	//		foreachif( vd , [ ] ( int& a ) {a -= 1; } , [ ] ( int a ) {return a < 5; } );
	//	cout << vd << nl;
	//	); lscode(
	//		cout << countifx( vd , [ ] ( int a ) {return a < 3; } ) << nl;
	//	);
	//
	//	cout << separtor;
	//	timeend( );
	//
	//}
	//
	//void test_01( PCDC& cout )
	//{
	//	timestart( true );
	//	cout.lmod( 20 );
	//
	//	lscode(
	//		auto va = makevector<int>( 20 , 20 );
	//	cout << va << nl;
	//	); lscode(
	//		deque vd { 1,0,2,3,5,6,6,7,8,9,10,11,23,38,25,48,99,100 };
	//	cout << vd << nl;
	//	); lscode(
	//		foreachx( va , [ ] ( int& a ) {a -= 1; } );
	//	cout << va << nl;
	//	); lscode(
	//		foreachif( va , [ ] ( int& a ) {a -= 1; } , [ ] ( int a ) {return a > 5; } );
	//	cout << va << nl;
	//	); lscode(
	//		cout << countifx( va , [ ] ( int a ) {return a > 14; } ) << nl;
	//	); lscode(
	//		foreachx( vd , [ ] ( int& a ) {a += 1; } );
	//	cout << vd << nl;
	//	); lscode(
	//		foreachif( vd , [ ] ( int& a ) {a -= 1; } , [ ] ( int a ) {return a < 5; } );
	//	cout << vd << nl;
	//	); lscode(
	//		cout << countifx( vd , [ ] ( int a ) {return a < 3; }) << nl;
	//	);
	//
	//	cout << separtor;
	//	timeend( );

}

void test_remove_if( PCDC& cout )
{

	//timestart;
	//lscode(
	//	auto va = makevector( 20 );
	//cout << va << nl;
	//); lscode(
	//	ranges::sort( va );
	//cout << va << nl;
	//); lscode(
	//	va.erase( remove_if( va.begin( ) , va.end( ) , [ ] ( int a ) {if ( a == 3 || a == 4 )return true; else return false; } ) , va.end( ) );
	//cout << va << nl;
	//); lscode(
	//	va.erase( remove_if( va.begin( ) , va.end( ) , [ ] ( int a )
	//		{
	//			if ( a < 2 || a> 18 )
	//				return true;
	//			else
	//				return false;
	//		} ) , va.end( ) );
	//cout << va << nl;
	//);
	//timeend( 1 );

}

void test_sort_002( PCDC& cout )
{
	//cout.lmod( 30 );
	//lscode(
	//	vector va { 8,7,9,3,5,4,7,2,0 };
	//NTIME( 20 )
	//	va.push_back( ix * rand( ) * 100 % 30 );
	//cout << va << nl;
	//); lscode(
	//	ranges::sort( va );
	//cout << va << nl;
	//); lscode(
	//	ranges::reverse( va );
	//cout << va << nl;
	//); lscode(
	//	for_each( va.begin( ) , va.end( ) , [ ] ( int a ) {
	//		getcout;
	//		if ( a % 2 == 0 && a != 0 )
	//			cout << a << sp;
	//		} );
	//); lscode(
	//	std::sort( va.begin( ) , va.end( ) );
	//cout << va << nl;
	//); lscode(
	//	std::sort( va.begin( ) , va.end( ) , [ ] ( int a , int b ) {return a > b; } );
	//cout << va << nl;
	//); lscode(
	//	std::sort( va.begin( ) , va.end( ) , [ ] ( int a , int b ) {return a < b; } );
	//cout << va << nl;
	//); lscode(
	//	cout.timestart( );
	//NTIME( 1000000 )
	//	va.push_back( ix );
	//cout.timeend( 1000000 );
	//); lscode(
	//	cout.timestart( );
	//NTIME( 100 )
	//	std::sort( va.begin( ) , va.end( ) , [ ] ( int a , int b ) {return a < b; } );
	//cout.timeend( 100 );
	//); lscode(
	//	cout.timestart( );
	//NTIME( 100 )
	//	ranges::sort( va.begin( ) , va.end( ) );
	//cout.timeend( 100 );
	//);
}

void test_file_fail01( PCDC& cout )
{

	//lscode(
	//	vector<int> va { 4 };
	//NTIME( 8 )
	//	va.push_back( ix * rand( ) % 20 + 3 );
	//cout << va << nl;
	//); lscode(
	//	ofstream of;
	//of.open( "d:/number.bin" , ios::out | ios::binary );
	//for ( auto i : va ) {
	//	cout << i << sp;
	//	of << i;
	//}
	//); lscode(
	//	of.close( );
	//); lscode(
	//	ifstream iif;
	//iif.open( "d:/number.bin" , ios::in | ios::binary );
	//int i = 0;
	//);
	//while ( !iif.eof( ) )
	//{
	//	iif >> i;

	//	cout << i << tab;
	//}
	//iif.close( );

}

void test_ranges( PCDC& cout )
{
	//timestart( );
	//cout.title( "begin ranges test..." );
	//cout.lmod( 30 );
	//code(
	//	vector va { 0 };
	//NTIME( 20 )
	//	va.push_back( rand( ) % 10 * ix );
	//); lcode(
	//	ranges::sort( va );
	//cout << va << newl;
	//); lscode(
	//	ranges::reverse( va );
	//cout << va << newl;
	//); lscode(
	//	cout << *ranges::begin( va ) << tab << *( ranges::end( va ) - 1 ) << tab << ranges::size( va ) << tab << ranges::ssize( va ) << sp << ranges::empty( va ) << sp << *ranges::min_element( va ) << sp << *ranges::max_element( va ) << newl;
	//); lscode(
	//	cout << ( "ok" == "ok" ) << tab << ( "bad" == "good" ) << newl;
	//); lscode(
	//	cout << imin( 2 , 3 ,4, 5 ) << tab << imax( 3 , 8 , 9 ) << newl;
	//);
	//cout.title( "end..." );
	//timeend( 30 );
}

void test_lambda_00( PCDC& cout )
{
	//auto value( string && s ) { return "string&& s"; }
	//auto value( const string & s ) { return "const string& s"; }
	//cout.lmod( 30 );
	//lscode(
	//	vector va { 0 };
	//NTIME( 59 )
	//	va.push_back( ix * rand( ) * 47 % 17 );
	//cout << va << nl;
	//); lscode(
	//	cout.timestart( );
	//NTIME( 1000000 )
	//	ranges::sort( va );
	//cout.timeend( 1000000 );
	//cout << va << nl;
	//); lscode(
	//	int result = 0;
	//for_each( va.begin( ) , va.end( ) , [ & ] ( int a ) {
	//	result += a; } );
	//cout << result << nl;
	//); lscode(
	//	result = 0;
	//for_each( va.begin( ) , va.end( ) , [ & ] ( int a ) {
	//	getcout; cout << result << "ok"; if ( a == 3 ) result++; } );
	//cout << result << nl;
	//);



}

void test_template_var( PCDC& cout )
{
	/*template< template <typename , typename > class C , typename T , std::allocator<T> >
	auto container( C<T , std::allocator<T> > c )
	{
		getcout;
		cout << "C<T,std::allocator<T>>" << nl;
		return T( );
	}

	template< template <typename , typename , typename ...> class C , typename T , typename Allocter = std::allocator<T> , typename ...Args>
	auto container( C<T , Args... , Allocter > c )
	{
		getcout;
		cout << "C<T,...,A>" << nl;
		return T( );
	}

	template<typename T >
	auto container( T c )
	{
		getcout;
		cout << "T" << nl;
		return T( );
	}

	template<typename T , typename X , template< typename , typename > typename C >
	auto container( C<T , X> c )
	{
		getcout;
		cout << "C<T,X>" << nl;
		return T( );
	}

	template<typename T , typename A , typename B , template< typename , typename , typename> typename C >
	auto container( C<T , A , B> c )
	{
		getcout;
		cout << "C<T,A,B>" << nl;
		return T( );
	}

	template<typename T , typename...A , typename B , template< typename , typename , typename...> typename C >
	auto container( C<T , A... , B> c )
	{
		getcout;
		cout << "C<T,A...,B>" << nl;
		return T( );
		cout.lmod( 30 );
		int ia = 0;
		float fa = 0;
		bool ib = true;
		CString cs = L"CString";
		string str = "string";
		wstring wstr = L"wstring";
		vector va { 1,0 };
		tuple tuplea { 1,2.0,"ok" };
		lscode(
			container( ia );
		container( fa );
		container( ib );
		container( cs );
		container( str );
		container( wstr );
		container( tuplea );

		);
	}*/



}

unsigned int long long ntommulti( unsigned long long int a , unsigned long long int b )
{

	//getcout;
	//cout << "阶乘" << nl;
	//cout << separtor;

	//int n = a , m = b , total = n;
	//cout << n << "-" << m << " 的阶乘：" << nl;
	//cout << n;
	//for ( int i = n + 1; i <= m; ++i ) {
	//	cout << "*" << i;
	//	total *= i;
	//}
	//cout << " = " << total;
	//cout << separtor;
	//return total;

}

unsigned int indexmulti( )
{

	//getcout;
	//cout << "乘法口诀表" << nl;
	//cout << separtor;
	//for ( unsigned int i = 1; i <= 9; ++i ) {
	//	for ( unsigned int j = 1; j <= i; ++j ) {
	//		cout << j << " * " << i << " = " << i * j << sp;
	//	}
	//	cout << nl;
	//	cout << separtor;
	//}
	//cout << separtor;
	//return 0;

}

void showlsort( )
{

	//getcout;
	//vector va { 4 };
	//NTIME( 8 )
	//	va.push_back( ix * rand( ) % 20 + 3 );
	//cout << "Begin Sort vector va :" << nl;
	//sort( va.begin( ) , va.end( ) , [ & ] ( int a , int b ) {
	//	getcout;
	//	cout << va << nl;
	//	cout << separtor;
	//	return a > b;
	//	} );
	//cout << va;

}

void test_sort_foreach_time( PCDC& cout )
{
	//cout.timestart( );
	//timestart( true );
	//cout.lmod( 30 );
	//lscode(
	//	auto va = makevector<int>( 30 , 20 );
	//cout << va << nl;
	//); lscode(
	//	ranges::sort( va );
	//cout << va << nl;
	//); lscode(
	//	for_each( va.begin( ) , va.end( ) , [ ] ( int& a ) {
	//		if ( a == 5 )
	//			a = 6;
	//		} );
	//cout << va << nl;
	//); lscode(
	//	for_each( find( va.begin( ) , va.end( ) , 7 ) , va.end( ) , [ ] ( int& a ) {
	//		a = 9; } );
	//cout << va << nl;
	//); lscode(
	//	auto i = count_if( va.begin( ) , va.end( ) , [ ] ( int a ) {
	//		return a == 6;
	//		} );
	//cout << i << tab << va.size( ) << nl;
	//); lscode(
	//	cout << va << nl;
	//cout << *begin( va ) << tab << *( end( va ) - 1 ) << nl;
	//); lscode(
	//	unsigned long long total = 0;
	//unsigned long long itotal = 0;

	//NTIME( 1000 )
	//{
	//	cout << ( total += ix ) << sp;
	//	itotal++;
	//}
	//cout << itotal << nl;
	//);
	//cout << separtor;
	//timeend( 1 );
	//cout.timeend( );

}

void test_str_function( PCDC& cout )
{
	//bool equalstring( const char* l , const char* r )
	//{
	//
	//	while ( *l != '\0' || *r != '\0' )
	//	{
	//		if ( *l++ != *r++ )
	//			return false;
	//	}
	//	return true;
	//}
	//
	//size_t gstrlen( const char* l )
	//{
	//	size_t strlen = 0;
	//	while ( *l++ != '\0' )
	//	{
	//		++strlen;
	//	};
	//
	//	return strlen;
	//}
	//
	//bool swapchar( char* l , char* r )
	//{
	//	if ( l != nullptr && r != nullptr && *l != '\0' && *r != '\0' )
	//	{
	//		char c = *l;
	//		*l = *r;
	//		*r = c;
	//		return true;
	//	}
	//	return false;
	//}
	//
	//bool gstrcopy( char* dest , const char* src )
	//{
	//	if ( dest != nullptr && src != nullptr && *src != '\0' )
	//	{
	//		size_t surlen = gstrlen( src );
	//		memcpy( dest , src , surlen + 1 );
	//		return true;
	//	}
	//	return false;
	//}
	//
	//bool gstrcat( char* dest , const char* src1 , const char* src2 )
	//{
	//	if ( dest != nullptr )
	//	{
	//		size_t src1len = gstrlen( src1 );
	//		size_t src2len = gstrlen( src2 );
	//		memcpy( dest , src1 , src1len );
	//		memcpy( dest + src1len , src2 , src2len + 1 );
	//		return true;
	//	}
	//	return false;
	//}
	//
	//bool gstrcat( char* dest , const char* src )
	//{
	//	if ( dest != nullptr )
	//	{
	//		size_t srclen = gstrlen( src );
	//		size_t destlen = gstrlen( dest );
	//		memcpy( dest + destlen , src , srclen + 1 );
	//		return true;
	//	}
	//	return false;
	//}
	//
	//bool gstrcat( char* dest , const char* src , size_t n )
	//{
	//	if ( dest != nullptr )
	//	{
	//		size_t srclen = gstrlen( src );
	//		size_t destlen = gstrlen( dest );
	//		memcpy( dest + destlen , src , n );
	//		*( dest + destlen + n ) = '\0';
	//		return true;
	//	}
	//	return false;
	//}
	//
	//bool gstrncat( char* dest , size_t n , const char* src )
	//{
	//	if ( dest != nullptr )
	//	{
	//		size_t srclen = gstrlen( src );
	//		size_t destlen = gstrlen( dest );
	//		n = min( n , destlen );
	//		memcpy( dest + n , src , srclen );
	//		*( dest + n + srclen ) = '\0';
	//		return true;
	//	}
	//	return false;
	//}
	//
	//char* reversestr( char* l )
	//{
	//	char* ptail = l + gstrlen( l ) - 1;
	//	char* savel = l;
	//	while ( l < ptail && swapchar( l++ , ptail-- ) ) { };
	//	return savel;
	//}
	//
	//bool IsOdd( int i ) { return ( ( i % 2 ) == 1 ); }
	//
	//bool IsEven( int i ) { return ( ( i % 2 ) == 0 ); }

		//cout.timestart( );
		//timestart( true );
		//cout.lmod( 20 );
		//lscode(
		//	const char* pa = "abcd";
		//const char* spa = "efg";
		//const char* fpa = "hijk";
		//char apa[ ] = "lmon";
		//char* npa = new char[20];
		//char* dpa = new char[20];
		//); lscode(
		//	cout << equalstring( pa , spa ) << sp;
		//cout << equalstring( fpa , spa ) << sp;
		//cout << equalstring( fpa , pa ) << sp;
		//cout << equalstring( pa , fpa ) << sp;
		//cout << separtor;
		//); lscode(
		//	cout << gstrlen( pa ) << sp << gstrlen( spa ) << sp << gstrlen( fpa ) << nl;
		//); lscode(
		//	cout << apa;
		//cout << tab << reversestr( apa ) << tab << apa << nl;
		//); lscode(
		//	gstrcopy( npa , fpa );
		//cout << npa << nl;
		//); lscode(
		//	gstrcat( dpa , fpa , pa );
		//cout << dpa << nl;
		//); lscode(
		//	cout << dpa << sp << fpa << nl;
		//gstrcat( dpa , fpa , 2 );
		//cout << dpa << nl;
		//); lscode(
		//	cout << dpa << sp << fpa << nl;
		//gstrncat( dpa , 3 , fpa );
		//cout << dpa << sp << fpa << nl;
		//);
		//cout << separtor;
		//delete[ ]npa;
		//delete[ ]dpa;
		//timeend();
		//cout.timeend();

}

void test_ranges_02( PCDC& cout )
{
	/*timestart( true );
	cout.lmod( 20 );

	lscode(
		auto va = makevector<int>( 20 , 20 );
	cout << va << nl;
	); lscode(
		ranges::sort( va , less<int>( ) );
	cout << va << nl;
	); lscode(
		ranges::sort( va , greater<int>( ) );
	cout << va << nl;
	); lscode(
		array v { 1,0,2,3,5,6,6,7,8,9,10,11,23,38,25,48,99,100 };
	cout << v << nl;
	); lscode(
		ranges::sort( v , less<int>( ) );
	cout << v << nl;
	); lscode(
		ranges::sort( v , greater<int>( ) );
	cout << v << nl;
	); lscode(
		deque vd { 1,0,2,3,5,6,6,7,8,9,10,11,23,38,25,48,99,100 };
	cout << vd << nl;
	); lscode(
		ranges::sort( vd , less<int>( ) );
	cout << vd << nl;
	); lscode(
		ranges::sort( vd , greater<int>( ) );
	cout << vd << nl;
	);

	cout << separtor;
	timeend( );*/

}

template<typename T>
T lstraits( T t , string name )
{
	//	getcout;
	//	cout << "Variable " << name << " type traits test is: " << separtor;
	//
	//#define showtrait(type)  cout<<"is "#type"? : "<<tab(2)<<is_##type<T>::value<<nl;
	//#define showtraits(type)  cout<<#type"? : "<<tab(2)<<type<T>::value<<nl;
	//	showtrait( void );
	//	showtrait( null_pointer );
	//	showtrait( integral );
	//	showtrait( floating_point );
	//	showtrait( array );
	//	showtrait( enum );
	//	showtrait( union );
	//	showtrait( class );
	//	showtrait( function );
	//	showtrait( pointer );
	//	showtrait( lvalue_reference );
	//	showtrait( rvalue_reference );
	//	showtrait( member_object_pointer );
	//	showtrait( member_function_pointer );
	//	showtrait( fundamental );
	//	showtrait( arithmetic );
	//	showtrait( scalar );
	//	showtrait( object );
	//	showtrait( compound );
	//	showtrait( reference );
	//	showtrait( member_pointer );
	//	showtrait( const );
	//	showtrait( volatile );
	//	showtrait( trivial );
	//	showtrait( trivially_copyable );
	//	showtrait( standard_layout );
	//	showtrait( empty );
	//	showtrait( polymorphic );
	//	showtrait( abstract );
	//	showtrait( final );
	//	showtrait( aggregate );
	//	showtrait( signed );
	//	showtrait( unsigned );
	//	showtrait( bounded_array );
	//	showtrait( unbounded_array );
	//	showtrait( constructible );
	//	showtrait( default_constructible );
	//	showtrait( copy_constructible );
	//	showtrait( move_constructible );
	//	showtrait( copy_assignable );
	//	showtrait( move_assignable );
	//	showtrait( destructible );
	//	showtraits( has_virtual_destructor );
	//	showtraits( has_unique_object_representations );
	//	showtraits( alignment_of );
	//	return T( );
}

void test_VA01( PCDC& cout )
{
	/*showcode(
		vector va { 3,8,9,9,10,11,12 };
	cout << gsum( va ) << nl;
	); showcode(
		deque ddc { 8.8,9.8 };
	cout << gsum( ddc ) << nl;
	); showcode(
		deque da { 8.8,9.8,7.6,3.2,8.98 };
	); showcode(
		cout << sum( va.begin( ) , va.end( ) ) << nl;
	cout << gsum( da ) << nl;
	); showcode(
		vector vc { 3,8,12 };
	cout << sum( vc.begin( ) , vc.end( ) ) << nl;
	); showcode(
		cout << sum( da.begin( ) , da.end( ) ) << nl;
	cout << gsum( da ) << nl;
	); showcode(
		auto [x , y , z] = structfun( 1 , 2 );
	cout << x << tab << y << tab << z << nl;
	);*/
}

//template<typename T , typename P>
//auto rectm( T w , P h )
//{
//	return w * h;
//}
//
//template<typename T  >
//T circlem( T r , int i , int j )
//{
//	getcout;
//	cout << "in circlem" << tab << i << tab << j << nl;
//	cout << r << nl;
//	return r;
//}
//
//template<typename T , typename H>
//auto tanglem( T b , H h )
//{
//	return b * h / 2;
//}

////template <typename A , typename ...Args>
////auto  binfun( A a , Args...args )
////{
////	A sum = a + ( args + ... );
////	size_t n = sizeof...( Args ) + 1;
////	long double avg = sum / n;
////	auto  x = ( abs( a - avg ) + ( abs( avg - args ) + ... ) ) / n;
////	return tuple { sum ,n,avg,x };
////}
////
////auto structfun( int a , int b )
////{
////	int x = a * 2;
////	int y = b * 2;
////	auto z = to_string( a + b );
////	return tuple { x , y , z };
////}
////
////template<typename FUN >
////void runf( FUN&& f )
////{
////	std::mutex l;
////	l.lock( );
////	getcout;
////	cout << "#" << this_thread::get_id( ) << tab;
////	f( );
////	l.unlock( );
////}
////
//
//void f1( int icount , int imod , int isecond , int* iret , int& iret2 )
//{
//	getcout;
//	int count = icount;
//	cout.timestart( );
//	NTIME( icount ) {
//		std::this_thread::sleep_for( std::chrono::milliseconds( isecond ) );
//		cout << ix + 1 << tab << tab;
//		if ( ( 1 + ix ) % imod == 0 )
//		{
//			--count;
//			++iret2;
//			cout << icount - count << "#" << nl;
//		}
//	}
//	cout << nl;
//	*iret = count;
//	cout.timeend( icount );
//	//cout.location( source_location::current( ) );
//	cout.printid( ) << tab;
//}
//
//template <typename RET , typename... Args>
//void f2( RET& ret , Args...args )
//{
//	getcout;
//	cout.printid( ) << tab;
//	cout << __func__ << tab << ret << sp;
//	constexpr int asize = sizeof...( args ) + 1;
//	int tmp[asize] = { ( 0,args ) ... };
//	for ( auto i : tmp )
//		ret += i;
//	std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
//	//	( ( *this << args << sp ) , ... );//	( cout << ...<< args);
//	( ( cout << args << sp ) , ... );
//}
//
//std::mutex mtx_iCount;
//
//static size_t	iCount = 0;
//size_t task( )
//{
//	getcout;
//	cout.timestart( );
//	NTIME( 1000000 )
//	{
//		iCount++;
//	}
//	cout.timeend( );
//	cout.timestart( );
//	NTIME( 1000000 )
//	{
//		mtx_iCount.lock( );
//		iCount--;
//		mtx_iCount.unlock( );
//	}
//	cout.timeend( );
//	return iCount;
//}
//
//#define name(Arg) #Arg": "<<Arg
//
//void test_01( PCDC& cout )
//{
//	//lscode(
//	//	int ret = 0;
//	////f2(i, 1 , 2 , 3  );
//	//thread t1( f2<int , int , int , int , int> , ref( ret ) , 2 , 3 , 4 , 5 );
//	//t1.join( );
//
//	////); code(
//	//	//std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
//	//); lscode(
//	//	cout.printid( ) << tab;
//	//cout << __func__ << tab << name( ret ) << sp;
//	//); lscode(
//	//	int il = 1100;
//	//int* p = &il;
//	//int& ril = *p;
//	//int& rril = il;
//	//const int* cp = p;
//	//const int* const ccp = p;
//	//CString str = "god";
//	//); lscode(
//	//	cout.ps( il , p , *p , ril , rril , *cp , *ccp , str , ret );
//	//); lscode(
//	//	cout.pt( il , p , *p , ril , rril , *cp , *ccp , str , ret );
//	//); lscode(
//	//	cout.pb( il , p , *p , ril , rril , *cp , *ccp , str , ret );
//	//);
//}
//
//void test_02( PCDC& cout )
//{
//	lscode(
//		int ret = 0 , i = 3;
//	thread t2( f2<int , int > , ref( ret ) , i );
//	); lscode(
//		cout << t2.hardware_concurrency( ) << nl;
//	); lscode(
//		cout << t2.get_id( ) << nl;
//	); lscode(
//		cout << t2.native_handle( ) << nl;
//	t2.join( );
//	); lscode(
//		cout << t2.joinable( ) << nl;
//	); lscode(
//		thread ta( task );
//	cout << ta.get_id( ) << nl;
//	//thread tb( task );
//	ta.join( );
//	//tb.join( )
//	); lscode(
//		cout << iCount << nl;
//	cout.type( mtx_iCount ) << nl;
//	); code(
//		cout.printid( );
//	cout << ::AfxGetAppName( ) << tab << ::AfxGetThread( )->m_nThreadID << tab << nl;
//	); lscode(
//		cout << *::AfxGetApp( )->m_lpCmdLine << nl;
//	); lcode(
//		auto hHeap = HeapCreate( NULL , 4096 , 4096 );
//	cout << hHeap << nl;
//	HeapDestroy( hHeap );
//	); lcode(
//	);
//}
//
//class road
//{
//public:
//	long int length;
//	struct X {
//		int x1;
//	}sx;
//	union UX {
//		int x;
//		int y;
//		int* p;
//	}ux;
//
//	static struct X a;
//public:
//	road( ) :length( 0 ) {
//		getcout;
//		cout << this << tab << "Ctor" << tab << length << nl;
//	}
//	road( long len ) :length( len ) {
//		getcout;
//		cout << this << tab << "Ctor(long)" << tab << length << nl;
//	}
//	~road( )
//	{
//		length = 0;
//		getcout;
//		cout << this << "destory road" << sp << length << nl;
//	}
//	void* operator new( size_t size )
//	{
//		getcout;
//		cout << "new*size=" << sp << size << tab << __func__ << nl;
//		return malloc( size );
//	}
//	void operator delete( void* p , size_t size )
//	{
//		getcout;
//		cout << "del*size=" << sp << size << tab << "*p=" << sp << p << nl;
//		if ( p != nullptr )
//			free( p );
//	}
//	void say( )
//	{
//		getcout;
//		cout << this << tab << length << nl;
//	}
//};
//
//void test_03( PCDC& cout )
//{
//	lscode(
//		road r1;
//	); lscode(
//		road * pr2 = new road( 200 );
//	); lscode(
//		r1.say( );
//	); lscode(
//		pr2->say( );
//	); lscode(
//		cout << pr2 << nl;
//	); lscode(
//		delete pr2;
//	); lscode(
//		cout << pr2 << nl;
//	pr2->say( );
//	); lscode(
//		cout << sizeof( r1 ) << nl;
//	);
//}
//
//auto autof( auto i , auto j )
//{
//	return i + j;
//}
//
//
//int autofl( int i , int j )
//{
//	return i + j;
//}
//
//void test_04( PCDC& cout )
//{
//	lscode(
//		cout << autof( 3 , 4 ) << nl;
//	); lscode(
//		cout << autof( 3 , 4.4 ) << nl;
//	); lscode(
//		auto i = 10;
//	auto ik { 12 };
//	auto il = { 20 };
//	auto ilk = { 1,2,3 };
//	); lscode(
//		cout.pt( i , ik , il , ilk );
//	); lscode(
//		auto lf = autofl;
//	cout << lf( 13 , 4 ) << nl;
//	);
//
//}
//
//class ctorf {
//public:
//	int x;
//	int y;
//	ctorf( int ix ) :x( ix ) {}
//	ctorf( int ix , int iy ) :ctorf( ix ) {
//		y = iy;
//	}
//
//};
//
//void test_05( PCDC& cout )
//{
//	lscode(
//		ctorf a( 2 , 5 );
//	cout << a.x << tab << a.y << nl;
//	); lscode(
//		auto clf = [ ] ( int a , int b ) {return a < b; };
//	set <int , decltype( clf )> lsa { 12,3,4,5,6,1 };
//	cout << lsa << nl;
//	); lscode(
//		auto lf = [ ] ( int a , int b ) {return a > b; };
//	set <int , decltype( lf )> sa { 12,3,4,5,6,1 };
//	cout << sa << nl;
//	); lscode(
//		tuple tua { 1,2.8,"good" };
//	const auto & [first , second , three] = tua;
//	cout << first << tab << second << tab << three << nl;
//	); lscode(
//		int aone[ ] { 3,8,9 };
//	const auto & [one , two , th] = aone;
//	cout << one << tab << two << tab << th << nl;
//	); lscode(
//		cout << std::is_aggregate_v<decltype( aone ) > << nl;
//	); lscode(
//		cout << std::is_aggregate_v<decltype( lf ) > << nl;
//	); lscode(
//		cout << std::is_aggregate_v<decltype( a ) > << nl;
//	); lscode(
//		cout << std::is_aggregate_v<decltype( tua ) > << nl;
//	);
//
//}
//
//auto fp( auto p )
//{
//	getcout;
//	cout << __func__ << tab << p.use_count( ) << nl;
//	return p;
//}
//
//void test_06( PCDC& cout )
//{
//	lscode(
//		auto p = make_shared<int>( 15 );
//	cout << *p << tab << p.use_count( ) << nl;
//	); lscode(
//		auto x = fp( p );
//	cout << *p << tab << p.use_count( ) << nl;
//	); lscode(
//		cout << alignof( decltype( p ) ) << nl;
//	cout << alignof( ctorf ) << nl;
//	);
//
//}
//
//template<typename T , typename ...Args>
//void serls( T a , Args...args )
//{
//	getcout;
//	constexpr size_t N = sizeof...( Args );
//	//constexpr size_t I = N - 1;
//	cout << "-(";
//	cout << "value: " << a << sp << "size: " << sizeof( a );
//	cout << ")-" << nl;
//	if constexpr ( N >= 1 )
//	{
//		serls( args... );
//	}
//	else
//	{
//		cout << "...end" << nl;
//	}
//}
//#define lsva(...) cout<<__VA_OPT__("**")##__VA_ARGS__<<nl;
//
//void test_07( PCDC& cout )
//{
//	vector<int> va {};
//	size_t imod = 8000;
//	BEGINTEST( imod )
//	{
//		va.push_back( rand( ) % ( ++ix ) - imod / 2 );
//		auto static sret = ranges::minmax_element( va );
//		auto iret = ranges::minmax_element( va );
//		if ( ( *iret.min != *sret.min ) || ( *iret.max != *sret.max ) )
//		{
//			sret = iret;
//			cout << sret << cout.modline( 4 , tab );
//		}
//	}ENDTEST
//		cout.modline( 5 , tab , true );
//	cout << va.size( ) << nl;
//
//}
//
//template<typename T , size_t isize = 0>
//class Pack {
//public:
//	T* head = nullptr;
//	size_t tsize = 0;
//	size_t maxsize = isize;
//	Pack( const T& it = T( ) , size_t msize = isize ) :tsize( msize ) , maxsize( msize )
//	{
//		head = new T[maxsize];
//		for ( size_t i = 0; i < tsize; ++i )
//		{
//			head[i] = it;
//		}
//	}
//	~Pack( )
//	{
//		if ( head )
//			delete[ ] head;
//		head = nullptr;
//	}
//	template<typename A , typename ...T>
//	Pack& add( A head , T...tails )
//	{
//		add( std::move( head ) );
//		if constexpr ( sizeof...( tails ) >= 1 )
//			add( tails... );
//		return *this;
//	}
//	Pack& add( T t )
//	{
//		if ( isfull( ) ) {
//			if ( maxsize == 0 )
//				maxsize = 1;
//			resetsize( maxsize * 2 , T( ) );
//		}
//		head[tsize] = std::move( t );
//		++tsize;
//		return *this;
//	}
//	Pack& print( bool isfull = false , size_t imod = 20 )
//	{
//		getcout;
//		size_t psize;
//		if ( isfull )
//			psize = maxsize;
//		else
//			psize = tsize;
//		for ( size_t i = 0; i < psize; ++i )
//		{
//			cout << head[i] << tab;
//			if ( ( i + 1 ) % imod == 0 )
//				cout << nl;
//		}
//		return *this;
//	}
//	bool set( const T t , size_t pos )
//	{
//		if ( pos <= maxsize )
//		{
//			head[pos] = t;
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	size_t size( )
//	{
//		return tsize;
//	}
//	size_t max_size( )
//	{
//		return maxsize;
//	}
//	void display( bool ifull = true , size_t imod = 20 )
//	{
//		getcout;
//		cout << "size: " << size( ) << sp;
//		cout << "maxsize: " << max_size( ) << sp;
//		if ( !empty( ) ) {
//			cout << "head: " << *begin( ) << sp;
//			cout << "tail: " << *tail( ) << sp;
//		}
//		cout << "is_full: " << isfull( ) << sp;
//		cout << "is_empty: " << empty( ) << sp;
//		cout << tab;
//		cout << "element: " << nl;
//		print( ifull , imod );
//	}
//	bool empty( )
//	{
//		if ( tsize == 0 )
//			return true;
//		else
//			return false;
//	}
//	bool isfull( )
//	{
//		if ( tsize == maxsize )
//			return true;
//		else
//			return false;
//	}
//	T* resetsize( size_t ssize , const T t )
//	{
//		maxsize = ssize;
//		T* Phead = new T[maxsize];
//		tsize = max( 0 , min( maxsize , tsize ) );
//		if ( Phead )
//		{
//			for ( size_t i = 0; i < tsize; ++i )
//			{
//				Phead[i] = head[i];
//			}
//		}
//		for ( size_t i = tsize; i < maxsize; ++i )
//		{
//			Phead[i] = t;
//		}
//		delete[ ]head;
//		head = Phead;
//		return head;
//	}
//	T* begin( )
//	{
//		return head;
//	}
//	T* end( )
//	{
//		return head + tsize;
//	}
//	T* tail( )
//	{
//		return ( head + tsize - 1 );
//	}
//};
//
//void test_01( PCDC& cout )
//{
//	rcode(
//		Pack<int>  pa( 8 , 6 );
//	pa.print( );
//	); rcode(
//		pa.resetsize( 8 , 3 );
//	pa.print( true );
//	); rcode(
//		pa.add( 5 );
//	pa.display( );
//	); rcode(
//		pa.resetsize( 4 , 3 );
//	pa.display( );
//	); rcode(
//		pa.add( 6 , 7 , 11 , 13 , 15 );
//	sort( pa.begin( ) , pa.end( ) , greater<int>( ) );
//	pa.display( );
//	); rcode(
//		int ie;
//	NTIME( 6 )
//	{
//		ie = rand( ) % 20;
//		pa.add( ie , ie * 2 );
// }
//	sort( pa.begin( ) , pa.end( ) , less<int>( ) );
//	pa.display( false , 32 );
//	); rcode(
//	str= std::format( "string: {2} : {1} : {0}" , i , str1 , d );
//		Pack<string> ps;
//	string s1 = "string#";
//	ps.display( false );
//	); rcode(
//		NTIME( 8 ) {
//		ps.add( s1 + to_string( ix + 1 ) );
//	}
//	sort( ps.begin( ) , ps.end( ) , [ ]<typename T> ( T a , T b ) { return a > b; } );
//	ps.display( false );
//	); rcode(
//		sort( ps.begin( ) , ps.end( ) , [ ] ( auto a , auto b ) { return !( a > b ); } );
//	ps.display( false );
//	); rcode(
//		sort( pa.begin( ) , pa.end( ) , greater<int>( ) );
//	pa.display( false , 33 );
//	); rcode(
//		string str;
//	size_t i = 100;
//	double d = 3.14159253;
//	string str1 = "good";
//	str= std::format( "string: {2} : {1} : {0}" , i , str1 , d );
//	cout << str << tab;
//	double de = static_cast<double>( ie );
//	cout << ie << sp << de << tab;
//	cout << nl;
//	);
//}