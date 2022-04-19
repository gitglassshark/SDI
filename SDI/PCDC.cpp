#include "pch.h"
#include "PCDC.h"
#include "SDI.h"


size_t PCDC::icount = 0;
extern class CColor dccr;

PCDC& starline(PCDC& dc)
{
	CString cs;
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

PCDC& sp(PCDC& dc) { return dc << "  "; }
PCDC& star(PCDC& dc) { return dc << "*"; }
PCDC& dash(PCDC& dc) { return dc << "-"; }
PCDC& com(PCDC& dc) { return dc << ','; }
PCDC& semi(PCDC& dc) { return dc << ';'; }
PCDC& tab(PCDC& dc) { return dc << '\t'; }

PCDC& cut(PCDC& dc) { return dc << starline; }

PCDC& cl( PCDC& dc ) { dc.clearscreen( ); return dc; }

PCDC& endl( PCDC& dc ) { return dc << '\n'; }

PCDC& el(PCDC& dc) { return dc <<'\n'; }

PCDC::PCDC(CWnd* pwnd) :m_pwnd(pwnd)
{
	if (m_pwnd) {
		id = icount;
		++icount;
		Create(m_pwnd);
	}
}

PCDC::~PCDC()
{
	--icount;
	this->Release();
}

PCDC& PCDC::Create(CWnd* pwnd)
{
	if (pwnd != nullptr)
		m_pwnd = pwnd;
	if (icreate)
		return *this;
	this->m_hDC = m_pwnd->GetWindowDC()->m_hDC;
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

PCDC& PCDC::Release()
{
	if (!icreate)
		return *this;
	CDC& dc = *this;
	dc.SelectObject(pfont);
	m_pwnd->ReleaseDC(this);
	font.DeleteObject();
	m_pwnd = nullptr;
	m_cdc = nullptr;
	icreate = false;
	return *this;
}

PCDC& PCDC::resettcolor()
{
	this->SetTextColor(m_tk);
	return *this;
}

PCDC& PCDC::settcolor(COLORREF tk)
{
	this->SetTextColor(tk);
	return *this;
}

PCDC& PCDC::setcolor(COLORREF line, COLORREF bar, COLORREF bk, COLORREF tk)
{
	m_bk = bk;
	m_tk = tk;
	m_bark = bar;
	m_linek = line;
	return *this;
}

PCDC& PCDC::setimod(int imod)
{
	this->ilinemod = imod;
	return *this;
}

const char PCDC::setlinechar(const char& c)
{
	char rc = this->mlinechar;
	this->mlinechar = c;
	return rc;
}

const void PCDC::clearscreen(const CRect* r, const COLORREF* cr)
{
	m_pwnd->GetClientRect(&mrect);
	CRect rect(mrect);
	if (r != nullptr)
	{
		mrect = *r;
	}
	else
	{
		cr != nullptr ? m_bk = *cr : true;
		p.x = mrect.left + initalpos;
		p.y = mrect.top + wbar * 3;// +initalpos;

		rect.left = 0;
		rect.top = 0;
		FillSolidRect(rect, m_bark);

		rect.bottom -= wbar;
		rect.left += wbar;
		rect.right -= wbar;
		rect.top += wbar;
		FillSolidRect(rect, m_linek);
	}

	wbar = 12;
	rect.bottom -= wbar;
	rect.left += wbar;
	rect.right -= wbar;
	rect.top += wbar;
	FillSolidRect(rect, m_bk);

}

PCDC& PCDC::operator << (PCDC& (*op) (PCDC&))
{
	return (*op) (*this);
}

PCDC& PCDC::operator <<(LPCTSTR cs)
{
	if ((cs != nullptr) && (*cs != '\0'))
	{
		ms = cs;
		imresizeout(ms);
	}
	return *this;
}

PCDC& PCDC::operator <<(char cs[])
{
	if ((cs != nullptr) && (strlen(cs)))
	{
		ms = cs;
		imresizeout(ms);
	}
	return *this;
}

PCDC& PCDC::operator <<(char const cs[])
{
	if ((cs != nullptr) && (strlen(cs)))
	{
		ms = cs;
		imresizeout(ms);
	}
	return *this;
}

PCDC& PCDC::operator <<(const CAtlString& s)
{
	if (!s.IsEmpty()) {
		imresizeout(s);
	}
	return *this;
}

PCDC& PCDC::operator <<(const std::wstring& s)
{
	if ((s.length()) && (s.at(0) != '\0')) {
		ms = s.c_str();
		imresizeout(ms);
	}
	return *this;
}

PCDC& PCDC::operator <<(const std::string& s)
{
	if ((s.length()) && (s.at(0) != '\0')) {
		ms = s.c_str();
		imresizeout(ms);
	}
	return *this;
}

PCDC& PCDC::operator <<(const CString& s)
{
	if (!s.IsEmpty()) {
		imresizeout(s);
	}
	return *this;
}

PCDC& PCDC::operator <<(const int n)
{
	ms.Format(_T("%ld"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator<<(const char c)
{
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
	return *this;
}

PCDC& PCDC::operator <<(const float n)
{
	ms.Format(_T("%4.2f"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const double n)
{
	ms.Format(_T("%f"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const long double n)
{
	ms.Format(_T("%lf"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const long int n)
{
	ms.Format(_T("%ld"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const long long n)
{
	ms.Format(_T("%lld"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const size_t n)
{
	ms.Format(_T("%zd"), n);
	imresizeout(ms);
	return *this;
}

PCDC& PCDC::operator <<(const bool b)
{
	if (b == true)
	{
		ms = st(true);
	}
	else {
		ms = st(false);
	}
	imresizeout(ms);
	return *this;
}



