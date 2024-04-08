#include <iostream>
#include <math.h>

#define LIMIT 20

using namespace std;

int main () {
	int n;
	cin >> n;

	if(n == 0) {
		cout << "0";
		return 0;
	}
	
	int tab[LIMIT*sizeof(n)];
	int i = 0;
	int length = 0;
	while(n != 0) {
		tab[i] = n%10;
		n /= 10;
		length++;
		i++;
	}

	int decimal = 0;
	for (int i=0; i < length; i++) {
		decimal += tab[i] * pow(8,i);
	}

	cout << decimal;

	return 0;
}