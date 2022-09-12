/* PROBLEMA VARIÁVEIS INDEXADAS
  Uma loja pretende simular um dia de suas vendas. Sabe-se que os preços dos produtos vendidos nesta loja variam de R$5,00 a R$100,00 e que cada cliente compra apenas um produto. 
  O número e o preço de cada produto, o número de clientes e os produtos comprados pelos clientes devem ser gerados aleatoriamente.

  No máximo 200 produtos.
  No máximo 50 clientes.

*/
#define MIN_PRECO 50
#define MAX_PRECO 100
#define MAX_PRODUTOS 200
#define MAX_CLIENTES 50
#include <stdio.h>
#include <stdlib.h>
#include "randfuncoes.h"
#include <time.h>

float geraPreco(){
	return randInt(MIN_PRECO*100, MAX_PRECO*100)/100.0;
}


int main(){
	srand(time(NULL));
	float precos[MAX_PRODUTOS];
	int compras[MAX_CLIENTES];
	//precos[1] = 84;
	//compras[2] = 3;
	int n_prod = 0, i = 0, n_clientes;
	
	n_prod = randInt(1, MAX_PRODUTOS);
	for(i=0; i<n_prod; i++){
		//precos[i] = randInt(MIN_PRECO, MAX_PRECO);
		precos[i] = geraPreco();
	}
	
	n_clientes = randInt(1, MAX_CLIENTES);
	for(i=0; i<n_clientes; i++){
		compras[i] = random(n_prod);
	}
	//int prod = 0;
	//float preco = 0;
	float faturamento = 0;
	printf("\nCliente Produto Preco");
	for (i=0; i<n_clientes; i++){
	    //prod = compras[i];
	    //preco = precos[prod];
		faturamento += precos[compras[i]];
		printf("\n%7d %7d %.2f", i, compras[i], precos[compras[i]]);
	}
	
	printf("\nFaturamento: %.2f", faturamento);
	return 0;
}

