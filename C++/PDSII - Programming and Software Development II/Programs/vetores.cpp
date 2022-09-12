#include <iostream>

using namespace std;

int main() {
    int vetorA[5]; //posições não inicializadas
    vetorA[3] = 99;
    for(int i=0; i<5; i++)
        cout << vetorA[i] << "\t";
    cout << endl;

    int vetorB[5] = {}; //posições inicializadas em 0
    for(int i=0; i<5; i++)
        cout << vetorB[i] << "\t";
    cout << endl;

    double vetorC[] = {1.1, 2.2, 3.3}; //alocação e inicialização
    cout << vetorC[1] << endl;
    return 0;
}
