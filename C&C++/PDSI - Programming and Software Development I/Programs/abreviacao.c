#include <stdio.h>

int main(){
	char abreviacao[128];
	char c;
	printf("Digite um nome e termine com ponto: \n");
	int i = 0, j = 1;
	do {
		c = getc(stdin);
		if (c == '.')
			break;
		if (c<=90 && c>=65){
			printf("%c.", c);
		}
	} while(1);
	return 0;
}

