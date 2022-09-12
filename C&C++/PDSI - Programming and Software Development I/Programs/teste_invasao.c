#include <stdio.h>
#include <stdlib.h>

void main(){
	int i=0,j=0;
	int vet[] = {10, 20, 30, 40};
	
	for(i=0; i<5/**/; i++){ //*invasão de memória -- atualiza a variavel i e o loop não termina.*/
        vec[i] = 1;
		printf("vec[%d] = %d\n", i, vec[i]);
		getchar();
	}
	printf("\ni = %d", i);
}

	