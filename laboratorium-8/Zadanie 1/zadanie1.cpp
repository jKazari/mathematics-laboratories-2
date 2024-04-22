#include <fstream>
#include <iomanip>

#define SIZE 5

using namespace std;

int main() {
	srand(time(NULL));
	fstream file;

	file.open("A.txt", ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			file << setw(2) << right << (rand() % 11) - 5 << " ";
		}
		file << endl;
	}
	file.close();

	file.open("B.txt", ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			file << setw(2) << right << (rand() % 11) - 5 << " ";
		}
		file << endl;
	}
	file.close();

	file.open("C.txt", ios::out);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) {
				file << 1 << " ";
			}
			else {
				file << 0 << " ";
			}
		}
		file << endl;
	}
	file.close();

	return 0;
}