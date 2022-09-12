#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TIPO DADO =========================================================================================
/*Tipo string simples para armazenar um dado binário.*/

typedef string TipoDado;



// TIPO CÉLULA =========================================================================================
/*Classe de Lista Encadeada, responsável por armazenar os dados binários para cada nome.*/

class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoDado dado;
        TipoCelula *prox;

    friend class ListaEncadeada;
};




// LISTA ENCADEADA =========================================================================================
/*Classe principal da Lista Encadeada, que possui os métodos necessários para armazenar os dados e,
posteriormente na classe da árvore, somá-los quando necessário.*/

class ListaEncadeada 
{
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void InsereFinal(TipoDado dado);

        int SomaDados();

        void Limpa();    

    private:
        int tamanho;
        TipoCelula* primeiro;
        TipoCelula* ultimo; 
        TipoCelula* Posiciona(int pos, bool antes);
};



// TIPO NÓ =========================================================================================
/*Nó da árvore binária, que contém um nome e os dados associados, bem como outros
nós esquerdo e direito para os filhos.*/

class TipoNo 
{
    public:
        TipoNo() {
            dados = new ListaEncadeada();
            esq = NULL;
            dir = NULL;
        }

        string nome;
        ListaEncadeada *dados;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};


// ÁRVORE BINÁRIA =======================================================================================
/*Classe principal da árvore binária. Possui métodos para inserção, remoção, obtenção do antecessor,
impressão InOrdem e para o destrutor da classe.*/

class ArvoreBinaria {
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();


        void InsereRecursivo(TipoNo* &p, string nome, TipoDado dado);

        void Insere(string nome, TipoDado dado);

        void Antecessor(TipoNo* q, TipoNo* &r);

        void RemoveRecursivo(TipoNo* &p, string nome);

        void Remove_e_Imprime(string nome);

        void InOrdem(TipoNo* p);

        void Imprime_Arvore();

        void ApagaRecursivo(TipoNo* p);

        void Reset();

    private:
        /*Variável usada para controlar o uso de espaços entre impressões de nós da árvore.
        Indica se o nome do primeiro nó de uma árvore binária já foi impresso*/
        bool primeiro_ja_impresso;
        TipoNo *raiz;
};