#include <iostream>

using namespace std;

int wykladnik (int podstawa, int wyk1) {
	int wartosc_narast = 1; // było 'int wartosc_narast' 
	for (int i = 0; i < wyk1; i++) {
		wartosc_narast *= podstawa;
	}
	return wartosc_narast; // było 'return podstawa'
}

int main() {
	int podstawa;
	int wyk1;

	cout << "Podaj podstawe:";
	cin >> podstawa;
	cout << "Podaj wykladnik:";
	cin >> wyk1;
	cout << wykladnik(podstawa, wyk1); // było 'cout << wykladnik (wyk1, podstawa)'
}