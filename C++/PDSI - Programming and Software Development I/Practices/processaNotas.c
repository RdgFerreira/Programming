/*
Processar arquivo pds1.dat e:
	a) Imprimir a média de todas as notas;
	b) Gerar um arquivo com os alunos que vão para a prova especial (soma das notas < 12),
	c) Imprimir o nome e a nota do melhor aluno.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTAM 100

int main(){
	
	int mat = 0;
	char *nome = NULL;
	float nota1 = 0, nota2 = 0;
	
	float soma = 0;
	int count_notas = 0;
	
	float maior_nota = -1;
	char nome_melhor[MAXTAM];
	
	FILE *arq = fopen("pds1.dat", "r");
	FILE *arq_esp = fopen("Especial.dat", "w");
	char linha[MAXTAM];
	
	while(!feof(arq)){ //feof() retorna 1 caso não há mais dados a se ler no arquivo do parametro.
		fgets (linha, MAXTAM, arq); //Lê a linha de um arquivo e a armazena em um vetor de caracteres.
		//printf("%s\n", linha);
		mat = atoi(strtok(linha, ",")); //atoi() = alpha numeric to integer.
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ",")); //atof() = alpha numeric to float.
		nota2 = atof(strtok(NULL, ","));
		printf("%d %s %.1f // %.1f\n", mat, nome, nota1, nota2);
		
		if(nota1 + nota2 < 12){
			fprintf(arq_esp, "%s, %.1f\n", nome, nota1+nota2);
		}
		
		if(nota1 + nota2 > maior_nota){
			maior_nota = nota1 + nota2;
			//char *strcpy(char *dest, *char *source)
			strcpy(nome_melhor, nome);
		}
		
		soma += nota1 + nota2;
		count_notas += 2;
	}
	
	printf("\nMedia: %.2f", soma/count_notas);
	
	printf("\nMelhor aluno: %s (%.1f)", nome_melhor, maior_nota);
	
	fclose(arq);
	fclose(arq_esp);
	
	
	
	return 0;
}