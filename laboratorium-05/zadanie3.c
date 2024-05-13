#include <stdio.h>

long long int factorial(long long int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

long long int binom_coeff(long long int n, long long int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void draw_pascal_triangle(int n) {
    for (int i=0; i < n+1; i++) {
        for (int s=0; s < (n-i)*2; s++) {
            printf(" ");
        }
        for (int j=0; j <= i; j++) {
            printf("%-4lld", binom_coeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    int n;
	printf("Give a number of rows: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Wrong input");
		return 0;
	}
    
    draw_pascal_triangle(n);
    
    return 0;
}
