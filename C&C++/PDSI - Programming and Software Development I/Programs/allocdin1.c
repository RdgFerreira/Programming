#include <stdio.h>
#include <stdlib.h>

void aloca(float **x, int n){ // Passagem de vetor por referência
	*x = (float*)malloc(n*sizeof(float));
	
	for(int i=0; i<n; i++){
		(*x)[i] = 0; //*((*x)+i) = 0;
	}
	
}

int main(){
	/*float x; // 4 bytes(32 bits)/enderecos na memória alocados automaticamente
	
	float *p=NULL;// Armazena float*
	
	x = 3.14;
	
	p = &x;
	
	printf("%f\n", *p);// "3.14"
	
	p = (float*)malloc(sizeof(float));// p recebe o primeiro endereco de memoria do tipo float* dos 4 alocados por malloc (tamanho de um endreço de float)

	*p = 2.72;
	
	printf("%f %d", *p, sizeof(float));// "2.72 4"
	
	free(p); //Libera o espaço alocado por malloc
	*/
	
	int n=0;
	
	scanf("%d", &n);
	
	if(n>0){
		
		//float v[n]; // Nao funciona: n é desconhecido em tempo de execução
		float *v=NULL;
		/*
		v = (float*)malloc(n * sizeof(float)); // Cria um vetor v[n]
		
		for(int i=0; i<n; i++){
			v[i] = 0;
		}
		*/
		aloca(&v, n);
		
		for(int i=0; i<n; i++){
			printf("v[%d] = %.1f", i, v[i]);
			printf("\n");
		}
		
		free(v);
		
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}