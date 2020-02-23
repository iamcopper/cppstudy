#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

#include <iostream>

class mycomplex {
public:
	mycomplex(double r = 0, double i = 0) :re(r), im(i) { }

	double real() const { return re; }
	double imag() const { return im; }
	mycomplex& operator+= (const mycomplex& r);
	mycomplex& operator+= (const double& r);

private:
	double re, im;

// 类的友元函数声明:
// 友元函数声明可以放在类内任意位置；
// 声明后该函数就可以直接操作类的Private数据域；
friend mycomplex& __doapl(mycomplex& ths, const mycomplex& r);
};

inline mycomplex&
__doapl(mycomplex& l, const mycomplex& r) {
	l.re += r.re;
	l.im += r.im;
	return l;
}

// 操作符重载-类成员函数
// 返回引用：将传入的数据，再以引用返回
inline mycomplex&
mycomplex::operator+= (const mycomplex& r) {
	return __doapl(*this, r);
}

inline mycomplex&
mycomplex::operator+= (const double& r) {
	this->re += r;
	return *this;
}

// 操作符重载-类非成员函数
// 不可返回引用：不可将临时对象作为引用返回
inline mycomplex
operator+ (const mycomplex& x, const mycomplex& y) {
	return mycomplex(x.real() + y.real(), x.imag() + y.imag());
}

inline mycomplex
operator+ (const double& x, const mycomplex& y) {
	return mycomplex(x + y.real(), y.imag());
}

inline mycomplex
operator+ (const mycomplex& x, const double& y) {
	return mycomplex(x.real() + y, x.imag());
}

inline mycomplex
operator- (const mycomplex& x) {
	return mycomplex(-x.real(), -x.imag());
}

inline bool
operator== (const mycomplex& x, const mycomplex& y) {
	return x.real() == y.real() && x.imag() == y.imag();
}

inline bool
operator!= (const mycomplex& x, const mycomplex& y) {
	return x.real() != y.real() || x.imag() != y.imag();
}

std::ostream&
operator<< (std::ostream& os, const mycomplex& x) {
	return os << '(' << x.real() << ',' << x.imag() << ')';
}

#endif /* __COMPLEX_HPP__ */
