#include <iostream>
using namespace std;

#include "ListaLinear.hpp"

int main() {
    cout << "Hello, World!" << endl;

    TipoChave k = 1;
    TipoItem x;
    ListaArranjo L;
    int pos = 1;

    x.SetChave(k);
    L.InsereInicio(x);     
    L.Imprime();
    cout << "Item na primeira posicao: " << x.GetChave() << endl;
    cout << endl;


    k = 2;
    x.SetChave(k);
    L.SetItem(x, pos);
    L.Imprime();
    cout << "Item na primeira posicao: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 3;
    x.SetChave(k);
    L.InsereFinal(x);       
    pos = L.GetTamanho();
    L.Imprime();
    cout << "Item na ultima posicao: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 1;
    pos = 1;
    x.SetChave(k);
    L.InserePosicao(x, pos);
    L.Imprime();
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 5;
    pos = 4;
    x.SetChave(k);
    L.InserePosicao(x, pos);
    L.Imprime();
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 4;
    pos = 4;
    x.SetChave(k);
    L.InserePosicao(x, pos);
    L.Imprime();
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    x = L.RemoveInicio();
    L.Imprime();
    cout << "Primeiro elemento removido: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    x = L.RemoveFinal();
    L.Imprime();
    cout << "Ultimo elemento removido: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    pos = 2;
    x = L.RemovePosicao(pos);
    L.Imprime();
    cout << "Elemento removido: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 4;
    x = L.Pesquisa(k);
    L.Imprime();
    cout << "Elemento pesquisado: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    k = 5; // Chave inexistente
    x = L.Pesquisa(k);
    L.Imprime();
    cout << "Elemento pesquisado: " << x.GetChave() << endl;
    cout << "Tamanho: " << L.GetTamanho() << endl;
    cout << endl;

    L.Limpa();
    cout << "Tamanho: " << L.GetTamanho() << endl;
    L.Imprime();


    return 0;
}

