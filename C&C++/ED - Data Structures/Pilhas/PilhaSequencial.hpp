#include <iostream>
using namespace std;

typedef int TipoChave;

class TipoItem 
{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();

    private:
        TipoChave chave;
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
        PilhaArranjo();
        int GetTopo() {return topo;};

        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Imprime();
        void Limpa();

    private:
        int topo;
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
};
