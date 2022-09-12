#include <stdio.h>
#include <stdlib.h>

void alocaMatriz_ref(int *** M, int n, int m) { //Passagem de matriz por referência
	*M = (int**)malloc(n * sizeof(int*));
	
	for(int i = 0; i < n; i++) {
		(*M)[i] = (int*)malloc(m * sizeof(int));
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			(*M)[i][j] = i + j;
		}
	}
}

int ** alocaMatriz(int n, int m) {
	int ** M = (int**)malloc(n * sizeof(int*));
	
	//M[0] = (int*)malloc(m * sizeof(int));
	//M[1] = (int*)malloc(m * sizeof(int));
	//...
	
	for(int i = 0; i < n; i++){
		M[i] = (int*)malloc(m * sizeof(int));
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			M[i][j] = i + j;
		}
	}
	
	return M;
}


void liberaMatriz(int ** M, int n, int m) {
	for(int i = 0; i < n; i++) {
		free(M[i]);
	}
	free(M);
}

void imprimeMatriz(int ** M, int n, int m) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%3d ", M[i][j]);
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

int main() {
	
	int n = 0, m = 0;
	int ** M = NULL; // Aponta para um vetor de endereços de memória (== linhas da matriz) que apontam para vetores de valores inteiros 
	
	printf("Type the matrix dimensions as: lines columns:\n");
	scanf("%d %d", &n, &m);
	
	//M = alocaMatriz(n, m);
	alocaMatriz_ref(&M, n, m);
	imprimeMatriz(M, n, m);
	liberaMatriz(M, n, m);
	
	return 0;
}















