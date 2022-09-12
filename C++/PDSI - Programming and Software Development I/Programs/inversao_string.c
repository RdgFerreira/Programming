#include <stdio.h>

int main(){
	char linha[128];
	char inversa[128];
	char c;
	int i = 0, j;
	printf("Digite uma string que termine com ponto: \n");
	do {
		c = getc(stdin);
		linha[i] = c;
		i++;
	} while(c!='.');
	j = i - 1;
	inversa[i] = '\0';
	i = 0;
	while(j>=0){
		inversa[j] = linha[i];
		j--;
		i++;
	}
	printf("\n%s", inversa);
	return 0;
}
