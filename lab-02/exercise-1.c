// Zachariasz Jażdżewski 04.03.2024

#include <stdio.h>

int main() {

	float a;
	float b;
	float c;

	printf("Prosze podac dlugosci trzech odcinkow\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	if((a + b > c) && (b + c > a) && (a + c > b)) {
		printf("Z podanych odcinkow mozna skonstruowac trojkat");
	}
	else {
		printf("Z podanych odcinkow nie mozna skonstruowac trojkata");
	}

	return 0;
}