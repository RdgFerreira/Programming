#include <stdio.h>

int x = 0;

void p(int, int);

int main() {
    int x = 1;
    p(x, x);
    return 0;
}

void p(int y, int z) { // y = z = 1
    x = x + 1; // x = 1 (global)
    y = y + 1; // y = 2
    z = z + 1; // z = 2 
    printf("%d\n", x + y + z); // 1 + 2 + 2
}