/*
Exemplo do uso da funcao strtok para encontrar "tokens" em strings

char *strtok(char *str, const char *delim)
*/

#include <stdio.h>
#include <string.h>

int main(){
	char str[] = "Pedro,Olmo-Stancioli,Vaz,de-Melo";
	char separadores[] = ",-";
	char *token;
	
	printf("str: %s\n", str); //"Pedro,Olmo-Stancioli,Vaz,de-Melo"
	
	token = strtok(str, separadores); //ou " "  //Processa os enderecos de memoria da string até encontrar o caracter separador de tokens (no caso, nomes separados por espaços), substitui por \0 e retorna o endereço de memoria de onde o processamento começou.
	
	/*
	printf("str: %s\n", str); //"Pedro"
	printf("token: %s\n", token); //"Pedro"
	*/
	
	
	/*
	token = strtok(NULL, " "); //Recomeça o processamento do endereço de memoria logo apos o do ultimo \0 colocado pela strtok.
	
	printf("str: %s\n", str); //"Pedro"
	printf("token: %s\n", token); //"Olmo"
	*/
	
	while(token != NULL){
		printf("token: %s\n", token); //"Pedro\nOlmo\nStancioli\nVaz\nde\nMelo"
		token = strtok(NULL, separadores); 
	}
	
	
	
	
	return 0;
}

