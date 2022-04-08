// SDIView.cpp: CSDIView 类的实现
//
#include "framework.h"
#include "pch.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SDI.h"
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
#define lscode(...)  lcode(__VA_ARGS__);

#define sst(code,...)  #code##","#__VA_ARGS__
#define SHOW(name) cout<<st(name)<<_T(" is:  ")<<name<<tab;
#define showtype(type)  cout<<"TYPE: "<<#type<<tab<<"NAME:  "<<typeid(type).name()<<tab <<"SIZE:  "<<sizeof(type)<<el;

#define RUNTEST(message)		cout.clearscreen();\
								cout.titleline(wstring(st(message)));

#define TITLE(message)      cout.clearscreen();\
							cout.titleline(wstring(st(message)));


template <typename T>
bool showinfo(PCDC* the, const T& c)
{
	PCDC& screen = *the;
	screen << "sizeof is:" << tab << sizeof(c) << tab << "typename is :" << tab << typeid(c).name() << el;
	return true;
};

using namespace std;

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

	//返回POINT结构
	return position;
}

void CSDIView::OnPaint() {

	cout.Release();
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
	cout.Create(this);
}

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

	RUNTEST(TEST STRING);
	char charmark = '*';
	int nchartime = 140;
	CAtlString strsplint(charmark, nchartime);
	screen << strsplint << el;

	wstring wstr1(_T("wstring is ok"));
	string astr1 = "astr1,string class";
	CAtlString strFormat(wstr1.c_str());
	screen << astr1 << el;
	screen << wstr1 << el;
	screen << strFormat << el;

	wstr1 = _T("this is a wstring test string");
	strFormat = wstr1.c_str();
	screen << wstr1 << el;
	screen << strFormat << el;
	strFormat = astr1.c_str();
	screen << strFormat << el;

	wstr1 = _T("this is a wstring test string");
	screen << wstr1 << el;

	// 定义备用变量
	CAtlString EnvStr, tok;
	CAtlString midle, temp, liststr, dome, grep, name, dock;
	CAtlString message, formatv, tail, head, result, str;
	unsigned long int ii = 0, ij = 0, itt = 0, icount = 0, imark = 0, itail = 0, imid = 0;

	//测试CAtlString Appendformat 功能
	formatv = (_T("first "));
	screen << formatv << el;
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
	screen << message << el;
	vecotr_paintmessage.push_back(message);

	tail = "is ok";
	head = "Is oK";
	ii = tail.CollateNoCase(head);
	message.Format(_T("#%ld"), ++icount);
	message = tail;
	message += "<CollateNoCase> ?qual ";
	message += head;
	message.AppendFormat(_T(" return value = %ld"), ii);
	screen << message << el;
	vecotr_paintmessage.push_back(message);

	tail = _T("123456789");
	ii = 5; ij = 3;
	message = tail;
	tail.Delete(ii, ij);
	message.AppendFormat(_T("从 %ld 开始删除 %ld 个字符 = "), ii, ij);
	message += tail;
	screen << message << el;
	vecotr_paintmessage.push_back(message);

	str.Format(_T("Floating point: %.2f\n"), 12345.12345);
	_tprintf_s(_T("%s"), (LPCTSTR)str);
	message = str;
	screen << message << el;
	vecotr_paintmessage.push_back(message);

	str.Format(_T("Left-justified integer: %.6d\n"), 35);
	_tprintf_s(_T("%s"), (LPCTSTR)str);
	message = str;
	screen << message << el;
	vecotr_paintmessage.push_back(message);

}

void CSDIView::OnPrintEnvVAR()
{
	// 打印环境变量
	CAtlString EnvStr, tok;
	EnvStr.GetEnvironmentVariable(_T("PATH"));
	int ipos = 0;
	tok = EnvStr.Tokenize(_T(";"), ipos);

	while (!isempty(tok)) {
		vecotr_paintmessage.push_back(tok);
		tok = EnvStr.Tokenize(_T(";"), ipos);
	};
	for (const auto& i : vecotr_paintmessage)
		screen << i << el;
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
	}

	if (ichoice == 2)
	{
		cout << cl;
		showtype(byte);
		showtype(BYTE);
		showtype(char);
		showtype(int);
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
		showtype(uintptr_t);
		showtype(intptr_t);
		showtype(shared_ptr<int>);
		showtype(unique_ptr<int>);
		showtype(nullptr);
		showtype(LPARAM);
		showtype(WPARAM);
		showtype(string);
		showtype(CAtlString);
		showtype(CString);
		showtype(set<int>);
		showtype(vector<int>);
		showtype(DWORD);
		showtype(WORD);
		showtype(int&);
		showtype(dccr.berry);
		showtype('a');
		showtype(0);
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
	//设置字体颜色，准备DC
	PCDC dc(this);

	vector<CAtlString> v;
	CAtlString csmessage;

	static CHAR CHAR64BIT[256] = { 0 };
	LONGLONG long64bit = 256 * 256 * 256 * 256 - 1;
	Long64ToChar(long64bit, CHAR64BIT);
	v.push_back(CAtlString(CHAR64BIT));
	dc << CAtlString(CHAR64BIT) << el;

	bitset<64> bit64a = 256;
	string sbitstr;

	sbitstr = bit64a.template to_string<char, char_traits<char>, allocator<char> >();

	CAtlString catstrbit32(sbitstr.c_str());
	v.push_back(CAtlString(catstrbit32));
	dc << catstrbit32 << el;

	bit64a = 256 * 256 * 256 * 256 * 256 * 256 * 256 * 256 - 1;
	sbitstr = bit64a.template to_string<char, char_traits<char>, allocator<char> >();
	v.push_back(CAtlString(sbitstr.c_str()));
	dc << CAtlString(sbitstr.c_str()) << el;

	dc.titleline(wstring(st(start test except catch try and throw...)));
	dc << typeid(catstrbit32).name() << el;

	for (auto& i : v) {
		position.y += step;
		dc << i << el;
		//COUTCS((dc), i);
	}

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
	theApp.m_pMainWnd->SetWindowTextW(strwindowstitle);

	CView::OnLButtonDblClk(nFlags, point);
}


void CSDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAtlString strwindowstitle;
	strwindowstitle.Format(_T("Current print position is x:%ld,y:%ld ,current cursor positon is x:%ld,y:%ld . TIP:Double click mouse left can reset the positon."), position.x, position.y, point.x, point.y);
	theApp.m_pMainWnd->SetWindowTextW(strwindowstitle);

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
			dc.TextOutW(x, y += step, strFormat);
		}
		x += lstep;
		y = 50;
	}
	x = lstep;
	y = 50 + linenumber * step;
	{
		intvec.swap(empty);
		strFormat.Format(_T("%ld"), intvec.size());
		dc.TextOutW(x, y += step, strFormat);
		vector<float>xvect;
		intvec.swap(xvect);
		strFormat.Format(_T("%ld"), intvec.size());
		dc.TextOutW(x, y += step, strFormat);
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

	PRINTSCREEN(20, 20, is  good);
	PRINTN(x, y += step, a);
	PRINTN(x, y += step, add(a, b));
	PRINTN(x, y += step, sub(a, b));
	PRINTN(x, y += step, mul(a, b));
	PRINTN(x, y += step, divv(a, b));

	//测试函数指针
	CAtlString strFormat;
	pt<int>;
	int(*func)(int a, int b);
	float (*fund)(float a, float b);
	func = add<int>;
	strFormat.Format(_T("%ld"), func(a, b));
	dc.TextOutW(x, y += step, strFormat);
	fund = add;
	strFormat.Format(_T("*func=add %ld"), func(a, b));
	dc.TextOutW(x, y += step, strFormat);
	//出现异常
	/*func = pt<int>;
	strFormat.Format(_T("(*func) add<int>%ld"), func(a, b));
	dc.TextOutW(x, y += step, strFormat);*/
	func = add;
	strFormat.Format(_T("(*func) add<int>%ld"), func(a, b));
	dc.TextOutW(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOutW(x, y += step, strFormat);
	strFormat.Format(_T("%ld"), func(a, b));
	dc.TextOutW(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOutW(x, y += step, strFormat);

	strFormat.Format(_T("%lf"), divv(fa, fb));
	dc.TextOutW(x, y += step, strFormat);
	strFormat.Format(_T("%lf"), fund(fa, fb));
	dc.TextOutW(x, y += step, strFormat);

	//恢复用户字体DC
	RestoreDCFont(dc);
}


void CSDIView::OnGetWindowsRect()
{
	//设置字体颜色，准备DC
	RECT rect;
	this->GetWindowRect(&rect);
	CString strto;
	PCDC dcout(this);
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
	theApp.m_pMainWnd->SetWindowTextW(strwindowstitle);

}



bool  CSDIView::spline(CDC& dc, string tips, int line, char c, int ntime)
{
	int x = 50;
	int y = (line == -1) ? position.y : line;
	int linestep = 30;
	int lstep = 120;
	char charmark = c;
	size_t nchartime = ntime;
	CAtlString strsplint(charmark, nchartime);
	CAtlString strtips = _T("**");
	strtips += tips.c_str();
	strtips += _T("****");
	dc.TextOutW(x, y += linestep, strsplint);
	if (tips != "0") {
		dc.TextOutW(x, y += linestep, strtips);
		dc.TextOutW(x, y += linestep, strsplint);
	}
	position.y = y;


	return true;

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
	pdc->TextOutW(position.x, position.y, str);
	position.y += step;

	//恢复用户字体DC
	if (dcreset)
		RestoreDCFont(*pdc);
	return dcreset;
}

void CSDIView::OnSTLFuncTest()
{
	//FCDC dcout(this);
	PCDC dcout(this);
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
	if (ia == 4) { char* e = "is error"; throw e; }
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
	PCDC screen(this);
	try {
		screen << "before runexcept" << el;
		//runexcept(1);
		//被跳过
		screen << "under runexcept" << el;
	}
	catch (char* e)
	{
		screen << typeid(e).name() << el;
	}
	catch (float e) {
		screen << e << el;
	}
	catch (double e) {
		screen << e << el;
	}
	catch (int e) {
		screen << e << el;
	}
	catch (char e) {
		screen << e << el;
	}
	catch (const CString& e) {
		screen << e << el;
	}
	catch (...) { screen << "catch all error" << el; };

}


void CSDIView::OnPCDCFunctionTest()
{
	PCDC screen(this);
	int ia = 10, ib = 20;
	float	fa = 31.1, fb = 41.0;
	bool iba = true;
	long la = 50;
	double da = 62.444;
	int* p = &ia;
	CAtlString strout = st(This is smilate termial console for mfc DC test...);
	std::string s = "this is a string..\t\t";
	size_t icount = 50;
	screen << strout << el;
	screen << iba << tab << la << tab << da << tab << p << tab << fa << el;
	screen << s << ia << el;
	screen << theApp.messagelog.size() << el;
	screen << st(ok this is a test for strmacroand screen dc) << el;
	screen << starline;
	const char* ps = "this is ok";

	screen << "is ok" << el;
	screen << ps << el;

	//循环输出程序运行顺序记录
	for (auto& i : theApp.messagelog) {
		screen << i << el;
	}
	for (size_t i = 0; i < 5; )
	{
		screen << ++i << "#" << el;
		for (size_t i = 0; i < 10;)
		{
			screen << ++i * 10 << tab;
		}
		screen << __func__ << __LINE__ << el;
	}

}


void CSDIView::OnSTLlStringTest()
{
	RUNTEST(STRING TEST);
	string s1 = "ok", s2 = "bad", s3 = "+";
	s1.append(s3);
	s1.append(s2);
	s1.append(s3);
	s1.append("good");
	s1.append(s3);
	s1.append(s2);

	screen << s1 << el;
	screen << s1.find(s2) << el;
	screen << s1.find("good") << el;
	screen << s1.rfind(s2) << el;

	screen << s1 << el;
	s1.replace(0, 0, "byeeeee");
	screen << s1 << el;
	screen << s1.substr(7, 4) << el;
	s1.insert(1, "ddd");
	screen << s1 << el;
	s1.erase();
	screen << "erase after " << s1 << el;

}

void CSDIView::OnGroundTest()
{
	RUNTEST(VECTOR TEST);
	vector<int>intvect;
	for (size_t i = 0; i < 20;)
	{
		intvect.push_back(++i * 3);
	}

	for (auto& i : intvect)
		screen << i << tab;
	screen << el;
	screen << "The vector size is " << intvect.size() << el;

	intvect.pop_back();
	intvect.pop_back();

	screen << st(The vector size is afthe pop two element is : ) << intvect.size() << el;

	for (auto& i : intvect)
		screen << i << tab;
	screen << el;
	screen << intvect.back() << tab << intvect.back() << tab << "size is: " << intvect.size() << tab << "max size is:" << intvect.max_size() << el;

	intvect.insert(intvect.begin() + 5, 10);
	intvect.insert(intvect.begin() + 6, 20);
	intvect.insert(intvect.begin() + 7, 30);

	for (auto& i : intvect)
		screen << i << tab;
	screen << el;
	vector<int> intvect2(intvect.begin(), intvect.begin() + 5);
	screen << intvect2;
	screen << starline;
	screen << intvect;
	intvect.resize(intvect.size() / 2);
	screen << starline;
	screen << intvect;
	screen << intvect2;
	intvect.swap(intvect2);
	screen << st(swap v1 & v2) << el;

	screen << starline;
	screen << intvect;
	screen << intvect2;
	screen << intvect.empty() << el;

	screen << starline;
	intvect2.resize(15, 5);
	screen << intvect2;
	for (size_t i = 0; i < 1024; i++)
	{
		intvect2.push_back((2 + i));
	}
	screen << starline;
	intvect2.resize(15);
	SHOW(intvect2.size());
	SHOW(intvect2.capacity());
	intvect2.shrink_to_fit();
	screen << intvect2;
	SHOW(intvect2.back());
	SHOW(intvect2.front());
	intvect2.insert(intvect2.begin(), 999);
	intvect2.insert(intvect2.end(), 999);
	screen << intvect2;
	screen << starline;
	SHOW(intvect2.size());
	SHOW(intvect2.capacity());
	intvect2.resize(20);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	intvect2.reserve(100);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	screen << starline;
	intvect2.reserve(20);
	SHOW(intvect2.capacity());
	SHOW(intvect2.size());
	vector<int>::iterator it = intvect2.begin();
	SHOW(*it);
	int x;
	screen << addressof(*it) << el;
	screen << &*it << el;
	screen << sizeof(int*) << tab << sizeof(int) << tab << sizeof(long long) << el;
	screen << address(x) << el;


	TITLE(PRINT  deque TEST);
	deque<int>d1;
	for (size_t i = 0; i < 20; i++)
	{
		d1.push_back(i * 2);
	}
	for (auto& i : d1)
		screen << i << tab;
	screen << el;
	d1.pop_front();
	screen << starline;
	d1.push_front(1000);
	for (int j = 0; j < 8; j++) {
		screen << j << "#" << tab;
		for (auto& i : d1) {
			screen << (i = i + j) << tab;
		}
		screen << el;
	}
	CRect rect = { 0,0,0,0 };
	//this->InvalidateRect(&rect);
	screen << starline;
	for (auto& i : d1)
		screen << i << tab;
	screen << el;
	d1.pop_back();
	d1.pop_front();
	for (size_t i = 0; i < 5; i++)
	{
		d1.pop_front();
	}
	d1.emplace_back(888);
	screen << d1.size() << el;
	SHOW(d1.size());
	SHOW(d1.max_size());
	SHOW(d1.empty());
	SHOW(d1.at(5));
	screen << el;
	screen.setlinechar('-');
	screen << starline;
	for (auto& i : d1)
		screen << i << tab;
	screen << el;
	d1.insert(d1.begin(), 222);
	screen << *d1.begin() << el;
	this->GetWindowRect(&rect);

	screen << rect.bottom << tab << rect.top << tab << rect.right << tab << rect.left << el;


}


void CSDIView::OnStlStackEqueueTest()
{
	RUNTEST(STACK EQUEUE TEST);
	screen.setcolor(dccr.darkslateblue, dccr.darkgreen, screen.m_bk, screen.m_tk);
	screen << cl;
	stack<int>ist;
	for (size_t i = 0; i < 20; i++)
	{
		ist.push(i + 10);
	}
	screen << ist.top() << el;
	screen << ist.size() << tab << ist.top() << tab << (ist.pop(), ist.top()) << el;
	screen << starline;
	screen << ist.size() << tab << ist.top() << el;
	screen << ist.top() << tab << ist.size() << tab << (ist.pop(), ist.top()) << tab << ist.size() << tab << ist.top() << el;
	screen << ist.size() << tab << ist.top() << el;
	screen << ist.empty();

	queue <int> ieq;
	for (size_t i = 0; i < 10; i++)
	{
		ieq.push(i + 2);
	}
	screen.setlinechar('#');
	screen << starline;
	screen << ieq.front() << el;
	screen << ieq.back() << el;
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
	RUNTEST(LIST TEST);
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
	screen << ssss << el;
	for (size_t l = 0; l < ssss.GetLength(); l++)
	{
		if (l % 2 == 1)
			ssss.Insert(l, '3');
	}
	screen << ssss << el;
	for (size_t l = 0; l < ssss.GetLength(); l++)
	{
		if (l % 3 == 2)
			ssss.Insert(l, '4');
	}
	screen << ssss << el;
	list<int> l2(ilt);
	screen.setlinechar('-');
	for (list<int>::iterator it = ilt.begin(); it != ilt.end(); ++it)
	{
		*it *= 2;
		screen << *it << tab;
	}
	screen << el;
	screen.setlinechar('-');
	for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it)
	{
		*it *= 2;
		screen << *it << tab;
	}
	screen << el;
	screen.clearscreen();
	lcode(ilt.erase(ilt.begin()); PrintEle(ilt, screen));
	lcode(ilt.pop_back(); PrintEle(ilt, screen));
	lcode(ilt.pop_front(); PrintEle(ilt, screen));
	lcode(ilt.insert(ilt.begin(), 666); PrintEle(ilt, screen));
	lcode(ilt.insert(ilt.begin(), 666); ilt.insert(ilt.begin(), 666); PrintEle(ilt, screen));
	lcode(ilt.remove(*ilt.begin()); PrintEle(ilt, screen));
	lcode(ilt.reverse(); PrintEle(ilt, screen));
	lcode(PrintEle(l2, screen); l2.reverse(); PrintEle(l2, screen));
	lcode(ilt.swap(l2); PrintEle(ilt, screen); PrintEle(l2, screen));
	lcode(ilt.sort(); ilt.reverse(); PrintEle(ilt, screen););

	screen << __FUNCTION__ << tab << __FUNCDNAME__ << tab << __FUNCSIG__ << el;
	screen << __DATE__ << __TIME__ << tab << __FILE__ << tab << __LINE__ << tab << __STDC_HOSTED__ << el;

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
	RUNTEST(BEGING TEST SET AND MULTISET);
	set<int> iset1;
	int mod = 30;
	for (size_t i = 0; i < 30; i++)
	{
		iset1.insert(i * rand() % mod);
	}

	lcode(PrintEle(iset1, screen););
	lcode(iset1.insert(25); PrintEle(iset1, screen););
	lcode(screen << iset1.size() << tab << iset1.count(15) << tab << iset1.max_size() << el; PrintEle(iset1, screen););

	lcode(screen << *iset1.begin() << tab << *iset1.end() << tab << iset1.empty() << tab << iset1.erase(5) << el; PrintEle(iset1, screen););
	auto it = iset1.find(8);
	if (it == iset1.end())
		screen << "is end" << el;
	lcode(iset1.insert(100););
	lcode(iset1.insert(200););
	lcode(iset1.insert(300););
	lcode(screen << "find" << tab << *iset1.upper_bound(20) << el; PrintEle(iset1, screen););
	lcode(screen << "find" << tab << *iset1.lower_bound(10) << el; PrintEle(iset1, screen););

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
	screen << cl;
	icompset a;
	screen << a(st(good), &screen) << tab << el;
	screen << a(100) << tab << el;

	list<int>ilt;
	for (size_t i = 0; i < 15; i++)
	{
		ilt.push_back((rand() * i * rand()) % 100);
	}
	lcode(PrintEle(ilt, screen));

	vector<int>intvec(20), empty;
	int i = 0;
	int icount = 1;
	int icountb = i + 1;
	for (auto& i : intvec)
	{
		i = icount++ * icountb++;
	}

	ilt.sort(a); PrintEle(ilt, screen);
	a.sortset(true); ilt.sort(a); PrintEle(ilt, screen);
	a.sortset(false); ilt.sort(a.sortset(false)); PrintEle(ilt, screen);
	sort(intvec.begin(), intvec.end(), compare); PrintEle(intvec, screen);
	sort(intvec.begin(), intvec.end(), a.sortset(true)); PrintEle(intvec, screen);
	a.sortset(false); sort(intvec.begin(), intvec.end(), a); PrintEle(intvec, screen);
	ilt.reverse(); PrintEle(ilt, screen);



	typedef void (*fun)(int, int);
	fun pfun = nullptr;
	CString wstring = _T("good");
	pair < CString, fun> w = make_pair(wstring, pfun);
	map<CString, fun> cfmap;
	cfmap.insert(w);
	cfmap.insert(make_pair(CString(wstring += wstring), pfun));
	cfmap.insert(pair<CString, fun>(CString(wstring = st(go)), pfun));
	cfmap.insert(map<CString, fun>::value_type(CString(st(bad)), pfun));
	screen << cfmap.size() << el;


	pair<int, float>x = make_pair(10, 2.3);
	screen << x.first << tab << x.second << el;
	auto* p = &x;
	map<int, float>imap;
	imap.insert(make_pair(10, 2.2));
	imap.insert(x);
	map<int, float>::iterator iit = imap.begin();
	lcode(screen << iit->first << tab << iit->second << el;);
	lcode(iit = imap.end(); screen << p->first << tab << p->second << el;);
	lcode(iit = imap.begin(); screen << p->first << tab << p->second << el;);

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

	PCDC screen(this);

	map<string, pfunc> menu;
	MAKEMENUITEM(ntest, menu);
	string name = "map second";
	map<string, pfunc>::iterator itt = menu.begin();
	itt->second(screen, itt->first);
	itt->second(screen, name);

	void* p = nullptr;
	screen << p << el;

	screen << (int) nullptr << tab << NULL << el;

	screen << sizeof(nullptr) << tab << sizeof(0) << tab << sizeof(NULL) << tab << sizeof(p) << el;

	screen << cl;
	int* pint = new int[1024];
	long long int sum = 0;
	for (size_t i = 0; i < 128; ++i)
	{
		pint[i] = 1 + i;
		sum += pint[i];
	}
	int* plint = new int;
	*plint = sizeof(pint);
	screen << "array size is : " << *plint << tab << "sum is " << sum << "  array elements is :" << el;
	for (size_t i = 0; i < 1024; i++)
	{
		screen << pint[i] << ", ";
	}
	screen << el;
	delete[]pint;
	delete[]plint;
	char* pc = "hello";
	CString ss = _T("123456");
	lcode(screen << strlen(pc) << tab << sizeof(_T("hello")) << tab << ss.GetLength() << el;);

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
	RUNTEST(STL ARGARMENT TEST);
	int x = 3;
	screen << returnt<int, 3>() << tab << sizeof(returnt<int, 3>()) << el;
	screen << returnt<long long int, 5>() << tab << sizeof(returnt<long long, 5>()) << el;
	screen << returnt<float, 3>() << tab << sizeof(returnt<float, 3>()) << el;

	vector<int>intvect;
	for (size_t i = 0; i < 20;)
	{
		intvect.push_back(++i * 3);
	}
	screen << intvect << el;

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
	screen << ilt << el;
	screen << l2 << el;
	multimap<CString, string>mmap;
	mmap.insert(pair<CString, string>(CString(st(imap first)), string("is first")));
	mmap.insert(make_pair(CString(st(imap second)), string("is second")));
	mmap.insert(multimap<CString, string>::value_type(CString(st(imap second)), string("is second")));
	screen << mmap << el;

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
	screen << cfmap << el;
	screen << iset1 << el;

}


void CSDIView::OnCxx20StlConceptTest()
{
	PCDC screen(this);

	//原始字符串字面量测试
	screen << R"h(hello\thello\thello)h" << el;

	vector<int>intvec(20);
	deque<int>intvec2(10);
	MakeEleRandom(intvec, 20);
	screen << intvec;
	MakeEleRandom(intvec2, 10);
	screen << intvec2;
	std::copy_if(intvec.begin(), intvec.end(), std::front_inserter(intvec2), [](int v) {return v < 10; });
	screen << intvec2 << el;
	std::copy_if(intvec.begin(), intvec.end(), std::back_inserter(intvec2), [](int v) {return v > 15; });
	screen << intvec2 << el;

}


void CSDIView::OnLamdbaFuncTest()
{
	makedc(cout);

	int x = 1, y = 2;
	auto funl = [=](int val)mutable ->int {
		//cout << val++ << tab << x << tab << y << el;
		return y += val * x;
	};
	function<int(int)> p = funl;
	cout << p(100) << el;
	SHOW(x); SHOW(y);

}


void CSDIView::OnStlTupleTest()
{
	//PCDC screen(this);
	lscode(

		using namespace std;
	auto tuplea = tuple<int, float, string, string, string>(10, 10.24, "good", "bad", "normal");
	auto tupleb = tuple<int, float, string, string, string>(22, 20.24, "good-b", "bad-b", "normal-b");
	screen << std::get<int>(tuplea) << tab;
	screen << std::get<1>(tuplea) << tab;
	screen << std::get<2>(tuplea) << tab;
	screen << std::get<3>(tuplea) << tab;
	screen << std::get<4>(tuplea) << el;
	std::get<4>(tuplea) = "change";
	screen << std::get<4>(tuplea) << tab;
	screen << cut;
	screen << std::get<0>(tupleb) << tab;
	screen << std::get<1>(tupleb) << tab;
	screen << std::get<2>(tupleb) << tab;
	screen << std::get<3>(tupleb) << tab;
	screen << std::get<4>(tupleb) << tab;

	swap(tuplea, tupleb);
	screen << std::get<0>(tupleb) << tab;
	screen << std::get<1>(tupleb) << tab;
	screen << std::get<2>(tupleb) << tab;
	screen << std::get<3>(tupleb) << tab;
	screen << std::get<4>(tupleb) << tab;

	typedef std::tuple<int, double, int, double> Mytuple;
	Mytuple c0(0, 1, 2, 3);

	// display contents " 0 1 2 3"
	screen << " " << std::get<0>(c0);
	screen << " " << std::get<1>(c0);
	screen << " " << std::get<2>(c0);
	screen << " " << std::get<3>(c0);
	screen << el;

	int v4 = 4;
	double v5 = 5;
	int v6 = 6;
	double v7 = 7;
	std::tie(v4, v5, v6, v7) = c0;

	// display contents " 0 1 2 3"
	screen << " " << v4;
	screen << " " << v5;
	screen << " " << v6;
	screen << " " << v7;
	screen << el;
	v7 = 10;
	screen << " " << std::get<3>(c0);
	screen << el;
	std::get<0>(c0) = 8;
	v4 = 9;
	screen << " " << std::get<0>(c0);
	screen << " " << v4;
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
		cout << &cout << tab << &screen << el;
	showtype(cout);
	showtype(screen);
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
	makedc(cout);
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
	PCDC& the;
	CString createname;
public:
	ptr(PCDC& dc,CString s):the(dc),createname(s)
	{
		the <<createname<<" is create" << el;
	}
	~ptr()
	{
		the <<createname<<" is decreate" << el;
	}
};

void CSDIView::OnPtrUniqueTest()
{
	//
	SimulationStdCout;
	cout << cut;
	lscode(
	ptr one(cout,CString("one"));
	);
	cout << cut;
	lscode(
	auto p=make_unique<ptr>(cout,CString("unique_ptr p"));
	);
	cout << cut;
	lscode(
	unique_ptr<ptr>two(new ptr(cout, CString("unique_ptr_two")));
	);
	cout << cut;
	lscode(
	unique_ptr<ptr>three=unique_ptr<ptr>(new ptr(cout, CString("unique_ptr_temp")));
	);
	cout << cut;
	lscode(cout<<three->createname<<el;);
	cout << cut;
	lscode(three.reset(new ptr(cout,CString("unique_ptr_threereset_tmp"))));
	cout<<cut;
	auto parr = unique_ptr< ptr[] >(new ptr[10]);


}



