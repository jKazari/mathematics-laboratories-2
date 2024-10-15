#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Shape {
	protected:
		string name;
	public:
		Shape() {
			name = "Shape";
		}
		Shape(string n) {
			name = n;
		}
		virtual double perimeter() = 0;
		virtual double area() = 0;
		void printInfo() {
			cout << name << " with area " << area() << " and perimeter " << perimeter() << "." << endl;
		}
};

class Circle : public Shape {
	protected:
		double radius;
	public:
		Circle() {
			radius = 0;
			name = "Circle";
		}
		Circle (double r) {
			radius = r;
			name = "Circle";
		}
		Circle (double r, string n) {
			radius = r;
			name = n;
		}
		virtual double perimeter() {
			return 2 * M_PI * radius;
		}
		virtual double area() {
			return M_PI * radius * radius;
		}
};

class Square : public Shape {
	protected:
		double side;
	public:
		Square() {
			side = 0;
			name = "Square";
		}
		Square(double s) {
			side = s;
			name = "Square";
		}
		Square(double s, string n) {
			side = s;
			name = n;
		}
		virtual double perimeter() {
			return 4 * side;
		}
		virtual double area() {
			return side * side;
		}
};

class Triangle : public Shape {
	protected:
		double a, b, c;
	public:
		Triangle() {
			a = b = c = 0;
			name = "Triangle";
		}
		Triangle(double a, double b, double c) {
			this->a = a;
			this->b = b;
			this->c = c;
			name = "Triangle";
		}
		Triangle(double a, double b, double c, string n) {
			this->a = a;
			this->b = b;
			this->c = c;
			name = n;
		}
		virtual double perimeter() {
			return a + b + c;
		}
		virtual double area() {
			double s = (a + b + c) / 2;
			return sqrt(s * (s-a) * (s-b) * (s-c));
		}
};

int main() {
	Square s(6);
	s.printInfo();

	Triangle t(3,4,5);
	t.printInfo();

	Circle c(5);
	c.printInfo();
	return 0;
}