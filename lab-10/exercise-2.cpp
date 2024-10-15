#include <iostream>
#include <cmath>

#define MAX_DEGREE 100

using namespace std;

struct Polynomial {
	int degree;
	double coefficients[MAX_DEGREE + 1];

	Polynomial() {
        degree = 0;
        for (int i = 0; i <= MAX_DEGREE; ++i) {
            coefficients[i] = 0.0;
        }
    }
};

Polynomial sum(Polynomial p1, Polynomial p2) {
	Polynomial polynomial_sum;
	polynomial_sum.degree = max(p1.degree, p2.degree);
	for (int i = 0; i <= polynomial_sum.degree; i++) {
        polynomial_sum.coefficients[i] = p1.coefficients[i] + p2.coefficients[i];
    }
    return polynomial_sum;
}

Polynomial difference(Polynomial p1, Polynomial p2) {
	Polynomial polynomial_sum;
	polynomial_sum.degree = max(p1.degree, p2.degree);
	for (int i = 0; i <= polynomial_sum.degree; i++) {
        polynomial_sum.coefficients[i] = p1.coefficients[i] - p2.coefficients[i];
    }
    return polynomial_sum;
}

Polynomial product(Polynomial p1, Polynomial p2) {
    Polynomial polynomial_sum;
    polynomial_sum.degree = p1.degree + p2.degree;
    for (int i = 0; i <= p1.degree; ++i) {
        for (int j = 0; j <= p2.degree; ++j) {
            polynomial_sum.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
        }
    }
    return polynomial_sum;
}

void print(Polynomial p) {
    bool firstTerm = true;

    for (int i = p.degree; i >= 0; i--) {
        double coefficient = p.coefficients[i];
        if (coefficient != 0) {
            if (!firstTerm && coefficient > 0) {
                cout << " + ";
            }
			else if (coefficient < 0) {
                cout << " - ";
            }

            if (abs(coefficient) != 1 || i == 0) {
                cout << abs(coefficient);
            }

            if (i > 0) {
                cout << "x";

                if (i > 1) {
                    cout << "^" << i;
                }
            }

            firstTerm = false;
        }
    }
}

int main() {
    Polynomial p1, p2;
    p1.degree = 3;
    p1.coefficients[0] = 1;
    p1.coefficients[1] = 2;
    p1.coefficients[2] = 3;
    p1.coefficients[3] = 4;

    p2.degree = 2;
    p2.coefficients[0] = 2;
    p2.coefficients[1] = 1;
    p2.coefficients[2] = 3;

    Polynomial polynomial_sum = sum(p1, p2);
    Polynomial polynomial_difference = difference(p1, p2);
    Polynomial polynomial_product = product(p1, p2);

	cout << "(";
    print(p1);
	cout << ") + (";
	print(p2);
	cout << ") = ";
	print(polynomial_sum);
	cout << endl;

	cout << "(";
    print(p1);
	cout << ") - (";
	print(p2);
	cout << ") = ";
	print(polynomial_difference);
	cout << endl;

	cout << "(";
    print(p1);
	cout << ") * (";
	print(p2);
	cout << ") = ";
	print(polynomial_product);
	cout << endl;

	return 0;
}