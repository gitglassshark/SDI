
// SDIView.h: CSDIView 类的接口
//

#pragma once
#include <vector>
#include <string>
#include "CDialogExDoModal.h"
#include "PCDC.h"


extern PCDC out;



class CSDIView : public CView
{
protected: // 仅从序列化创建
	CSDIView() noexcept;
	DECLARE_DYNCREATE(CSDIView)

	// 特性
public:
	CSDIDoc* GetDocument() const;

	// 操作
public:
	POINT position = { 50,50 };
	unsigned int step = 20;

public:
	PCDC& cout = out;
	CDC* m_dc;
	RECT m_max_rect = { 5,100,1890,2045 };
	LOGFONT  m_userset_logfont = { 0 };
	bool is_font_set_ok = false;
	CFont* m_p_defaultfont = nullptr;
	CFont m_user_font;
	CFont* m_p_newchoosefont = nullptr;

public:
	bool is_show_logmessage = true;
	vector<CAtlString> vecotr_paintmessage;

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	POINT SetPoint(int x, int y, POINT* p = nullptr);
protected:

	// 实现
public:
	virtual ~CSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

public:
	afx_msg void OnSetFont();
	afx_msg void OnShowlog();
	afx_msg void OnTestFontdlg();
	afx_msg void OnResetXY();
	afx_msg void OnTestCAtlString();
	afx_msg void OnPrintEnvVAR();
	afx_msg void OnUpperLower();
	afx_msg void OnMacroTest();
	afx_msg void OnGroundTest();
	afx_msg void OnObjectSize();
	afx_msg void OnAutoSetFont();
	afx_msg void OnBitExChar();

public:
	bool  CSDIView::spline(CDC& dc, string tips = "0", int line = -1, char c = '=', int ntime = 120);
	CDC& SetDefaultFontDC(CDC* pdc = nullptr);
	bool RestoreDCFont(CDC& dc);

	afx_msg void OnDialgoModal();
	// 调整字体大小系数对话框
	CDialogExDoModal m_fontresize_CDialogExDoModal;
	bool writedc(const CAtlString& str, CDC* pdc = nullptr);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnReadFile();
	afx_msg void OnVectorTest();
	afx_msg void OnMacroFuncPointTemplateTest();
	afx_msg void OnGetWindowsRect();
	afx_msg void OnSTLFuncTest();
	afx_msg void OnExceptCatchTest();
	afx_msg void OnPCDCFunctionTest();
	afx_msg void OnSTLlStringTest();
	afx_msg void OnStlStackEqueueTest();
	afx_msg void OnClearRecord();
	afx_msg void OnStlSetTest();
	afx_msg void OnStlMapMenu();
	afx_msg void OnSTLArgTest();
	afx_msg void OnCxx20StlConceptTest();
	afx_msg void OnLamdbaFuncTest();
	afx_msg void OnStlTupleTest();
	afx_msg void OnStlTypeTest();
	afx_msg void OnInitalListTest();
	afx_msg void OnPtrUniqueTest();
	afx_msg void OnLvalRvalTest();
};

#ifndef _DEBUG  // SDIView.cpp 中的调试版本
inline CSDIDoc* CSDIView::GetDocument() const
{
	return reinterpret_cast<CSDIDoc*>(m_pDocument);
}
#endif

