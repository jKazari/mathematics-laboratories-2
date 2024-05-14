#include <iostream>
#include <string>

using namespace std;

class Animal {
	string name;
	double weight;

	public:
		Animal(const string& n, int w) : name(n), weight(w) {}

	protected:
		void who() const {
			cout << "Name: " << name << ", Weight: " << weight << " pounds" << endl;
		}
};

class Lion : public Animal {
	public:
		Lion(const string& n, int w) : Animal(n, w) {}

		void who() const {
			Animal::who();
		}
};

class Aardvark : public Animal {
	public:
		Aardvark(const string& n, int w) : Animal(n, w) {}

		void who() const {
			Animal::who();
		}
};

int main() {
	Lion leo("Leo", 400);
    Aardvark algernon("Algernon", 50);

    leo.who();
    algernon.who();

	return 0;
}