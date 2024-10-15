#include <fstream>
#include <iostream>
#include <iomanip>

#define SIZE 5

using namespace std;

void readMatrixFromFile(const string& filename, int matrix[SIZE][SIZE]) {
    fstream file;
    file.open(filename, ios::in);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
}

int main() {
	fstream file;

	int matrix_a[SIZE][SIZE];
	int matrix_b[SIZE][SIZE];
	int matrix_c[SIZE][SIZE];

	readMatrixFromFile("matrix_a.txt", matrix_a);
    readMatrixFromFile("matrix_b.txt", matrix_b);
    readMatrixFromFile("matrix_c.txt", matrix_c);

	file.open("matrix_d.txt", ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			file << matrix_b[j][i] << " ";
		}
		file << endl;
	}
	file.close();

	file.open("matrix_e.txt", ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int b_times_a = 0;
			for (int k = 0; k < SIZE; k++) {
				b_times_a += matrix_b[i][k] * matrix_a[k][j];
			}
			b_times_a -= matrix_c[i][j];

			file << setw(3) << left << b_times_a << " ";
		}
		file << endl;
	}
	file.close();

	return 0;
}