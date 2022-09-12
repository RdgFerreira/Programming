/* PROBLEMA COM STRINGS
  
  Programa para criptografar uma mensagem,
  A regra de criptografia deve substituir o código ASCII de cada caracter da mensagem por:
    (5*Código_ASCII + 100)%256;
  As mensagens deverão terminar com ponto '.'

*/
#include <stdio.h>



unsigned char criptografa(unsigned char c){
	return (5*c + 100)%256;
}


int main(){
	
	unsigned char msg[10], msg_cod[10];
	int i = 0, n = 0;
	
	for(i=0; i<9; i++){
	    scanf("%c", &msg[i]);
		if (msg[i] == '.')
			break;
	}
	n = i;
	msg[i] = '\0';
	printf("\nmsg:\n%s", msg);
	
	printf("\nmsg codificada: \n");
	for(i=0; i<n; i++){
		msg_cod[i] = criptografa(msg[i]);
		printf("%c", msg_cod[i]);
	}		
	return 0;
}

