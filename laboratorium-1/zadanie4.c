#include <stdio.h>

int main() {
	int age;
	float shoe_size;
	
	printf("Prosze podac wiek: ");
	scanf("%d", &age);

	printf("Prosze podac rozmiar buta: ");
	scanf("%f", &shoe_size);

	printf("Podany wiek to %d, podany rozmiar buta to %f", age, shoe_size);

	return 0;
}