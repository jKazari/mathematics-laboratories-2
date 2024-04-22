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

void transposeMatrix(int matrix[SIZE][SIZE]) {
    int matrix_t[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix_t[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = matrix_t[i][j];
        }
    }
}

void writeMatrixToFile(const string& filename, int matrix[SIZE][SIZE], int number_size) {
	fstream file;
	file.open(filename, ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			file << setw(number_size) << left << matrix[i][j] << " ";
		}
		file << endl;
	}
	file.close();
}

int main() {
	fstream file;

	int matrix_a[SIZE][SIZE];
	int matrix_b[SIZE][SIZE];
	int matrix_c[SIZE][SIZE];

	readMatrixFromFile("AA.txt", matrix_a);
    readMatrixFromFile("BB.txt", matrix_b);
    readMatrixFromFile("CC.txt", matrix_c);

	transposeMatrix(matrix_b);

	writeMatrixToFile("D.txt", matrix_b, 1);

	file.open("E.txt", ios::out);
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