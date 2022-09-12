/*
Crie um programa para processar o arquivo "matrizes_float.txt" e:
	a) Imprimir as duas matrizes;
	b) Imprimir a soma das duas matrizes,
	c) Armazenar a soma das matrizes no arquivo "somaMatrizes.txt"
*/

#include <stdio.h>

#define MAXTAM 100

void imprimeMatriz(float M[][MAXTAM], int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%.1f ", M[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	FILE *arq, *arqw;
	int n=0, m=0;
	int i=0, j=0;
	float M1[MAXTAM][MAXTAM], M2[MAXTAM][MAXTAM];
	
	arq = fopen("matrizes_float.txt", "r"); //Opcoes de abertura: r(read), w(write), a(append)(adicionar linhas).
	arqw = fopen("somaMatrizes.txt", "w"); //Caso o arquivo não foi criado, fopen o criará no mesmo diretorio.
	fscanf(arq, "%d %d", &n, &m); //Lê dados do arquivo, consumindo-os em sequencia e armazenando-os nas variaveis.
	printf("\n%d %d", n, m);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fscanf(arq, "%f", &M1[i][j]);
		}
	}
	
	printf("\nMatriz 1:\n");
	imprimeMatriz(M1, n, m);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fscanf(arq, "%f", &M2[i][j]);
			M1[i][j] += M2[i][j];
		}
	}
	
	printf("\nMatriz 2:\n");
	imprimeMatriz(M2, n, m);
	
	printf("\nMatriz soma:\n");
	imprimeMatriz(M1, n, m);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			fprintf(arqw, "%.1f ", M1[i][j]); //Escreve no arquivo em questão.
		}
		fprintf(arqw, "\n");
	}
	
	fclose(arq);
	fclose(arqw);
	//Fecha o arquivo.
	return 0;
}