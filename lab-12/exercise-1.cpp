#include <iostream>
#include <string>

using namespace std;

class Bird {
	protected:
		string division;
		bool migrating;
	public:
		Bird() {
			division = "default";
			migrating = false;
		}
		Bird(string d, bool m) {
			division = d;
			migrating = m;
		}
};

class Corvidae : public Bird {
	protected:
		string order;
	public:
		Corvidae() {
			division = "default";
			order = "default";
			migrating = false;
		}
		Corvidae(string d, string o, bool m) {
			division = d;
			order = o;
			migrating = m;
		}
};

class Rook : public Corvidae {
	protected:
		string family;
		string species;
	public:
		Rook(string d, string o, string f, string s, bool m) {
			division = d;
			order = o;
			family = f;
			species = s;
			migrating = m;
		}
		void printInformation() {
			cout << "Division: " << division << endl;
			cout << "Order: " << order << endl;
			cout << "Family: " << family << endl;
			cout << "Species: " << species << endl;
			cout << "Migrates? ";
			migrating ? cout << "Yes" : cout << "No";
		}
};

int main() {
	Rook my_rook("Aves", "Passeriformes", "Corvidae", "Corvus frugilegus", false);

	my_rook.printInformation();

	return 0;
}