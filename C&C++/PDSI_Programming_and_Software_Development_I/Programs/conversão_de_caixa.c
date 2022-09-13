#include <stdio.h>

int main() {
	int i = 1;
	char linha[128];

    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);

	for (i = 0; linha[i] != '\0'; i++) {
		if(linha[i] >= 97 && linha[i] <= 122) linha[i] = linha[i] - 32;
	}
	
	printf("%s\n", linha);
	return 0;
}
