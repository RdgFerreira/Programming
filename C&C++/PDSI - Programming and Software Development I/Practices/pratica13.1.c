#include <stdio.h>
#include <stdlib.h>

void alocaMatriz_ref(float ***M, int n, int m){ //Passagem de matriz por referência
	*M = (float**)malloc(n * sizeof(float*));
	for(int i=0; i<n; i++){
		(*M)[i] = (float*)malloc(m * sizeof(float));
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			(*M)[i][j] = 0.0;
		}
	}
}

void liberaMatriz(float **M, int n, int m){
	for(int i=0; i<n; i++){
		free(M[i]);
	}
	free(M);
}

void imprimeMatriz(float **M, int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%.1f ", M[i][j]);
		}
		printf("\n");
	}
}

/*
0 1
1 2
2 3
(n=3, m=2) == Conjunto de n=3 vetores de m=2 valores
*/

int main(){
	
	int n=0;
	float **M=NULL; // Aponta para um vetor de endereços de memória (== linhas da matriz) que apontam para vetores de valores inteiros 
	
	scanf("%d", &n);
	
	alocaMatriz_ref(&M, n, n);
	imprimeMatriz(M, n, n);
	liberaMatriz(M, n, n);
	
	return 0;
}