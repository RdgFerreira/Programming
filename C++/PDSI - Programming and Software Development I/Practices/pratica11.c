#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void troca(int v[], int i, int j){
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void ordenar_selecao(int x[], int n){
	int menor, pos;
	int i, k=0;
	while(k<n){
		menor = 99999;
		for (i=k; i<n; i++){
			if(x[i]<menor){
				menor = x[i];
				pos = i;
			}
		}
		troca(x,k,pos);
		k++;
	}
}

int main(){
	
	FILE *arq;
	arq = fopen("cartelas.txt", "r");
	int acertou = 0, quadra = 0, quina = 0, acertou_lost = 0, ganhadores = 0, ganhadores_lost = 0;
	
	int combinacao[] = {6, 9, 22, 23, 48, 52};
	/*
	combinacao[0] = 6;
	combinacao[1] = 9;
	combinacao[2] = 22;
	combinacao[3] = 23;
	combinacao[4] = 48;
	combinacao[5] = 52;
	*/
	
	int combinacao_lost[] = {4, 8, 15, 16, 23, 42};
	/*
	combinacao_lost[0] = 4;
	combinacao_lost[1] = 8;
	combinacao_lost[2] = 15;
	combinacao_lost[3] = 16;
	combinacao_lost[4] = 23;
	combinacao_lost[5] = 42;
	*/
	
	int jogo[6];
	
	while(!feof(arq)){
		for(int i=0; i<6; i++){
			fscanf(arq, "%d", &jogo[i]);
		}
		
		/*
		for(int i=0; i<6; i++){
			printf("%3d ", jogo[i]);
		}
		*/
		
		ordenar_selecao(jogo, 6);
		//printf("\n");
		
		/*
		for(int i=0; i<6; i++){
			printf("%3d ", jogo[i]);
		}
		*/
		
		//getchar();
		
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				if(jogo[i] == combinacao[j])
					acertou++;
			}
		}
		
		for(int i=0; i<6; i++){
			if(jogo[i] == combinacao_lost[i])
				acertou_lost++;
		}
		
		if(acertou == 6)
			ganhadores++;
		
		if(acertou_lost == 6)
			ganhadores_lost++;

		if(acertou == 4)
			quadra++;
		
		if(acertou == 5)
			quina++;
		
		acertou = 0;
		acertou_lost = 0;
	}
	
	printf("Ganhadores do premio: %d", ganhadores);
	printf("\nAcertaram numeros de lost: %d", ganhadores_lost);
	printf("\nAcertaram a quadra: %d", quadra);
	printf("\nAcertaram a quina: %d", quina);
	fclose(arq);
	return 0;
}