#include <stdio.h>

void maxmin(int *A, int n, int *Max, int *Min) {
    int i;
    *Max = A[0];
    *Min = A[0];

    for (i = 1; i < n; i++) {    //Melhor Caso: n-1
        if (A[i] > *Max) {       //Pior Caso: 2(n-1)
          *Max = A[i];           //Caso Médio: (3/2)(n-1)
        }
        else if (A[i] < *Min) {
          *Min = A[i];
        }
    }
}

int main() {
    int A[10] = {12,32,93,31,29,33,45,76,38,9};
    int Max;
    int Min;

    maxmin(A, 10, &Max, &Min);
    printf("Max: %d\nMin: %d", Max, Min);




    return 0;
}