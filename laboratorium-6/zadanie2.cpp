#include <iostream>
#include <math.h>

#define LIMIT 20

using namespace std;

int main() {
    int octal;
    int octal_digits[LIMIT];

    cin >> octal;

    int i = 0;
	int length = 0;
    while (octal != 0) {
        octal_digits[i] = octal % 10;
        octal /= 10;
		length++;
        i++;
    }

    int decimal = 0;
    for (int i = 0; i < length; i++) {
        decimal += octal_digits[i] * pow(8, i);
    }

    cout << decimal;

    return 0;
}