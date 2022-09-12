#include <iostream>
using namespace std;

#include "PilhaEncadeada.hpp"

int main() {
    cout << "Hello, world!" << endl;

    TipoItem x;
    TipoChave k;
    PilhaEncadeada P;
    x.SetChave(k);

    k = 1;
    x.SetChave(k);
    P.Empilha(x);
    P.Imprime();
    cout << "Tamanho: " << P.GetTamanho() << ", Topo: " << P.GetTopo() << endl;
    cout << endl;

    k = 2;
    x.SetChave(k);
    P.Empilha(x);
    P.Imprime();
    cout << "Tamanho: " << P.GetTamanho() << ", Topo: " << P.GetTopo() << endl;
    cout << endl;

    x = P.Desempilha();
    P.Imprime();
    cout << "Tamanho: " << P.GetTamanho() << ", Topo: " << P.GetTopo() << endl;
    cout << endl;

    P.Limpa();
    P.Imprime();
    cout << "Tamanho: " << P.GetTamanho() << endl;
    cout << endl;

    cout << "Ex1 - Aula:" << endl << endl;
    int seq[5] = {1, 2, 3, 4, 5};
    TipoItem x1;
    PilhaEncadeada p1;

    for(int i = 0; i < 5; i++){
        x1.SetChave(seq[i]);
        p1.Empilha(x1);
    }
    
    while(!p1.Vazia()) {
        x1 = p1.Desempilha();
        x1.Imprime();
    }



    return 0;
}