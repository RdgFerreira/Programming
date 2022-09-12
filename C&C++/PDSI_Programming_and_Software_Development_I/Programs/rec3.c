#include <stdio.h>

int fat(int n){
	if(n<=1)
		return 1;
	return n * fat(n-1);
}

int fib(int n){
	if(n<=2)
		return 1;
	return fib(n-1) + fib(n-2);
}


int main(){
	int x=0;
	scanf("%d", &x);
	printf("%d! = %d\n", x, fat(x));
	printf("fib(%d) = %d\n", x, fib(x));
}