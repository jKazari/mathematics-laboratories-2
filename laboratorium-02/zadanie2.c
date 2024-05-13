// Zachariasz Jażdżewski 04.03.2024

#include <stdio.h>

int main() {

	int rok;

	printf("Prosze podac rok\n");
	scanf("%d",&rok);

	if (((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0)) {
		printf("Podany rok jest przestepny");
	}
	else {
		printf("Podany rok nie jest przestepny");
	}

	return 0;
}