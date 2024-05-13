#include <iostream>

using namespace std;

int* dynamicArray(int n) {
	int* dynamicArray = new int[n];

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		dynamicArray[i] = rand()%21 - 10;
	}

	return dynamicArray;
}

int main() {
	int n;
	cin >> n;

	int* myArray = dynamicArray(n);

	for (int i = 0; i < n; i++) {
		cout << myArray[i] << ", ";
	}

	delete [] myArray;

	return 0;
}