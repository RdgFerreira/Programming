#include <stdio.h>
#include <stdlib.h>
#define MAX_VETOR 60

int main(){
	int X[MAX_VETOR], Y[MAX_VETOR], Z[2*MAX_VETOR];
	int tamanho=0, igual=0;
	int num;
	for(int i=0; i<MAX_VETOR; i++){
		do{
			X[i] = rand();
		} while(X[i]<0 || X[i]>365);
		do{
			Y[i] = rand();
		} while(Y[i]<0 || Y[i]>365);
	}
	for(int i=0; i<MAX_VETOR; i++){
		num = X[i];
		igual = 0;
		for(int j=0; j<tamanho; j++){
			if(num==Z[j]){
				igual = 1;
				break;
			}
		}
		if(!igual){
			Z[tamanho] = num;
			tamanho++;
		}
		num = Y[i];
		igual = 0;
		for(int j=0; j<tamanho; j++){
			if(num==Z[j]){
				igual = 1;
				break;
			}
		}
		if(!igual){
			Z[tamanho] = num;
			tamanho++;
		}
	}
	printf("\n Vetor X: ( ");
	for(int i=0; i<MAX_VETOR; i++){
		printf("%d ", X[i]);
	}
	printf(")\n");
	printf("\n Vetor Y: ( ");
	for(int i=0; i<MAX_VETOR; i++){
		printf("%d ", Y[i]);
	}
	printf(")\n");
	printf("\n Vetor uniao: ( ");
	for(int i=0; i<tamanho; i++){
		printf("Z[%d] = %d\n", i, Z[i]);
	}
	printf(")\n");
	return 0;
}
