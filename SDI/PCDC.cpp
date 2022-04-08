#include "pch.h"
#include "PCDC.h"
#include "SDI.h"

extern class CColor dccr;


PCDC& starline(PCDC& dc)
{
	CString cs;
	CString st;
	st = dc.mlinechar;
	cs = dc.mlinechar;
	CSize size = dc.GetOutputTextExtent(cs);
	dc.m_pwnd->GetClientRect(&dc.mrect);
	//auto h = dc.mrect.bottom - (dc.mrect.top + dc.initalpos * 2);
	auto w = dc.mrect.right - (dc.mrect.left + dc.initalpos * 2);
	size_t icount = w / size.cx;
	for (size_t i = 0; i < icount - 1; ++i)
	{
		cs += dc.mlinechar;
	}
	dc << cs << el;

	return dc;
}


PCDC& tab(PCDC& dc)
{
	dc << ('\t');
	return dc;
}


PCDC& cut(PCDC& dc)
{
	dc << starline;
	return dc;
}


PCDC& cl(PCDC& dc)
{
	dc.clearscreen();
	return dc;
}


PCDC& el(PCDC& dc)
{
	dc << ('\n');
	return dc;
}


PCDC& PCDC::operator << (PCDC& (*op) (PCDC&))
{
	return (*op) (*this);
}

PCDC& PCDC::Create(CWnd* pwnd)
{
	if (pwnd != nullptr)
		m_pwnd = pwnd;
	if (icreate)
		return *this;
	this->m_hDC = pwnd->GetWindowDC()->m_hDC;
	CDC& dc = *this;
	auto tcolor = dccr.chocolate;
	auto bcolor = dccr.grey;

	//设置窗口背景颜色
	m_pwnd->GetClientRect(&mrect);
	p.x = mrect.left + initalpos;
	p.y = mrect.top;
	dc.FillSolidRect(mrect, m_bk);

	//设置字体颜色
	dc.SetBkColor(m_bk);
	dc.SetTextColor(m_tk);

	//设置缺省字体
	LOGFONT lf;
	// zero out structure
	memset(&lf, 0, sizeof(LOGFONT));
	font.CreatePointFont(this->mfontsize, _T("Cascadia Mono"));
	pfont = dc.SelectObject(&font);

	//根据字体大小调整步长
	font.GetLogFont(&lf);
	step = abs(lf.lfHeight + lf.lfHeight / 2);

	//检查输出位置
	if (!dc.PtVisible(p)) {
		p.x = initalpos;
		p.y = initalpos;
	}
	*this << cl;
	icreate = true;
	return *this;
}

PCDC::PCDC(CWnd* pwnd) :m_pwnd(pwnd)
{
	if (!pwnd) {
		return;
	}
	Create(pwnd);
}

PCDC& PCDC::Release()
{   
	if (!icreate)
		return *this;
	CDC& dc = *this;
	dc.SelectObject(pfont);
	m_pwnd->ReleaseDC(this);
	font.DeleteObject();
	m_hDC = nullptr;
	m_cdc = nullptr;
	icreate = false;
	return *this;
}

PCDC::~PCDC()
{
	this->Release();
}


PCDC& PCDC::operator <<(LPCTSTR cs)
{
	//
	if ((cs != nullptr) && (*cs != '\0'))
	{
		ms = cs;
		imresizeout(ms);
	}
	return *this;
}


PCDC& PCDC::operator <<(const char* cs)
{
	//
	if ((cs != nullptr) && (*cs != '\0'))
	{
		ms = cs;
		imresizeout(ms);
	}
	return *this;
}


PCDC& PCDC::operator <<(const CAtlString& s)
{
	//
	if (!s.IsEmpty()) {
		imresizeout(s);
	}
	//
	return *this;
}

PCDC& PCDC::operator <<(const std::wstring& s)
{
	//
	if ((s.length()) && (s.at(0) != '\0')) {
		ms = s.c_str();
		imresizeout(ms);
	}
	//
	return *this;
}


PCDC& PCDC::operator <<(const std::string& s)
{
	//
	if ((s.length()) && (s.at(0) != '\0')) {
		ms = s.c_str();
		imresizeout(ms);
	}
	//
	return *this;
}


PCDC& PCDC::operator <<(const CString& s)
{
	//
	if (!s.IsEmpty()) {
		imresizeout(s);
	}
	//
	return *this;
}


PCDC& PCDC::operator <<(const float n)
{
	//
	ms.Format(_T("%4.2f"), n);
	imresizeout(ms);
	return *this;
}


PCDC& PCDC::operator <<(const double n)
{
	//
	ms.Format(_T("%f"), n);
	imresizeout(ms);
	return *this;
}


PCDC& PCDC::operator <<(const long double n)
{
	//
	ms.Format(_T("%lf"), n);
	imresizeout(ms);
	//
	return *this;
}


PCDC& PCDC::operator <<(const long int n)
{
	//
	ms.Format(_T("%ld"), n);
	imresizeout(ms);
	//
	return *this;
}


PCDC& PCDC::operator <<(const long long n)
{
	//
	ms.Format(_T("%lld"), n);
	imresizeout(ms);
	//
	return *this;
}


PCDC& PCDC::operator <<(const size_t n)
{
	//
	ms.Format(_T("%zd"), n);
	imresizeout(ms);
	//
	return *this;
}


PCDC& PCDC::operator <<(const bool b)
{
	//
	if (b == true)
	{
		ms = st(true);
	}
	else {
		ms = st(false);
	}
	imresizeout(ms);

	//
	return *this;
}


PCDC& PCDC::operator <<(const int n)
{
	//
	ms.Format(_T("%ld"), n);
	imresizeout(ms);
	//
	return *this;
}


PCDC& PCDC::operator<<(const char c)
{
	//
	ms = c;
	if (c == '\n') {
		p.y += step;
		p.x = initalpos;
		return *this;
	}
	if (c == '\t')
	{
		ms = "    ";
	}
	imresizeout(ms);
	//
	return *this;
}



