#include <iostream>
#include "Ponto.hpp"

using namespace std;


int main() {

	Ponto p;

	p.setarXY(10, 20);
	
	cout << p.x << endl;
	cout << p.y << endl;
	
	p.setarXY(50);
	
	cout << p.x << endl;
	cout << p.y << endl;

	return 0;
}