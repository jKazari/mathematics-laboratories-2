#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	srand((unsigned) time(NULL));

	float macierz1[3][3];
	float macierz2[3][3];

	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			macierz1[i][j] = rand() % 1001;
			macierz2[i][j] = rand() % 1001;
		}
	}

	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			cout << left << setw(5) << macierz1[i][j];
		}
		cout << endl;
	}

	cout << endl << right << setw(7) << "+" << endl << endl; 

	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			cout << left << setw(5) << macierz2[i][j];
		}
		cout << endl;
	}

	cout << endl << right << setw(7) << "=" << endl << endl; 

	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			cout << left << setw(5) << macierz1[i][j] + macierz2[i][j];
		}
		cout << endl;
	}


	return 0;
}