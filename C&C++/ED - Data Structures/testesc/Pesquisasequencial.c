#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    int chave;
} Registro;

int Pesquisa(Registro *A, int n, int chave) {
    int i = 0;

    for (i = 0; i < n; i++) {
        if (A[i].chave == chave) {
            break;
        }
    }

    return i;
}

int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("\n%d\n", Pesquisa(A, 10, 2)); 




    return 0;
}