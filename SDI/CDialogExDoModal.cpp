// CDialogExDoModal.cpp: 实现文件
//

#include "pch.h"
#include "SDI.h"
#include "PCDC.h"





// CDialogExDoModal 对话框

IMPLEMENT_DYNAMIC(CDialogExDoModal, CDialogEx)

CDialogExDoModal::CDialogExDoModal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MODAL, pParent)
	, m_age_edit(0)
	, m_num1_d1_double(0)
	, m_num2_d1_double(0)
	, m_sum_d1_double(0)
	, m_int_decnum(0)
	, m_str_bitnum(_T(""))
{
	{ LOGMESSAGE(theApp); }
}

CDialogExDoModal::~CDialogExDoModal()
{
}

void CDialogExDoModal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AGE_DIAONE, m_age_edit);
	DDX_Text(pDX, IDC_EDIT_NUM1_D1, m_num1_d1_double);
	DDX_Text(pDX, IDC_EDIT_NUM2_D1, m_num2_d1_double);
	DDX_Text(pDX, IDC_EDIT_SUM_D1, m_sum_d1_double);
	//  DDX_CBIndex(pDX, IDC_COMBO1, m_school_d1_string);
	DDX_Control(pDX, IDC_COMBO_SCHOOL_D1, m_school_combo_d1);
	DDX_Text(pDX, IDC_EDIT_DECNUM_D1, m_int_decnum);
	DDX_Text(pDX, IDC_STATIC_BITNUM_D1, m_str_bitnum);
}


BEGIN_MESSAGE_MAP(CDialogExDoModal, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogExDoModal::OnBnClickedOk)
//	ON_CBN_SELCHANGE(IDC_COMBO1, &CDialogExDoModal::OnCbnSelchangeCombo1)
ON_EN_CHANGE(IDC_EDIT_AGE_DIAONE, &CDialogExDoModal::OnEnChangeEditAgeDiaone)
ON_BN_CLICKED(IDC_BUTTON_CALC_D1, &CDialogExDoModal::OnBnClickedButtonCalcD1)
ON_BN_CLICKED(IDC_BUTTON_DECTOBIT_D2, &CDialogExDoModal::OnBnClickedButtonDectobitD2)
END_MESSAGE_MAP()


// CDialogExDoModal 消息处理程序


void CDialogExDoModal::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


#define strboxn(n)  {CAtlString strage;\
					strage.Format(_T("%ld"), n);\
					AfxMessageBox(strage);}
#define wwindowst(n)	{CAtlString strage;\
						strage.Format(_T("ok:%ld"), n);\
						this->SetWindowText(strage);}

void CDialogExDoModal::OnEnChangeEditAgeDiaone()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不 // 发送此通知，除非重写 CDialogEx::OnInitDialog() // 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	m_age_edit = 100;
	this->UpdateData(true);
	CAtlString strage; 
	strage.Format(_T("ok %ld"), m_age_edit);
	this->SetWindowText(strage);
	this->m_age_edit;
	//this->UpdateData(true);

	// TODO:  在此添加控件通知处理程序代码
}


void CDialogExDoModal::OnBnClickedButtonCalcD1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	m_sum_d1_double = m_num2_d1_double + m_num1_d1_double;
	wwindowst(int(m_sum_d1_double));
	this->UpdateData(false);
}


BOOL CDialogExDoModal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
 	CAtlString stritem;
	stritem = _T("中国人民大学");
	m_school_combo_d1.AddString(stritem);
	stritem = _T("清华大学");
	m_school_combo_d1.AddString(stritem);
	stritem = _T("北京大学");
	m_school_combo_d1.AddString(stritem);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogExDoModal::OnBnClickedButtonDectobitD2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);

	CAtlString csmessage;

	static CHAR CHAR64BIT[256] = { 0 };
	LONGLONG long64bit = 256 * 256 * 256 * 256 - 1;
	Long64ToChar(long64bit, CHAR64BIT);

	bitset<64> bit64a = this->m_int_decnum;
	string sbitstr;

	sbitstr = bit64a.template to_string<char, char_traits<char>, allocator<char> >();

	CAtlString catstrbit32(sbitstr.c_str());

	this->m_str_bitnum = catstrbit32;
	
	this->UpdateData(false);

}
