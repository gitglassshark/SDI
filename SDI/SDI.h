
// SDI.h: SDI 应用程序的主头文件
//
#pragma once

#include "framework.h"
#include "pch.h"

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号
#include <vector>


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
#define PRINTN(x,y,number) {\
		CDC* pdc= this->GetWindowDC();\
		CAtlString strmessage;\
		strmessage.Format(_T(#number" is :""%ld ."),number);\
		this->ShowWindow(SW_SHOW);\
		this->UpdateWindow();\
		pdc->TextOut(x, y, strmessage);\
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


//测试字符串是否为空的宏
#ifndef isempty
#define isempty(astr) ((astr) == (_T("")))
#endif // !empty

//布尔测试宏

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

#ifndef st

#define st(...) (_T(###__VA_ARGS__))


#endif	

#ifndef strbox

#define strbox(OK) AfxMessageBox(_T(#OK))

#endif	

#define OBSIZEBEGIN(vectorname,stringname) vector<CAtlString> vectorname;CAtlString stringname;

#define  OBSIZE(obname,message,v) 	{message.Format(_T("The "#obname" size of is %d"), sizeof(obname));v.push_back(message);}


class CColor {
public:
	COLORREF red = RGB(255, 0, 0);
	COLORREF red4 = RGB(139, 0, 0);
	COLORREF green = RGB(34, 139, 34);
	COLORREF blue = RGB(0, 0, 255);
	COLORREF white = RGB(255, 255, 255);
	COLORREF chocolate = RGB(238, 118, 33);
	COLORREF black = RGB(0, 0, 0);
	COLORREF dodgerblue = RGB(16,78,139);
	COLORREF forestgreen = RGB(34,139,34);
	COLORREF darkgray= RGB(128, 128, 139);
	COLORREF darkslateblue= RGB(72, 61, 128);
	COLORREF slategray= RGB(112, 128, 144);
	COLORREF gray = RGB(128, 128, 128);
	COLORREF berry = RGB(135, 38, 87);
	COLORREF brown = RGB(128, 42, 42);
	COLORREF azure = RGB(131, 139, 139);
	COLORREF grey = RGB(28, 28, 28);
	COLORREF whitesmoke= RGB(245, 245,245);
	COLORREF silver= RGB(192, 192,192);
	COLORREF darkcyan= RGB(0, 139,139);
	COLORREF darkred= RGB(139, 0,0);
	COLORREF teal= RGB(0, 128,128);
};

using namespace std;

// CSDIApp:
// 有关此类的实现，请参阅 SDI.cpp
//

class CSDIApp : public CWinApp
{
public:
	CSDIApp() noexcept;


// 重写
public:
	vector <CAtlString> messagelog;
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIApp theApp;



