#include <stdio.h>

int x = 0;

void p(int &, int &);

int main() {
    int x = 1;
    p(x, x);
    return 0;
}

void p(int &y, int &z) { // y = z = referência para x = 1
    x = x + 1; // x = 1 (global)
    y = y + 1; // y = 2 (x = x + 1)
    z = z + 1; // z = 3 (x = x + 1)
    printf("%d\n", x + y + z); // 1 + 3 + 3 = 7
}