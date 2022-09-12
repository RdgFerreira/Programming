#include <stdio.h>

void fibonacci(unsigned int v[], int n){
	int i=0;
	v[0] = 1;
	v[1] = 1;
	for(i=2; i<=n; i++){
		v[i] = v[i-1] + v[i-2];
	}
}

void imprime_v(unsigned int v[], int n){
	int j=0;
	printf(" Sequencia Fibonacci: ( ");
	for(j=0; j<=n; j++){
		printf("%lu ", v[j]);
	}
	printf(")\n");
}

int main(){
	int termo=0, denovo=0;
	do {
		printf(" Digite um inteiro entre 0 e 1000: ");
		scanf("%d", &termo);
		if(termo<0 || termo>1000)
			return 0;
		unsigned int v[termo];
		fibonacci(v, termo);
		imprime_v(v, termo);
		printf("\n fibonacci(%d): %lu\n", termo, v[termo]); 
		printf("\n De novo? (1=S, 0=N) ");
		scanf("%d", &denovo);
	} while(denovo);
	return 0;
}

