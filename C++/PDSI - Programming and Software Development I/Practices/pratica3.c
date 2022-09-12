#include <stdio.h>
#include <math.h>
int f(unsigned int number){ 
   return (number | 1)-(number);
}
 
	
int main(){
	int r;
	unsigned int n;
	printf("Enter: ");
	scanf("%lu", &n);
	r = f(n);
	printf("%d\n", r);
	return 0;
}
//0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0010
//0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001
//0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000