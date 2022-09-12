#include <stdio.h>

void maxmin(int *A, int n, int *Max, int *Min) {
    int i, FimDoAnel;

    if ((n % 2) > 0) { 
        A[n] = A[n - 1]; 
        FimDoAnel = n; 
    } 
    else { 
        FimDoAnel = n - 1;
    }

    if (A[0] > A[1]) { 
        *Max = A[0]; *Min = A[1]; 
    } 
    else { 
        *Max = A[1]; *Min = A[0];
    }

    i = 3; 
    while (i <= FimDoAnel) { 
        if (A[i - 1] > A[i]) { 
            if (A[i - 1] > *Max) *Max = A[i - 1]; 
            if (A[i] < *Min) *Min = A[i]; 
        } 
        else { 
            if (A[i - 1] < *Min) *Min = A[i - 1]; 
            if (A[i] > *Max) *Max = A[i]; 
        } 
        i += 2; 
    } 
}

int main() {
    int A[10] = {12,32,93,31,29,33,45,76,38,9};
    int Max;
    int Min;

    maxmin(A, 10, &Max, &Min);
    printf("MaxMin3:\nMax: %d\nMin: %d", Max, Min);




    return 0;
}