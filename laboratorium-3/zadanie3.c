#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		printf(" ");
	}
	printf("X\n");
	
	for (int i = 2; i < n; i++) {
		for (int k = 0; k < n-i; k++) {
			printf(" ");
		}
		printf("X");
		for (int k = 0; k < i-2; k++) {
			printf(" ");
		}
		printf("X\n");
	}

	for (int i = 0; i < n; i++) {
		printf("X");
	}

	return 0;
}