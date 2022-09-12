#include <stdio.h>

int main(){
	int i=1, j=0;
	char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
	for(i=0; linha[i] != '\0'; i++){
	}
	printf("%d\n", i);
	while (j<((i-1)/2)){
		if(linha[j] != linha[i-2-j]){
			printf("Nao e palindromo");
       		return 0;
		}			
		j++;
	}
	printf("a palavra e palindroma", linha);
    return 0;
}
	