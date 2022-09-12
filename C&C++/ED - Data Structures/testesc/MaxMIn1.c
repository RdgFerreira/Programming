#include <stdio.h>

void maxmin(int *A, int n, int *Max, int *Min) {
    int i;
    *Max = A[0];
    *Min = A[0];

    for (i = 1; i < n; i++) {  //Complexidade 2(n-1) sempre
        if (A[i] > *Max) {
          *Max = A[i];
        }
        if (A[i] < *Min) {
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