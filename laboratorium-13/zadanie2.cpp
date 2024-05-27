#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    private:
        double re;
        double im;

    public:
        Complex(double real = 0.0, double imag = 0.0) : re(real), im(imag) {}

        Complex operator + (const Complex& other) const {
            return Complex(re + other.re, im + other.im);
        }

        Complex operator - (const Complex& other) const {
            return Complex(re - other.re, im - other.im);
        }

        Complex operator * (const Complex& other) const {
            return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
        }

        Complex operator / (const Complex& other) const {
            double denom = other.re * other.re + other.im * other.im;
            return Complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
        }

        Complex& operator += (const Complex& other) {
            re += other.re;
            im += other.im;
            return *this;
        }

        Complex& operator -= (const Complex& other) {
            re -= other.re;
            im -= other.im;
            return *this;
        }

        Complex& operator *= (const Complex& other) {
            double new_re = re * other.re - im * other.im;
            double new_im = re * other.im + im * other.re;
            re = new_re;
            im = new_im;
            return *this;
        }

        Complex& operator /= (const Complex& other) {
            double denom = other.re * other.re + other.im * other.im;
            double new_re = (re * other.re + im * other.im) / denom;
            double new_im = (im * other.re - re * other.im) / denom;
            re = new_re;
            im = new_im;
            return *this;
        }

        Complex& operator ++ () {
            ++re;
            return *this;
        }

        Complex operator ++ (int) {
            Complex temp(*this);
            ++re;
            return temp;
        }

        Complex& operator -- () {
            --re;
            return *this;
        }

        Complex operator -- (int) {
            Complex temp(*this);
            --re;
            return temp;
        }

        bool operator < (const Complex& other) const {
            return this->modulus() < other.modulus();
        }

        bool operator > (const Complex& other) const {
            return this->modulus() > other.modulus();
        }

        bool operator == (const Complex& other) const {
            return re == other.re && im == other.im;
        }

        friend ostream& operator << (ostream& os, const Complex& z) {
            os << z.re;
            if (z.im >= 0) {
                os << " + " << z.im << "i";
            } else {
                os << " - " << -z.im << "i";
            }
            return os;
        }

    private:
        double modulus() const {
            return sqrt(re * re + im * im);
        }
};

int main() {
    Complex z1(3.0, 4.0);
    Complex z2(1.0, -2.0);

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << "z1 + z2 = " << z1 + z2 << endl;
    cout << "z1 - z2 = " << z1 - z2 << endl;
    cout << "z1 * z2 = " << z1 * z2 << endl;
    cout << "z1 / z2 = " << z1 / z2 << endl;

    z1 += z2;
    cout << "z1 += z2 = " << z1 << endl;

    z1 -= z2;
    cout << "z1 -= z2 = " << z1 << endl;

    z1 *= z2;
    cout << "z1 *= z2 = " << z1 << endl;

    z1 /= z2;
    cout << "z1 /= z2 = " << z1 << endl;

    ++z1;
    cout << "++z1 = " << z1 << endl;

    z1++;
    cout << "z1++ = " << z1 << endl;

    --z1;
    cout << "--z1 = " << z1 << endl;

    z1--;
    cout << "z1-- = " << z1 << endl;

    z1 < z2 ? cout << "|z1| < |z2|" << endl : cout << "|z1| >= |z2|" << endl;
    z1 > z2 ? cout << "|z1| > |z2|" << endl : cout << "|z1| <= |z2|" << endl;
    z1 == z2 ? cout << "|z1| == |z2|" << endl : cout << "|z1| != |z2|" << endl;

    return 0;
}
