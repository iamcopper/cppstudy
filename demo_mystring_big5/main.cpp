#include <iostream>
#include "mystring.hpp"

using std::cout;
using std::endl;

// Ctor 1
void func1() {
	cout << "------func1 Ctor------" << endl;
	mystring str = "Hello";					// Ctor:1
	cout << "str=" << str << endl;
											// When the variable "str" leaving its effective scope,
											// its destructor func is automaticlly called.
											// Dtor:1
}

// Ctor 2
void func2() {
	cout << "------func2 Ctor------" << endl;
	mystring *pstr = new mystring("Hello");	// Ctor:1	("new" == alloc memory -> constructor)
	cout << "*pstr=" << *pstr << endl;
	delete pstr;							// Dtor:1	("delete" == destructor -> free memory)
}

// CopyCtor
void func3() {
	cout << "------func3 CopyCtor------" << endl;
	mystring str1("Hello");					// Ctor:1
	mystring str2(str1);					// CopyCtor:1
	
											// Dtor:1 + 1	(destructor str1, str2 when leaving effective scope)
}

// CopyAsgn
void func4() {
	cout << "------func4 CopyAsgn------" << endl;
	mystring str1("AAA");					// Ctor:1
	mystring str2("BBB");					// Ctor:1
	cout << ">>> Before CopyAsgn:" << endl;
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;

	str1 = str2;							// CopyAsgn:1	(copy assign from str1 to str2)
	cout << ">>> After CopyAsgn: str2 -> str1" << endl;
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
											// Dtor:1 + 1	(destructor str1, str2 when leaving effective scope)
}

// MoveCtor
void func5() {
	cout << "------func5 MoveCtor------" << endl;
	mystring str1("AAA");					// Ctor:1
	cout << ">>> Before MoveCtor:" << endl;
	cout << "str1=" << str1 << endl;

	mystring str2(std::move(str1));			// MoveCtor:1	(move constructor str2 from str1,
											//				str1 is move to str2, cann't acces str1 now)

	cout << ">>> After MoveCtor: str1 -> str2" << endl;
	cout << "str2=" << str2 << endl;
											// Dtor:1 + 1	(destructor str1, str2 when leaving effective scope)
}

// MoveAsgn 1
void func6() {
	cout << "------func6 MoveAsgn 1------" << endl;
	mystring str1("AAA");					// Ctor:1
	mystring str2("BBB");					// Ctor:1
	cout << ">>> Before MoveAsgn:" << endl;
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;

	str1 = std::move(str2);					// MoveAsgn:1	(move assign from str2 to str1,
											//				str2 is move to str1, cann't acces str2 now)

	cout << ">>> After MoveAsgn: str2 -> str1" << endl;
	cout << "str1=" << str1 << endl;
											// Dtor:1 + 1	(destructor str1, str2 when leaving effective scope)
}

// MoveAsgn 2
void func7() {
	cout << "------func7 MoveAsgn 2------" << endl;
	mystring str("AAA");					// Ctor:1
	cout << ">>> Before MoveAsgn:" << endl;
	cout << "str=" << str << endl;

	str = "Hello";							// Ctor:1		(1. constructor a temp mystring "Hello")
											// MoveAsgn:1	(2. move assign from the temp mystring to str)
											// Dtor:1		(3. destructor the temp mystring)
	cout << ">>> After MoveAsgn: \"Hello\" -> str" << endl;
	cout << "str=" << str << endl;
											// Dtor:1		(destructor the str when leaving effective scope)
}

int main(int argc, char *argv[])
{
	func1();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func2();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func3();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func4();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func5();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func6();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	func7();
	mystring::output_big5_cnt();
	mystring::reset_big5_cnt();

	return 0;
}
