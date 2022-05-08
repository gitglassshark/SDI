
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

class CDockablePane;



// CSDIApp:
// 有关此类的实现，请参阅 SDI.cpp
//
//using namespace std;

class CSDIApp : public CWinApp
{
public:
	CSDIApp( ) noexcept;


	// 重写
public:
	std::vector <CAtlString> messagelog;
	virtual BOOL InitInstance( );

	// 实现
	afx_msg void OnAppAbout( );
	DECLARE_MESSAGE_MAP( )
};

extern CSDIApp theApp;



