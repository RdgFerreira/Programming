#include "headers.hpp"



// LISTA ENCADEADA =========================================================================================

/*Construtor da célula.*/
TipoCelula::TipoCelula() {
    dado = "";
    prox = NULL;
}

/*Construtor da lista encadeada.*/
ListaEncadeada::ListaEncadeada() { // O(1)
    tamanho = 0;
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

/*Destrutortor da lista encadeada: procedimento limpa trata corretamente as células.*/
ListaEncadeada::~ListaEncadeada() { // O(n)
    Limpa();
    delete primeiro;
}

/*Método usado para as inserções na lista encadeada de cada nó da árvore.*/
void ListaEncadeada::InsereFinal(TipoDado dado) { // O(1)
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->dado = dado;

    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

/*Procedimento soma todos os dados binários em uma lista encadeada, percorrendo todas as
células.*/
int ListaEncadeada::SomaDados() {
    TipoCelula *p;
    p = primeiro->prox;
    int res = 0;

    while (p != NULL) { // O(n)
        res += stoi(p->dado, 0, 2);
        p = p->prox;
    }

    return res;
}

/*Procedimento limpa usado no destrutor da lista encadeada. Deleta os ponteiros a partir
da célula cabeça até que só sobre ela.*/
void ListaEncadeada::Limpa() { // O(n)
    TipoCelula *p;

    p = primeiro->prox;

    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
    tamanho = 0;
}



// ÁRVORE BINÁRIA =========================================================================================

/*Construtor da classe da Árvore Binária. Indica que o nome do primeiro nó ainda não foi impresso.*/
ArvoreBinaria::ArvoreBinaria() {
    primeiro_ja_impresso = false;
    raiz = NULL;
}

/*Destrutor da classe da Árvore Binária. Chama o procedimento que trata os nós adequadamente.*/
ArvoreBinaria::~ArvoreBinaria() {
    ApagaRecursivo(raiz);
    raiz = NULL;
}

/*Procedimento recursivo para inserção de nós na árvore, tomando os nomes como chaves.
Percorre a árvore a partir da raiz e, enquanto não encontra um nó vazio ou um nó com
o mesmo nome, realiza chamadas recursivas para o nó esquerdo (nome é menor na ordem lexicográfica)
ou para o nó direito (nome é menor na ordem lexicográfica). Caso o nome seja igual, apenas
adiciona o dado ao final da lista encadeada do nó, caso o nó seja nulo, cria um novo registro.*/
void ArvoreBinaria::InsereRecursivo(TipoNo* &p, string nome, TipoDado dado) {
    if(p == NULL) {
        p = new TipoNo();
        p->nome = nome;
        p->dados->InsereFinal(dado);
    }
    else if(nome == p->nome) {
        p->dados->InsereFinal(dado);
    }
    else {
        if(nome < p->nome) {
            InsereRecursivo(p->esq, nome, dado);
        }
        else {
            InsereRecursivo(p->dir, nome, dado);
        }
    }
}

/*Procedimento usado no programa principal que recebe o nome e o dado do arquivo de entrada
e chama o procedimento descrito acima com o nó raiz.*/
void ArvoreBinaria::Insere(string nome, TipoDado dado) {
    InsereRecursivo(raiz, nome, dado);
}

/*Procedimento usado na remoção de um nó da árvore, que procura um antecessor 
(filho mais à direita da subárvore da esquerda) para substituir um nó com
2 filhos que está para ser removido.*/
void ArvoreBinaria::Antecessor(TipoNo* q, TipoNo* &r) {
    if(r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }

    q->nome = r->nome;
    q->dados = r->dados;
    q = r;
    r = r->esq;
    free(q);
}

/*Procedimento recursivo de remoção e impressão adequada do nome e da soma dos
dados binários de um nó da árvore. Procura recursivamente até achar o nó com o
nome passado por parâmetro, imprime o nome e a soma dos dados e, por fim, trata
os casos de remoção (nó com 1 ou 0 filhos, ou 2 filhos).*/
void ArvoreBinaria::RemoveRecursivo(TipoNo* &p, string nome) {
    TipoNo *aux;

    if (nome < p->nome)
        return RemoveRecursivo(p->esq, nome);
    else if (nome > p->nome)
        return RemoveRecursivo(p->dir, nome);
    else {
        int soma = p->dados->SomaDados();
        cout << nome << " " << soma << endl;

        /*1 ou 0 filhos.*/
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
        else {
            /*2 filhos.*/
            Antecessor(p, p->esq);
        }
    }
}

/*Procedimento de remoção do nó usado no programa principal que recebe o nome lido no arquivo
de entrada. Chama o procedimento recursivo descrito anteriormente com o nó raiz da árvore.*/
void ArvoreBinaria::Remove_e_Imprime(string nome) {
    return RemoveRecursivo(raiz, nome);
}

/*Método responsável pela impressão InOrdem dos nomes dos nós da árvore binária.
Atualiza a variável "primeiro_ja_impresso" para true para que impressões sejam
realizadas com um espaço à esquerda, assim, não haverá um espaço em branco ao final
da impressão.*/
void ArvoreBinaria::InOrdem(TipoNo* p) {
    if(p != NULL) {
        InOrdem(p->esq);
        if(!primeiro_ja_impresso) {
            cout << p->nome;
            primeiro_ja_impresso = true;
        }
        else {
            cout << " " << p->nome;
        }
        InOrdem(p->dir);
    }
}

/*Procedimento usado no programa principal que chama  a impressão InOrdem a partir do nó raiz.*/
void ArvoreBinaria::Imprime_Arvore() {
    InOrdem(raiz);
}

/*Método recursivo usado no destrutor da classe. Recebe a raiz como parâmetro e deleta PosOrdem
os ponteiros para os nós.*/
void ArvoreBinaria::ApagaRecursivo(TipoNo* p) {
    if(p != NULL) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

/*Método que inverte o sinal lógico da varíavel que controla os espaços vazios na impressão.
É usado no progrma principal após a impressão dos registros removidos.*/
void ArvoreBinaria::Reset() {
    primeiro_ja_impresso = !primeiro_ja_impresso;
}
