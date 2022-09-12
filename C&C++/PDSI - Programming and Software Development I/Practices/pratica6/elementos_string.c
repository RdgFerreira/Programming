#include <stdio.h>

int main(){
	int i=1;
	char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
	for(i=0; linha[i] != '\0'; i++){
		printf("%c", linha[i]);
	}
	printf("\n%d", i-1);
	return 0;
}
