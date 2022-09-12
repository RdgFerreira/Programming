/*
 Leia as informações de peso, altura e sexo de uma pessoa e informe
se ela pode engordar ou emagrecer a partir do seu peso ideal, que é
calculado: Homem: (Altura - 100) x 0.9 ; Mulher: (Altura - 100) x 0.85.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
	float altura;
	float peso;
	char sexo;
}Pessoa;

void avalia_Peso_Pessoa(Pessoa p){
	float pesoIdeal = 0;
	if(p.sexo == 'F')
		pesoIdeal = (p.altura-100)*0.85;
	else 
		pesoIdeal = (p.altura-100)*0.9;
	printf("Peso ideal: %.2f\n", pesoIdeal);
	if(p.peso>pesoIdeal)
		printf("Pode emagrecer.\n");
	else
		printf("Pode engordar.\n");
}

int main(){
	/*float peso, altura;
	char sexo;
	*/
	Pessoa p;
	printf("Digite altura(cm), peso(kg), sexo: ");
	scanf("%f %f %c", &p.altura, &p.peso, &p.sexo);
	avalia_Peso_Pessoa(p);
	return 0;
}

