#include <stdio.h>

float juros(float v){
	return v = v*(1.006);
}

int main(){
	//11/2019
	float valor;
	valor = 5000;
	//12/2019
	valor = juros(valor);
	//01/2020
	valor = juros(valor);
	valor = valor - 1500;
	//02/2020
	valor = juros(valor);
	//03/2020
	valor = juros(valor);
	//04/2020
	valor = juros(valor);
	//05/2020
	valor = juros(valor);
	//06/2020
	valor = juros(valor);
	valor = valor - 2800;
	//07/2020
	valor = juros(valor);
	//08/2020
	valor = juros(valor);
	printf("Divida = R$%.2f", valor);
	return 0;
}
