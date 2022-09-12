#ifndef TESTOBJECT
#define TESTOBJECT

#include <iostream>

using namespace std;

class TestObject {
	int atributo;
	public:
		
		TestObject(int valor) : atributo(valor) {}
		
		~TestObject() {
			cout << "~TestObject" << atributo << endl;
		}
};

#endif