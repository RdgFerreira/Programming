#include <stdio.h>

int main(){
	int x = 20;
	int *y;
	y = &x;
	//*y == conteudo de x.
	printf("\nConteudo de x = %d", x);
	printf("\nEndereco de x = %p", &x);
	printf("\nConteudo de y = %d", y);
	printf("\nEndereco de y = %p", &y);
	printf("\nConteudo do endereco apontado por y = %d\n", *y);
	int a = 0x0FF0; 
    int b = 0xFF00;
    int c;
 
    c = a << 4; printf("%04X << 4 = %04X\n", a, c);
    c = a >> 4; printf("%04X >> 4 = %04X\n", a, c);
    c = a & b;  printf("%04X & %04X = %04X\n", a, b, c);
 
    //Serão exibidos:
 
    //0FF0 << 4 = FF00
    //0FF0 >> 4 = 00FF
    //0FF0 & FF00 = 0F00
	return 0;
}

	


















