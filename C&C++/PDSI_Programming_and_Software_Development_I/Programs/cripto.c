/* 
	Programa para criptografar uma mensagem,
	A regra de criptografia deve substituir o código ASCII de cada caracter da mensagem por:
	(5 * Código_ASCII + 100) % 256;
	As mensagens deverão terminar com ponto '.'
*/
#include <stdio.h>


unsigned char criptografa(unsigned char c){
	return (5 * c + 100) % 256;
}

int main() {
	
	unsigned char msg[1000], msg_cod[1000];
	int i = 0, n = 0;

	printf("Escreva uma mensagem que termine com ponto final:\n");

	while (1) {
		scanf("%c", &msg[i]);
		if (msg[i] == '.') break;
		i += 1;
	}
	
	n = i + 1;
	msg[i] = '\0';
	printf("\nmsg: %s", msg);
	printf("\nmsg codificada: ");

	for(i = 0; i < n; i++) {
		msg_cod[i] = criptografa(msg[i]);
		printf("%c", msg_cod[i]);
	}

	return 0;
}

