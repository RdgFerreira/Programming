#include <iostream>
#include "TestObject.hpp"

using namespace std;

int main() {

	TestObject o1(1);
	TestObject* o2 = new TestObject(2);
	delete (o2);
	return 0;
}