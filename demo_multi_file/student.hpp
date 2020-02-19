#ifndef __STUDENT_HPP___
#define __STUDENT_HPP___

#include <iostream>

namespace STUDENT {

	class Student {
	private:
		std::string m_name;
		int m_age;

	public:
		Student(std::string name, int age);
		~Student();
		void say();
	};

	extern void print(Student & stu);
};

#endif /* __STUDENT_HPP___ */
