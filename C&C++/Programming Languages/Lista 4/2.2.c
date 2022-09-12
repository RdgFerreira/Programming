#include "stdio.h"
#include "stdlib.h"

#define Max(x, y) ((x < y) ? y : x)

int main() {
    for (int i = 0; i < 30; i++)
    {
        printf("%d\n", Max(rand() % 10, 5));
    }

    return 0;
}