/* COMANDO SWITCH

  Só funciona com condições do tipo: 
    expressão == constante
  
       |
    expr == const1 -T- B_const1
       |                  |
       F                  |
       |                  |
    expr == const2 -T- B_const1
       |                  |
       F                  |
       ...               ...
       |		          |
	expr == constN -T- B_constN
	
	
	
  switch(expr){
	  case const1:
	    B_const1
	  case const2:
	    B_const2
	  case const3:
	    B_const3
		    ...
	  case constN:
	    B_constN
	  default:
	    B_default
  }
  
  Problema:
  
  Calcular salário baseado em titulação:
    Doutorado: +1500
	Mestrado: +1000
	Graduação: +2000
	Ensino médio: +500
	Base: +400
	
*/
#include <stdio.h>
#define DOUTORADO 4
#define MESTRADO 3
#define GRADUACAO 2
#define ENSINO_MEDIO 1
 
float calcSalario (int titulacao){
	float salario = 0;
	switch(titulacao){
		                    // Simulando if_else...
		case DOUTORADO:     //   salario = 5400;
		   salario += 1500; //   break
		case MESTRADO:      //   salario = 3900;
		   salario += 1000; //   break
		case GRADUACAO:     //   salario = 2900;
		   salario += 2000; //   break
		case ENSINO_MEDIO:  //   salario = 900;
		   salario += 500;  //   break
		default:            
		   salario += 400;
	}
	return salario;
}

int main(){
	int t = 0;
	printf("Digite a titulacao: \n");
	printf("Doutorado: 4\n");
	printf("Mestrado: 3\n");
	printf("Graduacao: 2\n");
	printf("Ensino medio: 1\n");
	printf("Outro: 0\n");
	scanf("%d", &t);
	printf("Salario: %.2f\n", calcSalario(t));
	return 0;
}

