#include <stdio.h>
#include <math.h>

int main() {

	int lower_bound = 10;
	int upper_bound = 30;
	int a, b, c = 0;
	int m = 2;

	while (c <= upper_bound) {
		for (int n = 1; n < m; n++) {
			a = m*m - n*n;
			b = 2*m*n;
			c = m*m + n*n;

			if (c > upper_bound) {
				break;
			}

			if (a >= lower_bound && b >= lower_bound) {
				printf("%d %d %d\n", a, b, c);
			}
		}
		m++;
	}

	return 0;
}
