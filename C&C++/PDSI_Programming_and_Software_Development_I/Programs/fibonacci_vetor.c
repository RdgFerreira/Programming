#include <stdio.h>
#include <stdlib.h>

void fibonacci (int ** v, int n){
	int i = 0;
	(*v)[0] = 1;
	(*v)[1] = 1;

	for (i = 2; i <= n; i++) (*v)[i] = (*v)[i-1] + (*v)[i-2];
}

void imprime_v (unsigned int v[], int n){
	int j = 0;

	printf(" Sequencia Fibonacci: ( ");
	 
	for (j = 0; j <= n; j++) printf("%lu ", v[j]);

	printf(")\n");
}

void aloca_vetor (int ** v, int n) {
	*v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) (*v)[i] = 0;
}

int main() {
	int termo = 0, denovo = 0;
	int * v = NULL;

	do {
		printf(" Digite um inteiro entre 1 e 1000: ");
		scanf("%d", &termo);
		if(termo < 1 || termo > 1000) return 0;

		aloca_vetor(&v, termo);
		fibonacci(&v, termo);
		imprime_v(v, termo);

		printf("\n fibonacci(%d): %lu\n", termo, v[termo]); 
		printf("\n De novo? (1=S, 0=N) ");
		scanf("%d", &denovo);

		free(v);

	} while(denovo);

	return 0;
}

