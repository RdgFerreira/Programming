#include <stdio.h>

int main(){
	int i=0, j=0, k=0;
	int X[10], Y[10], Z[20];
	printf("Preencha o vetor X com 10 elementos entre espacos: ");
	for(i=0; i<10; i++){
		scanf("%d", &X[i]);
	}
	printf("Preencha o vetor Y com 10 elementos entre espacos: ");
	for(i=0; i<10; i++){
		scanf("%d", &Y[i]);
	}
	for(i=0; j<20; j++){
		if(j%2==0){
			Z[j] = X[i];
		    i++;
		}
		else{
			Z[j] = Y[k];
			k++;
		}
	}
	printf("\n Vetor: ( ");
	for(i=0; i<20; i++){
		printf("%d ", Z[i]);
	}
	printf(")");
	return 0;
}

