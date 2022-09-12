#include <stdio.h>

void Idade(int ano){
	if (ano == 1967)
		printf("\nSgt. Peppers!\n");
	else if (ano == 1973)
		printf("\nThe Dark Side of the Moon!\n");
	else if (ano == 1989)
		printf("\nBeneath the Remains!\n");
	else
		printf("\nNenhum album interessante :(\n");
	int idade = 2020 - ano;
	printf("Voce completa %d anos este ano.\n", idade);
	if (idade <= 18)
		printf("Escute Beatles!\n");
}
int main(){
	int ano;
	printf("Digite o ano de nascimento: ");
	scanf("%d", &ano);
	if (ano >= 2020){
		printf("\nAno invalido!\n");
	} else { Idade(ano);
	}
	return 0;
}