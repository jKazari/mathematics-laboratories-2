#include <iostream>

using namespace std;

int main () {
	float m[2][2];
	float det;

	for (int i = 0; i < 2; i++) {
		for (int j=0; j < 2; j++) {
			cin >> m[i][j];
		}
	}

	det = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	if (det == 0) {
		cout << "Matrix is not invertable";
		return 0;
	}

	float inv[2][2] = {
		 m[1][1] / det, 
		-m[0][1] / det, 
		-m[1][0] / det, 
		 m[0][0] / det
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << inv[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}