/* 
  Uma empresa armazena em uma variável indexada os números dos cheques
emitidos em um dia pelo setor financeiro.
  Considere que os números dos cheques são valores inteiros de 1 a 100
e que os cheques são emitidos em uma ordem aleatória.
  Ao final do dia, para facilitar o controle, a empresa precisa ordenar
esses dados em ordem crescente.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXCHEQUES 100
#include "randfuncoes.h"

//Checa se há elementos iguais em um vetor.
int existe(int k, int v[], int n){
	int i=0;
	for(i=0; i<n; i++){
		if(k==v[i])
			return 1;
	}
	return 0;
}

//Imprime os elementos de um vetor.
void imprimeVet(int v[], int n){
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
}

//Ordena, por contagem, os elementos de um vetor em ordem crescente usando outro vetor auxiliar.
void ordcont(int vet[], int vet_ord[], int n){
	int j=0, i=0;
	int cont[MAXCHEQUES];
	for(j=0; j<n; j++){
		cont[j] = 0;
		for(i=0; i<n; i++){
			if(vet[i]<vet[j])
				cont[j]++;
		}
		vet_ord[cont[j]] = vet[j];
	}
}

int main(){
	srand((unsigned)time(NULL));
	int vet[MAXCHEQUES], cont[MAXCHEQUES], vet_ord[MAXCHEQUES];
	int n = randInt(1,MAXCHEQUES);
	printf("\nn: %d", n);
	int i=0, cheque=0;
	
	//Cria um vetor de cheques gerados aleatoriamente.
	while(i<n){
		cheque = randInt(1,MAXCHEQUES);
		if(!existe(cheque, vet, i)){
			vet[i] = cheque;
			i++;
		}
	}
	printf("\nCheques: ");
	imprimeVet(vet, n);
	
	ordcont(vet, vet_ord, n);
	
	printf("\nCheques ordenados: ");
	imprimeVet(vet_ord, n);
	return 0;
}