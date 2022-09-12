#include "stdio.h"

#define SUM(X , Y) (X) + (Y)

int main (int argc , char ** argv) {
    printf("sum = %d\n", SUM(argc, argv[0][0]));
    return 0;
}
