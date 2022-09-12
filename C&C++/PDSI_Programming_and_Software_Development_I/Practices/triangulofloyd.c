#include <stdio.h>

int main(){
	int N=0, soma=1;
	printf("Digite um inteiro positivo: ");
	scanf("%d", &N);
	for(int linha = 1; linha <=N; linha++){
		for(int coluna = 1; coluna <= linha; coluna++){
			printf("%d ", soma);
            soma++;
        }
		printf("\n");
    }		
	return 0;
}

