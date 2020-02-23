#ifndef __MYSTRING_HPP__
#define __MYSTRING_HPP__

#include <cstring>
#include <iostream>
using std::ostream;

class mystring {
public:
	mystring(const char *cstr = nullptr);         // constructor
	mystring(const mystring& str);                // copy constructor
	mystring& operator= (const mystring& str);    // copy assignment
	~mystring();                                  // destructor
	char *get_c_str() const { return m_data; }
private:
	char *m_data;
};

inline
mystring::mystring(const char *cstr) {
	if (cstr != nullptr) {
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	} else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline
mystring::mystring(const mystring& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline mystring&
mystring::operator= (const mystring& str) {
	if (this == &str)
		return *this;

	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;
}

inline mystring::~mystring() {
	delete[] m_data;
}

ostream& operator<< (ostream& os, const mystring& str) {
	return os << str.get_c_str();
}

#endif /* __MYSTRING_HPP__ */
