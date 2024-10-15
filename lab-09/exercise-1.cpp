#include <iostream>

using namespace std;

void switchValues(int* a, int* b) {
	int c = *b;
	*b = *a;
	*a = c;
}

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	cout << "Before switching values: " << a << ", " << b << endl;

	switchValues(&a,&b);

	cout << "After switching values: " << a << ", " << b;

	return 0;
}