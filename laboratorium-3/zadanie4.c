#include <stdio.h>

int main() {
    int lower, upper;
    scanf("%d", &lower);
	scanf("%d", &upper);

    for (int a = lower; a <= upper; a++) {
        for (int b = a+1; b <= upper; b++) {
            for (int c = b+1; c <= upper; c++) {
                if (a*a + b*b == c*c) {
                    printf("%d  %d  %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
