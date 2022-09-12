#include <iostream>
using namespace std;

typedef int TipoChave;

typedef struct Item {
    TipoChave chave;
    /* outros componentes */
} Item;

#define Troca_item(A, B) {Item c = A; A = B; B = c; }
#define Troca(A, B) {int c = A; A = B; B = c; }

void Bolha_item(Item *v, int n) {
    int i, j, trocou;

    for(i = 0; i < n-1; i++) {
        trocou = 0;

        for(j = 1; j < n-i; j++) {
            if (v[j].chave < v[j-1].chave) { 
                Troca_item(v[j-1], v[j]);
                trocou = 1;
            }
        }

        if(!trocou) {
            break;
        }
    }
}

void Imprime_item(Item *v, int n) {
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

// ============================================================

void Imprime(int *v, int n) {
    cout << endl << "[";
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            cout << v[i];
        }
        else {
            cout << v[i] << ", ";
        }
    }
    cout << "]" << endl;
}

void Bolha(int *v, int n) {
    int i, j, trocou, trocas;
    trocas = 0;

    for(i = 0; i < n-1; i++) {
        trocou = 0;

        for(j = 1; j < n-i; j++) {
            if (v[j] < v[j-1]) { 
                Troca(v[j-1], v[j]);
                trocou = 1;
                trocas++;
                if (trocas == 4) {
                    Imprime(v, n);
                }
            }
        }

        if(!trocou) {
            break;
        }
    }
}

int main() {

    // g++ Bolha.cpp -o Bolha
    // ./Bolha.exe

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
    Item v1[n] = {i5, i4, i3, i2, i1};

    Imprime_item(v1, n);
    Bolha_item(v1, n);
    Imprime_item(v1, n);

    cout << endl << endl << endl << endl;

    n = 10;
    int v2[n] = {35, 10, 40, 25, 45, 30, 50, 5, 20, 15};

    Imprime(v2, n);
    Bolha(v2, n);
    Imprime(v2, n);





    return 0;
}