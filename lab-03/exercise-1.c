#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (i == n-1) {
			printf("%d", i*7);
			break;
		}
		printf("%d, ", i*7);
	}

	return 0;
}