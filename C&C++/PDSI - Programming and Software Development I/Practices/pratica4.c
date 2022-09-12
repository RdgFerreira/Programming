#include <stdio.h>
#include <math.h>
#include "pratica4.h"

float paraMetrosPorSegundo(float v){
	return v/3.6;
}

float areaCirculo(float raio){
	return M_PI * (raio*raio);
}

int maior3(int n1, int n2, int n3){
	if ((n1 >= n2) && (n1 >= n3))
		return n1;
	else if ((n2 >= n1) && (n2 >= n3))
		return n2;
	else
		return n3;
}

int ehPar(int n){
	if (n%2==0)
		return 1;
	else
		return 0;
}

int ehDivisivelPor3ou5(int n){
	if ((n%3==0) ^ (n%5==0))
		return 1;
	else
		return 0;
}

float pesoIdeal(float h, char sexo){
	if (sexo == 'M')
		return (72.7*h) - 58.0;
	else if (sexo == 'F')
		return (62.1*h) - 44.7;
}

int somaImpares(int N){
	int count = 0;
	int soma = 0;
	do {
		if (count%2!=0)
			soma = soma + count;
		count++;
	} while (count <= N);
    return soma;
}

double fatorial(int N){
	int count = 2;
	double fatorial = 1;
	do {
		fatorial = fatorial * count;
		count++;
    } while (count <= N);
    return fatorial;
}

int somaNumerosDiv3ou5(int N){
	int soma = 0;
	int n = 0;
	do {
		if ((n%3==0) ^ (n%5==0))
			soma = soma + n;
		n++;
		} while (n<=N);
	return soma;
}

float calculaMedia(int x, int y, int z, int operacao){
	if (operacao == 1)
		return cbrt(x*y*z);
	else if (operacao == 2)
		return ((x)+(2*y)+(3*z))/(6);
	else if (operacao == 3)
		return (3)/((1/x)+(1/y)+(1/z));
	else if (operacao == 4)
		return (x+y+z)/(3);
}

int numeroDivisores(int N){
	int n = 1;
	int count = 0;
	do {
		if (N%n==0)
            count++;
    n++;		
	} while(n<=N);
    return count;
}

int enesimoFibonacci(int N){
	if (N==1)
		return 0;
	if (N==2)
		return 1;
	int a = 0, b = 1, enesimo;
	for (int i = 3; i<=N; i++){
		enesimo = a + b;
		a = b;
		b = enesimo;
	}
	return enesimo;
}

int mdc(unsigned int x, unsigned int y){
	int menor, maximo;
	if (x<y)
		menor = x;
	else 
		menor = y;
	for (int i = 2; i <= menor; i++)
		if (x%i==0 && y%i==0)
			maximo = i;
	return maximo;
}

int mmc(unsigned int x, unsigned int y){
	int mult, maior;
	if (x<y)
		maior = y;
	else
		maior = y;
	while(1){
		if ((maior%x==0) && (maior%y==0))
			break;
		maior++;
	}
	return maior;
}

	