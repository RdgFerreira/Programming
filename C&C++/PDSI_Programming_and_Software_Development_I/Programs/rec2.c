#include <stdio.h>

void foo(int a){
	if(a<0)
		return;
	//printf("\n%d", a); //3\n2\n1\n0
	foo(a-1);
	printf("\n%d", a); //0\n1\n2\n3
}

//n + n-1 + n-2 +...+ 1
int soma(int n){
	if(n<=0)
		return 0;
	return n + soma(n-1);
}

int main(){
	int a=5;
	foo(a);
	printf("\nSoma: %d", soma(a));
	return 0;
}