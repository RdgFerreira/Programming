#include <stdio.h>
#include <stdlib.h>

int valor_inicial = 10;

int valor_intermediario = 5;

void calcula (int * valores) {
    int taxa = 3;
    valores[0] = valor_inicial + valor_intermediario * taxa;
    valores[1] = valores[0] * 3;
}

int main () {
    int * valores = (int*)malloc(3 * sizeof(int));
    calcula(valores) ;
    valores[2] = valor_inicial + valor_intermediario;
    printf("valores[0]: %d\n", valores[0]);
    printf("valores[1]: %d\n", valores[1]);
    printf("valores[2]: %d\n", valores[2]);
    free(valores);
}