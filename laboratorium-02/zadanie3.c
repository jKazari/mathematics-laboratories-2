// Zachariasz Jażdżewski 04.03.2024

#include <stdio.h>

int main() {
	
	float x;

	printf("Prosze podac liczbe\n");
	scanf("%f", &x);

	(1 <= x) && (x <= 10) ? printf("Funkcja należy do przedziału [1,10]") : printf("Funkcja nie należy do przedziału [1,10]");

	return 0;
}