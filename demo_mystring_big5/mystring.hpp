#ifndef __MYSTRING_HPP__
#define __MYSTRING_HPP__

#include <cstddef>
#include <iostream>
#include <cstring>

#undef __DEBUG__

#ifdef __DEBUG__
#define dprintf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define dprintf(fmt, ...)
#endif

class mystring {
public:
	// Ctor: constructor
	mystring(const char *cstr = nullptr) {
		dprintf("[Debug:Ctor] %s\n", cstr);
		Ctor++;
		if (cstr != nullptr) {
			m_len = strlen(cstr);
			m_data = new char[m_len + 1];
			strcpy(m_data, cstr);
		} else {
			m_len = 0;
			m_data = new char[1];
			*m_data = '\0';
		}
	}

	// CopyCtor: copy constructor
	mystring(const mystring& str) {
		dprintf("[Debug:CopyCtor] %s\n", str.m_data);
		CopyCtor++;
		m_len = str.m_len;
		m_data = new char[m_len + 1];
		strcpy(m_data, str.m_data);
	}

	// CopyAsgn: copy assignment
	mystring& operator= (const mystring& str) {
		dprintf("[Debug:CopyAsgn] %s -> %s\n", str.m_data, m_data);
		CopyAsgn++;
		if (this == &str)
			return *this;

		if (m_data != nullptr)
			delete[] m_data;
		m_len = str.m_len;
		m_data = new char[m_len + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}

	// MoveCtor: move constructor
	mystring(mystring&& str) noexcept :
		m_len(str.m_len),
		m_data(str.m_data) {
		dprintf("[Debug:MoveCtor] %s -> %s\n", str.m_data, m_data);
		MoveCtor++;
		str.m_len = 0;
		str.m_data = nullptr;
	}

	// MoveAsgn: move assignment
	mystring& operator= (mystring&& str) noexcept {
		dprintf("[Debug:MoveAsgn] %s -> %s\n", str.m_data, m_data);
		MoveAsgn++;
		if (this == &str)
			return *this;

		if (m_data != nullptr)
			delete[] m_data;
		m_len = str.m_len;
		m_data = str.m_data;
		str.m_len = 0;
		str.m_data = nullptr;
		return *this;
	}

	// Dtor: destructor
	~mystring() {
		dprintf("[Debug:Dtor] %s\n", m_data);
		Dtor++;
		if (m_data != nullptr)
			delete[] m_data;
	}

	char *get_c_str() const {
		return m_data;
	}

	// 类内静态成员函数：没有this指针，也不能加const声明
	static void output_big5_cnt();
	static void reset_big5_cnt();

private:
	char *m_data = nullptr;
	size_t m_len = 0;

	// 类内静态成员：不能在类内部初始化静态成员
	static size_t Ctor;      // constructor count
	static size_t CopyCtor;  // copy constructor count  1/5
	static size_t CopyAsgn;  // copy assignment count   2/5
	static size_t MoveCtor;  // move constructor count  3/5
	static size_t MoveAsgn;  // move assignment count   4/5
	static size_t Dtor;      // destructor count        5/5
};

// 操作符重载函数声明
std::ostream&
operator<< (std::ostream& os, const mystring& str);

#endif /* __MYSTRING_HPP__ */
