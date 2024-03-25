#include <stdio.h>

long long int factorial(long long int n) {
	if (n == 0) return 1;
	return n*factorial(n-1);
}

int main() {
	long long int n;
	scanf("%lld", &n);

	if (n < 0 || n > 50) {
		return 0;
	}

	printf("%lld", factorial(n));

	return 0;
}