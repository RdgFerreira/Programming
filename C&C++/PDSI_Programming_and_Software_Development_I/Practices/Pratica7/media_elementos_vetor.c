#include <stdio.h>
#include <stdlib.h>
#include "randfuncoes.h"

float media_vetor(float v[], int n){
	int j=0;
	double soma=0.0;
	for(j=0; j<n; j++){
		soma += v[j];
	}
	return soma/(double)n;
}

int main(){
	int n=0, i=0; 
	do{	
	    printf("Digite o numero de elementos do vetor (ate 1000): ");
		scanf("%d", &n);
		if(n<0 || n>1000)
			printf("Tamanho invalido\n");
	} while (n<0 || n>1000);
	float v[n];
	printf("\n Vetor: ( ");
	for(i=0; i<n; i++){
		v[i] = randFloat(0, 10);
		printf("%.2f ", v[i]);
	}
	printf(")\n");
	printf(" Media dos elementos do vetor = %.2lf", media_vetor(v, n));
	return 0;
}