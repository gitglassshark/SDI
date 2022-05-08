// SDIView.cpp: CSDIView 类的实现
//
#include "framework.h"
#include "pch.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SDI.h"
#include "MainFrm.h"
#endif

#include "SDIDoc.h"
#include "SDIView.h"
#include "CDialogExDoModal.h"
#include "resource.h"
#include "PCDC.h"
#include "test.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern int igi;
bool is_show_logmessage = false;

// CSDIView
IMPLEMENT_DYNCREATE( CSDIView , CView )

BEGIN_MESSAGE_MAP( CSDIView , CView )
	ON_WM_PAINT( )
	ON_COMMAND( ID_SET_FONT , &CSDIView::OnSetFont )
	ON_COMMAND( ID_SHOW_LOG , &CSDIView::OnShowlog )
	ON_COMMAND( ID_TEST_FONTDLG , &CSDIView::OnTestFontdlg )
	ON_COMMAND( ID_RESET_XY , &CSDIView::OnResetXY )
	ON_COMMAND( ID_TEST_CATLSTRING , &CSDIView::OnTestCAtlString )
	ON_COMMAND( ID_PRINT_ENV , &CSDIView::OnPrintEnvVAR )
	ON_COMMAND( ID_UPPER_LOWER , &CSDIView::OnUpperLower )
	ON_COMMAND( ID_MACRO_TEST , &CSDIView::OnMacroTest )
	ON_COMMAND( ID_GROUND_TEST , &CSDIView::OnGroundTest )
	ON_COMMAND( ID_OBJECT_SIZE , &CSDIView::OnObjectSize )
	ON_COMMAND( ID_AUTO_SETFONT , &CSDIView::OnAutoSetFont )
	ON_COMMAND( ID_BIT_EX_CHAR , &CSDIView::OnBitExChar )
	ON_COMMAND( ID_DIALGO_MODAL , &CSDIView::OnDialgoModal )
	ON_WM_LBUTTONDBLCLK( )
	ON_WM_MOUSEMOVE( )
	ON_COMMAND( ID_READ_FILE , &CSDIView::OnReadFile )
	ON_COMMAND( ID_VECTOR_TEST , &CSDIView::OnVectorTest )
	ON_COMMAND( ID_MC_FP_TL_TEST , &CSDIView::OnMacroFuncPointTemplateTest )
	ON_COMMAND( ID_GET_WINDOWS_RECT , &CSDIView::OnGetWindowsRect )
	ON_COMMAND( ID_STL_FUNC_TEST , &CSDIView::OnSTLFuncTest )
	ON_COMMAND( ID_EXCEPT_CATCH_TEST , &CSDIView::OnExceptCatchTest )
	ON_COMMAND( ID_PCDC_FUNCTION_TEST , &CSDIView::OnPCDCFunctionTest )
	ON_COMMAND( ID_STL_STRING_TEST , &CSDIView::OnSTLlStringTest )
	ON_COMMAND( ID_STL_STACK_EQUEUE_TEST , &CSDIView::OnStlStackEqueueTest )
	ON_COMMAND( ID_CLEAR_RECORD , &CSDIView::OnClearRecord )
	ON_COMMAND( ID_STL_SET_TEST , &CSDIView::OnStlSetTest )
	ON_COMMAND( ID_STL_MAP_MENU , &CSDIView::OnStlMapMenu )
	ON_COMMAND( ID_STL_ARG_TEST , &CSDIView::OnSTLArgTest )
	ON_COMMAND( ID_CXX20_STL_CONCEPT_TEST , &CSDIView::OnCxx20StlConceptTest )
	ON_COMMAND( ID_LAMDBA_FUNC_TEST , &CSDIView::OnLamdbaFuncTest )
	ON_COMMAND( ID_STL_TUPLE_TEST , &CSDIView::OnStlTupleTest )
	ON_COMMAND( ID_STL_TYPE_TEST , &CSDIView::OnStlTypeTest )
	ON_COMMAND( ID_INITAL_LIST_TEST , &CSDIView::OnInitalListTest )
	ON_COMMAND( ID_PTR_UNIQUE_TEST , &CSDIView::OnPtrUniqueTest )
	ON_COMMAND( ID_LVAL_RVAL_TEST , &CSDIView::OnLvalRvalTest )
	ON_COMMAND( ID_STL_STD_FORWARD_TEST , &CSDIView::OnStlStdForwardTest )
	ON_COMMAND( ID_PAINT_DC_TEST , &CSDIView::OnPaintDcTest )
	ON_COMMAND( ID_STL_STACK_TEST , &CSDIView::OnStlStackTest )
	ON_COMMAND( ID_STL_FUNCTOR_TYPERELOAD_TEST , &CSDIView::OnStlFunctorTypereloadTest )
	ON_COMMAND( ID_DC_TCOLOR_TEST , &CSDIView::OnDcTcolorTest )
	ON_COMMAND( ID_TASK_RUNTIME_TEST , &CSDIView::OnTaskRuntimeTest )
END_MESSAGE_MAP( )

// CSDIView 构造/析构
CSDIView::CSDIView( ) noexcept {

	//append logmessagerecode macro
	{LOGMESSAGE( theApp ); }

	//append random seed;
	srand( time( nullptr ) );
}

CSDIView::~CSDIView( ) {
}

BOOL CSDIView::PreCreateWindow( CREATESTRUCT& cs ) {
	{ LOGMESSAGE( theApp ); }
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow( cs );
}

// CSDIView 绘图
void CSDIView::OnDraw( CDC* pDC ) {
	{ LOGMESSAGE( theApp ); }
	CSDIDoc* pDoc = GetDocument( );
	ASSERT_VALID( pDoc );
	if ( !pDoc )
		return;
	// TODO: 在此处为本机数据添加绘制代码


}

// CSDIView 诊断
#ifdef _DEBUG
void CSDIView::AssertValid( ) const { CView::AssertValid( ); }

void CSDIView::Dump( CDumpContext& dc ) const { CView::Dump( dc ); }

CSDIDoc* CSDIView::GetDocument( ) const // 非调试版本是内联的
{
	ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( CSDIDoc ) ) );
	return (CSDIDoc*)m_pDocument;
}
#endif //_DEBUG


POINT CSDIView::SetPoint( int x , int y , POINT* p ) {
	// 如果位置超出范围，进行回绕重置
	if ( x >= 1900 )
		x = 50;
	if ( y >= 1900 )
		y = 5;

	//如果参数指针不为空，将位置存入POINT结构
	if ( p ) {
		p->x = position.x;
		p->y = position.y;
		return *p;
	}

	//设置输出坐标位置
	this->position.x = x;
	this->position.y = y;

	//返回POINT结构return position;
}

void CSDIView::OnPaint( ) {
	{	LOGMESSAGE( theApp );	}

	// 用于绘制的设备上下文
	CPaintDC dc( this );
	//设置字体颜色，准备DC
	this->SetDefaultFontDC( &dc );

	//定义并设置输出起点位置
	//long int& x = position.x;
	//long int& y = position.y;
	//int iline = 0;

	//恢复用户字体DC
	RestoreDCFont( dc );
}

void CSDIView::OnSetFont( ) {

	//设置字体
	memset( &m_userset_logfont , 0 , sizeof( LOGFONT ) ); // zero out structure
	CFontDialog fontDlg( &m_userset_logfont );
	fontDlg.DoModal( );

	is_font_set_ok = true;//字体设置成功，切换标志位
	fontDlg.GetCurrentFont( &m_userset_logfont );
	//放大字体间距
	step = abs( m_userset_logfont.lfHeight ) * 1.5;

	//刷新屏幕
	this->Invalidate( true );
}

void CSDIView::OnShowlog( ) {
	// TODO: 在此添加命令处理程序代码
	SimulationStdCout;
	if ( is_show_logmessage ) {
		is_show_logmessage = false;
		auto ic = 1;
		cout << clear << "系统调用顺序" << separtor;
		for ( const auto& i : theApp.messagelog )
			cout << ic++ << sp << i << newl;
	}
	else {
		is_show_logmessage = true;
		this->Invalidate( true );
	}
}

void CSDIView::OnTestFontdlg( ) {
	// TODO: 在此添加命令处理程序代码
	CFontDialog dlg;
	CAtlString str , str2;
	str = "error";
	LOGFONT lf = { 0 };
	int size;
	int bsize;
	int csize;

	if ( dlg.DoModal( ) == IDOK ) {
		size = dlg.GetSize( );
		bsize = size;
		csize = size;
		dlg.GetCurrentFont( &lf );

		str.Format( _T( "The size of the selected font = %ld" ) , size );
		vecotr_paintmessage.push_back( str );
		str2 = dlg.GetFaceName( );
		str = "FaceName is ";
		str += str2;
		vecotr_paintmessage.push_back( str );
		str.Format( _T( "The size of the selected font = %ld" ) , size );
		vecotr_paintmessage.push_back( str );
		str.Format( _T( "The bsize of the selected font = %ld" ) , bsize );
		vecotr_paintmessage.push_back( str );

		str.Format( _T( "The csize of the selected font = %ld" ) , csize );
		vecotr_paintmessage.push_back( str );
		CAtlString str2;
		str2.Format( _T( "The size = %ld =%ld =%ld" ) , size , bsize , csize );
		vecotr_paintmessage.push_back( str2 );
		this->Invalidate( true );
	}
	else {
		AfxMessageBox( str );
	}
}

void CSDIView::OnResetXY( )
{
	// 重设输出位置坐标
	SetPoint( 50 , 5 );

}

void CSDIView::OnTestCAtlString( )
{
	SimulationStdCout;
	char charmark = '*';
	int nchartime = 140;
	CAtlString strsplint( charmark , nchartime );
	cout << strsplint << newl;

	wstring wstr1( _T( "wstring is ok" ) );
	string astr1 = "astr1,string class";
	CAtlString strFormat( wstr1.c_str( ) );
	cout << astr1 << newl;
	cout << wstr1 << newl;
	cout << strFormat << newl;

	wstr1 = _T( "this is a wstring test string" );
	strFormat = wstr1.c_str( );
	cout << wstr1 << newl;
	cout << strFormat << newl;
	strFormat = astr1.c_str( );
	cout << strFormat << newl;

	wstr1 = _T( "this is a wstring test string" );
	cout << wstr1 << newl;

	// 定义备用变量
	CAtlString EnvStr , tok;
	CAtlString midle , temp , liststr , dome , grep , name , dock;
	CAtlString message , formatv , tail , head , result , str;
	unsigned long int ii = 0 , ij = 0 , itt = 0 , icount = 0 , imark = 0 , itail = 0 , imid = 0;

	//测试CAtlString Appendformat 功能
	formatv = ( _T( "first " ) );
	cout << formatv << newl;
	formatv.AppendFormat( _T( "position.x is %ld ,position.y is %ld" ) , position.x , position.y );
	vecotr_paintmessage.push_back( formatv );
	tail = "is ok";
	head = "is ok";
	ii = tail.CompareNoCase( head );
	message.Format( _T( "#%ld" ) , ++icount );
	message = tail;
	message += " <CompareNoCase> ?qual ";
	message += head;
	message.AppendFormat( _T( " return value = %ld" ) , ii );
	cout << message << newl;
	vecotr_paintmessage.push_back( message );

	tail = "is ok";
	head = "Is oK";
	ii = tail.CollateNoCase( head );
	message.Format( _T( "#%ld" ) , ++icount );
	message = tail;
	message += "<CollateNoCase> ?qual ";
	message += head;
	message.AppendFormat( _T( " return value = %ld" ) , ii );
	cout << message << newl;
	vecotr_paintmessage.push_back( message );

	tail = _T( "123456789" );
	ii = 5; ij = 3;
	message = tail;
	tail.Delete( ii , ij );
	message.AppendFormat( _T( "从 %ld 开始删除 %ld 个字符 = " ) , ii , ij );
	message += tail;
	cout << message << newl;
	vecotr_paintmessage.push_back( message );

	str.Format( _T( "Floating point: %.2f\n" ) , 12345.12345 );
	_tprintf_s( _T( "%s" ) , (LPCTSTR)str );
	message = str;
	cout << message << newl;
	vecotr_paintmessage.push_back( message );

	str.Format( _T( "Left-justified integer: %.6d\n" ) , 35 );
	_tprintf_s( _T( "%s" ) , (LPCTSTR)str );
	message = str;
	cout << message << newl;
	vecotr_paintmessage.push_back( message );

}

void CSDIView::OnPrintEnvVAR( )
{
	// 打印环境变量
	SimulationStdCout;
	CAtlString EnvStr , tok;
	EnvStr.GetEnvironmentVariable( _T( "PATH" ) );
	int ipos = 0;
	tok = EnvStr.Tokenize( _T( ";" ) , ipos );

	while ( !isempty( tok ) ) {
		vecotr_paintmessage.push_back( tok );
		tok = EnvStr.Tokenize( _T( ";" ) , ipos );
	};
	for ( const auto& i : vecotr_paintmessage )
		cout << i << newl;
	lscode(
		cout << "this is out dc" << tab << &cout << tab << newl;
	);
}

void CSDIView::OnUpperLower( )

{
	//大小写开关bool值，静态变量，已记录上次转换状态
	static bool isupper = true;

	//如果是大写转换位标志为真，则进行大写转换，否则进行小写转换
	if ( isupper ) {
		for ( auto& i : vecotr_paintmessage ) {
			i.MakeUpper( );
		}
		for ( auto& i : theApp.messagelog )
		{
			i.MakeUpper( );
		}
	}
	else
	{//如果是小写转换位标志，开始进行小写转换,循环日志数据记录容器
		for ( auto& i : vecotr_paintmessage ) {
			i.MakeLower( );
		}
		for ( auto& i : theApp.messagelog )
		{
			i.MakeLower( );
		}
	}

	//反转大小写转换位标志，以便下次进入自动进行反向转换
	isupper = !isupper;

	this->Invalidate( true );
}

void CSDIView::OnAutoSetFont( )
{
	// 设置字体、背景颜色
	CDC* p = this->GetWindowDC( );
	CDC& dc = *p;
	auto cb = dccr.grey;
	auto ct = dccr.chocolate;
	dc.SetBkColor( cb );
	dc.SetTextColor( ct );

	//设置窗口背景颜色
	CRect rect;
	GetClientRect( &rect );
	dc.FillSolidRect( rect , dccr.grey );

	//CAtlString strText = _T("自动设置为系统字体");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle( (HFONT)GetStockObject( DEFAULT_GUI_FONT ) );
	pDefaultGUIFont->GetLogFont( &lf );
	lf.lfHeight = 24;

	CFont fontDraw;
	fontDraw.CreateFontIndirect( &lf );
	CFont* pOldFont = dc.SelectObject( &fontDraw );

	//dc.DrawText(strText, &rect, DT_CENTER | DT_WORDBREAK);

	//删除字体
	dc.SelectObject( pOldFont );
}

void CSDIView::OnBitExChar( )
{
	SimulationStdCout;
	CAtlString catstrbit32;
	CAtlString csmessage;
	LONGLONG i = 256 * 256 * 256;
	string sbitstr;
	bitset<64> bit64a = 256;
	sbitstr = bit64a.template to_string<char , char_traits<char> , allocator<char> >( );
	catstrbit32 = sbitstr.c_str( );

	cout << bit64a << newl;
	cout << bitset<64>( 256 ) << newl;
	cout << catstrbit32 << cut;

	bit64a = 256 * 256 * 256 * 256 * 256 * 256 * 256 * 256 - 1;
	cout << bit64a << newl;

	sbitstr = bit64a.template to_string<char , char_traits<char> , allocator<char> >( );
	cout << CAtlString( sbitstr.c_str( ) ) << newl;

	cout << typeid( catstrbit32 ).name( ) << newl;
	//cout.titleline(wstring(st(start test except catch try and throw...)));

}

CDC& CSDIView::SetDefaultFontDC( CDC* pdc/*=nullptr*/ )
{
	if ( pdc == nullptr )
	{
		pdc = this->GetWindowDC( );
	}

	CDC& dc = *pdc;
	auto bcolor = dccr.grey;
	auto tcolor = dccr.chocolate;

	//设置窗口背景颜色
	CRect rect;
	GetClientRect( &rect );
	dc.FillSolidRect( rect , bcolor );

	//设置字体颜色
	dc.SetBkColor( bcolor );
	dc.SetTextColor( tcolor );

	//设置缺省字体
	LOGFONT lf;
	// zero out structure
	memset( &lf , 0 , sizeof( LOGFONT ) );

	//如果字体选择标志置位，使用用户选择字体
	if ( is_font_set_ok ) {
		VERIFY( m_user_font.CreateFontIndirect( &m_userset_logfont ) );
	}
	else {
		m_user_font.DeleteObject( );
		if ( !m_user_font.CreatePointFont( 120 , _T( "Cascadia Code" ) ) )
			strbox( font creat fail );
	}

	m_p_defaultfont = dc.SelectObject( &m_user_font );

	//根据字体大小调整步长
	m_user_font.GetLogFont( &lf );
	step = abs( lf.lfHeight + lf.lfHeight / 2 );

	//检查输出位置
	if ( !dc.PtVisible( position ) ) {
		this->SetPoint( 50 , 5 );
	}
	dc.AssertValid( );
	return dc;//返回设备DC引用
}

bool CSDIView::RestoreDCFont( CDC& dc )
{
	//删除用户字体
	if ( &dc != nullptr ) {
		dc.SelectObject( m_p_defaultfont );
	}
	m_user_font.DeleteObject( );
	this->ReleaseDC( &dc );
	return true;
}

void CSDIView::OnDialgoModal( )
{
	// TODO: 在此添加命令处理程序代码
	m_fontresize_CDialogExDoModal.DoModal( );
}

void CSDIView::OnLButtonDblClk( UINT nFlags , CPoint point )
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAtlString strwindowstitle;
	strwindowstitle.Format( _T( "Reset Current print position is x:%ld,y:%ld !" ) , position.x , position.y );
	position.x = point.x;
	position.y = point.y;
	theApp.m_pMainWnd->SetWindowText( strwindowstitle );

	CView::OnLButtonDblClk( nFlags , point );
}

void CSDIView::OnMouseMove( UINT nFlags , CPoint point )
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAtlString strwindowstitle;
	strwindowstitle.Format( _T( "Current print position is x:%ld,y:%ld ,current cursor positon is x:%ld,y:%ld . TIP:Double click mouse left can reset the positon." ) , position.x , position.y , point.x , point.y );
	theApp.m_pMainWnd->SetWindowText( strwindowstitle );

	CView::OnMouseMove( nFlags , point );
}

void CSDIView::OnReadFile( )
{
	//准备用户DC 
	CDC& dc = this->SetDefaultFontDC( );

	//定义文件对话框 设置为打开
	CFileDialog f( true );
	f.DoModal( );

	//得到文件名
	CAtlString openfilename = f.GetPathName( );
	CFile cfile( openfilename , CFile::modeRead );

	//准备读入缓冲区
	const int icount = 1024;
	int iretcount = 1024;
	char pbufRead[icount];
	memset( pbufRead , 0 , sizeof( pbufRead ) );
	ASSERT( sizeof( pbufRead ) == icount );

	cfile.SeekToBegin( );
	CAtlString readline;

	//定义输出区域
	RECT rect;
	this->GetWindowRect( &rect );

	//开始读入数据，如果读入字节数小于设置读入字节（返回值），说明读到文件末尾，退出读取循环。
	while ( iretcount == icount )
	{
		iretcount = cfile.Read( pbufRead , sizeof( pbufRead ) );
		readline = pbufRead;
		dc.DrawText( readline , iretcount , &rect , DT_LEFT );
	}

	//ASSERT(0 == memcmp(pbufWrite, pbufRead, sizeof(pbufWrite)));
	cfile.Close( );

	//恢复用户字体DC
	RestoreDCFont( dc );
}

void CSDIView::OnMacroFuncPointTemplateTest( )
{

	SimulationStdCout;
	int x = 50;
	int y = 50;
	int a = 100;
	int b = 10;
	float fa = 100.33;
	float fb = 10.22;


	//测试宏

	//测试函数指针
	CAtlString strFormat;
	int( *func )( int a , int b );
	float ( *fund )( float a , float b );
	func = add<int>;
	strFormat.Format( _T( "%ld" ) , func( a , b ) );
	cout << strFormat << endl;
	fund = add;
	strFormat.Format( _T( "*func=add %ld" ) , func( a , b ) );
	cout << strFormat << endl;
	//出现异常
	func = sub;
	strFormat.Format( _T( "(*func) add<int>%ld" ) , func( a , b ) );
	cout << strFormat << endl;
	func = add;
	strFormat.Format( _T( "(*func) add<int>%ld" ) , func( a , b ) );
	cout << strFormat << endl;
	strFormat.Format( _T( "%lf" ) , fund( fa , fb ) );
	cout << strFormat << endl;
	strFormat.Format( _T( "%ld" ) , func( a , b ) );
	cout << strFormat << endl;
	strFormat.Format( _T( "%lf" ) , fund( fa , fb ) );
	cout << strFormat << endl;

	strFormat.Format( _T( "%lf" ) , divv( fa , fb ) );
	cout << strFormat << endl;
	strFormat.Format( _T( "%lf" ) , fund( fa , fb ) );
	cout << strFormat << endl;

}

void CSDIView::OnGetWindowsRect( )
{
	SimulationStdCout;
	RECT rect;
	this->GetWindowRect( &rect );
	CString strto;
	strto.Format( _T( "step %ld " ) , step );
	cout << strto << newl;
	strto.Format( _T( "rect.left %ld " ) , rect.left );
	cout << strto << newl;
	strto.Format( _T( "rect.right %ld " ) , rect.right );
	cout << strto << newl;
	strto.Format( _T( "rect.bottm %ld " ) , rect.bottom );
	cout << strto << newl;
	strto.Format( _T( "rect.top %ld " ) , rect.top );
	cout << strto << newl;

	CAtlString strwindowstitle;
	strwindowstitle.Format( _T( "Current print position is x:%ld,y:%ld" ) , position.x , position.y );
	theApp.m_pMainWnd->SetWindowText( strwindowstitle );

}

bool CSDIView::writedc( const CAtlString& str , CDC* pdc )
{
	//设置字体颜色，准备DC

	bool dcreset = false;
	if ( pdc == nullptr )
	{
		pdc = &this->SetDefaultFontDC( );
		dcreset = true;
	}
	pdc->TextOut( position.x , position.y , str );
	position.y += step;

	//恢复用户字体DC
	if ( dcreset )
		RestoreDCFont( *pdc );
	return dcreset;
}

void CSDIView::OnClearRecord( )
{
	////清空记录
	vecotr_paintmessage.clear( );
	this->Invalidate( true );
}

void CSDIView::OnExceptCatchTest( )
{

	// 测试throw异常类型 
	SimulationStdCout;
	try {
		cout << "before runexcept" << newl;
		//runexcept(1);
		//被跳过
		cout << "under runexcept" << newl;
	}
	catch ( char* e )
	{
		cout << typeid( e ).name( ) << newl;
	}
	catch ( float e ) {
		cout << e << newl;
	}
	catch ( double e ) {
		cout << e << newl;
	}
	catch ( int e ) {
		cout << e << newl;
	}
	catch ( char e ) {
		cout << e << newl;
	}
	catch ( const CString& e ) {
		cout << e << newl;
	}
	catch ( ... ) { cout << "catch all error" << newl; };

}

void CSDIView::OnSTLlStringTest( )
{
	SimulationStdCout;
	RUNTEST( STRING TEST );
	string s1 = "ok" , s2 = "bad" , s3 = "+";
	s1.append( s3 );
	s1.append( s2 );
	s1.append( s3 );
	s1.append( "good" );
	s1.append( s3 );
	s1.append( s2 );

	cout << s1 << newl;
	cout << s1.find( s2 ) << newl;
	cout << s1.find( "good" ) << newl;
	cout << s1.rfind( s2 ) << newl;

	cout << s1 << newl;
	s1.replace( 0 , 0 , "byeeeee" );
	cout << s1 << newl;
	cout << s1.substr( 7 , 4 ) << newl;
	s1.insert( 1 , "ddd" );
	cout << s1 << newl;
	s1.erase( );
	cout << "erase after " << s1 << newl;

}

void CSDIView::OnStlStackEqueueTest( )
{
	SimulationStdCout;

}

void CSDIView::OnStlMapMenu( )
{
	SimulationStdCout;
	map<string , pfunc> menu;
	//MAKEMENUITEM( ntest , menu );
	string name = "map second";
	map<string , pfunc>::iterator itt = menu.begin( );
	lscode(
		itt->second( cout , itt->first );
	itt->second( cout , name );
	);
	cout << cut;
	lscode(
		cout << *itt << tab << &ntest << endl << cut;
	cout << ( itt->second == &ntest ) << tab << st( itt->second == &ntest , is equal ) << nl;
	);
	code(
		map<int , float>mif = { {2,34.3},{234,8.40},{536,10324.788},{233,839.81392},{238,8.9399} };
	multimap<int , float>mmif = { {2,4.3},{234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	pair<int , string>paone { 100,"pair" };
	auto & [i , x] = paone;
	);
	lscode(
		cout << i << com << x << endl;
	for ( const auto& [first , second] : mif )
		cout << first << com << second << semi << tab;
	cout << endl;
	);



}

void CSDIView::OnSTLArgTest( )
{
	//return y += val * x;
	SimulationStdCout;
	int x = 3;
	cout << returnt<int , 3>( ) << tab << sizeof( returnt<int , 3>( ) ) << newl;
	cout << returnt<long long int , 5>( ) << tab << sizeof( returnt<long long , 5>( ) ) << newl;
	cout << returnt<float , 3>( ) << tab << sizeof( returnt<float , 3>( ) ) << newl;

	vector<int>intvect;
	for ( size_t i = 0; i < 20;)
	{
		intvect.push_back( ++i * 3 );
	}
	cout << intvect << newl;

	list<int>ilt;
	for ( size_t i = 0; i < 15; i++ )
	{
		ilt.push_back( i + 10 );
	}
	for ( list<int>::iterator it = ilt.begin( ); it != ilt.end( ); ++it )
	{
		*it *= 2;
	}
	list<int> l2( ilt );
	for ( list<int>::iterator it = ilt.begin( ); it != ilt.end( ); ++it )
	{
		*it *= 2;
	}
	cout << ilt << newl;
	cout << l2 << newl;
	multimap<CString , string>mmap;
	mmap.insert( pair<CString , string>( CString( st( imap first ) ) , string( "is first" ) ) );
	mmap.insert( make_pair( CString( st( imap second ) ) , string( "is second" ) ) );
	mmap.insert( multimap<CString , string>::value_type( CString( st( imap second ) ) , string( "is second" ) ) );
	cout << mmap << newl;

	CString wstring = _T( "good" );
	pair<CString , int> w = make_pair( wstring , 100 );
	pair<int , float>ifx = make_pair( 10 , 2.3 );
	map<CString , int> cfmap;
	cfmap.insert( w );
	cfmap.insert( make_pair( CString( wstring += wstring ) , 200 ) );
	cfmap.insert( pair<CString , int>( CString( wstring = st( go ) ) , 300 ) );
	cfmap.insert( map<CString , int>::value_type( CString( st( bad ) ) , 400 ) );
	multiset<int> iset1;
	int mod = 30;
	for ( size_t i = 0; i < 30; i++ )
	{
		iset1.insert( i * rand( ) % mod );
	}
	cout << cfmap << newl;
	cout << iset1 << newl;

}

void CSDIView::OnCxx20StlConceptTest( )
{
	PCDC cout( this );

	//原始字符串字面量测试
	cout << R"h(hello\thello\thello)h" << newl;



}

void CSDIView::OnStlTupleTest( )
{
	SimulationStdCout;
	cout.flushscreen( );
	lscode(

		using namespace std;
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	auto tupleb = tuple<int , float , string , string , string>( 22 , 20.24 , "good-b" , "bad-b" , "normal-b" );
	cout << std::get<int>( tuplea ) << tab;
	cout << std::get<1>( tuplea ) << tab;
	cout << std::get<2>( tuplea ) << tab;
	cout << std::get<3>( tuplea ) << tab;
	cout << std::get<4>( tuplea ) << newl;
	std::get<4>( tuplea ) = "change";
	cout << std::get<4>( tuplea ) << tab;
	cout << cut;
	cout << std::get<0>( tupleb ) << tab;
	cout << std::get<1>( tupleb ) << tab;
	cout << std::get<2>( tupleb ) << tab;
	cout << std::get<3>( tupleb ) << tab;
	cout << std::get<4>( tupleb ) << tab;

	swap( tuplea , tupleb );
	cout << std::get<0>( tupleb ) << tab;
	cout << std::get<1>( tupleb ) << tab;
	cout << std::get<2>( tupleb ) << tab;
	cout << std::get<3>( tupleb ) << tab;
	cout << std::get<4>( tupleb ) << tab;

	typedef std::tuple<int , double , int , double> Mytuple;
	Mytuple c0( 0 , 1 , 2 , 3 );

	// display contents " 0 1 2 3"
	cout << " " << std::get<0>( c0 );
	cout << " " << std::get<1>( c0 );
	cout << " " << std::get<2>( c0 );
	cout << " " << std::get<3>( c0 );
	cout << newl;

	int v4 = 4;
	double v5 = 5;
	int v6 = 6;
	double v7 = 7;
	std::tie( v4 , v5 , v6 , v7 ) = c0;

	// display contents " 0 1 2 3"
	cout << " " << v4;
	cout << " " << v5;
	cout << " " << v6;
	cout << " " << v7;
	cout << newl;
	v7 = 10;
	cout << " " << std::get<3>( c0 );
	cout << newl;
	std::get<0>( c0 ) = 8;
	v4 = 9;
	cout << " " << std::get<0>( c0 );
	cout << " " << v4;
	)

}

void CSDIView::OnInitalListTest( )
{
	SimulationStdCout;
	lscode(
		NTIME( 4 ) {
		cout << ix << tab << "good" << tab;
		cout << ix << tab << "bad" << tab;
	}
	cout << newl;
	cout << "Hello world!" << newl;
	showtype( "Hello world!" );
	);
	lscode(
		vector<int>va;
	NTIME( 4 )
		va.push_back( ix );
	int iy = 0;
	for ( auto i : ( cout << ++iy << tab << "ok" << tab , va ) )
		cout << "run" << tab << newl;
	);

}

void CSDIView::OnStlStdForwardTest( )
{
	coutExtSetSimulation;
	cout << cl;
	lscode(
		int i = 1;
	int ia = 2;
	const int ci = 3;
	const int ic = 5;
	int& r = ia;
	int&& rr = 4;
	const int& irc = ic;
	const int&& irr = 7000;
	int* p = &i;
	callf( i );
	callf( ci );
	callf( r );
	callf( rr );
	callf( irc );
	callf( irr );
	callf( 7 );
	callf( i + 7 );
	);
	using namespace type;
	showtype( type::INT );
	showtype( type::DOUB );
	showtype( type::CHPtr );
	showtype( sType::CHPtr );
	showtype( sType::LNT );
	showtype( LNT );
	lscode(
		cout << imax( 3 , 8 , 9 , 10 , 22 , 12 , i , ia , ci , irr , irc ) << newl;
	cout << gmax( 3.4 , 898.8 , 0.9 , 10 , 200.22 , 12.0 ) << newl;
	cout << lex<int>( ) << newl;
	cout << lex<float>( ) << newl;
	cout << lex( ) << newl;
	);
	vector<int> va = { 10000,9,9,8,2000 };
	decltype( va )::value_type ixa = *va.begin( );

	auto ava = makevector( 1 , 3 , 5 , 9 );
	cout << ava << endl;

}

void CSDIView::OnPaintDcTest( )
{
	//开始绘图
	SimulationStdCout;
	//CRect rect(800, 800,1000,1000);
	//cout << cl;/*cout.Rectangle(&rect);*/
	//lscode(
	//	cout << cout.m_cdc << tab << cout.m_hDC << tab
	//	<< cout.m_hAttribDC << tab << cout.m_bPrinting << newl;
	//);
	cout.status( );

}

void CSDIView::OnLamdbaFuncTest( )
{
	// TODO 测试lamdba表达式
	SimulationStdCout;
	cout.settcolor( RGB( 139 , 0 , 0 ) );
	cout.title( "begin lambda experss test..." );
	cout.resettcolor( );
	auto funl = [ ] ( int val1 , int val2 )mutable ->bool {
		return val1 > val2;
	};
	int x = 1 , y = 2;
	cout << x << newl;
	function<bool( int , int )> p = funl;
	cout << p( 100 , 200 );
	cout << newl;
	showtype( p );
	showtype( funl );
	auto funl1 = [ & ] ( int val )mutable ->int {
		int z = 210;
		showtype( z );
		return igi + val;
	};
	function<int( int )> p1 = funl1;
	showtype( funl1 );
	showtype( p1 );
	cout << cut;

	vector<int> iset1;
	int mod = 30;
	for ( size_t i = 0; i < 30; i++ )
	{
		iset1.insert( iset1.end( ) , i * rand( ) % mod );
	}
	cout << iset1 << newl << cut;
	sort( iset1.begin( ) , iset1.end( ) , std::function<bool( int , int )>( [ ] ( int a , int b ) ->bool { return a < b; } ) );
	cout << iset1 << newl << cut;
	sort( iset1.begin( ) , iset1.end( ) , funl );
	cout << iset1 << newl;

	//lambda experssion
	lscode( cout << [ ] ( ) {return 5; }( ) << newl;);
	lscode(
		struct lam {
		int i = 10;
		int operator()( )const
		{
			return [ ] { int i = 6;
			i++; return i; }( );
		};
	};
	int i = 2;
	auto l = [ = ] ( )mutable {
		struct B {
			void set( int a )
			{
				i = a;
			}
			int i = 20;
			int b = 30;
		};
		B a {};
		i++;
		a.set( i );
		return i + a.i;
	};

	cout << lam( )( ) << newl;
	);

	lscode(
		if ( !itisnull( i ) )
			cout << "it is not null!" << newl;
	);
	int arr[ ] = { 3,8,2,5,0 };
	lscode(
		cout.forprinta( arr , sizeof( arr ) / sizeof( int ) );
	);
	cout << arr[3] << tab << arr[4] << endl;

}

void CSDIView::OnLvalRvalTest( )
{
	// TODO: lVAL RVAL
	SimulationStdCout;
	lscode(
		int&& o = 4; cout << o << tab;
	const int&& g = 4;
	const int c = 5;
	o = 8;
	cout << o << newl;
	showtype( o );
	showtype( int&& );
	);
	lscode(
		vector<int>va = { 1,3,5,5,9,10 };
	cout << va << newl;
	);
	lscode(
		map<int , float>mapa = { {2,3.2},{3,4.2},{5,6.7},{7,8.8} };
	cout << mapa << endl;
	);
	lscode(
		int ia = 1;
	int ib = 2;
	int* pia = &ia;
	int* pib = &ib;
	int& ria = *pia;
	cout.pb( ia , ib , pia , pib , *pia , *pib , ria , &ria );
	);
	lscode(
		pia = &ib;
	pib = &ia;
	*pia = 3;
	cout.pb( ia , ib , pia , pib , *pia , *pib , ria , &ria );
	);

}

void CSDIView::OnPtrUniqueTest( )
{
	coutExtSetSimulation;

	lscode(
		Mptr( iua , int );
	Mptr( pptrb , ptr );
	int ibb = *iua;
	Mptrs( parrb , ptr , 3 );
	Msptrs( parrc , ptr , 2 );
	cout << iua << tab << *iua << tab << newl;
	);
	CString name = _T( "array unique_ptr#" );
	lscode(
		size_t size = 3;
	unique_ptr<ptr[ ]>three = make_unique<ptr[ ]>( size );
	CString s;
	CString finalname;
	for ( int i = 0; i < size; ++i ) {
		s.Format( _T( "%ld" ) , i );
		finalname = name + s;
		three[i].set( i , finalname );
	}
	lscode( cout << three[0].name << newl;);
	showtype( cout );
	);

	int* pa = new int { 99 };
	unique_ptr<int>unaptr( pa );
	cout << *unaptr << tab << unaptr << tab << address( unaptr ) << tab << pa << tab; cout.type( unaptr );

	lscode(
		size = 80;
	int* pint = new int[size];
	long long int sum = 0;
	for ( size_t i = 0; i < size; ++i )
	{
		pint[i] = 1 + i;
		sum += pint[i];
	}
	int* plint = new int;
	*plint = sizeof( pint );
	cout << "array size is : " << *plint << tab << "sum is " << sum << "  array elements is :" << newl;
	for ( size_t i = 0; i < size; i++ )
	{
		cout << pint[i] << ", ";
		if ( ( 1 + i ) % 20 == 0 )
			cout << cut;
	}
	cout << newl;
	delete[ ]pint;
	delete[ ]plint;
	)
}

void CSDIView::OnSTLFuncTest( )
{
	coutExtSetSimulation;
	int ia = 10 , ib = 20;
	float	fa = 1.1 , fb = 11.0;
	CAtlString strout;

	strout.Format( st( "ia is %ld ,ib is %ld ,add result  is %ld " ) , ia , ib , add( ia , ib ) );
	cout << strout << newl;
	strout.Format( st( "ia is %ld ,ib is %ld ,sub result  is %ld " ) , ia , ib , sub( ia , ib ) );
	cout << strout << newl;
	strout.Format( st( "ia is %ld ,ib is %ld ,mul result  is %ld " ) , ia , ib , mul( ia , ib ) );
	cout << strout << newl;
	strout.Format( st( "ia is %ld ,ib is %ld ,divv resultm is %ld " ) , ia , ib , divv( ia , ib ) );
	cout << strout << newl;
	strout.Format( st( "fa is %lf ,ib is %lf ,add result  is %lf " ) , fa , fb , add( fa , fb ) );
	cout << strout << newl;
	strout.Format( st( "fa is %lf ,ib is %lf ,sub result  is %lf " ) , fa , fb , sub( fa , fb ) );
	cout << strout << newl;
	strout.Format( st( "fa is %lf ,ib is %lf ,mul result  is %lf " ) , fa , fb , mul( fa , fb ) );
	cout << strout << newl;
	strout.Format( st( "fa is %lf ,ib is %lf ,div result  is %lf " ) , fa , fb , divv( fa , fb ) );

	class dycA;
	class dycA {
	public:
		string classid;
	public:
		dycA( ) {};
		dycA( string name )
		{
			classid = name;
			auto PtrCreate = &dycA::create;
		}
		static void say( ) {
			getcout;
			cout << "in static" << endl;
		}
		dycA* create( )
		{
			return new dycA;
		}
		void nameID( string name )
		{

		}
	};

	dycA classa;
	cout.title( st( " beging template calss test " ) ) << newl << cut;
	base basea;
	base<>baseb;
	base<int>basec;
	showtype( basea ) << newl;
	showtype( baseb ) << newl;
	showtype( basec ) << newl;
	bbase da;
	bbase<> db;
	bbase<int> dc;
	showtype( da ) << newl;
	showtype( db ) << newl;
	showtype( dc ) << newl;
	dbasef<base<>> df;
	dbasef<base<int>> dg;
	showtype( df ) << newl;
	showtype( dg ) << newl;
	cout << comp( 1 , 2 ) << endl;
	print( 1 , 2 , 3 , 4 , 5 );

	TITLE( PRINT  deque TEST );
	deque<int>d1;
	for ( size_t i = 0; i < 20; i++ )
	{
		d1.push_back( i * 2 );
	}
	for ( auto& i : d1 )
		cout << i << tab;
	cout << newl;
	d1.pop_front( );
	cout << separtor;
	d1.push_front( 1000 );
	for ( int j = 0; j < 8; j++ ) {
		cout << j << "#" << tab;
		for ( auto& i : d1 ) {
			cout << ( i = i + j ) << tab;
		}
		cout << newl;
	}
	CRect rect = { 0,0,0,0 };
	cout << separtor;
	for ( auto& i : d1 )
		cout << i << tab;
	cout << newl;
	d1.pop_back( );
	d1.pop_front( );
	for ( size_t i = 0; i < 5; i++ )
	{
		d1.pop_front( );
	}
	d1.emplace_back( 888 );
	cout << d1.size( ) << newl;
	SHOW( d1.size( ) );
	SHOW( d1.max_size( ) );
	SHOW( d1.empty( ) );
	SHOW( d1.at( 5 ) );
	cout << newl;
	cout.setlinechar( '-' );
	cout << separtor;
	for ( auto& i : d1 )
		cout << i << tab;
	cout << newl;
	d1.insert( d1.begin( ) , 222 );
	cout << *d1.begin( ) << newl;
	this->GetWindowRect( &rect );

	cout << rect.bottom << tab << rect.top << tab << rect.right << tab << rect.left << newl;

}

void CSDIView::OnStlStackTest( )
{
	SimulationStdCout;

	static int imod = 0;
	++imod;
	if ( imod >= 4 )
	{
		imod = 1;
	}
	stack<int> skt;
	queue<int>qut;
	if ( imod == 1 )
	{
		RUNTEST( STACK EQUEUE TEST );

		stack<int>ist;
		for ( size_t i = 0; i < 20; i++ )
		{
			ist.push( i + 10 );
		}
		cout << ist.top( ) << newl;
		cout << ist.size( ) << tab << ist.top( ) << tab << ( ist.pop( ) , ist.top( ) ) << newl;
		cout << separtor;
		cout << ist.size( ) << tab << ist.top( ) << newl;
		cout << ist.top( ) << tab << ist.size( ) << tab << ( ist.pop( ) , ist.top( ) ) << tab << ist.size( ) << tab << ist.top( ) << newl;
		cout << ist.size( ) << tab << ist.top( ) << newl;
		cout << ist.empty( );

		queue <int> ieq;
		for ( size_t i = 0; i < 10; i++ )
		{
			ieq.push( i + 2 );
		}
		cout.setlinechar( '#' );
		cout << separtor;
		cout << ieq.front( ) << newl;
		cout << ieq.back( ) << newl;

	}
	if ( imod == 2 )
	{
		NTIME( 100 )
			skt.push( ix * 8 );
		cout << st( stack size is : ) << sp << skt.size( ) << tab << st( stack top elements is : ) << sp << "stack is empty? answer is : " << skt.empty( ) << cut;
		if ( skt.empty( ) == false )
			cout << skt.top( );
		NTIME( 100 )
		{
			cout << 1 + ix << "# : " << skt.top( ) << tab;
			skt.pop( );
			if ( ix % 8 == 7 )
				cout << cut;
		}
		cout << cut;
		cout << st( stack size is : ) << sp << skt.size( ) << tab << st( stack top elements is : ) << sp << "stack is empty? answer is : " << skt.empty( );
		if ( skt.empty( ) == false )
			cout << skt.top( );
	}
	if ( imod == 3 )
	{
		NTIME( 100 )
			qut.push( ix * 5 );
		cout << st( queue size is : ) << qut.size( ) << sp << st( first element is : ) << qut.front( ) << sp << st( end element is : ) << qut.back( ) << sp << st( is empty ? : ) << qut.empty( ) << cut;
		NTIME( 100 )
		{
			cout << 1 + ix << "# : " << qut.front( ) << sp;
			qut.pop( );
			if ( ix % 8 == 7 )
				cout << cut;
		}
		cout << cut;
		lscode(
			cout << st( size if ) << sp << qut.size( ) << tab << st( queue is empty ? : ) << qut.empty( ) << cut;
		);

	}
}

void CSDIView::OnStlFunctorTypereloadTest( )
{
	coutExtSetSimulation;

	static int imod = 0;
	++imod;
	if ( imod >= 2 )
	{
		imod = 1;
	}
	auto tuplea = tuple<int , float , string , string , string>( 10 , 10.24 , "good" , "bad" , "normal" );
	if ( imod == 1 )
	{
		class fraction {
		public:
			int a;
			bool operator()( int a , int b ) { return a > b; }
			bool operator()( int a ) { return a > 0; }
			double operator()( int s , int b , int c ) {
				return double( s + b + c ) / double( a );
			}
			fraction( int n )
			{
				a = n;
			}
			operator double( )const {
				getcout;
				cout << st( in double( ) ) << a << tab;
				return double( a / -1.0 );
			}
		};

		//类型转换，仿函数
		fraction a( 4 );
		lscode(
			cout << double( a ) << tab; cout << a.a << tab << a( 2 ) << tab << a( 2 , 4 ) << tab << a( 2 , 2 , 4 ) << tab << double( 2 ) / double( 4 ) << cut;
		cout << a + 5 << cut;
		);
		lscode(
			locationmessage;
		);
		lscode(
			tuple<int , float , string , string , string>tupleb {};
		);
		lscode(
		);
	}

}

void CSDIView::OnMacroTest( )
{
	SimulationStdCout;
	static int imod = 0;
	++imod;
	if ( imod >= 3 )
		imod = 1;
	list<int>ilt;
	for ( size_t i = 0; i < 15; i++ )
	{
		ilt.push_back( i + 10 );
	}
	list<int> l2( ilt );
	for ( list<int>::iterator it = ilt.begin( ); it != ilt.end( ); ++it )
	{
		*it *= 2;
	}
	if ( imod == 1 )
	{
		lscode(
			CString ssss( '2' , 129 );
		cout << ssss << newl;
		);

		lscode(
			for ( size_t l = 0; l < ssss.GetLength( ); l++ )
			{
				if ( l % 2 == 1 )
					ssss.Insert( l , '3' );
			}
		cout << ssss << newl;
		);
		lscode(
			for ( size_t l = 0; l < ssss.GetLength( ); l++ )
			{
				if ( l % 3 == 2 )
					ssss.Insert( l , '4' );
			}
		cout << ssss << newl;
		);

		cout.setlinechar( '-' ); cout << cut; cout.title( st( good titele function ) );

		lscode(
			cout << __FUNCTION__ << tab << __FUNCDNAME__ << tab << __FUNCSIG__ << newl;
		);
		lscode(
			cout << __DATE__ << sp << __TIME__ << tab << __FILE__ << tab << __LINE__ << tab << __func__ << tab << __STDC_HOSTED__ << newl;
		);
		lscode(
			cout.location( std::source_location::current( ) );
		);

		lscode(
			showtype( __FILE__ );
		showtype( __LINE__ );
		showtype( __DATE__ );
		showtype( __TIME__ );
		);

	}

	if ( imod == 2 )
	{
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
		cout << cut;
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
	if ( imod == 3 )
	{
	}
}

void CSDIView::OnStlSetTest( )
{
	SimulationStdCout;

	static int imod = 0;
	++imod;
	if ( imod == 5 ) imod = 0;

	if ( imod == 1 ) { OnStlSetTest1( cout ); }

	if ( imod == 2 ) { OnStlSetTest2( cout ); }

	if ( imod == 3 ) { OnStlSetTest3( cout ); }

	if ( imod == 4 )
	{
	}


}

void CSDIView::OnGroundTest( )
{
	coutExtSetSimulation;

	test00( cout );
	test01( cout );
	test02( cout );
	test03( cout );
	test04( cout );
	test05( cout );

}

void CSDIView::OnVectorTest( )
{
	static int imod = 0;
	++imod;
	if ( imod >= 6 )
	{
		imod = 1;
	}

	if ( imod == 1 )
	{
		coutExtSetSimulation;
		test_build_vector( );
		test_build_container( );
	}

	if ( imod == 2 )
	{
		coutExtSetSimulation;
		cout.flushscreen( );
		vector<int>vecta { 3, 4, 5, 6,33,89,992,8192,8282,1 };
		vector<int>intvec( 20 );
		deque<int>intvec2( 10 );
		cout.MakeEleRandom( intvec , 20 , 100 );
		cout.lmod( 20 );
		cout << cut << intvec << endl;
		cout.MakeEleRandom( intvec2 , 50 , 3000 );
		cout.lmod( 15 );
		cout << cut << intvec2 << endl;
		std::copy_if( intvec.begin( ) , intvec.end( ) , std::front_inserter( intvec2 ) , [ ] ( int v ) {return v < 10; } );
		cout << cut << intvec2 << newl;
		std::copy_if( intvec.begin( ) , intvec.end( ) , std::back_inserter( intvec2 ) , [ ] ( int v ) {return v > 15; } );
		cout << cut << intvec2 << cut;
		cout << tpcount( vecta ) << nl;
		cout.title( st( beging foreach mem_fun test ) );
		cout << vecta.size( ) << sp << vecta.max_size( ) << sp << vecta.capacity( ) << endl;
	}
	if ( imod == 3 )
	{
		//设置字体颜色，准备DC
		CDC& dc = this->SetDefaultFontDC( );

		int x = 50;
		int y = 50;
		int step = 30;
		int lstep = 120;

		CAtlString strFormat;
		const int linenumber = 60;
		const int cownumber = 15;
		vector<float>intvec( linenumber ) , empty;

		float icount = 0;
		float icountb = 1;
		for ( int i = 0; i < cownumber; i++ , icountb++ ) {
			icount = 0;
			icountb = i + 1;
			for ( auto& i : intvec )
			{
				i = icount++ / icountb++;
				strFormat.Format( _T( "%2.4lf" ) , i );
				dc.TextOut( x , y += step , strFormat );
			}
			x += lstep;
			y = 50;
		}
		x = lstep;
		y = 50 + linenumber * step;
		{
			intvec.swap( empty );
			strFormat.Format( _T( "%ld" ) , intvec.size( ) );
			dc.TextOut( x , y += step , strFormat );
			vector<float>xvect;
			intvec.swap( xvect );
			strFormat.Format( _T( "%ld" ) , intvec.size( ) );
			dc.TextOut( x , y += step , strFormat );
		}

		//恢kj复用户字体DC
		RestoreDCFont( dc );
	}
	if ( imod == 4 )
	{
		SimulationStdCout;
		cout.title( st( beging test ) );
		vector<int>intvect( 10 );
		vector<int> intvect2( intvect.begin( ) , intvect.begin( ) + 5 );
		for ( size_t i = 0; i < 20;)
		{
			intvect.push_back( ++i * 3 );
		}

		cout << intvect << endl;
		cout << "The vector size is " << intvect.size( ) << newl;
		intvect.pop_back( );
		intvect.pop_back( );
		cout << st( The vector size is afthe pop two element is : ) << intvect.size( ) << newl;

		cout << intvect << endl;
		cout << intvect.back( ) << tab << intvect.back( ) << tab << "size is: " << intvect.size( ) << tab << "max size is:" << intvect.max_size( ) << newl;

		intvect.insert( intvect.begin( ) + 5 , 10 );
		intvect.insert( intvect.begin( ) + 6 , 20 );
		intvect.insert( intvect.begin( ) + 7 , 30 );

		cout << intvect << endl;
		cout << intvect2;
		cout << cut;
		cout << intvect;
		intvect.resize( intvect.size( ) / 2 );
		cout << cut;
		cout << intvect;
		cout << cut;
		cout << intvect2;
		intvect.swap( intvect2 );
		cout << st( swap v1 & v2 ) << newl;

		cout << separtor;
		cout << intvect;
		cout << cut;
		cout << intvect2;
		cout << intvect.empty( ) << newl;
		intvect2.resize( 15 , 5 );

		cout << intvect2 << newl;
		for ( size_t i = 0; i < 1024; i++ )
		{
			intvect2.push_back( ( 2 + i ) );
		}
		intvect2.resize( 15 );
		SHOW( intvect2.size( ) ) << endl;
		SHOW( intvect2.capacity( ) ) << endl;
		intvect2.shrink_to_fit( );
		cout << intvect2 << endl;
		SHOW( intvect2.back( ) ) << endl;
		SHOW( intvect2.front( ) ) << endl;
		intvect2.insert( intvect2.begin( ) , 999 );
		intvect2.insert( intvect2.end( ) , 999 );
		cout << intvect2;
		SHOW( intvect2.size( ) ) << endl;
		SHOW( intvect2.capacity( ) ) << endl;
		intvect2.resize( 20 );
		SHOW( intvect2.capacity( ) ) << endl;
		SHOW( intvect2.size( ) ) << endl;
		intvect2.reserve( 100 );
		SHOW( intvect2.capacity( ) ) << endl;
		SHOW( intvect2.size( ) ) << endl;
		intvect2.reserve( 20 );
		SHOW( intvect2.capacity( ) ) << endl;
		SHOW( intvect2.size( ) ) << endl;
		vector<int>::iterator it = intvect2.begin( );
		SHOW( *it ) << endl;
		int x;
		cout << addressof( *it ) << tab << &*it << tab << address( x ) << newl;

	}
}

void CSDIView::OnTaskRuntimeTest( )
{
	coutExtSetSimulation;
	static size_t imod = 0;
	++imod;
	if ( imod == 6 ) imod = 1;
	if ( imod == 1 ) { OnTaskRuntimeTest1( cout ); }
	if ( imod == 2 ) { OnTaskRuntimeTest2( cout ); }
	if ( imod == 3 ) { OnTaskRuntimeTest3( cout ); }
	if ( imod == 4 ) { OnTaskRuntimeTest4( cout ); }
	if ( imod == 5 ) { OnTaskRuntimeTest5( cout ); }

}

void CSDIView::OnDcTcolorTest( )
{
	SimulationStdCout;
	static int imod = 0;
	++imod;
	if ( imod >= 6 ) { imod = 1; }
	if ( imod == 1 ) { OnDcTcolorTest1( cout ); }
	if ( imod == 2 ) { OnDcTcolorTest2( cout ); }
	if ( imod == 3 ) { OnDcTcolorTest3( cout ); }
	if ( imod == 4 ) { OnDcTcolorTest4( cout ); }
	if ( imod == 5 ) { OnDcTcolorTest5( cout ); }
}

void CSDIView::OnPCDCFunctionTest( )
{
	SimulationStdCout;
	static size_t imod = 0;
	++imod;
	if ( imod == 10 )
		imod = 1;
	if ( imod == 1 ) { OnPCDCFunctionTest1( cout ); }
	if ( imod == 2 ) { OnPCDCFunctionTest2( cout ); }
	if ( imod == 3 ) { OnPCDCFunctionTest3( cout ); }
	if ( imod == 4 ) { OnPCDCFunctionTest4( cout ); }
	if ( imod == 5 ) { OnPCDCFunctionTest5( cout ); }
	if ( imod == 6 ) { OnPCDCFunctionTest6( cout ); }
	if ( imod == 7 ) { OnPCDCFunctionTest7( cout ); }
	if ( imod == 8 ) { OnPCDCFunctionTest8( cout ); }
	if ( imod == 9 ) { OnPCDCFunctionTest9( cout ); }
}

void CSDIView::OnObjectSize( )
{
	//切换输出列
	SimulationStdCout;
	static int ichoice = 0;
	if ( ++ichoice > 3 ) ichoice = 1;
	if ( ichoice == 2 ) { OnObjectSize2( cout ); }
	if ( ichoice == 1 ) { OnObjectSize1( cout ); }
	if ( ichoice == 3 ) { OnObjectSize3( cout ); }

}

void CSDIView::OnStlTypeTest( )
{
	SimulationStdCout;
	static int imod = 0;
	++imod;
	if ( imod >= 4 ) { imod = 1; }

	if ( imod == 1 ) { OnStlTypeTest1( cout ); }
	if ( imod == 2 ) { OnStlTypeTest2( cout ); }
	if ( imod == 3 ) { OnStlTypeTest3( cout ); }
}


