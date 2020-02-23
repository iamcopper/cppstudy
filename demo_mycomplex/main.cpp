#include <iostream>
#include "mycomplex.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	mycomplex c1(2, 4);
	mycomplex c2;
	cout << "c1 = " <<  c1 << endl;
	cout << "c2 = " << c2 << endl;

	c2 += c1;
	c2 += 3;

	c2 = c1 + c2;
	c2 = 7 + c1;
	c2 = c1 + 5;
	c2 = -c1;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	cout << "(c1 == c2) = "<< (c1 == c2) << endl;
	cout << "(c1 != c2) = " << (c1 != c2) << endl;

	return 0;
}
