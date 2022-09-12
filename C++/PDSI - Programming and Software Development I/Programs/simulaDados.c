/*
 Escreva um programa para simular a rolagem de dois dados. Neste programa,
você deve rolar os dois dados 36000 vezes e:
a) imprimir quantas vezes cada arranjo ocorreu;
b) imprimir a soma dos dados mais frequente;
c) imprimir o arranjo mais frequente.
*/

#include <stdio.h>
#include <stdlib.h>
#include "randfuncoes.h"
#include <time.h>
#define NFACES 6
#define NSOMAS NFACES+NFACES-1
#define NROLLS 50

void zeraMatriz(int M[][NFACES], int n, int m){
	int i=0, j=0;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			M[i][j] = 0;
		} 
	}
}

void zeraVetor(int v[], int n){
	int i=0;
	for(i=0; i<n; i++){
		v[i] = 0;
	}
}

int rolaDado(){
	return randInt(0, NFACES); //N aleatorio entre 0 e NFACES-1.
}

void imprimeMatriz(int M[][NFACES], int n, int m){
	int i=0, j=0;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%5d ", M[i][j]);
		}
		printf("\n");
	}
}

void imprimeVetor(int v[], int n){
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){
	int M[NFACES][NFACES];
	int d1=0, d2=0, i=0, j=0;
	int somas[NSOMAS];
	srand(time(NULL));
	
	zeraMatriz(M, NFACES, NFACES);
	zeraVetor(somas, NSOMAS);
	
	for(i=0; i<NROLLS; i++){
		d1 = rolaDado();
		d2 = rolaDado();
		M[d1][d2]++;
		somas[d1+d2]++;
	}
	
	imprimeMatriz(M, NFACES, NFACES);
	printf("\nVetor de somas:");
	imprimeVetor(somas, NSOMAS);
	
	int maior_i=0;
	for(i=1; i<NSOMAS; i++){
		if(somas[i] > somas[maior_i]){
			maior_i = i;
		}
	}
	
	printf("\nSoma mais frequente: %d\n", maior_i+2);
	
	int maior_j=0;
	maior_i=0;
	for(i=0; i<NFACES; i++){
		for(j=0; j<NFACES; j++){
			if(M[i][j] > M[maior_i][maior_j]){
				maior_i = i;
				maior_j = j;
			}
		}
	}
	
	printf("\nArranjo mais frequente: (%d,%d) (%d vezes)\n", maior_i+1, maior_j+1, M[maior_i][maior_j]);
	
	return 0;
}

