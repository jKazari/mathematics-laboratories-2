#include <iostream>
#include <cmath>

#define MAX_DEGREE 100

using namespace std;

class Polynomial {
    public:
        int degree;
        double coefficients[MAX_DEGREE + 1];

        Polynomial() {
            degree = 0;
            for (int i = 0; i <= MAX_DEGREE; i++) {
                coefficients[i] = 0.0;
            }
        }

        Polynomial operator + (const Polynomial& other) const {
            Polynomial result;
            result.degree = max(degree, other.degree);
            for (int i = 0; i <= result.degree; i++) {
                result.coefficients[i] = coefficients[i] + other.coefficients[i];
            }
            return result;
        }

        Polynomial operator - (const Polynomial& other) const {
            Polynomial result;
            result.degree = max(degree, other.degree);
            for (int i = 0; i <= result.degree; i++) {
                result.coefficients[i] = coefficients[i] - other.coefficients[i];
            }
            return result;
        }

        Polynomial operator * (const Polynomial& other) const {
            Polynomial result;
            result.degree = degree + other.degree;
            for (int i = 0; i <= degree; i++) {
                for (int j = 0; j <= other.degree; ++j) {
                    result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
                }
            }
            return result;
        }

        friend ostream& operator << (ostream& os, const Polynomial& w) {
            bool firstTerm = true;
            for (int i = w.degree; i >= 0; i--) {
                double coefficient = w.coefficients[i];
                if (coefficient != 0) {
                    if (!firstTerm && coefficient > 0) {
                        os << " + ";
                    } else if (coefficient < 0) {
                        os << " - ";
                    }

                    if (abs(coefficient) != 1 || i == 0) {
                        os << abs(coefficient);
                    }

                    if (i > 0) {
                        os << "x";

                        if (i > 1) {
                            os << "^" << i;
                        }
                    }

                    firstTerm = false;
                }
            }
            if (firstTerm) {
                os << "0";
            }
            return os;
        }
};

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

    cout << "(" << p1 << ") + (" << p2 << ") = " << p1 + p2 << endl;
    cout << "(" << p1 << ") - (" << p2 << ") = " << p1 - p2 << endl;
    cout << "(" << p1 << ") * (" << p2 << ") = " << p1 * p2 << endl;

    return 0;
}
