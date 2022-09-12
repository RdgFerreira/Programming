#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=0;
	float y=0.0;
	char z=' ';
	scanf("%d", &x);
	fflush(stdin);
	scanf("%f", &y);
	fflush(stdin);
	scanf("%c", &z);
	fflush(stdin);
	printf("int digitado = \'%d\'\n", x);
	printf("float digitado = \'%f\'\n", y);
	printf("char digitado = \'%c\'\n", z);
	return 0;
}