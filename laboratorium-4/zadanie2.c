#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Input a positive natural number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Wrong input\n");
        return 1;
    }

    double inverse = 1.0/n;

    int counter = 1;
	do {
		if (counter >= 20) { 
            printf("More than 20 iterations\n");
            return 1;
        }
        counter++;
	}
    while ((1.0/pow(2, counter)) >= inverse);
	

    if (counter <= 20) {
        printf("(1/2)^%d = 1/%.0lf < 1/%d so n = %d\n", counter, pow(2,counter), n, counter);
    }

    return 0;
}
