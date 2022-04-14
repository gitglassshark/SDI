#include "pch.h"
#include "FCDC.h"
#include "SDI.h"

extern class CColor dccr;

bool FCDC::el = true;

FCDC::FCDC(CWnd* pwnd) :m_pwnd(pwnd)
{
	if (pwnd) {
		m_cdc = pwnd->GetWindowDC();
		m_pwnd = pwnd;
	}

	CDC& dc = *m_cdc;
	auto bcolor = dccr.grey;
	auto tcolor = dccr.chocolate;

	//���ô��ڱ�����ɫ
	CRect rect;
	m_pwnd->GetClientRect(&rect);
	dc.FillSolidRect(rect, bcolor);

	//����������ɫ
	dc.SetBkColor(bcolor);
	dc.SetTextColor(tcolor);

	//����ȱʡ����
	LOGFONT lf;
	// zero out structure
	memset(&lf, 0, sizeof(LOGFONT));

	//�������ѡ���־��λ��ʹ���û�ѡ������
	CFont font, * pfont;
	if (!font.CreatePointFont(120, _T("Cascadia Code"))) {
	}

	pfont = dc.SelectObject(&font);

	//���������С��������
	font.GetLogFont(&lf);
	step = abs(lf.lfHeight + lf.lfHeight / 2);

	//������λ��
	if (!dc.PtVisible(p)) {
		p.x = initalpos;
		p.y = initalpos;
	}
	dc.AssertValid();
}


FCDC::~FCDC()
{
	m_cdc->ReleaseOutputDC();
	m_cdc = nullptr;
}


FCDC& FCDC::operator << (FCDC& (*op) (FCDC&))
{
	// call the function passed as parameter with this stream   as the argument
	return (*op) (*this);
}


FCDC& el(FCDC& dcstrm)
{
	dcstrm << ('\n');
	return dcstrm;
}


FCDC& FCDC::operator <<(LPCTSTR cs)
{
	//
	if ((cs != nullptr) && (*cs != '\0'))
	{
		CString s;
		s = cs;
		m_cdc->TextOut(p.x, p.y, cs);
		CSize size;
		size = m_cdc->GetOutputTextExtent(cs);
		p.x += size.cx;
	}
	return *this;
}


FCDC& FCDC::operator <<(const char* cs)
{
	//
	if ((cs != nullptr) && (*cs != '\0'))
	{
		CString s;
		s = cs;
		m_cdc->TextOut(p.x, p.y, s);
		CSize size;
		size = m_cdc->GetOutputTextExtent(s);
		p.x += size.cx;
	}
	return *this;
}


FCDC& FCDC::operator <<(const CAtlString& s)
{
	//
	if (!s.IsEmpty()) {
		m_cdc->TextOut(p.x, p.y, s);
		CSize size;
		size = m_cdc->GetOutputTextExtent(s);
		p.x += size.cx;
	}
	//
	return *this;
}


FCDC& FCDC::operator <<(const std::string& s)
{
	//
	if ((s.length()) && (s.at(0) != '\0')) {
		CString cs;
		cs = s.c_str();
		m_cdc->TextOut(p.x, p.y, cs);
		CSize size;
		size = m_cdc->GetOutputTextExtent(cs);
		p.x += size.cx;
	}
	//
	return *this;
}


FCDC& FCDC::operator <<(const CString& s)
{
	//
	if (!s.IsEmpty()) {
		m_cdc->TextOut(p.x, p.y, s);
		CSize size;
		size = m_cdc->GetOutputTextExtent(s);
		p.x += size.cx;
	}
	//
	return *this;
}


FCDC& FCDC::operator <<(const double n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%f"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;
	//
	return *this;
}


FCDC& FCDC::operator <<(const long double n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%lf"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;
	//
	return *this;
}


FCDC& FCDC::operator <<(const long int n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%ld"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}


FCDC& FCDC::operator <<(const long long n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%lld"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}


FCDC& FCDC::operator <<(const size_t n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%zd"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}


FCDC& FCDC::operator <<(const bool b)
{
	//
	CString s;
	CSize size;
	if (b == true)
	{
		s = st(true);
	}
	else {
		s = st(false);
	}
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}


FCDC& FCDC::operator <<(const int n)
{
	//
	CString s;
	CSize size;
	s.Format(_T("%ld"), n);
	m_cdc->TextOut(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}


FCDC& FCDC::operator<<(const char& c)
{
	//
	if (c == '\n') {
		p.y += step;
		p.x = initalpos;
		return *this;
	}
	CString s;
	s = c;
	m_cdc->TextOut(p.x, p.y, s);
	CSize size;
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;

	//
	return *this;
}



