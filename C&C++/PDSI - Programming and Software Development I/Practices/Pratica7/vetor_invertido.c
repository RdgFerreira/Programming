#include <stdio.h>

int main(){
	int n=0, i=0, k=0;
	do{	
	    printf("Digite o numero de elementos do vetor (ate 1000): ");
		scanf("%d", &n);
		if(n<0 || n>1000)
			printf("Tamanho invalido\n");
	} while (n<0 || n>1000);
	k = n;
	int X[n], Y[n];
	printf("Preencha o vetor X com %d elementos entre espacos: ", n);
	for(i=0; i<n; i++){
		scanf("%d", &X[i]);
	}
	for(i=0; i<n; i++){
		Y[i] = X[n-1-i];
	}
	printf("\n Vetor digitado: ( ");
	for(i=0; i<k; i++){
		printf("%d ", X[i]);
	}
	printf(")\n");
	printf("\n Vetor invertido: ( ");
	for(i=0; i<k; i++){
		printf("%d ", Y[i]);
	}
	printf(")\n");
	return 0;
}

