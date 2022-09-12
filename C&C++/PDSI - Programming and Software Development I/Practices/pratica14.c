#include <stdio.h>
#include <math.h>

//1)
int somaCubos(int n){
	if(n==1)
		return 1;
	return pow(n,3) + somaCubos(n-1);
}

//2)
void imprimeNaturaisOrdemCrescente(int n){
	if(n<0)
		return;
	imprimeNaturaisOrdemCrescente(n-1);
	printf(" %d", n);
}

//3)
void imprimeNaturaisOrdemDecrescente(int n){
	if(n<0)
		return;
	printf(" %d", n);
	imprimeNaturaisOrdemDecrescente(n-1);
}

//4)
int somaElementosVetor(int v[], int n){
	if(n==1)
		return v[0];
	return v[n-1] + somaElementosVetor(v, n-1);
}

//5)
float mediaElementosVetor(int v[], int n){
	return (float)somaElementosVetor(v, n)/(float)n;
}

//6)
int potencia(int x, int y){
	if(y==1)
		return x;
	if(y==0)
		return 1;
	return x * potencia(x,y-1);
}

//7)
void inverteString(char *str){
	if(*str == '\0')
		return;
	inverteString(str+1);
	printf("%c", *str);
}

//8)
int inteiroInvertido(int n, int *count){
	int resto;
	if(n==0)
		return *count;
	else{
		resto = n%10;
		*count *= 10;
		*count += resto;
		inteiroInvertido(n/10,count);
		return *count;
	}
}

//9)
unsigned long long inteiroParaBinario(unsigned long long n){
	if(n == 0) return 0;
	return (n%2) + 10*inteiroParaBinario(n/2);
}

//10)
int menorElemento(int *v, int n){
	int atual = v[n - 1];
	int menor;
	if(n-1 == 0)
		return v[n-1];
	else{
		menor = menorElemento(v,n-1);
		if(menor<=atual)
			return menor;
		else
			return atual;
	}
}

int main(){
	int x=0, y=0, count=0;
	int v[] = {10, 2, 3};
	char str[] = "socorram me subi no onibus em marrocos";
	scanf("%d %d", &x, &y);
	printf("\nSoma dos primeiros %d cubos: %d", x, somaCubos(x));
	printf("\nNaturais de 0 ate %d: ", x);
	imprimeNaturaisOrdemCrescente(x);
	printf("\nNaturais de %d ate 0: ", x);
	imprimeNaturaisOrdemDecrescente(x);
	printf("\nSoma dos elementos de um vetor de 3 inteiros: %d", somaElementosVetor(v,3));                
	printf("\nMedia dos elementos de um vetor de 3 inteiros: %f", mediaElementosVetor(v,3));                
	printf("\n%d^%d = %d", x, y, potencia(x,y));
	printf("\n");
	inverteString(str);
	printf("\n1234567890 invertido: %d", inteiroInvertido(1234567890,&count));
	printf("\n64 na base binaria: %d", inteiroParaBinario(64));
	printf("\nMenor elemento do vetor de 3 inteiros: %d", menorElemento(v,3));
	
	return 0;
}