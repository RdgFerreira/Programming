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

class TipoNo
{
    public:
        TipoNo();
        void Imprime() {
            cout << item.GetChave() << " ";
        }
        
    private:
        TipoItem item;
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void Insere(TipoItem item);
        void Caminha(int tipo);

        void Limpa();

    private:
        void InsereRecursivo(TipoNo* &p, TipoItem item);
        void ApagaRecursivo(TipoNo* p);

        void PorNivel();
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p);
        void PosOrdem(TipoNo* p);

        TipoNo *raiz;
};

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
        FilaArranjo();

        void Enfileira(TipoNo* item);
        TipoNo* Desenfileira();

        int GetFrente() {return frente;};
        int GetTras() {return tras;};
        
        void Imprime();
        void Limpa();

    private:
        int frente;
        int tras;
        static const int MAXTAM = 15;
        TipoNo* nos[MAXTAM];
};