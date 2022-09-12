#include <iostream>
using namespace std;









// TIPOS CHAVE, ITEM E NÓ ===================================================================

typedef int TipoChave;

class TipoItem {
    public:
        TipoItem() {
            Chave = -1;
        }

        void setChave(int k) {
            Chave = k;
        }

        TipoChave getChave() {
            return Chave;
        }

        void Imprime() {
            cout << Chave << " ";
        }

        TipoChave Chave;
};

class TipoNo {
    public:
        TipoNo() {
            item.setChave(-1);
            esq = NULL;
            dir = NULL;
        }

        TipoItem item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};









// FILA AUXILIAR =========================================================================

class Fila
{
    public:
        Fila() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Enfileira(TipoNo *item) = 0;
        virtual TipoNo* Desenfileira() = 0;
        virtual void Limpa() = 0;

    protected:
        int tamanho;
};

class FilaArranjo : public Fila
{
    public:
        FilaArranjo() : Fila() {
            frente = 0;
            tras = 0;
        }

        void Enfileira(TipoNo* no) {
            if (tamanho == MAXTAM) {
                cout << "Enfileira->ERRO: Fila cheia!";
                return;
            }

            nos[tras] = no;
            // fila circular
            tras = (tras + 1) % MAXTAM; 
            tamanho++;
        }

        TipoNo* Desenfileira() {
            TipoNo *aux;

            if (tamanho == 0) {
                cout << "Desenfileira->ERRO: Fila vazia!";
                throw "";
            }

            aux = nos[frente];
            // fila circular
            frente = (frente + 1) % MAXTAM; 
            tamanho--;
            return aux;
        }

        int GetFrente() {return frente;};
        int GetTras() {return tras;};
        
        // void Imprime();
        void Limpa() {
            frente = 0;
            tras = 0;
            tamanho = 0;
        }

    private:
        int frente;
        int tras;
        static const int MAXTAM = 15;
        TipoNo* nos[MAXTAM];
};









// BST =======================================================================================

class ArvoreBinaria {
    public:
        ArvoreBinaria() {
            raiz = NULL;
        }
        ~ArvoreBinaria() {
            Limpa();
        }


        void InsereRecursivo(TipoNo* &p, TipoItem item) {
            if(p == NULL) {
                p = new TipoNo();
                p->item = item;
            }
            else {
                if(item.getChave() < p->item.getChave())
                    InsereRecursivo(p->esq, item);
                else
                    InsereRecursivo(p->dir, item);
            }
        }

        void Insere(TipoItem item) {
            InsereRecursivo(raiz,item);
        }

        TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave) {
            TipoItem aux;

            if (p == NULL) {
                aux.setChave(-1); // Flag para item não presente
                return aux;
            }

            if (chave < p->item.getChave()) return PesquisaRecursivo(p->esq, chave);

            else if (chave > p->item.getChave()) return PesquisaRecursivo(p->dir, chave);

            else return p->item;
        }

        TipoItem Pesquisa(TipoChave chave) {
            return PesquisaRecursivo(raiz, chave);
        }

        void Antecessor(TipoNo* q, TipoNo* &r) {
            if(r->dir != NULL) {
                Antecessor(q, r->dir);
                return;
            }

            q->item = r->item;
            q = r;
            r = r->esq;
            free(q);
        }

        void RemoveRecursivo(TipoNo* &p, TipoChave chave) {
            TipoNo *aux;

            if (p == NULL) {
                cout << "Item nao está presente" << endl;
                return;
            }

            if (chave < p->item.getChave())
                return RemoveRecursivo(p->esq, chave);
            else if (chave > p->item.getChave())
                return RemoveRecursivo(p->dir, chave);
            else {
                if (p->dir == NULL) {
                    aux = p;
                    p = p->esq;
                    free(aux);
                }
                else if(p->esq == NULL) {
                    aux = p;
                    p = p->dir;
                    free(aux);
                }
                else
                    Antecessor(p, p->esq);
            }
        }

        void Remove(TipoChave chave) {
            return RemoveRecursivo(raiz, chave);
        }

        void ApagaRecursivo(TipoNo* p) {
            if(p != NULL) {
                ApagaRecursivo(p->esq);
                ApagaRecursivo(p->dir);
                delete p;
            }
        }

        void Limpa() {
            ApagaRecursivo(raiz);
            raiz = NULL;
        }

        void PreOrdem(TipoNo* p) {
            if(p != NULL) {
                p->item.Imprime();
                PreOrdem(p->esq);
                PreOrdem(p->dir);
            }
        }

        void InOrdem(TipoNo* p) {
            if(p != NULL) {
                InOrdem(p->esq);
                p->item.Imprime();
                InOrdem(p->dir);
            }
        }

        void PosOrdem(TipoNo* p) {
            if(p != NULL) {
                PosOrdem(p->esq);
                PosOrdem(p->dir);
                p->item.Imprime();
            }
        }

        void PorNivel() {
            FilaArranjo F; // fila de apontadores para nos
            TipoNo *p;
            F.Enfileira(raiz);

            while(!F.Vazia()) {
                p = F.Desenfileira();
                
                if(p != NULL) {
                    p->item.Imprime();
                    F.Enfileira(p->esq);
                    F.Enfileira(p->dir);
                }
            }
        }

        void Caminha(int tipo) {
            if (tipo == 1) {
                PreOrdem(raiz);
                return;
            }
            else if (tipo == 2) {
                InOrdem(raiz);
                return;
            }
            else if (tipo == 3) {
                PosOrdem(raiz);
                return;
            }
            else if (tipo == 4) {
                PorNivel();
                return;
            }
        }

        TipoNo *raiz;
};











int main() {
    ArvoreBinaria T;
    int n = 7;

    TipoChave Chaves[n] = {4, 2, 3, 6, 7, 1, 5};
    TipoItem Itens[n];

    for(int i = 0; i < n; i++) Itens[i].Chave = Chaves[i];

    for(TipoItem k : Itens) T.Insere(k);

    cout << "PreOrdem:  ";
    T.Caminha(1);
    cout << endl << endl;
    
    cout << "InOrdem:  ";
    T.Caminha(2);
    cout << endl << endl;

    cout << "PosOrdem:  ";
    T.Caminha(3);
    cout << endl << endl;

    cout << "PorNivel:  ";
    T.Caminha(4);
    cout << endl << endl;

    T.Remove(7);
    cout << "PorNivel apos remover chave 4:  ";
    T.Caminha(4);
    cout << endl << endl;

    T.Remove(2);
    cout << "PorNivel apos remover chave 2:  ";
    T.Caminha(4);
    cout << endl << endl;

    T.Remove(4);
    cout << "PorNivel apos remover chave 4:  ";
    T.Caminha(4);
    cout << endl << endl;





    return 0;
}