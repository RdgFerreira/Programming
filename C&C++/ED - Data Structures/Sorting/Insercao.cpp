#include <iostream>
using namespace std;

typedef int TipoChave;

typedef struct Item {
    TipoChave chave;
    /* outros componentes */
} Item;

// #define Troca(A, B) {Item c = A; A = B; B = c; }

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

void Insercao(Item *v, int n) {
    int i,j;
    Item aux;
    int trocas = 0;

    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;

        while (( j >= 0 ) && (aux.chave < v[j].chave)) {
            v[j + 1] = v[j];
            j--;
            trocas++;
            if(trocas == 4) {
                Imprime(v,n);
            }
        }

        v[j + 1] = aux;
    }
}

void Insercao_sentinela(Item *v, int n){ 
    int i, j;
    Item aux;

    for (i = 2; i <= n; i++) { 
        aux = v[i]; 
        j = i - 1;
        v[0] = aux; /* sentinela */

        while (aux.chave < v[j].chave){
            v[j+1] = v[j]; 
            j--;
        }

        v[j+1] = aux;
    }
}

int main() {

    // g++ Insercao.cpp -o Insercao
    // ./Insercao.exe

    int n = 10;
    int vec[n] = {20,15,10,5,30,25,50,45,40,35};
    Item v[n];
    for(int i = 0; i < n; i++) {
        Item aux;
        aux.chave = vec[i];
        v[i] = aux;
    }

    Imprime(v, n);
    Insercao(v, n);
    Imprime(v, n);




    return 0;
}