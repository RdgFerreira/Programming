#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	int x;
	short int y;
	char a;
	unsigned char b;
	
	x = pow(2,31) - 1; //maior int possível
	y = pow(2,15) - 1; // maior short int possível
	
	printf("Maior int = %d, Maior short int = %d\n", x, y);
	x += 1;//overflow
	y += 1;//overflow
	
	printf("Maior int + 1 = %d, Maior short int + 1 = %d\n", x, y);
	a = pow(2,7) - 1;
	b = pow(2,8) - 1;
	
	printf("Maior char = %d, Maior unsigned char = %d\n", x, y);
	a += 1;//overflow
	b += 1;//overflow
	
	printf("Maior char + 1 = %d, Maior unsigned char + 1 = %d\n", x, y);
	system("PAUSE");
	return 0;
}