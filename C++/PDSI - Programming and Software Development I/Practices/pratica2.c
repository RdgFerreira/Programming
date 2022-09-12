#include <stdio.h>
#include <math.h>
#include "estatistica.h"

int main(){
	float x1, x2, x3, mu1, mu2, beta, b;
	x1=-2.0;
	x2=0.0;
	x3=-6.0;
	mu1=0.5;
	mu2=-5.0;
	beta=2.0;
	b=4.0;
	float cauchyf, gumbelf, laplacef;
	cauchyf = cauchy(x1);
	gumbelf = gumbel(x2, mu1, beta);
	laplacef = laplace(x3, mu2, b);
	printf("\nCauchy = %f", cauchyf);
	printf("\nGumbel = %f", gumbelf);
	printf("\nLaplace = %f", laplacef);
	return 0;
}

