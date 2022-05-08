#pragma once
#include "pch.h"


// CDialogExDoModal 对话框

class CDialogExDoModal : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogExDoModal)

public:
	CDialogExDoModal(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogExDoModal();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	afx_msg void OnCbnSelchangeCombo1();
	unsigned int m_age_edit;
	afx_msg void OnEnChangeEditAgeDiaone();
	double m_num1_d1_double;
	double m_num2_d1_double;
	double m_sum_d1_double;
	afx_msg void OnBnClickedButtonCalcD1();
//	CString m_school_d1_string;
	CComboBox m_school_combo_d1;
	virtual BOOL OnInitDialog();
	long m_int_decnum;
	CString m_str_bitnum;
	afx_msg void OnBnClickedButtonDectobitD2();
};
