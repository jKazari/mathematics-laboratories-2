#include <stdio.h>
#include <math.h>

typedef struct {
	double a, b, c;
} Vector;

int are_same(Vector v, Vector u) {
	return (v.a == u.a && v.b == u.b && v.c == u.c);
}

void print_vector(Vector v) {
	printf("[%.2lf, %.2lf, %.2lf]", v.a, v.b, v.c);
}

double vector_length(Vector v) {
	return sqrt(pow(v.a,2) + pow(v.b,2) + pow(v.c,2)); 
}

Vector add_vectors(Vector v, Vector u) {
	Vector w = {v.a + u.a, v.b + u.b, v.c + u.c};
	return w;
}

Vector subtract_vectors(Vector v, Vector u) {
	Vector w = {v.a - u.a, v.b - u.b, v.c - u.c};
	return w;
}

double dot_product(Vector v, Vector u) {
	return v.a*u.a + v.b*u.b + v.c*u.c;
}

Vector cross_product(Vector v, Vector u) {
	Vector w = {v.b*u.c - v.c*u.b, -v.a*u.c + v.c*u.a, v.a*u.b - v.b*u.a};
	return w;
}

int are_perpendicular(Vector v, Vector u) {
	return (dot_product(v, u) == 0);
}

int are_paralell(Vector v, Vector u) {
	Vector zero = {0,0,0};
	return are_same(cross_product(v, u), zero);
}

void input_vector(Vector *v, const char *label) {
    printf("%s = ", label);
    char input[100];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "[%lf, %lf, %lf]", &(v->a), &(v->b), &(v->c));
}

int main() {
	Vector v1, v2;

    // Input vectors
    input_vector(&v1, "v1");
    input_vector(&v2, "v2");
	printf("\n");

	// Length
	printf("|v1| = %.2lf\n", vector_length(v1));
	printf("|v2| = %.2lf\n\n", vector_length(v2));

	// Sum of vectors
	printf("v1 + v2 = ");
	print_vector(add_vectors(v1, v2));
	printf("\n");

	// Difference of vectors
	printf("v1 - v2 = ");
	print_vector(subtract_vectors(v1, v2));
	printf("\n\n");

	// Dot product
	printf("v1 o v2 = %.2lf => ", dot_product(v1, v2));

	// Perpendicular?
	if (are_perpendicular(v1, v2)) {
		printf("vectors are perpendicular\n");
	}
	else {
		printf("vectors are not perpendicular\n");
	}

	// Cross product
	printf("v1 x v2 = ");
	print_vector(cross_product(v1, v2));
	printf(" => ");
	
	// Paralell?
	if (are_paralell(v1, v2)) {
		printf("vectors are paralell\n\n");
	}
	else {
		printf("vectors are not paralell\n\n");
	}

	return 0;
}