#include <iostream>
#include "mystring.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	mystring s1("Hello"); // constructor
	mystring s2("World"); // constructor
	cout << s1 << endl;
	cout << s2 << endl;

	mystring s3(s1);      // copy constructor
	cout << s3 << endl;
	s3 = s2;              // copy assignment
	cout << s3 << endl;

	return 0;
}
