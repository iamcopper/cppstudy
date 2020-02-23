#include <iostream>
#include <cstring>
#include <cstddef>
#include "mystring.hpp"

using std::cout;
using std::endl;

size_t mystring::Ctor = 0;      // constructor count
size_t mystring::CopyCtor = 0;  // copy constructor count  1/5
size_t mystring::CopyAsgn = 0;  // copy assignment count   2/5
size_t mystring::MoveCtor = 0;  // move constructor count  3/5
size_t mystring::MoveAsgn = 0;  // move assignment count   4/5
size_t mystring::Dtor = 0;      // destructor count        5/5

// 此处没有static关键字, 已在类内声明过, 详见《C++ Primer》P269-270
// 在类的外部定义静态成员，不能重复static关键字，
// 该关键字只出现在类内部的声明语句中。
void mystring::output_big5_cnt() {
	cout << "Ctor:     " << Ctor << endl
		 << "CopyCtor: " << CopyCtor << endl
		 << "CopyAsgn: " << CopyAsgn << endl
		 << "MoveCtor: " << MoveCtor << endl
		 << "MoveAsgn: " << MoveAsgn << endl
		 << "Dtor:     " << Dtor << endl;
}

void mystring::reset_big5_cnt() {
	Ctor = 0;
	CopyCtor = 0;
	CopyAsgn = 0;
	MoveCtor = 0;
	MoveAsgn = 0;
	Dtor = 0;
}

std::ostream&
operator<< (std::ostream& os, const mystring& str) {
	return os << str.get_c_str();
}
