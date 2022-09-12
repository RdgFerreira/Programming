#include <stdio.h>
#include <stdlib.h>
#include "randfuncoes.h"
#define MAX_VETOR 1000
#define QTE 5000000

int main(){
	int num=0, max=0, min=0, i=0;
	int v[MAX_VETOR];
	for(i=0; i<MAX_VETOR; i++){
		v[i] = 0;
	}
	for(i=0; i<QTE; i++){
		num = randInt(0, 999);
		v[num]++;
	}
	max = v[num];
	min = v[num];
	for(i=0; i<MAX_VETOR; i++){
		if(v[i] >= max)
			max = v[i];
		if(v[i] <= min)
			min = v[i];
	}
	printf("\nAmplitude do rol de vezes que cada um dos 5.000.000 de numeros aleatorios entre 0 e 999 foi gerado: %d", max-min);
	return 0;
}