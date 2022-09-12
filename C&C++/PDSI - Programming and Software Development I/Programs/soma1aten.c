//calcular e exibir a soma dos inteiros entre 1 e n. Limite para unsigned int: N = 92681
//Soma = n(n+1)/2
//Solução força bruta:
#include <stdio.h>

unsigned int SomaN(unsigned int N){
	unsigned int soma = 0, k = 1;
    while(k <= N){
		soma += k;
		k++;
	}
    return soma;
}	

void calculasoma(){
	int N;
	do{
		printf("\nDigite o N: ");
	    scanf("%d", &N);
	}while(N <= 0);
	printf("\nSoma = %u\n", SomaN(N));
}

void main(){
	int resp;
	do{
        calculasoma();
		printf("\nDe novo? (1=S) (0=N)\n");
		scanf("%d", &resp);
	}while(resp == 1);
}
