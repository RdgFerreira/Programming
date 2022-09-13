#include <stdio.h>
#include <math.h>
#define lim pow(10, -6)

double fatorial (int n) {
	double fat = 1;
	for (int i = 2; i <= n; i++) fat *= i;
	return fat;
}

int main() {
    double indice = 1;
	double euler = indice;

	for(int i = 1; indice > lim; i++) {
		indice = 1.0 / fatorial(i);
		euler += indice;
	}
	
	printf("euler: %lf", euler);
	return 0;
}