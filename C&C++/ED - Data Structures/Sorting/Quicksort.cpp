#include <iostream>
using namespace std;

typedef int TipoChave;

// PILHA AUXILIAR =============================================================================================

class TipoItem 
{
    public:
        TipoItem() {
            chave = -1; // indica um item vazio
        }

        TipoItem(TipoChave c) {
            chave = c;
        }

        void SetChave(TipoChave c) {
            chave = c;
        }

        TipoChave GetChave() {
            return chave;
        }

        void Imprime() {
            cout << "[" << chave << "]" << endl;
        }
// ===============================================================
        TipoChave chave;
        int esq, dir;
};

class Pilha
{
    public:
        Pilha(){tamanho = 0;};

        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Empilha(TipoItem item) = 0;
        virtual TipoItem Desempilha() = 0;
        virtual void Limpa() = 0;

    protected:
        int tamanho;
};

class PilhaArranjo : public Pilha
{
    public:
        PilhaArranjo() : Pilha() {
            topo = -1;
        }

        int GetTopo() {return topo;};

        void Empilha(TipoItem item) {
            if(tamanho == MAXTAM) {
                cout << "Empilha->ERRO: A pilha está cheia!" << endl;
            }

            topo++;
            itens[topo] = item;
            tamanho++;
        }

        TipoItem Desempilha() {
            TipoItem aux;

            if(tamanho == 0) {
                cout << "Desempilha->ERRO: A pilha está vazio!" << endl;
            }

            aux = itens[topo];
            topo--;
            tamanho--;
            return aux;
        }

        void Imprime() {
            if (tamanho == 0) {
                cout << "Imprime->ERRO: Pilha vazia!" << endl;
            }

            for (int i = topo; i >= 0; i--) {
                itens[i].Imprime();
            }
        }

        void Limpa() {
            topo = -1;
            tamanho = 0;
        }
// ======================================================
        int topo;
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
};










// QUICKSORT =============================================================================================================

typedef struct Item {
    TipoChave chave;
    int esq;
    int dir;
    /* outros componentes */
} Item;

#define Troca(A, B) {Item c = A; A = B; B = c; }

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

void Particao(int Esq, int Dir, int *i, int *j, Item *v) { 
    Item x, w;
    *i = Esq;
    *j = Dir;
    x = v[(*i + *j)/2]; /* obtem o pivo x */

    do { 
        while (x.chave > v[*i].chave) {
            (*i)++;
        }
        while (x.chave < v[*j].chave) {
            (*j)--;
        }
        if (*i <= *j) { 
            w = v[*i]; 
            v[*i] = v[*j]; 
            v[*j] = w;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

/* Entra aqui o procedimento Particao */
void Ordena(int Esq, int Dir, Item *v) {
    int i, j;
    Particao(Esq, Dir, &i, &j, v);
    if (Esq < j) Ordena(Esq, j, v);
    // Imprime(v, );
    if (i < Dir) Ordena(i, Dir, v);
}

void QuickSort(Item *v, int n) { 
    Ordena(0, n-1, v); 
}

/*
void Particao2(int Esq, int Dir, int *i, int *j, TipoItem *v) { 
    TipoItem x, w;
    *i = Esq;
    *j = Dir;
    x = v[(*i + *j)/2];

    do { 
        while (x.chave > v[*i].chave) {
            (*i)++;
        }
        while (x.chave < v[*j].chave) {
            (*j)--;
        }
        if (*i <= *j) { 
            w = v[*i]; 
            v[*i] = v[*j]; 
            v[*j] = w;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}


void QuickSortNaoRec(TipoItem *v, int n) {
    PilhaArranjo pilha; 
    TipoItem item; // campos esq e dir
    int esq, dir, i, j;
    // FPVazia(&pilha);
    esq = 0;
    dir = n-1;
    item.dir = dir;
    item.esq = esq;
    pilha.Empilha(item);

    do {
        if (dir > esq) {
            Particao2(esq, dir, &i, &j, v);

            if ((j-esq) > (dir-i)) {
                item.dir = j;
                item.esq = esq;
                pilha.Empilha(item);
                esq = i;
            }
            else {
                item.esq = i;
                item.dir = dir;
                pilha.Empilha(item);
                dir = j;
            }
        }
        else {
            TipoItem aux = pilha.Desempilha();
            dir = item.dir;
            esq = item.esq;
        }
    } while (pilha.GetTamanho() != 0);
}
*/

/*
void Imprime2(TipoItem *v, int n) {
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
*/

int main() {

    // g++ Quicksort.cpp -o Quicksort
    // ./Quicksort.exe

    int n = 7;
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
    Item i7;
    i7.chave = 7;
    Item v[n] = {i3, i6, i4, i5, i1, i7, i2};

    // int i = 0;
    // int j = n-1;

    Imprime(v, n);
    QuickSort(v, n);
    //Particao(i, j, &i, &j, v);
    Imprime(v, n);

    /*
    TipoItem I1;
    I1.SetChave(1);
    TipoItem I2;
    I2.SetChave(2);
    TipoItem I3;
    I3.SetChave(3);
    TipoItem I4;
    I4.SetChave(4);
    TipoItem I5;
    I5.SetChave(5);
    TipoItem I6;
    I6.SetChave(6);
    TipoItem I7;
    I7.SetChave(7);
    TipoItem V1[n] = {I3, I6, I4, I5, I1, I7, I2};

    Imprime2(V1, n);
    QuickSortNaoRec(V1, n);
    Imprime2(V1, n);
    */



    return 0;
}