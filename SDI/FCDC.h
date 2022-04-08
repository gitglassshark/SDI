#pragma once
#include <afxwin.h>
#include <iostream>
#include <sstream>
#include <string>




class FCDC : public CObject
{
public:
	const LONG initalpos = 50;
	const LONG initalstep = 20;

public:
	CDC* m_cdc = nullptr;
	CWnd* m_pwnd = nullptr;
	POINT p = { initalpos, initalpos };
	LONG step = initalstep;

public:
	static bool el;

public:
	FCDC(CWnd* pwnd);
	~FCDC();

	//explicit operator char *() const;

public:
	FCDC& operator<<(const char& c);
	FCDC& operator<<(const char* s);
	FCDC& operator<<(const std::string& s);
	FCDC& operator<<(LPCTSTR s);
	FCDC& operator<<(const CString& s);
	FCDC& operator<<(const CAtlString& s);
	FCDC& operator<<(const bool b);
	FCDC& operator<<(const int n);
	FCDC& operator<<(const long int n);
	FCDC& operator<<(const long long n);
	FCDC& operator<<(const double n);
	FCDC& operator<<(const long double n);
	FCDC& operator<<(const size_t n);

public:
	FCDC& operator<< (FCDC& (*op) (FCDC&));

public:
	template<typename T> FCDC& operator <<(const T& s);
	template<typename T> FCDC& operator <<(T* n);

};

FCDC& el(FCDC& dcstrm);


template<typename T>
FCDC& FCDC::operator <<(T* n) {
	CString s;
	CSize size;
	s.Format(_T("%p"), n);
	m_cdc->TextOutW(p.x, p.y, s);
	size = m_cdc->GetOutputTextExtent(s);
	p.x += size.cx;
	return *this;
};


template<typename T>
FCDC& FCDC::operator <<(const T& s) {
	std::ostringstream ostrs;
	ostrs << s;
	string cs;
	cs = ostrs.str();
	CString css;
	css = cs.c_str();
	CSize size;
	m_cdc->TextOutW(p.x, p.y, css);
	size = m_cdc->GetOutputTextExtent(css);
	p.x += size.cx;
	return *this;
};


