#ifndef CLASSEATRIBUTOESTATICO
#define CLASSEATRIBUTOESTATICO

#include <iostream>

using namespace std;

class ClasseAtributoEstatico {

public:
	static int numero;
	
	ClasseAtributoEstatico() {
		ClasseAtributoEstatico::numero++;
	}
	
	void imprimirNumero () {
		cout << ClasseAtributoEstatico::numero << endl;
	}
};

#endif