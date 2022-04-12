#pragma once
#include <afxwin.h>
#include <iostream>
#include <set>
#include <bitset>
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
	size_t id = 0;
	static size_t icount;
	int iargs = 0;

public:
	LONG wbar = 8;
	const LONG initalpos = wbar + 35;
	const LONG initalstep = 20;
	LONG step = initalstep;
	POINT p = { initalpos, initalpos };
	CRect mrect;
	CSize msize;
	int ilinemod = 26;
	bool icutline = false;


public:
	COLORREF m_bk = dccr.grey;
	COLORREF m_tk = dccr.chocolate;
	COLORREF m_bark = dccr.berry;
	COLORREF m_linek = dccr.azure;
	int mfontsize = 120;
	CFont font, * pfont;


public:
	CDC* m_cdc = nullptr;
	CWnd* m_pwnd = nullptr;


public:
	char mlinechar = _T('-');
	CString ms;
	CString opstr;


public:
	PCDC(CWnd* pwnd = nullptr);
	PCDC& Create(CWnd* pwnd);
	PCDC& Release();
	~PCDC();


	//explicit operator char *() const;

public:
	PCDC& operator<<(const char c);
	PCDC& operator<<(char const cs[]);
	PCDC& operator<<(char cs[]);
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
	template <typename  int N = 64> PCDC& operator <<(bitset<N>& bits)
	{
		string str = bits.to_string();
		ms = str.c_str();
		imresizeout(ms);
		return *this;
	}
	template <typename  int N = 64> PCDC& operator <<(const bitset<N>& bits)
	{
		string str = bits.to_string();
		ms = str.c_str();
		imresizeout(ms);
		return *this;
	};
	template <typename T> PCDC& operator <<(const multiset<T>& s);
	template <typename T> PCDC& operator <<(const deque<T>& d);
	template <typename T, size_t len> PCDC& operator <<(const array<T, len>& a);
	template<typename T> PCDC& forprintr(T* b, T* e);
	template<typename T> PCDC& forprintv(T&& v);
	template<typename T> PCDC& forprintm(T&& m);
	template <typename S> void linemod(S l, S linemod, PCDC& (*op)(PCDC&) = el, char* stail = nullptr);
	template <typename X> PCDC& operator <<(const unique_ptr<X>& unptr);

	template <typename X> PCDC& pt(X a);
	template <typename T, typename ...X> PCDC& pt(T a, X...args);
	template <typename X> PCDC& pc(X a);
	template <typename T, typename ...X> PCDC& pc(T a, X...args);
	template <typename X> PCDC& pb(X a);
	template <typename T, typename ...X> PCDC& pb(T a, X...args);
	PCDC& pl() { return *this; }
	template <typename T, typename ...X> PCDC& pl(T a, X...args);
	template <typename X> PCDC& adress(X a);
	template <typename T, typename ...X> PCDC& adress(T a, X...args);
	PCDC& type() { return *this; };
	template <typename T, typename ...X> PCDC& type(T&& a, X&&...args);


public:
	PCDC& args()
	{
		*this << __func__ << "  args4#" << iargs++ << el;
		return *this;
	}

	template <typename X>
	PCDC& args(X&& a)
	{
		*this << __func__ << "  args3#" << iargs++ << el;
		return *this;
	}

	template <typename... X>
	PCDC& args(X&&...Args)
	{
		*this << __func__ << "  args2#" << iargs++ << " sizeof is: " << sizeof...(Args) << el;
		args((X&&)Args...);
		return *this;
	}

	template <typename T, typename... X>
	PCDC& args(T a, X&&...Args)
	{
		*this << __func__ << " args1# " << iargs++ << " sizeof is: " << sizeof...(Args) << el;
		args((X&&)Args...);
		return *this;
	}

};


template <typename T, typename ...X>
PCDC& PCDC::pl(T a, X...args)
{
	*this << a << '\n';
	pl(args...);
	return *this;
}


template <typename X>
PCDC& PCDC::pt(X a)
{
	*this << a << '\n';
	return *this;
}


template <typename T, typename ...X>
PCDC& PCDC::pt(T a, X...args)
{
	*this << a << '\t';
	pt(args...);
	return *this;
}


template <typename X>
PCDC& PCDC::pc(X a)
{
	*this << a << '\n';
	return *this;
}


template <typename T, typename ...X>
PCDC& PCDC::pc(T a, X...args)
{
	*this << a << ", ";
	pc(args...);
	return *this;
}


template <typename X>
PCDC& PCDC::pb(X a)
{
	*this << '{' << a << "}" << '\n';
	return *this;
}


template <typename T, typename ...X>
PCDC& PCDC::pb(T a, X...args)
{
	*this << '{' << a << "},";
	pb(args...);
	return *this;
}


template <typename X>
PCDC& PCDC::adress(X a)
{
	ms.Format(_T("[0x%p]"), &a);
	imresizeout(ms);
	*this << '\n';
	return *this;
}


template <typename T, typename ...X>
PCDC& PCDC::adress(T a, X...args)
{
	ms.Format(_T("[0x%p],"), &a);
	imresizeout(ms);
	adress(args...);
	return *this;
}


template <typename T, typename ...X>
PCDC& PCDC::type(T&& a, X&&...args)
{
	*this << "TYPE:  " << typeid(a).name() << '\t' << "SIZE:  " << sizeof(a) << '\t' << "HASHCODE: " << typeid(a).hash_code() << el;
	type((X&&)args...);
	return *this;
}


template<typename T>
PCDC& PCDC::operator <<(T* p)
{
	ms.Format(_T("%p"), p);
	imresizeout(ms);
	return *this;
}


template <typename X>
PCDC& PCDC::operator <<(const unique_ptr<X>& unptr)
{
	ms.Format(_T("%p"), unptr.get());
	imresizeout(ms);
	return *this;
}


template<typename Tstring>
PCDC& PCDC::operator <<(Tstring s)
{
	if (decltype(s) == decltype(NULL) || decltype(s) == decltype(nullptr) || decltype(s) == decltype(void*))
	{
		ms.Format(_T("%p"), (Tstring&&)s);
	}
	else {
		if ((s.length()) && (s.at(0) != '\0')) {
			ms = s.c_str();
		}
	}
	imresizeout(ms);
	return *this;
}


template<typename S>
void PCDC::linemod(S l, S linemod, PCDC& (*op)(PCDC&), char* stail)
{
	if (++l % linemod == 0)
	{
		(*op)(*this);
		if (stail)
			*this << stail;
	}
}


template<typename T>
PCDC& PCDC::forprintr(T* b, T* e)
{
	int il = 0;
	for (auto* it = b; it != e; ++it)
	{
		*this << *it << tab;
		linemod(il, ilinemod);
	}
	return *this;
}


template<typename T>
PCDC& PCDC::forprintv(T&& v)
{
	int il = 0;
	for (const auto& i : v)
	{
		*this << i << tab;
		linemod(il, ilinemod);
	}
	return *this;
}


template<typename T>
PCDC& PCDC::forprintm(T&& m)
{
	int il = 0;
	for (const auto& i : m)
	{
		*this << "{" << i.first << "," << i.second << "}   ";
		linemod(il, ilinemod);
	}
	return *this;
}


template <typename T, size_t len>
PCDC& PCDC::operator <<(const array<T, len>& a)
{
	if (len == 0 || &a == nullptr)
		return *this;
	else
		return forprintv(a);
}


template <typename X>
PCDC& PCDC::operator <<(const vector<X>& v)
{
	if (v.empty())
		return *this;
	else
		return forprintv(v);
}


template <typename T>
PCDC& PCDC::operator <<(const deque<T>& d)
{
	if (d.empty())
		return *this;
	else
		return forprintv(d);
}


template <typename T, typename X>
PCDC& PCDC::operator <<(const map<T, X>& m)
{
	if (!m.size())
		return *this;
	else
		return forprintm(m);
}


template <typename T, typename X>
PCDC& PCDC::operator <<(const multimap<T, X>& m)
{
	if (!m.size())
		return *this;
	else
		return forprintm(m);
}


template <typename T>
PCDC& PCDC::operator <<(const multiset<T>& s)
{
	if (!s.size())
		return *this;
	else
		return forprintv(s);
}


template <typename T>
PCDC& PCDC::operator <<(const set<T>& s)
{
	if (!s.size())
		return *this;
	else
		return forprintv(s);
}




template <typename T>
PCDC& PCDC::operator <<(const list<T>& l)
{
	if (!l.size())
		return *this;
	else
		return forprintv(l);
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





