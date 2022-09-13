#include <stdio.h>
#include <stdlib.h>

void aloca_string(char ** str, int n) {
	*str = (char*)malloc(n * sizeof(char));

	int i = 0;

	for (; i < n - 1; i++)
	{
		(*str)[i] = 'a';
	}
	
	(*str)[i] = '\0';
}

int main() {
	int n = 2;
	printf("Digite o tamanho da string: ");
	scanf("%d", &n);

	char * linha = NULL;
	aloca_string(&linha, n + 1);
	char * inversa = NULL;
	aloca_string(&inversa, n + 1);

	char c;
	int i = 0, j = 0;

	printf("Digite uma string de tamanho n que termine com ponto: \n");
	do {
		c = getc(stdin);
		linha[i] = c;
		i++;
	} while(c != '.');

	j = i - 1;
	// inversa[i] = '\0';
	i = 0;
	while(j >= 0) {
		inversa[j] = linha[i];
		j--;
		i++;
	}
	printf("\n%s", inversa);

	free(linha);
	free(inversa);


	return 0;
}
