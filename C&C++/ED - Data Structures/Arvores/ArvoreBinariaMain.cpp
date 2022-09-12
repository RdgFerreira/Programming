#include <iostream>
using namespace std;

#include "ArvoreBinaria.hpp"

int main() {
    // g++ ArvoreBinariaMain.cpp ArvoreBinaria.cpp -o ArvoreBinaria

    
    ArvoreBinaria A;
    TipoItem x;
    TipoChave k;

    k = 2;
    x.SetChave(k);
    A.Insere(x);

    k = 1;
    x.SetChave(k);
    A.Insere(x);

    k = 3;
    x.SetChave(k);
    A.Insere(x);

    cout << "Caminhamento por PreOrdem: " << endl;
    A.Caminha(1);
    cout << endl << endl;

    cout << "Caminhamento por InOrdem: " << endl;
    A.Caminha(2);
    cout << endl << endl;

    cout << "Caminhamento por PosOrdem: " << endl;
    A.Caminha(3);
    cout << endl << endl;

    cout << "Caminhamento por Nivel: " << endl;
    A.Caminha(4);
    cout << endl;

    A.Limpa();



    




    return 0;
}