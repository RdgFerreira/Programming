#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aleatório float entre 0 e 1.
float randf(){
	return (float)rand()/RAND_MAX;
}

//Aleatório float entre min e max.
float randFloat(float min, float max){ //min = 1.5, max = 3.5.
	return min + randf()*(max - min);
}

//Aleatório entre 0 e n-1.
int random(int n){
	return rand()%n; //Aleatório entre 0 e n-1.
}

//Aleatório entre min e max (inclusive os dois).
int randInt(int min, int max){ //min = 5, max = 10.
	return min + random(max - min + 1);
}

int main(){
	int x = 0, i = 0;
	float y = 0, max = -999999, min = 999999;
	// RAND_MAX: o maior inteiro gerado pela função rand: 32767.
    srand(time(NULL)); //SEED ou SEMENTE da função rand associado ao tempo (segundos).	
	for (i=0; i<100000; i++){
		//x = randInt(5, 10);       
	    //printf("x = %d\n", x);
		y = randFloat(1.5, 3.5);
		//printf("%f\n", y); 
		if (y > max)
			max = y;
		else if (y < min)
			min = y;
	}
	printf("\nmin: %f, max: %f", min, max);
	return 0;
}

