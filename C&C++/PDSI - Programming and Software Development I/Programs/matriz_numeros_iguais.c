#include <stdio.h>
#include <stdlib.h>
#include "randfuncoes.h"

int main(){
	int m=0, n=0, k=0, proximo=0, anterior=0, count0=0, conta0=0, aux=0;;
	
	do {
		printf("Digite m e n: ");
		scanf("%d %d", &m, &n);
		if (m<1 || m>100 || n<1 || n>100)
			printf("Valor invalido!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	
	do {
		printf("Digite k: ");
		scanf("%d", &k);
		if (k<2)
			printf("Valor invalido!\n");
	}while(k<2);
	
	int M[m][n];
	int M_linha[m][n];
	int M_coluna[m][n];
	
	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			M[i][j] = randInt(1,k);
		}
	}
	
	printf(" ");
	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
		printf(" ");
	}
	
	while(1)
	{
		conta0 = count0;
		for (int i=0; i<m; i++)
		{
			proximo = 0;
			anterior = -1;
			for (int j=0; j<n; j++)
			{
				M_linha[i][j] = M[i][j];
				if(j != n-1)
				{
					if(M_linha[i][j] != anterior){
						if(proximo >= 3)
							for(int x = proximo; x>0; x--){
								M_linha[i][j-x] = 0;
							}
						proximo = 1;
					}
					else
						proximo++;
				}
				else
				{
					if(M_linha[i][j] != anterior)
					{
						if(proximo >= 3)
							for(int x = proximo; x>0; x--){
								M_linha[i][j-x] = 0;
							}
					}
					else if(proximo>=2)
					{
						for(int x = proximo; x>=0; x--){
							M_linha[i][j-x] = 0;
						}
					}
				}
				anterior = M[i][j];
			}
		}
	
		for (int j=0; j<n; j++)
		{
			proximo = 0;
			anterior = -1;
			for (int i=0; i<m; i++)
			{
				M_coluna[i][j] = M[i][j];
				if(i != m-1)
				{
					if(M_coluna[i][j] != anterior){
						if(proximo >= 3)
							for(int x = proximo; x>0; x--){
								M_coluna[i-x][j] = 0;
							}
						proximo = 1;
					}
					else
						proximo++;
				}
				else
				{
					if(M_coluna[i][j] != anterior)
					{
						if(proximo >= 3)
							for(int x = proximo; x>0; x--){
								M_coluna[i-x][j] = 0;
							}
					}
					else if(proximo>=2)
					{
						for(int x = proximo; x>=0; x--){
							M_coluna[i-x][j] = 0;
						}
					}
				}
				
				anterior = M[i][j];
			}
		}
		
		for (int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(M_linha[i][j] == 0 || M_coluna[i][j] == 0){
					M[i][j] = 0;
					count0++;
				}
			}
		}
		
		if(conta0 == count0)
			break;
	
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(M[i][j] == 0)
				{
					for(int x=i-1; x>=0; x--)
					{
						aux = M[x][j];
						if(aux==0)
							break;
						else
						{
							M[x][j] = M[x+1][j];
							M[x+1][j] = aux;
						}
					}
				}
			}
		}
	}
	printf("\nMatriz final:\n");
	printf(" ");
	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
		printf(" ");
	}
	
	return 0;
}