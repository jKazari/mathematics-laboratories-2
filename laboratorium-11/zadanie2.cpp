#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
	private:
		double a, b;
	public:
		Rectangle() {
			a = 1;
			b = 1;
		}

		Rectangle(double x) {
			a = x;
			b = x;
		}

		Rectangle(double x, double y) {
			a = x;
			b = y;
		}

		double getA() {
			return a;
		}

		double getB() {
			return b;
		}

		double diagonal() {
			return sqrt(pow(a,2) + pow(b,2));
		}

		double area() {
			return a * b; 
		}

		double circumference() {
			return 2*a + 2*b;
		}

		double isBiggerThan(Rectangle& r) {
			return this->area() > r.area();
		}

		void info() {
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "Diagonal = " << this->diagonal() << endl;
			cout << "Area = " << this->area() << endl;
			cout << "Circumference = " << this->circumference() << endl << endl;
		}
};

int main() {
	Rectangle r1;
	Rectangle r2(2);
	Rectangle r3(3,4);

	cout << "Rectangle r1: " << endl;
	r1.info();
	cout << "Rectangle r2: " << endl;
	r2.info();
	cout << "Rectangle r3: " << endl;
	r3.info();

	cout << "Side a of r3 = " << r3.getA() << endl;
	cout << "Side b of r3 = " << r3.getB() << endl;
	cout << "Diagonal of r3 = " << r3.diagonal() << endl;
	cout << "Area of r3 = " << r3.area() << endl;
	cout << "Circumference of r3 = " << r3.circumference() << endl;
	
	cout << "r3 bigger than r2? "; 
	r3.isBiggerThan(r2) ? cout << "True" : cout << "False";

	return 0;
}