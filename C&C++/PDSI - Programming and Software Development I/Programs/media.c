/*
Problema:

Calcular e exibir a média de inteiros positivos digitados pelo usuário.
  No máximo 15 inteiros podem ser digitados.
  Se o usuário digitar 0, interrompa o processo.
  Inteiros negativos devem ser ignorados.
*/

#include <stdio.h>

float media(){
	int x =-1, n = 0, soma = 0, n_total = 0;
	while(n_total<15){
		scanf("%d", &x);
		n_total++;
		if (x==0)
			break;
		if (x<0)
			continue;
		n++;
		soma += x;
	}
	return (float)soma/n;
}

