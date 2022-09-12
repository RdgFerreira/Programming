#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void raiz(char n){
	printf("Enter: ");
	scanf("%c", &n);
	n = 48 + rand()%10;
	printf("Random: = %c\n", n);
}

int main(){
	srand(time(NULL));
    char n;
    raiz(n);
    return 0;
}


	