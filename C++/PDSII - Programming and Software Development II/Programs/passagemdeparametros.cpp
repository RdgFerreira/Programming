#include <iostream>

using namespace std;

void addOneValue(int x) {
    x = x + 1;
}

void addOneReference(int &x) {
    x = x + 1;
}

void addOnePointer(int *x) {
    *x = (*x) + 1;
}


int main() {
    int a = 0;
    int i = NULL;
    cout << "Antes: " << a << endl;
    addOneValue(a); //(valor)
    cout << "Depois: " << a << endl; //a = 0 (passagem de parametro por valor)
    addOneReference(a);
    cout << "Depois (referencia): " << a << endl;
    addOnePointer(&a);
    cout << "Depois (referencia): " << a << endl;
    return 0;
}