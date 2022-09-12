#include <iostream>
using namespace std;

// Ordem
const int M = 2;

typedef struct Registro {
    int chave;
    // Outros dados:
    // ...
} Registro;

class Pagina {
    int n;
    Registro registros[2*M];
    Pagina *filhos[2*M+1];
    // Operações:

    Registro* Pesquisa(Registro x) {
        if(this == NULL) {
            cout << "Registro nao encontrado!" << endl;
            return NULL; 
        }

        int i = 1;
        while (i < n && x.chave > registros[i-1].chave) i++;

        if (x.chave == registros[i-1].chave) // Encontrou x
            return &registros[i-1];
        
        if (x.chave < registros[i-1].chave)
            return filhos[i-1]->Pesquisa(x);

        else
            return filhos[i]->Pesquisa(x);
    }
};

class ArvoreB {
    Pagina *raiz;
    // Operações:

    ArvoreB() {Inicializa();}
    
    void Inicializa() {
        raiz = NULL;
    }
};

int main() {




    return 0;
}