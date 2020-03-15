#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Shape {
public:
	virtual void draw() = 0;
	virtual int SizeOf() {
		return sizeof(Shape);
	}
};

class Rect : public Shape {
public:
	void draw() {
		cout << "Rect" << endl;
	}
	virtual int SizeOf() {
		return sizeof(Rect);
	}

private:
	int length, height;
};

class Square : public Rect {
public:
	void draw() {
		cout << "Square" << endl;
	}
	virtual int SizeOf() {
		return sizeof(Square);
	}
};

class Ellipse : public Shape {
public: 
	void draw() {
		cout << "Ellipse" << endl;
	}
	virtual int SizeOf() {
		return sizeof(Ellipse);
	}
private:
	int x, y;
	int r1, r2;
};

class Circle : public Ellipse {
public:
	void draw() {
		cout << "Circle" << endl;
	}
	virtual int SizeOf() {
		return sizeof(Circle);
	}
};

void drawAll(const vector<Shape*>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << sizeof(*(v[i])) << ' ';
		cout << v[i]->SizeOf() << ' ';
		v[i]->draw();
	}
}

int main(int argc, char *argv[])
{
	Rect r1;
	Square q1;

	r1.draw();
	q1.draw();

	Rect* pr = new Rect();
	pr->draw();
	delete pr;

	cout << sizeof(Shape) << endl;
	cout << sizeof(Rect) << endl;
	cout << sizeof(Square) << endl;
	cout << sizeof(Ellipse) << endl;
	cout << sizeof(Circle) << endl;

	vector<Shape*> v;
	v.push_back(&r1);
	v.push_back(&q1);
	v.push_back(new Circle);
	v.push_back(new Ellipse);
	drawAll(v);

	return 0;
}
