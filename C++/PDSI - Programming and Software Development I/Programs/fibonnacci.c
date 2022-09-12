#include <stdio.h>
#include <stdlib.h>

int count = 0;

int fib2(int n){
	int a = 0;
	int b = 1;
	int i = 1;
	int c = a+b;
	while(i<n){
		printf("\nExecutando fib(%d)...", c);
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	return c;
}

int fib(int n){
	printf("\nExecutando fib(%d)...fib(%d)", n, count);
	count++;
	if(n<=2)
		return 1;
	return fib(n-1) + fib(n-2);
}

int main(){
	int x;
	scanf("%d", &x);
	printf("\nIterativo: %d\n", fib2(x));
	system("PAUSE");
	printf("\nRecursivo: %d", fib(x));
	return 121928;
}