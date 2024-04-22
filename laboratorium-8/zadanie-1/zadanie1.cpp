#include <fstream>
#include <iomanip>
#include <ctime>

#define SIZE 5
#define MIN_VALUE -5
#define MAX_VALUE 5

using namespace std;

void generateRandomMatrix(const string& filename) {
    fstream file;
    
    file.open(filename, ios::out);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file << setw(2) << right << (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE << " ";
        }
        file << endl;
    }
    file.close();
}

void generateIdentityMatrix(const string& filename) {
    fstream file;

    file.open(filename, ios::out);
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
}

int main() {
    srand(time(NULL));

    generateRandomMatrix("matrix_a.txt");
    generateRandomMatrix("matrix_b.txt");
    generateIdentityMatrix("matrix_c.txt");

    return 0;
}
