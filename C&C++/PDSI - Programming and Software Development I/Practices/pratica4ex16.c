#include <stdio.h>
#include "pratica4.h"

int main(){
	unsigned int x, y;
	do {
		printf("Digite dois numeros inteiros positivos: ");
		scanf("%lu %lu", &x, &y);
		if ((x<=0) || (y<=0))
			printf("Numero(s) invalido(s)!\n");
	} while ((x<=0) || (y<=0));
	printf("O MDC entre %lu e %lu = %d\n", x, y, mdc(6,10));
	printf("O MMC entre %lu e %lu = %d\n", x, y, mmc(6,10));
	return 0;
}
