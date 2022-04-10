#pragma once
#include <afxwin.h>
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <sstream>
#include <string>
#include "SDI.h"


#define nonull(v) (((v )!=nullptr )&&(&(v )!=nullptr ) )

class PCDC;
extern class CColor dccr;

typedef struct _tag_iosset {
	byte set;
	byte flag;

}ioset;

PCDC& cl(PCDC& dc);
PCDC& cut(PCDC& dc);
PCDC& tab(PCDC& dc);
PCDC& el(PCDC& dc);
PCDC& starline(PCDC& dc);


class PCDC : public CDC
{
public:
	bool icreate = false;
	bool icutline = false;
	LONG wbar = 8;
	const LONG initalpos = wbar + 35;
	const LONG initalstep = 20;
	LONG step = initalstep;
	int ilinemod = 26;
	static size_t icount;
	size_t id=0;


public:
	char mlinechar = _T('-');
	COLORREF m_bk = dccr.grey;
	COLORREF m_tk = dccr.chocolate;
	COLORREF m_bark = dccr.berry;
	COLORREF m_linek = dccr.azure;
	int mfontsize = 128;
	CFont font, * pfont;
	CDC* m_cdc = nullptr;
	CWnd* m_pwnd = nullptr;
	POINT p = { initalpos, initalpos };
	CSize msize;
	CRect mrect;
	CString ms;


public:
	PCDC(CWnd* pwnd = nullptr);
	PCDC& Create(CWnd* pwnd);
	PCDC& Release();
	~PCDC();


	//explicit operator char *() const;

public:
	PCDC& operator<<(const char c);
	//PCDC& operator<<(const char* s);
	PCDC& operator<<(char const cs[] );
	PCDC& operator<<(LPCTSTR s);
	PCDC& operator<<(const std::string& s);
	PCDC& operator<<(const std::wstring& s);
	PCDC& operator<<(const CString& s);
	PCDC& operator<<(const CAtlString& s);
	PCDC& operator<<(const bool b);
	PCDC& operator<<(const int n);
	PCDC& operator<<(const long int n);
	PCDC& operator<<(const long long n);
	PCDC& operator<<(const float n);
	PCDC& operator<<(const double n);
	PCDC& operator<<(const long double n);
	PCDC& operator<<(const size_t n);


public:
	PCDC& operator<< (PCDC& (*op) (PCDC& dc));


public:
	PCDC& resettcolor();
	PCDC& settcolor(COLORREF tk);
	PCDC& setcolor(COLORREF line, COLORREF bar, COLORREF bk, COLORREF tk);
	PCDC& setimod(int imod);
	const char setlinechar(const char& c = '=');
	const void clearscreen(const CRect* r = nullptr, const COLORREF* cr = nullptr);
	const CSize& imresizeout(const CString& cs);


public:
	template<typename T> PCDC& operator <<(T* p);
	template<typename Tstring> PCDC& operator <<(Tstring s);
	template<typename Tstring> PCDC& titleline(const Tstring& s);
	template <typename X> PCDC& operator <<(const vector<X>& v);
	template <typename T> PCDC& operator <<(const list<T>& l);
	template <typename T, typename X> PCDC& operator <<(const multimap<T, X>& m);
	template <typename T, typename X> PCDC& operator <<(const map<T, X>& m);
	template <typename T> PCDC& operator <<(const set<T>& s);
	template <typename T> PCDC& operator <<(const multiset<T>& s);
	template <typename T> PCDC& operator <<(const deque<T>& d);


};


template<typename T>
PCDC& PCDC::operator <<( T* p)
{
	ms.Format(_T("%p"), p);
	imresizeout(ms);
	return *this;
};


template<typename Tstring>
PCDC& PCDC::operator <<(Tstring s)
{
	//
	if (decltype(s) == decltype(NULL) || decltype(s) == decltype(nullptr) || decltype(s) == decltype(void*))
	{
		ms.Format(_T("%p"), s);
	}
	else {
		if ((s.length()) && (s.at(0) != '\0')) {
			ms = s.c_str();
		}
	}
	imresizeout(ms);
	//
	return *this;
}


template <typename X> PCDC& PCDC::operator <<(const vector<X>& v)
{
	int il = 0;
	if (v.empty())
		return *this;
	for (const auto& i : v)
	{
		*this << i << tab;
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T> PCDC& PCDC::operator <<(const deque<T>& d)
{
	int il = 0;
	if (d.empty())
		return *this;
	for (const auto& i : d)
	{
		*this << i << tab;
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T, typename X> PCDC& PCDC::operator <<(const map<T, X>& m)
{
	int il = 0;
	if (!m.size())
		return *this;
	for (const auto& i : m)
	{
		*this << "{" << i.first << "," << i.second << "}   ";
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T, typename X> PCDC& PCDC::operator <<(const multimap<T, X>& m)
{
	int il = 0;
	if (!m.size())
		return *this;
	for (const auto& i : m)
	{
		*this << "{" << i.first << "," << i.second << "}   ";
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T> PCDC& PCDC::operator <<(const multiset<T>& s)
{
	int il = 0;
	if (!s.size())
		return *this;
	for (const auto& i : s)
	{
		*this << i << tab;
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T> PCDC& PCDC::operator <<(const set<T>& s)
{
	int il = 0;
	if (!s.size())
		return *this;
	for (const auto& i : s)
	{
		*this << i << tab;
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template <typename T> PCDC& PCDC::operator <<(const list<T>& l)
{
	int il = 0;
	if (!l.size())
		return *this;
	for (const auto& i : l)
	{
		*this << i << tab;
		if (++il % ilinemod == 0)
		{
			*this << el;
		}
	}
	*this << el;
	return *this;
}


template<typename Tstring>
PCDC& PCDC::titleline(const Tstring& s)
{
	CString ts;
	ts = s.c_str();
	if (!ts.IsEmpty())
	{
		ts.MakeUpper();
	}
	else
	{
		ts = _T("BEGIN TEST");
	}

	CString cs;
	cs = '<';
	PCDC& dc = *this;
	CSize size = dc.GetOutputTextExtent(cs);
	dc.m_pwnd->GetClientRect(&dc.mrect);
	auto w = dc.mrect.right - (dc.mrect.left + dc.initalpos * 2);
	size_t icount = w / size.cx - ts.GetLength();
	icount /= 2;
	for (size_t i = 0; i < icount; ++i)
	{
		cs += this->mlinechar;
	}
	cs += ts;
	for (size_t i = 0; i < icount - 1; ++i)
	{
		cs += this->mlinechar;
	}
	cs += '>';
	imresizeout(cs);
	return dc;
}


template <typename T>
CString address(T& x)
{
	CString cs;
	cs.Format(_T("%lp"), &x);
	return cs;
}


template <typename T>
bool swap(T& a, T& b)
{
	if ((a != nullptr) && (b != nullptr) && (&a != nullptr) && (&b != nullptr) && (&a != &b))
	{
		T c;
		c = a;
		a = b;
		b = c;
		return true;
	}
	return false;
}



