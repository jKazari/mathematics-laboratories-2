#include <stdio.h>

void draw_square(int n) {
	for (int i=0; i < n; i++) {
		for (int j=0; j < n; j++) {
			if (i == 0 || i == n-1) {
				printf("# ");
			}
			else if (j == 0 || j == n - 1) {
				printf("# ");
			}
			else if (n > 8 && (i == j || i == n - 1 - j)) {
				printf("# ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("Input square side length: ");
	scanf("%d", &n);

	if (n < 1) {
		printf("Side length should be natural and positive.");
		return 0;
	}

	draw_square(n);

	return 0;
}