#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAXNUMBER 5
#include "randfuncoes.h"

void popula_vetor (float u[], float v[], int n){
	int j=0;
	for(j=0; j<n; j++){
		u[j] = randFloat(0, MAXNUMBER);
		v[j] = randFloat(0, MAXNUMBER);
	}
}

float produto_escalar(float u[], float v[], int n){
	int i=0;
	float soma=0.0;
	for(i=0; i<n; i++){
	    soma += u[i]*v[i];
	}
	return soma;
}

void imprime_vetor(float u[], int n, int s){
	int k=0;
	printf(" Vetor %d = ( ", s);
	for(k=0; k<n; k++){
		printf("%.2f ", u[k]);
	}
	printf(")");
}

int main(){
	srand(time(NULL));
	int tamanho=0;
	scanf("%d", &tamanho);
	float u[tamanho];
	float v[tamanho];
	popula_vetor(u, v, tamanho);
	imprime_vetor(u, tamanho, 1);
	printf("\n");
	imprime_vetor(v, tamanho, 2);
	printf("\nProduto escalar = %f", produto_escalar(u, v, tamanho));
	return 0;
}

