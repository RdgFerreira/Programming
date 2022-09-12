#include <iostream>
using namespace std;

#define MAX 1000

typedef int TipoChave;
typedef struct Registro {
    TipoChave Chave;
    /* Outros campos */
}Registro;

class Tabela {
    public:
        Tabela() {}
        Tabela(int num) : n(num) {}

        void Imprime(int n) {
            cout << "[";
            for(int i = 1; i <= n; i++) {
                if (i == n) {
                    cout << Itens[i].Chave;
                    break;
                }
                cout << Itens[i].Chave << ", ";
            }
            cout << "]" << endl;
        }
        

        int Pesquisa(TipoChave x) {
            Itens[0].Chave = x; /* sentinela */
            int i = n + 1;
            do {
                i--;
            } while (Itens[i].Chave != x);
            return i;
        }

        int n;
        Registro Itens[MAX + 1];
};

int main() {
    int n = 5;

    Tabela tabela1(n);

    for(int i = 1; i <= n; i++) {
        tabela1.Itens[i].Chave = i;
    }

    tabela1.Imprime(n);

    cout << endl << "Indice do elemento 3: " << tabela1.Pesquisa(3) << endl;


    return 0;
}