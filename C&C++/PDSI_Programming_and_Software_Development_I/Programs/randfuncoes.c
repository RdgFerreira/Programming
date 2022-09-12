#include <stdlib.h>
#include "randfuncoes.h"


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