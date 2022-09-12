#include <stdio.h>
#include <math.h>
#include "pratica4.h"

int main(int argc, char const *argv[]){
	
	printf("Ex 1:\n");
	printf("180 km/h = %.2f\n",  paraMetrosPorSegundo(180));
	
	printf("Ex 2:\n");
	printf("Area de um circulo de raio 2cm = %.2f\n", areaCirculo(2.0));
	
	printf("Ex 3:\n");
	printf("O maior entre 1, 2 e 3 eh o numero %d\n", maior3(1, 2, 3));
	
	printf("Ex 4:\n");
	printf("2 %s\n", ehPar(2) ? "eh par" : "eh impar");
	
	printf("Ex 5:\n");
	printf("3 %s\n", ehDivisivelPor3ou5(3) ? "eh divisivel" : "nao eh divisivel");
	
	printf("Ex 6:\n");
	printf("Peso ideal para um homem de 1.80 metros: %.2f kg\n", pesoIdeal(1.80, 'M'));
	printf("Peso ideal para uma mulher de 1.60 metros: %.2f kg\n", pesoIdeal(1.60, 'F'));
	
	printf("Ex 8:\n");
	printf("Soma dos impares de 0 ate 9 = %d\n", somaImpares(9));
	
	printf("Ex 9:\n");
	printf("5! = %.2lf\n", fatorial(5));
	
	printf("Ex 10:\n");
	printf("Soma dos numeros divisiveis ou por 3 ou por 5 menores ou igual a N=10: %d\n", somaNumerosDiv3ou5(10));
	
	printf("Ex 11:\n");
	printf("10 tem %d divisores\n", numeroDivisores(10));
	
	printf("Ex 12:\n");
	printf("Raiz cubica entre 1, 2 e 3 = %.2f\n", calculaMedia(1,2,3,1));
	printf("Media ponderada entre 1, 2 e 3 = %.2f\n", calculaMedia(1,2,3,2));
	printf("Media harmonica entre 1, 2 e 3 = %.2f\n", calculaMedia(1,2,3,3));
	printf("Media aritmetica entre 1, 2 e 3 = %.2f\n", calculaMedia(1,2,3,4));
	
	printf("Ex 13:\n");
	printf("O ultimo termo da sequencia fibonacci de 8 eh: %d\n", enesimoFibonacci(8));
	
	printf("Ex 14:\n");
	printf("O MDC entre 6 e 10 = %d\n", mdc(6,10));
	
	printf("Ex 15:\n");
	printf("O MMC entre 6 e 10 = %d\n", mmc(6,10));
	
	return 0;
}
