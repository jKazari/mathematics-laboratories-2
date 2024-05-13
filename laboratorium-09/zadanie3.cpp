#include <iostream>
#include <fstream>

using namespace std;

void randomMatrix(fstream& file, int n) {
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file << rand()%10 << " ";
		}
		file << endl;
	}
}

int main() {
	fstream file("matrix.txt", ios::out);
	int n;
	cin >> n;

	randomMatrix(file, n);

	return 0;
}