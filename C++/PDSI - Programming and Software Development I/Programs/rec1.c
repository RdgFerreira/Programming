#include <stdio.h>
#include <math.h>

float z_score(float x, float mu, float beta){
	return (x-mu)/beta;
}

float exp_gumbel(float z){
	return -(z + exp(-z));
}

float gumbel(float x, float mu, float beta){
	float z = z_score(x, mu, beta);
	float e = exp_gumbel(z);
	return (1/beta)*exp(e);
}

int main(){
	float x=0, mu=0, beta=0;
	scanf("%f %f %f", &x, &mu, &beta);
	printf("%f", gumbel(x,mu,beta));
	return 0;
}	