#include <iostream>
using namespace std;

#define MAX 1000

typedef int TipoChave;
typedef struct Registro {
    TipoChave Chave;
    /* Outros campos */
}Registro;

class TabelaBinaria {
    public:
        TabelaBinaria() {}
        TabelaBinaria(int num) : n(num) {}

        void Imprime(int n) {
            cout << "[";
            for(int i = 1; i <= n; i++) {
                if (i == n) {
                    cout << Item[i].Chave;
                    break;
                }
                cout << Item[i].Chave << ", ";
            }
            cout << "]" << endl;
        }
        

        int Pesquisa(TipoChave x) {
            if (n == 0) { /* vetor vazio */
                return 0;
            } 

            int i;
            int Esq = 1;
            int Dir = n;

            do {
                i = (Esq + Dir) / 2;
                if (x > Item[i].Chave) 
                    Esq = i + 1; /* procura na partição direita */
                else
                    Dir = i - 1; /* procura na partição esquerda */
            } while ((x != Item[i].Chave) && (Esq <= Dir));

            if (x == Item[i].Chave)
                return i;
            return 0;
        }

        int n;
        Registro Item[MAX + 1];
};

int main() {
    int n = 5;

    TabelaBinaria tabela1(n);

    for(int i = 1; i <= n; i++) {
        tabela1.Item[i].Chave = i;
    }

    tabela1.Imprime(n);

    cout << endl << "Indice do elemento 3: " << tabela1.Pesquisa(3) << endl;


    return 0;
}