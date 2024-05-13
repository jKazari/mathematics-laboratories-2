#include <iostream>

using namespace std;

class Counting {
	private:
		static int counter;
	public:
		Counting() {
			counter++;
		}

		static void howMuch() {
			cout << counter;
		}
};

int Counting::counter = 0;

int main() {
	Counting c1;
	Counting c2;
	Counting c3;

	Counting::howMuch();

	return 0;
}
