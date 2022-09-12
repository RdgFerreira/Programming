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

class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;
    
    friend class PilhaEncadeada;
};

class PilhaEncadeada : public Pilha
{
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        TipoChave GetTopo();

        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Imprime();
        void Limpa();

    private:
        TipoCelula* topo;
};