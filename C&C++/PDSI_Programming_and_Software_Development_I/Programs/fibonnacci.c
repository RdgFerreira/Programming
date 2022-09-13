#include <stdio.h>
#include <stdlib.h>

int count = 0;

int fib_iter(int n) {
	int a = 0, b = 1, i = 1;
	int c = a+b;

	while(i < n) {
		printf("\nExecutando fib(%d)...", c);
		c = a + b;
		a = b;
		b = c;
		i++;
	}

	return c;
}

int fib_rec(int n) {
	printf("\nExecutando fib(%d)...fib(%d)", n, count);
	count++;

	if(n <= 2) return 1;
	return fib_rec(n-1) + fib_rec(n-2);
}

int main() {
	int x;
	scanf("%d", &x);

	printf("\nIterativo: %d\n", fib_iter(x));
	system("PAUSE");
	printf("\nRecursivo: %d", fib_rec(x));

	return 0;
}