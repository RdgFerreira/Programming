#include <iostream>
#include "Ponto.hpp"

using namespace std;

int main() {
	Ponto p1;
	Ponto *p2 = new Ponto();

	p1.y = 123;
	p2->y = 321;
	cout << p1.x << "\t" << p1.y << endl;
	cout << p2->x << "\t" << p2->y << endl;

	delete p2;
	return 0;
}