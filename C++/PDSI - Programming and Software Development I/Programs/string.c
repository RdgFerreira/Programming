/* STRINGS

  String = Sequência de caracteres que termina em '/0'.
*/

#include <stdio.h>

void imprimeStr(const char *s){ // Ou (char s[]) // O endereço em *s fica inalterável.
    int i = 0;
	printf("\n");
	while (s[i] != '\0'){
		printf("%c", s[i]);
		i++;
	}
}

int main(){
	char c = 'A';
	
	char str[1000] = "Ola!"; // Variavel str recebe endereço de memória do primeiro caracter da string. ('O', 'l', 'a', '!', '\0') = string. // Espaço disponível: 999 + '\0'.
	                     // Caracteres são armazenados em ordem nos endereços de memória subsequentes (cada byte um caracter). Total = 5 endereços de memória.
	printf("\n%p", str); // Imprime o endereço armazenado em str. (str é ponteiro).
	printf("\n%s", str); // Imprime os caracteres até parar no '\0'. 
	
	*(str + 0) = 'a'; // Ou str[0] = 'a'; // Substitui o primeiro char da string por 'a'.
	str[2] = 'o'; // Substitui o terceiro char da string por 'o'.
	
	
	str[2] = '\0'; // Substitui o terceiro char da string por 'o', ou seja, termina a string no segundo char.
	
	imprimeStr(str);  
	return 0;
	
}

