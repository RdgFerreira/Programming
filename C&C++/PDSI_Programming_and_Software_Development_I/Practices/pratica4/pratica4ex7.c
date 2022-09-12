#include <stdio.h>
#include "pratica4.h"

int main(){
	float h, peso;
	char sexo;
	printf("Peso (kg): ");
	scanf("%f", &peso);
	printf("Altura (m): ");
	scanf ("%f", &h);
	do {
		printf("\nSexo (M ou F):");
		scanf ("%c", &sexo);
		if ((sexo !='M') && (sexo !='F')){
			printf("Sexo Invalido\n");
		}
	} while((sexo !='M') && (sexo !='F'));
	printf("\nPeso Ideal = %.2f\n", pesoIdeal(h, sexo));
	if (pesoIdeal (h, sexo) > peso)
		printf("Voce precisa ganhar %.2f kg\n", pesoIdeal(h, sexo) - peso);
	else if (pesoIdeal(h, sexo) < peso)
		printf("Voce precisa perder %.2f kg\n", peso - pesoIdeal(h, sexo));
	else
		printf("Voce esta no peso ideal");
	return 0;
}	
