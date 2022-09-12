#include <iostream>
using namespace std;

typedef int TipoChave;

typedef struct Item {
    TipoChave chave;
    /* outros componentes */
} Item;

#define Troca(A, B) {Item c = A; A = B; B = c; }

void Selecao (Item *v, int n) { 
    int i, j, Min;

    for (i = 0; i < n - 1; i++) { 
        Min = i;
        for (j = i + 1 ; j < n; j++) {
            if (v[j].chave < v[Min].chave) 
            Min = j;
        }
        Troca(v[i], v[Min]);
    }
}

void Imprime(Item *v, int n) {
    cout << endl << "[";
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            cout << v[i].chave;
        }
        else {
            cout << v[i].chave << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {

    // g++ Selecao.cpp -o Selecao
    // ./Selecao.exe

    int n = 5;
    Item i1;
    i1.chave = 1;
    Item i2;
    i2.chave = 2;
    Item i3;
    i3.chave = 3;
    Item i4;
    i4.chave = 4;
    Item i5;
    i5.chave = 5;
    Item v[n] = {i5, i4, i3, i2, i1};

    Imprime(v, n);
    Selecao(v, n);
    Imprime(v, n);




    return 0;
}