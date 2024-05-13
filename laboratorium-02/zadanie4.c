// Zachariasz Jażdżewski 04.03.2024

#include <stdio.h>
#include <math.h>

int main() {
	
	float a, b, c;
	float delta;

	printf("Prosze podac wspolczynniki funkcji kwadratowej\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	delta = pow(b,2) - 4*a*c;

	if (delta > 0) {
		float x1, x2;
		x1 = (-b - sqrt(delta)) / 2;
		x2 = (-b + sqrt(delta)) / 2;

		printf("Funkcja posiada dwa miejsca zerowe:\n");
		printf("x1 = %f\n", x1);
		printf("x2 = %f", x2);
	}
	else if (delta == 0) {
		float x0;
		x0 = -b / 2*a;

		printf("Funkcja posiada dokladnie jedno miejsce zerowe:\n");
		printf("x0 = %f", x0);
	}
	else {
		printf("Funkcja nie posiada miejsc zerowych");
	}
	
	return 0;
}