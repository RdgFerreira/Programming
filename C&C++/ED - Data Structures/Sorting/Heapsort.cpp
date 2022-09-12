#include <iostream>
using namespace std;

typedef int TipoChave;

typedef struct Item {
    TipoChave chave;
    /* outros componentes */
} Item;

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

void Refaz(int Esq, int Dir, Item *v) {
    int i, j;
    Item x;
    i = Esq;
    j = i * 2;
    x = v[i-1];

    while (j <= Dir) {
        if (j < Dir) {
            if (v[j-1].chave < v[j].chave) {
                j++;
            }
        }

        if (x.chave >= v[j-1].chave) {
            break;
        }

        v[i-1] = v[j-1];
        i = j;
        j = i * 2;
    }
    v[i-1] = x;
}

void Constroi(Item *v, int n) {
    int Esq;
    Esq = (n / 2) + 1;
    while (Esq > 1) {
        Esq--;
        Refaz(Esq, n, v);
    }
}

/*
Item RetiraMax(Item *v, int *n) {
    Item Maximo;

    if (*n < 1) {
        cout << "Erro: heap vazio!" << endl;
    } else { 
        Maximo = v[1]; 
        v[1] = v[*n]; 
        (*n)--;
        Refaz(1, (*n)--, v);
    }

    return Maximo;
}
*/

void Heapsort(Item *v, int *n) {
    int Esq, Dir;
    Item x;
    Constroi(v, *n); /* constroi o heap */
    Esq = 1; 
    Dir = (*n);
    int trocas = 0;

    while (Dir > 1) { /* ordena o vetor */
        x = v[0]; 
        v[0] = v[Dir-1]; 
        v[Dir-1] = x; 
        Dir--;
        trocas++;
        if(trocas == 4) {
            Imprime(v,9);
        }
        Refaz(Esq, Dir, v);
    }
}


int main() {
    // g++ Heapsort.cpp -o Heapsort

    int n = 9;
    int vec[n] = {8,10,12,6,4,18,2,14,16};
    Item v[n];
    for(int i = 0; i < n; i++) {
        Item aux;
        aux.chave = vec[i];
        v[i] = aux;
    }
    /*
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
    Item i6;
    i6.chave = 6;
    */
    // Item v[n] = {i5, i4, i3, i2, i1};

    Imprime(v, n);
    Heapsort(v, &n);
    Imprime(v, n);

    /*
    n = 6;
    Item i7;
    i7.chave = 7;
    Item i11;
    i11.chave = 11;
    Item i12;
    i12.chave = 12;
    Item i13;
    i13.chave = 13;

    Item V1[n] = {i12, i11, i13, i5, i6, i7};

    Imprime(V1, n);
    Heapsort(V1, &n);
    Imprime(V1, n);
    */

    return 0;
}