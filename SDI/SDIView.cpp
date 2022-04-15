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


#include <chrono>
#include <functional>
#include <type_traits>
#include <tuple>
#include <iostream>
#include "SDIDoc.h"
#include "SDIView.h"
#include "FCDC.h"
#include "PCDC.h"
#include "CDialogExDoModal.h"
#include "resource.h"
#include <typeinfo>
#include <bitset>
#include <string>
#include <memory>
#include <set>
#include <map>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>
#include <cctype>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define addmenu(name) addmenuitem(#name,name);

#define gett(name)  decltype(name)
#define getI(name)  gett(name.begin())
#define getCI(name)  gett(name)::const_iterator
#define ALL(V)  V.begin(),V.end()
#define NTIME(N)  for(size_t ix=0;ix<(N);++ix)
#define FORALL(V,iterator)  for(getCI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORALLW(V,iterator)  for(getCI(V) V##iterator = V.begin(); V##iterator != V.end();++V##iterator)
#define FORN(N,icountn)  for(size_t icountn=0;icountn<(N);++icountn)
#define FORV(ielement,V)  for(const auto &ielement:V)
#define FORW(ielement,V)  for(auto &ielement:V)

#define makedc(cout)  unique_ptr<PCDC> me_unique_dc=make_unique<PCDC>(this); PCDC & cout=*me_unique_dc;

#define makemedc(DC)  unique_ptr<PCDC> pdc(new PCDC(this));PCDC& DC = *pdc;
#define SimulationStdCout  auto cout_me_ptr=make_unique<PCDC>(this);auto& cout= *cout_me_ptr;


#define lcode(...)	cout.settcolor(dccr.red)<<L"source code is:"<<el;cout.settcolor(dccr.berry)<<"{ "#__VA_ARGS__<<L" }"<<el;cout.settcolor(dccr.green)<<L"run result is: "<<el<<starline;cout.resettcolor();__VA_ARGS__;

#define showcode(...)	lcode(__VA_ARGS__)
#define showcodes(...)	lcode(__VA_ARGS__)
#define lscode(...)  lcode(__VA_ARGS__)

#define sst(code,...)  #code##","#__VA_ARGS__
#define SHOW(name) cout<<st(name)<<_T(" is: ")<<name<<tab
#define showv(name) st(name)<<_T(" value is: ")<<name<<tab
#define showtype(...)  cout<<#__VA_ARGS__<<" type:  "<<typeid(##__VA_ARGS__).name()<<"  size:  "<<sizeof(##__VA_ARGS__)<<"  HASH: "<<typeid(##__VA_ARGS__).hash_code()<<el;


#define RUNTEST(message)		/*cout.clearscreen();\
								cout.titleline(wstring(st(message)));*/

#define TITLE(message)      /*cout.clearscreen();\
							cout.titleline(wstring(st(message)));*/


template <typename T>
bool showinfo(PCDC* the, const T& c)
{
	PCDC& cout = *the;
	cout << "sizeof is:" << tab << sizeof(c) << tab << "typename is :" << tab << typeid(c).name() << el;
	return true;
};


class CColor dccr;



COLORREF crcolorred = RGB(255, 0, 0);
COLORREF crcolorgreen = RGB(34, 139, 34);
COLORREF crcolorblue = RGB(0, 0, 255);
COLORREF crcolorwhite = RGB(255, 255, 255);
COLORREF crcolorchocolate = RGB(238, 118, 33);
COLORREF crcolorblack = RGB(0, 0, 0);
COLORREF crcolorstellblue = RGB(70, 130, 180);
COLORREF crcolordarkgreen = RGB(0, 100, 0);
COLORREF crcolorgray = RGB(192, 192, 192);
COLORREF crcolorberry = RGB(135, 38, 87);
COLORREF crcolorbrown = RGB(128, 42, 42);
COLORREF crcolorazure = RGB(131, 139, 139);
COLORREF crcolorgrey = RGB(28, 28, 28);
bool is_show_logmessage = false;

// CSDIView

IMPLEMENT_DYNCREATE(CSDIView, CView)

BEGIN_MESSAGE_MAP(CSDIView, CView)
	ON_WM_PAINT()
	ON_COMMAND(ID_SET_FONT, &CSDIView::OnSetFont)
	ON_COMMAND(ID_SHOW_LOG, &CSDIView::OnShowlog)
	ON_COMMAND(ID_TEST_FONTDLG, &CSDIView::OnTestFontdlg)
	ON_COMMAND(ID_RESET_XY, &CSDIView::OnResetXY)
	ON_COMMAND(ID_TEST_CATLSTRING, &CSDIView::OnTestCAtlString)
	ON_COMMAND(ID_PRINT_ENV, &CSDIView::OnPrintEnvVAR)
	ON_COMMAND(ID_UPPER_LOWER, &CSDIView::OnUpperLower)
	ON_COMMAND(ID_MACRO_TEST, &CSDIView::OnMacroTest)
	ON_COMMAND(ID_GROUND_TEST, &CSDIView::OnGroundTest)
	ON_COMMAND(ID_OBJECT_SIZE, &CSDIView::OnObjectSize)
	ON_COMMAND(ID_AUTO_SETFONT, &CSDIView::OnAutoSetFont)
	ON_COMMAND(ID_BIT_EX_CHAR, &CSDIView::OnBitExChar)
	ON_COMMAND(ID_DIALGO_MODAL, &CSDIView::OnDialgoModal)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_READ_FILE, &CSDIView::OnReadFile)
	ON_COMMAND(ID_VECTOR_TEST, &CSDIView::OnVectorTest)
	ON_COMMAND(ID_MC_FP_TL_TEST, &CSDIView::OnMacroFuncPointTemplateTest)
	ON_COMMAND(ID_GET_WINDOWS_RECT, &CSDIView::OnGetWindowsRect)
	ON_COMMAND(ID_STL_FUNC_TEST, &CSDIView::OnSTLFuncTest)
	ON_COMMAND(ID_EXCEPT_CATCH_TEST, &CSDIView::OnExceptCatchTest)
	ON_COMMAND(ID_PCDC_FUNCTION_TEST, &CSDIView::OnPCDCFunctionTest)
	ON_COMMAND(ID_STL_STRING_TEST, &CSDIView::OnSTLlStringTest)
	ON_COMMAND(ID_STL_STACK_EQUEUE_TEST, &CSDIView::OnStlStackEqueueTest)
	ON_COMMAND(ID_CLEAR_RECORD, &CSDIView::OnClearRecord)
	ON_COMMAND(ID_STL_SET_TEST, &CSDIView::OnStlSetTest)
	ON_COMMAND(ID_STL_MAP_MENU, &CSDIView::OnStlMapMenu)
	ON_COMMAND(ID_STL_ARG_TEST, &CSDIView::OnSTLArgTest)
	ON_COMMAND(ID_CXX20_STL_CONCEPT_TEST, &CSDIView::OnCxx20StlConceptTest)
	ON_COMMAND(ID_LAMDBA_FUNC_TEST, &CSDIView::OnLamdbaFuncTest)
	ON_COMMAND(ID_STL_TUPLE_TEST, &CSDIView::OnStlTupleTest)
	ON_COMMAND(ID_STL_TYPE_TEST, &CSDIView::OnStlTypeTest)
	ON_COMMAND(ID_INITAL_LIST_TEST, &CSDIView::OnInitalListTest)
	ON_COMMAND(ID_PTR_UNIQUE_TEST, &CSDIView::OnPtrUniqueTest)
	ON_COMMAND(ID_LVAL_RVAL_TEST, &CSDIView::OnLvalRvalTest)
	ON_COMMAND(ID_STL_STD_FORWARD_TEST, &CSDIView::OnStlStdForwardTest)
	ON_COMMAND(ID_PAINT_DC_TEST, &CSDIView::OnPaintDcTest)
END_MESSAGE_MAP()

// CSDIView 构造/析构

CSDIView::CSDIView() noexcept {

	//append logmessagerecode macro
	{LOGMESSAGE(theApp); }

	//append random seed;
	srand(time(nullptr));
}

CSDIView::~CSDIView() {
}

BOOL CSDIView::PreCreateWindow(CREATESTRUCT& cs) {
	{ LOGMESSAGE(theApp); }
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSDIView 绘图

void CSDIView::OnDraw(CDC* pDC) {
	{ LOGMESSAGE(theApp); }
	CSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码


}

// CSDIView 诊断

#ifdef _DEBUG
void CSDIView::AssertValid() const { CView::AssertValid(); }

void CSDIView::Dump(CDumpContext& dc) const { CView::Dump(dc); }

CSDIDoc* CSDIView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDoc)));
	return (CSDIDoc*)m_pDocument;
}
#endif //_DEBUG

// CSDIView 消息处理程序

POINT CSDIView::SetPoint(int x, int y, POINT* p) {
	// 如果位置超出范围，进行回绕重置
	if (x >= 1900)
		x = 50;
	if (y >= 1900)
		y = 5;

	//如果参数指针不为空，将位置存入POINT结构
	if (p) {
		p->x = position.x;
		p->y = position.y;
		return *p;
	}

	//设置输出坐标位置
	this->position.x = x;
	this->position.y = y;

	//返回POINT结构return position;
}

void CSDIView::OnPaint() {
	{	LOGMESSAGE(theApp);	}
	// 用于绘制的设备上下文
	CPaintDC dc(this);
	//设置字体颜色，准备DC
	this->SetDefaultFontDC(&dc);

	//定义并设置输出起点位置
	long int& x = position.x;
	long int& y = position.y;
	int iline = 0;

	//恢复用户字体DC
	RestoreDCFont(dc);
}
//using namespace std;

void CSDIView::OnSetFont() {

	//设置字体
	memset(&m_userset_logfont, 0, sizeof(LOGFONT)); // zero out structure
	CFontDialog fontDlg(&m_userset_logfont);
	fontDlg.DoModal();

	is_font_set_ok = true;//字体设置成功，切换标志位
	fontDlg.GetCurrentFont(&m_userset_logfont);
	//放大字体间距
	step = abs(m_userset_logfont.lfHeight) * 1.5;

	//刷新屏幕
	this->Invalidate(true);
}

void CSDIView::OnShowlog() {
	// TODO: 在此添加命令处理程序代码
	SimulationStdCout;
	if (is_show_logmessage) {
		is_show_logmessage = false;
		cout << theApp.messagelog << el;
	}
	else {
		is_show_logmessage = true;
		this->Invalidate(true);
	}
}

void CSDIView::OnTestFontdlg() {
	// TODO: 在此添加命令处理程序代码
	CFontDialog dlg;
	CAtlString str, str2;
	str = "error";
	LOGFONT lf = { 0 };
	int size;
	int bsize;
	int csize;

	if (dlg.DoModal() == IDOK) {
		size = dlg.GetSize();
		bsize = size;
		csize = size;
		dlg.GetCurrentFont(&lf);

		str.Format(_T("The size of the selected font = %ld"), size);
		vecotr_paintmessage.push_back(str);
		str2 = dlg.GetFaceName();
		str = "FaceName is ";
		str += str2;
		vecotr_paintmessage.push_back(str);
		str.Format(_T("The size of the selected font = %ld"), size);
		vecotr_paintmessage.push_back(str);
		str.Format(_T("The bsize of the selected font = %ld"), bsize);
		vecotr_paintmessage.push_back(str);

		str.Format(_T("The csize of the selected font = %ld"), csize);
		vecotr_paintmessage.push_back(str);
		CAtlString str2;
		str2.Format(_T("The size = %ld =%ld =%ld"), size, bsize, csize);
		vecotr_paintmessage.push_back(str2);
		this->Invalidate(true);
	}
	else {
		AfxMessageBox(str);
	}
}

void CSDIView::OnResetXY()
{
	// 重设输出位置坐标
	SetPoint(50, 5);

}

void CSDIView::OnTestCAtlString()
{
	SimulationStdCout;
	char charmark = '*';
	int nchartime = 140;
	CAtlString strsplint(charmark, nchartime);
	cout << strsplint << el;

	wstring wstr1(_T("wstring is ok"));
	string astr1 = "astr1,string class";
	CAtlString strFormat(wstr1.c_str());
	cout << astr1 << el;
	cout << wstr1 << el;
	cout << strFormat << el;

	wstr1 = _T("this is a wstring test string");
	strFormat = wstr1.c_str();
	cout << wstr1 << el;
	cout << strFormat << el;
	strFormat = astr1.c_str();
	cout << strFormat << el;

	wstr1 = _T("this is a wstring test string");
	cout << wstr1 << el;

	// 定义备用变量
	CAtlString EnvStr, tok;
	CAtlString midle, temp, liststr, dome, grep, name, dock;
	CAtlString message, formatv, tail, head, result, str;
	unsigned long int ii = 0, ij = 0, itt = 0, icount = 0, imark = 0, itail = 0, imid = 0;

	//测试CAtlString Appendformat 功能
	formatv = (_T("first "));
	cout << formatv << el;
	formatv.AppendFormat(_T("position.x is %ld ,position.y is %ld"), position.x, position.y);
	vecotr_paintmessage.push_back(formatv);
	tail = "is ok";
	head = "is ok";
	ii = tail.CompareNoCase(head);
	message.Format(_T("#%ld"), ++icount);
	message = tail;
	message += " <CompareNoCase> ?qual ";
	message += head;
	message.AppendFormat(_T(" return value = %ld"), ii);
	cout << message << el;
	vecotr_paintmessage.push_back(message);

	tail = "is ok";
	head = "Is oK";
	ii = tail.CollateNoCase(head);
	message.Format(_T("#%ld"), ++icount);
	message = tail;
	message += "<CollateNoCase> ?qual ";
	message += head;
	message.AppendFormat(_T(" return value = %ld"), ii);
	cout << message << el;
	vecotr_paintmessage.push_back(message);

	tail = _T("123456789");
	ii = 5; ij = 3;
	message = tail;
	tail.Delete(ii, ij);
	message.AppendFormat(_T("从 %ld 开始删除 %ld 个字符 = "), ii, ij);
	message += tail;
	cout << message << el;
	vecotr_paintmessage.push_back(message);

	str.Format(_T("Floating point: %.2f\n"), 12345.12345);
	_tprintf_s(_T("%s"), (LPCTSTR)str);
	message = str;
	cout << message << el;
	vecotr_paintmessage.push_back(message);

	str.Format(_T("Left-justified integer: %.6d\n"), 35);
	_tprintf_s(_T("%s"), (LPCTSTR)str);
	message = str;
	cout << message << el;
	vecotr_paintmessage.push_back(message);

}

void CSDIView::OnPrintEnvVAR()
{
	// 打印环境变量
	SimulationStdCout;
	CAtlString EnvStr, tok;
	EnvStr.GetEnvironmentVariable(_T("PATH"));
	int ipos = 0;
	tok = EnvStr.Tokenize(_T(";"), ipos);

	while (!isempty(tok)) {
		vecotr_paintmessage.push_back(tok);
		tok = EnvStr.Tokenize(_T(";"), ipos);
	};
	for (const auto& i : vecotr_paintmessage)
		cout << i << el;
	lscode(
		cout << "this is out dc" << tab << &cout << tab << el;
	);
}

void CSDIView::OnUpperLower()

{
	//大小写开关bool值，静态变量，已记录上次转换状态
	static bool isupper = true;

	//如果是大写转换位标志为真，则进行大写转换，否则进行小写转换
	if (isupper) {
		for (auto& i : vecotr_paintmessage) {
			i.MakeUpper();
		}
		for (auto& i : theApp.messagelog)
		{
			i.MakeUpper();
		}
	}
	else
	{//如果是小写转换位标志，开始进行小写转换,循环日志数据记录容器
		for (auto& i : vecotr_paintmessage) {
			i.MakeLower();
		}
		for (auto& i : theApp.messagelog)
		{
			i.MakeLower();
		}
	}

	//反转大小写转换位标志，以便下次进入自动进行反向转换
	isupper = !isupper;

	this->Invalidate(true);
}

template <typename T>
T add(T a, T b)
{
	return a + b;
}

template <typename T>
T sub(T a, T b)
{
	return a - b;
}

template <typename T>
T mul(T a, T b)
{
	return a * b;
}

template <typename T>
T divv(T a, T b)
{
	return a / b;
}

void CSDIView::OnObjectSize()
{
	//切换输出列
	makedc(cout);
	static int ichoice = 0;
	if (++ichoice > 2)
		ichoice = 1;

	if (ichoice == 1)
	{
		cout << cl;
		showtype(CObject);
		showtype(FCDC);
		showtype(PCDC);
		showtype(CDC);
		showtype(CPaintDC);
		showtype(CColor);
		showtype(LOGFONT);
		showtype(CFont);
		showtype(CFontDialog);
		showtype(CView);
		showtype(CFrameWnd);
		showtype(CWinApp);
		showtype(CSplitterWnd);
		showtype(CDumpContext);
		showtype(CREATESTRUCT);
		showtype(CToolBar);
		showtype(CStatusBar);
		showtype(CCreateContext);
		showtype(CClientDC);
		showtype(CSDIDoc);
		showtype(CArchive);
		showtype(CFileDialog);
		showtype(CD2DSizeU);
		showtype(CHwndRenderTarget);
		showtype(&CSDIView::OnObjectSize);
		showtype(FILE);
		showtype(LRESULT);
		showtype(HDC);
		showtype(HWND);
		showtype(POINT);
		showtype(RECT);
		showtype(CRect);
		showtype(CSize);
		showtype(NMHDR);
		showtype(HMODULE);
		showtype(_AFX_THREAD_STATE);
		showtype(WINDOWPLACEMENT);
		showtype(AFX_MSGMAP);
		showtype(AFX_MSGMAP_ENTRY);
		showtype(LPARAM);
		showtype(WPARAM);
		showtype(string);
		showtype(CAtlString);
		showtype(CString);
		showtype(DWORD);
		showtype(WORD);
		showtype(dccr.berry);
	}

	if (ichoice == 2)
	{
		cout << cl;
		showtype(BYTE);
		showtype(char);
		showtype(char&);
		showtype(const char);
		showtype(const char&);
		showtype(int);
		showtype(int&);
		showtype(const int);
		showtype(const int&);
		showtype(short);
		showtype(long);
		showtype(LONG);
		showtype(long long);
		showtype(double);
		showtype(float);
		showtype(long double);
		showtype(bool);
		showtype(BOOL);
		showtype(size_t);
		showtype(NULL);
		showtype(void*);
		showtype(int*);
		showtype(const int*);
		showtype(int*&);
		showtype(const int*&);
		showtype(char*);
		showtype(const char*);
		showtype(char*&);
		showtype(uintptr_t);
		showtype(intptr_t);
		showtype(shared_ptr<int>);
		showtype(unique_ptr<int>);
		showtype(nullptr);
		showtype(set<int>);
		showtype(vector<int>);
		showtype(map<int, string>);
		showtype(multimap<int, string>);
		showtype(tuple<int, string, CString>);
	}

}

void CSDIView::OnAutoSetFont()
{
	// 设置字体、背景颜色
	CDC* p = this->GetWindowDC();
	CDC& dc = *p;
	auto cb = dccr.grey;
	auto ct = dccr.chocolate;
	dc.SetBkColor(cb);
	dc.SetTextColor(ct);

	//设置窗口背景颜色
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, dccr.grey);

	//CAtlString strText = _T("自动设置为系统字体");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 24;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);
	CFont* pOldFont = dc.SelectObject(&fontDraw);

	//dc.DrawText(strText, &rect, DT_CENTER | DT_WORDBREAK);

	//删除字体
	dc.SelectObject(pOldFont);
}

void CSDIView::OnBitExChar()
{
	SimulationStdCout;
	CAtlString catstrbit32;
	CAtlString csmessage;
	LONGLONG i = 256 * 256 * 256;
	string sbitstr;
	bitset<64> bit64a = 256;
	vector<CAtlString> v;
	sbitstr = bit64a.template to_string<char, char_traits<char>, allocator<char> >();
	catstrbit32 = sbitstr.c_str();

	cout << bit64a << el;
	cout << bitset<64>(256) << el;
	cout << catstrbit32 << cut;

	bit64a = 256 * 256 * 256 * 256 * 256 * 256 * 256 * 256 - 1;
	cout << bit64a << el;

	sbitstr = bit64a.template to_string<char, char_traits<char>, allocator<char> >();
	cout << CAtlString(sbitstr.c_str()) << el;

	cout << typeid(catstrbit32).name() << el;
	//cout.titleline(wstring(st(start test except catch try and throw...)));

}

CDC& CSDIView::SetDefaultFontDC(CDC* pdc/*=nullptr*/)
{
	if (pdc == nullptr)
	{
		pdc = this->GetWindowDC();
	}

	CDC& dc = *pdc;
	auto bcolor = dccr.grey;
	auto tcolor = dccr.chocolate;

	//设置窗口背景颜色
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, bcolor);

	//设置字体颜色
	dc.SetBkColor(bcolor);
	dc.SetTextColor(tcolor);

	//设置缺省字体
	LOGFONT lf;
	// zero out structure
	memset(&lf, 0, sizeof(LOGFONT));

	//如果字体选择标志置位，使用用户选择字体
	if (is_font_set_ok) {
		VERIFY(m_user_font.CreateFontIndirect(&m_userset_logfont));
	}
	else {
		m_user_font.DeleteObject();
		if (!m_user_font.CreatePointFont(120, _T("Cascadia Code")))
			strbox(font creat fail);
	}

	m_p_defaultfont = dc.SelectObject(&m_user_font);

	//根据字体大小调整步长
	m_user_font.GetLogFont(&lf);
	step = abs(lf.lfHeight + lf.lfHeight / 2);

	//检查输出位置
	if (!dc.PtVisible(position)) {
		this->SetPoint(50, 5);
	}
	dc.AssertValid();
	return dc;//返回设备DC引用
}

bool CSDIView::RestoreDCFont(CDC& dc)
{
	//删除用户字体
	if (&dc != nullptr) {
		dc.SelectObject(m_p_defaultfont);
	}
	m_user_font.DeleteObject();
	this->ReleaseDC(&dc);
	return true;
}

void CSDIView::OnDialgoModal()
{
	// TODO: 在此添加命令处理程序代码
	m_fontresize_CDialogExDoModal.DoModal();
}

void CSDIView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAtlString strwindowstitle;
	strwindowstitle.Format(_T("Reset Current print position is x:%ld,y:%ld !"), position.x, position.y);
	position.x = point.x;
	position.y = point.y;
	theApp.m_pMainWnd->SetWindowText(strwindowstitle);

	CView::OnLButtonDblClk(nFlags, point);
}

void CSDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAtlString strwindowstitle;
	strwindowstitle.Format(_T("Current print position is x:%ld,y:%ld ,current cursor positon is x:%ld,y:%ld . TIP:Double click mouse left can reset the positon."), position.x, position.y, point.x, point.y);
	theApp.m_pMainWnd->SetWindowText(strwindowstitle);

	CView::OnMouseMove(nFlags, point);
}

void CSDIView::OnReadFile()
{
	//准备用户DC 
	CDC& dc = this->SetDefaultFontDC();

	//定义文件对话框 设置为打开
	CFileDialog f(true);
	f.DoModal();

	//得到文件名
	CAtlString openfilename = f.GetPathName();
	CFile cfile(openfilename, CFile::modeRead);

	//准备读入缓冲区
	const int icount = 1024;
	int iretcount = 1024;
	char pbufRead[icount];
	memset(pbufRead, 0, sizeof(pbufRead));
	ASSERT(sizeof(pbufRead) == icount);

	cfile.SeekToBegin();
	CAtlString readline;

	//定义输出区域
	RECT rect;
	this->GetWindowRect(&rect);

	//开始读入数据，如果读入字节数小于设置读入字节（返回值），说明读到文件末尾，退出读取循环。
	while (iretcount == icount)
	{
		iretcount = cfile.Read(pbufRead, sizeof(pbufRead));
		readline = pbufRead;
		dc.DrawText(readline, iretcount, &rect, DT_LEFT);
	}

	//ASSERT(0 == memcmp(pbufWrite, pbufRead, sizeof(pbufWrite)));
	cfile.Close();

	//恢复用户字体DC
	RestoreDCFont(dc);
}

void CSDIView::OnVectorTest()
{
	//设置字体颜色，准备DC
	CDC& dc = this->SetDefaultFontDC();

	int x = 50;
	int y = 50;
	int step = 30;
	int lstep = 120;

	CAtlString strFormat;
	const int linenumber = 60;
	const int cownumber = 15;
	vector<float>intvec(linenumber), empty;

	float icount = 0;
	float icountb = 1;
	for (int i = 0; i < cownumber; i++, icountb++) {
		icount = 0;
		icountb = i + 1;
		for (auto& i : intvec)
		{
			i = icount++ / icountb++;
			strFormat.Format(_T("%2.4lf"), i);
			dc.TextOut(x, y += step, strFormat);
		}
		x += lstep;
		y = 50;
	}
	x = lstep;
	y = 50 + linenumber * step;
	{
		intvec.swap(empty);
		strFormat.Format(_T("%ld"), intvec.size());
		dc.TextOut(x, y += step, strFormat);
		vector<float>xvect;
		intvec.swap(xvect);
		strFormat.Format(_T("%ld"), intvec.size());
		dc.TextOut(x, y += step, strFormat);
	}

	//恢kj复用户字体DC
	RestoreDCFont(dc);
}

template <typename T>
T(*pt)(T a, T b);

void CSDIView::OnMacroFuncPointTemplateTest()
{
	//设置字体颜色，准备DC
	CDC& dc = this->SetDefaultFontDC();

	int x = 50;
	int y = 50;
	int a = 100;
	int b = 10;
	float fa = 100.33;
	float fb = 10.22;
	int step = 30;
	int lstep = 120;


	//测试宏

	//测试函数指针
	CAtlString strFormat;
	pt<int>;
	int(*func)(int a, int b);
	float (*fund)(float a, float b);
	func = add<int>;
	strFormat.Format(_T("%ld"), func(a, b));
	dc.TextOut(x, y += step, strFormat);
	fund = add;
	strFormat.Format(_T("*func=add %ld"), func(a, b));
	//dc.(x, y += step, strFormat);
	//出现异常
	/*func = pt<int>;
	strFormat.Format(_T("(*func) add<int>%ld"), func(a, b));
	dc.TextOut(x, y += step, strFormat);*/
	func = add;
	strFormat.Format(_T("(*func) add<int>%ld"), func(a, b));
	dc.TextOut(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOut(x, y += step, strFormat);
	strFormat.Format(_T("%ld"), func(a, b));
	dc.TextOut(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOut(x, y += step, strFormat);

	strFormat.Format(_T("%lf"), divv(fa, fb));
	dc.TextOut(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOut(x, y += step, strFormat);

	//恢复用户字体DC
	RestoreDCFont(dc);
}

void CSDIView::OnGetWindowsRect()
{
	//设置字体颜色，准备DC
	RECT rect;
	this->GetWindowRect(&rect);
	CString strto;
	makedc(dcout);
	strto.Format(_T("step %ld "), step);
	dcout << strto << el;
	strto.Format(_T("rect.left %ld "), rect.left);
	dcout << strto << el;
	strto.Format(_T("rect.right %ld "), rect.right);
	dcout << strto << el;
	strto.Format(_T("rect.bottm %ld "), rect.bottom);
	dcout << strto << el;
	strto.Format(_T("rect.top %ld "), rect.top);
	dcout << strto << el;

	CAtlString strwindowstitle;
	strwindowstitle.Format(_T("Current print position is x:%ld,y:%ld"), position.x, position.y);
	theApp.m_pMainWnd->SetWindowText(strwindowstitle);

}

bool CSDIView::writedc(const CAtlString& str, CDC* pdc)
{
	//设置字体颜色，准备DC

	bool dcreset = false;
	if (pdc == nullptr)
	{
		pdc = &this->SetDefaultFontDC();
		dcreset = true;
	}
	pdc->TextOut(position.x, position.y, str);
	position.y += step;

	//恢复用户字体DC
	if (dcreset)
		RestoreDCFont(*pdc);
	return dcreset;
}

void CSDIView::OnSTLFuncTest()
{
	//FCDC dcout(this);
	makedc(dcout);
	int ia = 10, ib = 20;
	float	fa = 1.1, fb = 11.0;
	CAtlString strout;

	strout.Format(st("ia is %ld ,ib is %ld ,add result  is %ld "), ia, ib, add(ia, ib));
	dcout << strout << el;
	strout.Format(st("ia is %ld ,ib is %ld ,sub result  is %ld "), ia, ib, sub(ia, ib));
	dcout << strout << el;
	strout.Format(st("ia is %ld ,ib is %ld ,mul result  is %ld "), ia, ib, mul(ia, ib));
	dcout << strout << el;
	strout.Format(st("ia is %ld ,ib is %ld ,divv resultm is %ld "), ia, ib, divv(ia, ib));
	dcout << strout << el;
	strout.Format(st("fa is %lf ,ib is %lf ,add result  is %lf "), fa, fb, add(fa, fb));
	dcout << strout << el;
	strout.Format(st("fa is %lf ,ib is %lf ,sub result  is %lf "), fa, fb, sub(fa, fb));
	dcout << strout << el;
	strout.Format(st("fa is %lf ,ib is %lf ,mul result  is %lf "), fa, fb, mul(fa, fb));
	dcout << strout << el;
	strout.Format(st("fa is %lf ,ib is %lf ,div result  is %lf "), fa, fb, divv(fa, fb));
}

void runexcept(int ia = 1, float fa = 2.1, char* ps = nullptr)throw(int, float, double, char*, char, CString)
{
	if (ia == 1) { int e = ia; throw e; }
	if (ia == 2) { float e = fa; throw e; }
	if (ia == 3) { double e = 8.888; throw e; }
	//if (ia == 4) { char* e = "is error"; throw e; }
	if (ia == 5) { char e = 'a'; throw e; }
	if (ia == 6) { CString e; e = _T("somthing is error "); e += __func__; throw e; }
};

void CSDIView::OnClearRecord()
{
	////清空记录
	vecotr_paintmessage.clear();
	this->Invalidate(true);
}

void CSDIView::OnExceptCatchTest()
{

	// 测试throw异常类型 
	SimulationStdCout;
	try {
		cout << "before runexcept" << el;
		//runexcept(1);
		//被跳过
		cout << "under runexcept" << el;
	}
	catch (char* e)
	{
		cout << typeid(e).name() << el;
	}
	catch (float e) {
		cout << e << el;
	}
	catch (double e) {
		cout << e << el;
	}
	catch (int e) {
		cout << e << el;
	}
	catch (char e) {
		cout << e << el;
	}
	catch (const CString& e) {
		cout << e << el;
	}
	catch (...) { cout << "catch all error" << el; };

}

template<typename X>
X value(X a)
{
	return a;
}

template<typename ...X>
int  argsvalue(X...args)
{
	int i = 0;
	int ai[] = { (value(args),0)... };
	return i;
}

class A {
public:
	template<typename T >
	auto operator<<(initializer_list<T> c)
	{
		T isum = *c.begin() - *c.begin();
		for (auto i : c)
			isum += i;
		return isum;
	}

	template<typename T >
	auto sum(initializer_list<T> c)
	{
		T isum = *c.begin() - *c.begin();
		for (auto i : c)
			isum += i;
		return isum;
	}
};


void CSDIView::OnSTLlStringTest()
{
	SimulationStdCout;
	RUNTEST(STRING TEST);
	string s1 = "ok", s2 = "bad", s3 = "+";
	s1.append(s3);
	s1.append(s2);
	s1.append(s3);
	s1.append("good");
	s1.append(s3);
	s1.append(s2);

	cout << s1 << el;
	cout << s1.find(s2) << el;
	cout << s1.find("good") << el;
	cout << s1.rfind(s2) << el;

	cout << s1 << el;
	s1.replace(0, 0, "byeeeee");
	cout << s1 << el;
	cout << s1.substr(7, 4) << el;
	s1.insert(1, "ddd");
	cout << s1 << el;
	s1.erase();
	cout << "erase after " << s1 << el;

}

void CSDIView::OnGroundTest()
{
	SimulationStdCout;
	vector<int>intvect;
	for (size_t i = 0; i < 20;)
	{
		intvect.push_back(++i * 3);
	}

	for (auto& i : intvect)
		cout << i << tab;
	cout << el;
	cout << "The vector size is " << intvect.size() << el;

	intvect.pop_back();
	intvect.pop_back();

	cout << st(The vector size is afthe pop two element is : ) << intvect.size() << el;

	for (auto& i : intvect)
		cout << i << tab;
	cout << el;
	cout << intvect.back() << tab << intvect.back() << tab << "size is: " << intvect.size() << tab << "max size is:" << intvect.max_size() << el;

	intvect.insert(intvect.begin() + 5, 10);
	intvect.insert(intvect.begin() + 6, 20);
	intvect.insert(intvect.begin() + 7, 30);

	for (auto& i : intvect)
		cout << i << tab;
	cout << el;
	vector<int> intvect2(intvect.begin(), intvect.begin() + 5);
	cout << intvect2;
	cout << starline;
	cout << intvect;
	intvect.resize(intvect.size() / 2);
	cout << starline;
	cout << intvect;
	cout << intvect2;
	intvect.swap(intvect2);
	cout << st(swap v1 & v2) << el;

	cout << starline;
	cout << intvect;
	cout << intvect2;
	cout << intvect.empty() << el;

	cout << starline;
	intvect2.resize(15, 5);
	cout << intvect2;
	for (size_t i = 0; i < 1024; i++)
	{
		intvect2.push_back((2 + i));
	}
	cout << starline;
	intvect2.resize(15);
	SHOW(intvect2.size());
	SHOW(intvect2.capacity());
	intvect2.shrink_to_fit();
	cout << intvect2;
	SHOW(intvect2.back());
	SHOW(intvect2.front());
	intvect2.insert(intvect2.begin(), 999);
	intvect2.insert(intvect2.end(), 999);
	cout << intvect2;
	cout << starline;
	SHOW(intvect2.size());
	SHOW(intvect2.capacity());
	intvect2.resize(20);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	intvect2.reserve(100);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	cout << starline;
	intvect2.reserve(20);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	vector<int>::iterator it = intvect2.begin();
	SHOW(*it);
	int x;
	cout << addressof(*it) << el;
	cout << &*it << el;
	cout << sizeof(int*) << tab << sizeof(int) << tab << sizeof(long long) << el;
	cout << address(x) << el;


	TITLE(PRINT  deque TEST);
	deque<int>d1;
	for (size_t i = 0; i < 20; i++)
	{
		d1.push_back(i * 2);
	}
	for (auto& i : d1)
		cout << i << tab;
	cout << el;
	d1.pop_front();
	cout << starline;
	d1.push_front(1000);
	for (int j = 0; j < 8; j++) {
		cout << j << "#" << tab;
		for (auto& i : d1) {
			cout << (i = i + j) << tab;
		}
		cout << el;
	}
	CRect rect = { 0,0,0,0 };
	cout << starline;
	for (auto& i : d1)
		cout << i << tab;
	cout << el;
	d1.pop_back();
	d1.pop_front();
	for (size_t i = 0; i < 5; i++)
	{
		d1.pop_front();
	}
	d1.emplace_back(888);
	cout << d1.size() << el;
	SHOW(d1.size());
	SHOW(d1.max_size());
	SHOW(d1.empty());
	SHOW(d1.at(5));
	cout << el;
	cout.setlinechar('-');
	cout << starline;
	for (auto& i : d1)
		cout << i << tab;
	cout << el;
	d1.insert(d1.begin(), 222);
	cout << *d1.begin() << el;
	this->GetWindowRect(&rect);

	cout << rect.bottom << tab << rect.top << tab << rect.right << tab << rect.left << el;


}

void CSDIView::OnStlStackEqueueTest()
{
	SimulationStdCout;
	RUNTEST(STACK EQUEUE TEST);
	cout.setcolor(dccr.darkslateblue, dccr.darkgreen, cout.m_bk, cout.m_tk);
	cout << cl;
	stack<int>ist;
	for (size_t i = 0; i < 20; i++)
	{
		ist.push(i + 10);
	}
	cout << ist.top() << el;
	cout << ist.size() << tab << ist.top() << tab << (ist.pop(), ist.top()) << el;
	cout << starline;
	cout << ist.size() << tab << ist.top() << el;
	cout << ist.top() << tab << ist.size() << tab << (ist.pop(), ist.top()) << tab << ist.size() << tab << ist.top() << el;
	cout << ist.size() << tab << ist.top() << el;
	cout << ist.empty();

	queue <int> ieq;
	for (size_t i = 0; i < 10; i++)
	{
		ieq.push(i + 2);
	}
	cout.setlinechar('#');
	cout << starline;
	cout << ieq.front() << el;
	cout << ieq.back() << el;
}

class clist;

class clist {
public:
	clist* pnext = nullptr;
	int* pdata = nullptr;
public:
	clist(int d = 0)
	{
		pdata = new int;
		*pdata = d;
	}
	~clist()
	{
		delete pdata;
		pnext = nullptr;
	}
	clist* getnextp()
	{
		return pnext->pnext;
	};
	clist* setnextporaddnew(clist* p = nullptr)
	{
		if (p == nullptr) {
			pnext = new clist(0);
		}
		else
		{
			pnext = p;
		}
		return pnext->pnext;
	}
	int setdata(int d)
	{
		return *pdata = d;
	}
};

template <typename T, typename DC>
bool PrintSingleEle(T& e, DC& dc)
{
	dc << e << tab;
	return true;
}

template <typename T, typename DC>
bool PrintEle(const T& v, DC& dc)
{
	int il = 1;
	if (v.empty())
		return false;
	for (const auto& i : v)
	{
		if (il % 10 == 0)
		{
			++il;
			PrintSingleEle(i, dc);
			dc << el;
		}
		else
			PrintSingleEle(i, dc);
	}
	dc << el;
	return true;
}

void CSDIView::OnMacroTest()
{
	SimulationStdCout;
	list<int>ilt;
	for (size_t i = 0; i < 15; i++)
	{
		ilt.push_back(i + 10);
	}
	for (list<int>::iterator it = ilt.begin(); it != ilt.end(); ++it)
	{
		*it *= 2;
	}
	CString ssss('2', 129);
	cout << ssss << el;
	for (size_t l = 0; l < ssss.GetLength(); l++)
	{
		if (l % 2 == 1)
			ssss.Insert(l, '3');
	}
	cout << ssss << el;
	for (size_t l = 0; l < ssss.GetLength(); l++)
	{
		if (l % 3 == 2)
			ssss.Insert(l, '4');
	}
	cout << ssss << el;
	list<int> l2(ilt);
	cout.setlinechar('-');
	for (list<int>::iterator it = ilt.begin(); it != ilt.end(); ++it)
	{
		*it *= 2;
		cout << *it << tab;
	}
	cout << el;
	cout.setlinechar('-');
	for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it)
	{
		*it *= 2;
		cout << *it << tab;
	}
	cout << el;
	cout.clearscreen();
	lcode(ilt.erase(ilt.begin()); PrintEle(ilt, cout));
	lcode(ilt.pop_back(); PrintEle(ilt, cout));
	lcode(ilt.pop_front(); PrintEle(ilt, cout));
	lcode(ilt.insert(ilt.begin(), 666); PrintEle(ilt, cout));
	lcode(ilt.insert(ilt.begin(), 666); ilt.insert(ilt.begin(), 666); PrintEle(ilt, cout));
	lcode(ilt.remove(*ilt.begin()); PrintEle(ilt, cout));
	lcode(ilt.reverse(); PrintEle(ilt, cout));
	lcode(PrintEle(l2, cout); l2.reverse(); PrintEle(l2, cout));
	lcode(ilt.swap(l2); PrintEle(ilt, cout); PrintEle(l2, cout));
	lcode(ilt.sort(); ilt.reverse(); PrintEle(ilt, cout););

	cout << __FUNCTION__ << tab << __FUNCDNAME__ << tab << __FUNCSIG__ << el;
	cout << __DATE__ << __TIME__ << tab << __FILE__ << tab << __LINE__ << tab << __STDC_HOSTED__ << el;

}

template <typename T>
void MakeSingleEleRandom(T& r, const int mod)
{
	r = rand() % mod;
}

template <typename T>
bool MakeEleRandom(T& r, const int mod)
{
	if (r.empty())
		return false;
	for (auto& i : r)
		MakeSingleEleRandom(i, mod);
	return true;
}

bool iset = false;
bool compare(int a, int b)
{
	if (iset)
	{
		return a > b;
	}
	else
	{
		return a < b;
	}
}

void CSDIView::OnStlSetTest()
{
	SimulationStdCout;
	set<int> iset1;
	int mod = 30;
	for (size_t i = 0; i < 30; i++)
	{
		iset1.insert(i * rand() % mod);
	}
	cout<<iset1<<el;
	iset1.insert(25);
	cout<<iset1<<el;

	lcode(cout << iset1.size() << tab << iset1.count(15) << tab << iset1.max_size() << el; cout<<iset1;);

	lcode(cout << *iset1.begin() << tab << *iset1.end() << tab << iset1.empty() << tab << iset1.erase(5) << el; cout<<iset1<<el;);
	auto it = iset1.find(8);
	if (it == iset1.end())
		cout << "is end" << el;
	lcode(iset1.insert(100););
	lcode(iset1.insert(200););
	lcode(iset1.insert(300););
	lcode(cout << "find" << tab << *iset1.upper_bound(20) << el; cout<<iset1<<el;);
	lcode(cout << "find" << tab << *iset1.lower_bound(10) << el; cout<<iset1;);

	class icompset {
	public:
		bool mset = false;
		int ivalset = 0;
		void* iptset = nullptr;
		bool ichceknull = false;


	public:
		icompset& sortset(bool iset)
		{
			mset = iset;
			return *this;
		}


		bool operator()(int a)
		{
			if (mset)
			{
				return a > ivalset;
			}
			else
			{
				return a < ivalset;
			}
		}


		bool operator()(int a, int b)const
		{
			if (mset)
			{
				return a > b;
			}
			else
			{
				return a < b;
			}
		}


		bool compare(int a, int b)const
		{
			if (mset)
			{
				return a > b;
			}
			else
			{
				return a < b;
			}
		}


		CString operator()(CString name = _T(""), PCDC* pdc = nullptr)
		{
			if (pdc != nullptr)
			{
				if (name.IsEmpty())
				{
					*pdc << "name is null !" << el;
				}
				else
				{
					*pdc << "name is " << tab << name << tab << __func__ << tab;
				}
			}
			return name;
		};
	};
	cout << cl;
	icompset a;
	cout << a(st(good), &cout) << tab << el;
	cout << a(100) << tab << el;

	list<int>ilt;
	for (size_t i = 0; i < 15; i++)
	{
		ilt.push_back((rand() * i * rand()) % 100);
	}
	cout<<ilt<<el;

	vector<int>intvec(20), empty;
	int i = 0;
	int icount = 1;
	int icountb = i + 1;
	for (auto& i : intvec)
	{
		i = icount++ * icountb++;
	}

	ilt.sort(a);
	cout<<ilt<<el;
	a.sortset(true); ilt.sort(a);
	cout<<ilt<<el;
	a.sortset(false); ilt.sort(a.sortset(false));
	cout<<ilt<<el;
	sort(intvec.begin(), intvec.end(), compare);
	cout<<ilt<<el;
	sort(intvec.begin(), intvec.end(), a.sortset(true)); 
	cout<<ilt<<el;
	a.sortset(false); sort(intvec.begin(), intvec.end(), a);
	cout<<ilt<<el;
	ilt.reverse(); 
	cout<<ilt<<el;



	typedef void (*fun)(int, int);
	fun pfun = nullptr;
	CString wstring = _T("good");
	pair < CString, fun> w = make_pair(wstring, pfun);
	map<CString, fun> cfmap;
	cfmap.insert(w);
	cfmap.insert(make_pair(CString(wstring += wstring), pfun));
	cfmap.insert(pair<CString, fun>(CString(wstring = st(go)), pfun));
	cfmap.insert(map<CString, fun>::value_type(CString(st(bad)), pfun));
	cout << cfmap.size() << el;


	pair<int, float>x = make_pair(10, 2.3);
	cout << x.first << tab << x.second << el;
	auto* p = &x;
	map<int, float>imap;
	imap.insert(make_pair(10, 2.2));
	imap.insert(x);
	map<int, float>::iterator iit = imap.begin();
	lcode(cout << iit->first << tab << iit->second << el;);
	//lcode(iit = imap.end(); cout << p->first << tab << p->second << el;);
	lcode(iit = imap.begin(); cout << p->first << tab << p->second << el;);

}

int ntest(PCDC& dc, string p)
{
	dc << p << el;
	return 0;
}

typedef int (*pfunc)(PCDC&, string);

#define MAKEMENUITEM(fname,menumap)  { string str=#fname;\
					pfunc p=fname;\
					menumap.insert(make_pair(str,p));}

void CSDIView::OnStlMapMenu()
{
	SimulationStdCout;
	map<string, pfunc> menu;
	MAKEMENUITEM(ntest, menu);
	string name = "map second";
	map<string, pfunc>::iterator itt = menu.begin();
	itt->second(cout, itt->first);
	itt->second(cout, name);

	void* p = nullptr;
	cout << p << el;

	cout << (int) nullptr << tab << NULL << el;

	cout << sizeof(nullptr) << tab << sizeof(0) << tab << sizeof(NULL) << tab << sizeof(p) << el;

	cout << cl;
	int* pint = new int[1024];
	long long int sum = 0;
	for (size_t i = 0; i < 128; ++i)
	{
		pint[i] = 1 + i;
		sum += pint[i];
	}
	int* plint = new int;
	*plint = sizeof(pint);
	cout << "array size is : " << *plint << tab << "sum is " << sum << "  array elements is :" << el;
	for (size_t i = 0; i < 1024; i++)
	{
		cout << pint[i] << ", ";
	}
	cout << el;
	delete[]pint;
	delete[]plint;
	CString ss = _T("123456");

}

template <typename T = int, int N = 1>
T returnt()
{
	T ib = 2.2;
	for (size_t i = 0; i < N; i++)
	{
		ib = i + ib + 1;
	}
	return 100.22 * ib;
};

void CSDIView::OnSTLArgTest()
{
	//return y += val * x;
	SimulationStdCout;
	int x = 3;
	cout << returnt<int, 3>() << tab << sizeof(returnt<int, 3>()) << el;
	cout << returnt<long long int, 5>() << tab << sizeof(returnt<long long, 5>()) << el;
	cout << returnt<float, 3>() << tab << sizeof(returnt<float, 3>()) << el;

	vector<int>intvect;
	for (size_t i = 0; i < 20;)
	{
		intvect.push_back(++i * 3);
	}
	cout << intvect << el;

	list<int>ilt;
	for (size_t i = 0; i < 15; i++)
	{
		ilt.push_back(i + 10);
	}
	for (list<int>::iterator it = ilt.begin(); it != ilt.end(); ++it)
	{
		*it *= 2;
	}
	list<int> l2(ilt);
	for (list<int>::iterator it = ilt.begin(); it != ilt.end(); ++it)
	{
		*it *= 2;
	}
	cout << ilt << el;
	cout << l2 << el;
	multimap<CString, string>mmap;
	mmap.insert(pair<CString, string>(CString(st(imap first)), string("is first")));
	mmap.insert(make_pair(CString(st(imap second)), string("is second")));
	mmap.insert(multimap<CString, string>::value_type(CString(st(imap second)), string("is second")));
	cout << mmap << el;

	CString wstring = _T("good");
	pair<CString, int> w = make_pair(wstring, 100);
	pair<int, float>ifx = make_pair(10, 2.3);
	map<CString, int> cfmap;
	cfmap.insert(w);
	cfmap.insert(make_pair(CString(wstring += wstring), 200));
	cfmap.insert(pair<CString, int>(CString(wstring = st(go)), 300));
	cfmap.insert(map<CString, int>::value_type(CString(st(bad)), 400));
	multiset<int> iset1;
	int mod = 30;
	for (size_t i = 0; i < 30; i++)
	{
		iset1.insert(i * rand() % mod);
	}
	cout << cfmap << el;
	cout << iset1 << el;

}

void CSDIView::OnCxx20StlConceptTest()
{
	PCDC cout(this);

	//原始字符串字面量测试
	cout << R"h(hello\thello\thello)h" << el;

	vector<int>intvec(20);
	deque<int>intvec2(10);
	MakeEleRandom(intvec, 20);
	cout << intvec;
	MakeEleRandom(intvec2, 10);
	cout << intvec2;
	std::copy_if(intvec.begin(), intvec.end(), std::front_inserter(intvec2), [](int v) {return v < 10; });
	cout << intvec2 << el;
	std::copy_if(intvec.begin(), intvec.end(), std::back_inserter(intvec2), [](int v) {return v > 15; });
	cout << intvec2 << el;

}

int igi = 88;
typedef int (*PFU)(int);
using PTRFUN = int (*)(int);

void CSDIView::OnLamdbaFuncTest()
{
	// TODO 测试lamdba表达式
	SimulationStdCout
		auto funl = [](int val1, int val2)mutable ->bool {
		return val1 > val2;
	};
	int x = 1, y = 2;
	cout << x << el;
	function<bool(int, int)> p = funl;
	cout << p(100, 200);
	cout << el;
	showtype(p);
	showtype(funl);
	showtype(PTRFUN);
	auto funl1 = [&](int val)mutable ->int {
		int z = 210;
		showtype(z);
		return igi + val;
	};
	function<int(int)> p1 = funl1;
	showtype(funl1);
	showtype(p1);
	cout << cut;

	vector<int> iset1;
	int mod = 30;
	for (size_t i = 0; i < 30; i++)
	{
		iset1.insert(iset1.end(), i * rand() % mod);
	}
	cout << iset1 << el << cut;
	sort(iset1.begin(), iset1.end(), std::function<bool(int, int)>([](int a, int b) ->bool { return a < b; }));
	cout << iset1 << el << cut;
	sort(iset1.begin(), iset1.end(), funl);
	cout << iset1;
}

void CSDIView::OnStlTupleTest()
{
	SimulationStdCout;
	cout.clearscreen();
	lscode(

		using namespace std;
	auto tuplea = tuple<int, float, string, string, string>(10, 10.24, "good", "bad", "normal");
	auto tupleb = tuple<int, float, string, string, string>(22, 20.24, "good-b", "bad-b", "normal-b");
	cout << std::get<int>(tuplea) << tab;
	cout << std::get<1>(tuplea) << tab;
	cout << std::get<2>(tuplea) << tab;
	cout << std::get<3>(tuplea) << tab;
	cout << std::get<4>(tuplea) << el;
	std::get<4>(tuplea) = "change";
	cout << std::get<4>(tuplea) << tab;
	cout << cut;
	cout << std::get<0>(tupleb) << tab;
	cout << std::get<1>(tupleb) << tab;
	cout << std::get<2>(tupleb) << tab;
	cout << std::get<3>(tupleb) << tab;
	cout << std::get<4>(tupleb) << tab;

	swap(tuplea, tupleb);
	cout << std::get<0>(tupleb) << tab;
	cout << std::get<1>(tupleb) << tab;
	cout << std::get<2>(tupleb) << tab;
	cout << std::get<3>(tupleb) << tab;
	cout << std::get<4>(tupleb) << tab;

	typedef std::tuple<int, double, int, double> Mytuple;
	Mytuple c0(0, 1, 2, 3);

	// display contents " 0 1 2 3"
	cout << " " << std::get<0>(c0);
	cout << " " << std::get<1>(c0);
	cout << " " << std::get<2>(c0);
	cout << " " << std::get<3>(c0);
	cout << el;

	int v4 = 4;
	double v5 = 5;
	int v6 = 6;
	double v7 = 7;
	std::tie(v4, v5, v6, v7) = c0;

	// display contents " 0 1 2 3"
	cout << " " << v4;
	cout << " " << v5;
	cout << " " << v6;
	cout << " " << v7;
	cout << el;
	v7 = 10;
	cout << " " << std::get<3>(c0);
	cout << el;
	std::get<0>(c0) = 8;
	v4 = 9;
	cout << " " << std::get<0>(c0);
	cout << " " << v4;
	)

}

int f(int a, int b)
{
	return a + b;
}

template<class T>
struct typestruct {
	typedef map<int, T> mytype;
};

void CSDIView::OnStlTypeTest()
{
	SimulationStdCout;
	lcode(
		CString s;
	string s2;
	LONG x;
	bool bcomp = std::is_same_v<decltype(x), LONG>;
	cout << bcomp << el;
	bcomp = std::is_same_v<decltype(s), decltype(s2)>;
	cout << bcomp << el;
	cout << typeid(decay<decltype(x)>::type).name() << el;
	cout << &cout << tab << typeid(cout).name() << tab << typeid(&cout).name() << el;
	cout << (int*) nullptr << tab << sizeof(nullptr) << tab << typeid(nullptr).name() << el;
	cout << (int*)NULL << tab << sizeof(NULL) << tab << typeid(NULL).name() << el;
	cout << (int*)NULL << tab << sizeof(void*) << tab << typeid(int*).name() << el;
	);
	lscode(
		cout << &cout << tab << &cout << el;
	showtype(cout);
	showtype(cout);
	cout << address(cout) << el;
	cout << address(std::cout) << el;
	cout << this << tab << &s << tab << &s2 << tab << &x << el;
	showtype(std::cout);
	showtype(this);
	showtype(*this);
	);
	lcode(
		LONG y;
	if (typeid(x).name() == typeid(y).name())
		cout << typeid(x).name() << el;
	);
	lcode(
		vector<int>va;
	va.push_back(1);
	va.push_back(2);
	gett(va)::iterator it = va.begin();
	cout << *it << el;
	getI(va) iit = va.begin();
	cout << *iit << el;
	cout << cut;
	FORALL(va, itx)
		cout << *itx << tab;
	for (auto i : va)
		cout << i << tab;
	FORN(va.size(), i)
		cout << va.at(i) << tab;
	FORV(i, va)
		cout << i << tab; cout << el;
	showtype(va);
	);
	lcode(
		typedef int fun(int, int);
	typedef int (*pfun)(int, int);
	typedef fun* func;
	func p = f;
	cout << p(10, 20) << cut;
	fun * pf = f;
	cout << pf(20, 30) << cut;
	pfun ppf;
	fun w;
	ppf = f;
	cout << ppf(100, 200) << cut;
	showtype(p);
	showtype(pf);
	showtype(ppf);
	);


}

void CSDIView::OnInitalListTest()
{
	SimulationStdCout;
	lscode(
		NTIME(4) {
		cout << ix << tab << "good" << tab;
		cout << ix << tab << "bad" << tab;
	}
	cout << el;
	cout << "Hello world!" << el;
	showtype("Hello world!");
	);
	lscode(
		vector<int>va;
	NTIME(4)
		va.push_back(ix);
	int iy = 0;
	for (auto i : (cout << ++iy << tab << "ok" << tab, va))
		cout << "run" << tab << el;
	);

}

class ptr
{
public:
	CString createname = _T("noname");
	PCDC* pdc = nullptr;
	int mid = 0;
	static int iall;
	static int icreate;
public:
	ptr() {
		static int i = 0;
		++i;
		iall = i;
	}
	ptr(PCDC& dc, CString s) : createname(s)
	{
		icreate++;
		dc << createname << " is create,iall is" << tab << iall << tab << "icreate is " << tab << icreate << el;
		pdc = &dc;
	}
	bool set(PCDC& dc, int id, CString s = CString("noname"))
	{
		mid = id;
		pdc = &dc;
		createname = s;
		return true;
	}
	~ptr()
	{
		--iall;
		if (pdc)
			*pdc << createname << " is decreate,iall is" << tab << iall << tab << "icreate is " << tab << icreate << el;
	}
};

int ptr::iall = 0;
int ptr::icreate = 0;

void CSDIView::OnPtrUniqueTest()
{
	SimulationStdCout;
	lscode(
		unique_ptr<ptr[]>three = make_unique<ptr[]>(10);
	CString s;
	CString name = _T("array unique_ptr#");
	CString finalname;
	for (int i = 0; i < 5; ++i) {
		s.Format(_T("%ld"), i);
		finalname = name + s;
		three[i].set(cout, i, finalname);
	}
	lscode(cout << three[0].createname << el;);
	showtype(cout);
	);
	int* pa = new int{ 99 };
	unique_ptr<int>unaptr(pa);
	cout << *unaptr << tab << unaptr << tab << address(unaptr) << tab << pa << tab; cout.type(unaptr);

}

void CSDIView::OnLvalRvalTest()
{
	// TODO: lVAL RVAL
	SimulationStdCout;
	lscode(
		int&& o = 4; cout << o << tab;
	const int&& g = 4;
	const int c = 5;
	o = 8;
	cout << o << el;
	showtype(o);
	showtype(int&&);
	);
	lscode(
		vector<int>va = { 1,3,5,5,9,10 };
	for (auto i : va)
		cout << i << tab;
	cout << el;
	);
	lscode(
		map<int, float>mapa = { {2,3.2},{3,4.2},{5,6.7},{7,8.8} };
	for (auto i : mapa)
		cout << i.first << " , " << i.second << tab;
	cout << el;
	);

}

void fun(PCDC& out, int& a)
{
	out << "int a" << tab << a << el;
}

void fun(PCDC& out, const int& a)
{
	out << "const int a" << tab << a << el;
}

void fun(PCDC& out, int&& a)
{
	out << "int &&a " << tab << a << el;
}

void fun(PCDC& out, const int&& a)
{
	out << "const int &&a " << tab << a << el;
}

void fun(PCDC& out, int* a)
{
	out << "int* a " << tab << a << el;
}

template<typename T>
void funt(PCDC& out, T&& a)
{
	out << typeid(std::forward<T>(a)).name() << tab << a << tab << typeid(T&&).name() << el;
}

template <typename T>
void callf(PCDC& out, T v)
{
	fun(out, v);
	fun(out, (T&&)(v));
	fun(out, std::forward<T>(v));
}

template<typename T, typename E, typename int ic = 1000 * 1000>
auto cinsert(T t, E e)
{
	NTIME(ic)
		t.insert(t.end(), e);
	return e;
}

template<template <class> class C, typename t >
auto con(C<t> v)
{
	t a = *v.begin();
	return *v.begin();
}

namespace type {
	typedef int INT;
	typedef double DOUB;
	using CHPtr = char*;
}

struct sType {
	typedef int INT;
	typedef double DOUB;
#define LNT  INT
	using CHPtr = char*;
};

void CSDIView::OnStlStdForwardTest()
{
	SimulationStdCout;
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
	callf(cout, i);
	callf(cout, ci);
	callf(cout, r);
	callf(cout, rr);
	callf(cout, irc);
	callf(cout, irr);
	callf(cout, 7);
	callf(cout, i + 7);
	);
	cout << cl;
	using namespace type;
	showtype(type::INT);
	showtype(type::DOUB);
	showtype(type::CHPtr);
	showtype(sType::CHPtr);
	showtype(sType::LNT);
	showtype(LNT);
	lscode(
		cout << imax(3, 8, 9, 10, 22, 12, i, ia, ci, irr, irc) << el;
	cout << gmax(3.4, 898.8, 0.9, 10, 200.22, 12.0) << el;
	cout << lex<int>() << el;
	cout << lex<float>() << el;
	cout << lex() << el;
	);
	vector<int> va = { 10000,9,9,8,2000 };
	decltype(va)::value_type ixa = *va.begin();

}

void CSDIView::OnPaintDcTest()
{
	//开始绘图
	SimulationStdCout;
	//CRect rect(800, 800,1000,1000);
	cout << cl;/*cout.Rectangle(&rect);*/
	lscode(
		cout << cout.m_cdc << tab << cout.m_hDC << tab
		<< cout.m_hAttribDC << tab << cout.m_bPrinting << el;
	cout << "good" << tab << cout.ms.IsEmpty() << tab << cout.ms << el;
	);
	lscode(
		CFile ofile(_T("D:/VS2022/MFC/SDI/SDI/test.txt"), CFile::modeCreate | CFile::modeReadWrite);
	string str = "This is a text.txt test string\n";
	ofile.Write(str.c_str(), str.length());
	ofile.Write(str.c_str(), str.length());
	ofile.Write(str.c_str(), str.length());
	ofile.SeekToBegin();
	);
	lscode(
		char strr[256]{};
	size_t len = ofile.Read(strr, 256);
	cout << ofile.m_hFile << tab << ofile.GetFileName() << tab << ofile.GetFilePath() << tab
		<< ofile.GetFileTitle() << tab << ofile.GetLength() << tab << ofile.GetPosition()
		<< el;
	string strt(strr);
	cout << strt << el;
	);
	cout.type(cout);
	cout.address(cout) << el;
	cout << showv(ofile.GetFileName()) << el;
	cout << showv(ofile.GetFilePath()) << el;
	cout << showv(ofile.GetLength()) << el;
	cout << showv(ofile.GetFileTitle()) << el;
	cout << showv(ofile.GetPosition()) << el;



}

void CSDIView::OnPCDCFunctionTest()
{
	SimulationStdCout;

	static size_t imod = 0;

	cout << cl;
	char ca = 'a';
	int ia = 10;
	float fa = 31.1;
	bool iba = true;
	long la = 500000;
	long long lla = 256 * 256 * 25650;
	double da = 62.444;
	long double lda = 262.844;
	size_t icount = 50;
	int* ip = &ia;
	char* cp = &ca;
	long* lp = &la;
	long long* llp = &lla;
	double* dp = &da;
	const char* chp = "const char []";
	const char chpa[] = "char []";
	CAtlString catlstr = st(Smilate termial console mfc DC test, CAtlString...);
	CString cstr = st(Smilate termial console mfc DC test, CString...);
	std::string cs = "This is a string...   ";
	std::wstring wcs = L"This is a Wstring...   ";
	int iitem = 5;
	int& ria = ia;
	int&& rra = 10;
	array<int, 10>arrone = { 88,77,66,44,33,22,11,01,99,43 };
	int i = 500;
	auto tuplea = tuple<int, float, string, string, string>(10, 10.24, "good", "bad", "normal");

	initializer_list<int> v = { 3,4,5,6 };
	vector<int>vecta{ 3, 4, 5, 6,1 };
	vector<int>va = { 12,234,56,78,892,8,235,86 };
	map<int, float>mif = { {2,4.3},{234,8.90},{56,1024.788},{23,839.8192},{28,8.999} };
	int length = tuple_size<decltype(tuplea)>::value;


	cout << cut;
	cout%tuplea;
	cout<<cut;
	goto end;

	if (imod % iitem == 0)
	{
		lscode(
			cout.type(ia);
		cout.type(ria);
		cout.type(rra);
		cout.type((std::move(ia)));
		cout.type((std::move(ria)));
		cout.type((std::move(rra)));
		cout << showv(tuplea) << showv(length) << el;
		cout.type(tuplea);
		cout << cut;
		cout[tuplea];
		//cout <<length<<tab<<tuplea << el;
		);
	}

	if (imod % iitem == 4)
	{
		argsvalue(1, 2, 3, 4, 5);
		lscode(
			{
			cout << chp << tab; showtype(chp);
			cout << chpa << tab;  showtype(chpa);
			cout << catlstr << tab; showtype(catlstr);
			cout << cstr << tab; showtype(cstr);
			cout << cs << tab; showtype(cs);
			cout << wcs << tab; showtype(wcs);
			}
		);
	}

	if (imod % iitem == 1)
	{

		{
			cout << "beging test dc..." << tab << st(print value) << el;
			cout << icount << tab << ca << tab << ia << tab << fa << tab << iba << tab << la << tab << lla << tab << da << el << cut;
		}

		lscode(
			{
			cout << ip << tab << *cp << tab << lp << tab << llp << tab << dp << el << cut;
			}
		);

	}
	if (imod % iitem == 2)
	{
		lcode(
			{
			cout << va << el << mif << el;
			}
		);
	};

	if (imod % iitem == 3)
	{
		cout << cl;
		cout << arrone << el;
		cout.pl(icount, ca, ia, fa, iba, la, lla, da, cs, wcs);
		cout.pb(icount, ca, ia, fa, iba, la, lla, da, cstr);
		cout.pc(icount, ca, ia, fa, iba, la, lla, da, cstr);
		cout.pt(icount, ca, ia, fa, iba, la, lla, da);
		cout.address(icount, ca, ia, fa, iba, la, lla, da);
		cout.pt(va, mif) << cut;
		cout.pb(va, mif) << cut;
		cout.pc(va, mif) << cut;
		cout.type(cout, ca, ia);
		lscode(
			cout << cut;
		cout.args();
		cout << cut;
		cout.args(1);
		cout << cut;
		cout.args(1, 2);
		cout << cut;
		cout.args(1, 2, 3);
		cout.pl(3, i, ia, 6.0, "good");
		cout.pt(3, i, ia, 6.0, "good");
		cout.pb(3, i, ia, 6.0, "good");
		cout.pc(3, i, ia, 6.0, "good");
		cout << sum({ 3, 4, 5, 6 }) << el;
		cout << set<int>{ 3, 4, 5, 6, 2} << el;
		cout << (initializer_list<int>{ 2, 3, 4, 5, 6, 7, 9 });
		cout << vecta << el;
		cout << " " << tuple_size<decltype(tuplea)>::value << el;
		cout << " " << typeid(decltype(tuplea)).name() << el;
		);
	}

end:
	++imod;
	if (imod == 4)
		imod = 0;
}






