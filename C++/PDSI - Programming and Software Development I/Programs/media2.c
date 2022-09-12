/* COMANDO FOR
  
  for(operação de inicialização; condição de entrada; operação de atualização){
  Bloco_for;
  }
       |
    op_ini
	   |---------------------------|
       |	                       |
    cond_entrada -T- Bloco_for -- op_atu
       |
       F
       |
       ...	   
*/
 
#include <stdio.h>

float media(){
	int x = -1, n = 0, soma = 0, n_total = 0;
	for(n_total = 0; n_total < 15 && x!=0; n_total++) {
		scanf("%d", &x);
		//if (x == 0)
		//	break;
		if (x <= 0)
			continue;
		n++;
		soma += x;
	}
	return (float)soma/n;
}  

