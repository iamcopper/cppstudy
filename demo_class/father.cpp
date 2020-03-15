/*
 * C++ 类demo: 包括类继承的特点，多态，以及vector的使用
 */
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Father {
public:
	Father(string name, int age) :
		name_(name), age_(age)
	{ }

	virtual ~Father() { }

	/* 父类虚方法被子类继承，可以被子类重写 */
	virtual void Hello(void)
	{
		cout << "Father say hello..." << endl;
		cout << "  [Father Access Father Attribute] name:" << name_ << ", age:" << age_ << endl;
	}

	/* 父类public非虚方法被子类直接访问继承，不能被子类重写 */
	void Run(void)
	{
		cout << "Father running..." << endl;
	}

// 父类protected属性可以被子类直接访问
protected:
	string name_;
	int    age_;
};

class Son1 : public Father {
public:
	Son1(string name, int age) :
		Father(name, age)
	{ }

	virtual void Hello(void)
	{
		cout << "Son1 say hello..." << endl;
		cout << "  [Son1 Access Father Attribute] name:" << Father::name_ << ", age:" << Father::age_ << endl;
		cout << "  [Son1 Access Father Attribute] name:" << name_ << ", age:" << age_ << endl;
	}

	/* 直接调用父类public方法 */
	void CallFatherRun(void)
	{
		cout << "Son1 call father run: --->" << endl;
		Run();
	}
};

class Son2 : public Father {
public:
	Son2(string name, int age) :
		Father("Father:" + name, age), name_("Son2:" + name), age_(age)
	{ }

	/* 子类重写父类虚方法 */
	virtual void Hello(void)
	{
		cout << "Son2 say hello..." << endl;
		cout << "  [Son2 Access Father Attribute] name:" << Father::name_ << ", age:" << Father::age_ << endl;
		cout << "  [Son2 Access Son2 Attribute]   name:" << Son2::name_ << ", age:" << Son2::age_ << endl;
		cout << "  [Son2 Access Son2 Attribute]   name:" << name_ << ", age:" << age_ << endl;
	}

/*
 * 子类有与父类同名属性，不指定命名空间时，默认访问子类属性；
 * 若需要访问父类属性，则需要显示指明父类命名空间,如：Father::xxx;
 */
protected:
	string name_;
	int    age_;
};

int main(int argc, char *argv[])
{
	Father f("Tom", 55);
	f.Hello();

	Son1 s1("Jerry1", 3);
	s1.Hello();
	s1.CallFatherRun();

	Son2 s2("Jerry2", 4);
	s2.Hello();


	cout << "------------use vector-------------" << endl;
	vector<Father*> vec{&f, &s1, &s2};
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		/* 迭代器类型：是一个指向该容器所存放的类型的指针 */
		(*it)->Hello();
	}

	return 0;
}
