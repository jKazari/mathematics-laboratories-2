#include <stdio.h>

int main() {
	int a;
	printf("Please input a positive integer: ");
	scanf("%d", &a);

	if (a <= 0) {
		printf("Wrong input");
		return 0;
	}

	int i = 1;
	int counter = 0;
	while (a-i >= 0) {
		a -= i;
		i += 2;
		counter++;
	}
	

	if (a == 0) {
		printf("Given number is the square of %d", counter);
	}
	else {
		printf("Given number is not a square number");
	}

	return 0;
}