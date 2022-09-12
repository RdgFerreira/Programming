#include <stdio.h>

int main(){
	int n = 0;
	char conceito;
	printf("0 a 4: 1\n");
	printf("5: 2\n");
	printf("6: 3\n");
	printf("7: 4\n");
	printf("8: 5\n");
	printf("9+: 6\n");
	do {
		printf("Nota: ");
	    scanf("%d", &n);
		if(n<1 || n>6)
			printf("Nota invalida\n");
	} while(n<1 || n>6);
		switch(n){
		case 1:
		    conceito = 'F';
			break;
		case 2:
		    conceito = 'E';
			break;
		case 3:
		    conceito = 'D';
			break;
		case 4:
		    conceito = 'C';
			break;
		case 5:
		    conceito = 'B';
			break;
		case 6:
		    conceito = 'A';
			break;
	    }
	printf("\nConceito: %c", conceito); 
	return 0;
}