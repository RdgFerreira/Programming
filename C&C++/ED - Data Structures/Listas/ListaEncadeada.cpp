#include "ListaEncadeada.hpp"

// TIPO ITEM -------------------------------------------------------------------------------------------------

TipoItem::TipoItem() {
    chave = -1; // indica um item vazio
}

TipoItem::TipoItem(TipoChave c) {
    chave = c;
}

void TipoItem::SetChave(TipoChave c) {
    chave = c;
}

TipoChave TipoItem::GetChave() {
    return chave;
}

void TipoItem::Imprime() {
    cout << chave << endl;
}





// LISTA ENCADEADA -----------------------------------------------------------------------------------------

TipoCelula::TipoCelula() {
    item.SetChave(-1);
    prox = NULL;
}

ListaEncadeada::ListaEncadeada() : Lista() { // O(1)
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() { // O(n)
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false) { // Melhor caso O(1), Pior caso O(n)
    TipoCelula *p; 
    int i;

    if ( (pos > (tamanho+1)) || (pos <= 0) ) {
        cout << "Posiciona->ERRO: Posicao Invalida!" << endl;
        throw "";
    }
    
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }

    // vai para a próxima se antes for false
    if(!antes) {
        p = p->prox;
    }
    return p;
}

TipoItem ListaEncadeada::GetItem(int pos) {
    TipoCelula *p;

    p = Posiciona(pos);
    return p->item;
}

void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item) { // O(1)
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;

    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if(nova->prox == NULL) {
        ultimo = nova;
    }
};

void ListaEncadeada::InsereFinal(TipoItem item) { // O(1)
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;

    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};

void ListaEncadeada::InserePosicao(TipoItem item, int pos) {
    TipoCelula *p, *nova;

    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;

    if ( (pos > (tamanho+1)) || (pos <= 0) ) {
        cout << "InserePosicao ->ERRO: Posicao Invalida!" << endl;
        throw "";
    }

    if (pos == (tamanho+1)) {
        return InsereFinal(item);
    }
    else if (pos == 1) {
        return InsereInicio(item);
    }
    else {
        nova->prox = p->prox;
        p->prox = nova;
        tamanho++;

        if(nova->prox == NULL) {
            ultimo = nova;
        }
    }
};

TipoItem ListaEncadeada::RemoveInicio() { // O(1)
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0) {
        cout << "ERRO: Lista Vazia!" << endl;
        throw "";
    }

    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;

    if(primeiro->prox == NULL) {
        ultimo = primeiro;
    }

    aux = p->item;
    delete p;

    return aux;
}

TipoItem ListaEncadeada::RemoveFinal() { // O(n)
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0) {
        cout << "ERRO: Lista Vazia!" << endl;
        throw "";
    }
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);

    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;

    return aux;
}

TipoItem ListaEncadeada::RemovePosicao(int pos) { // Melhor caso O(1), Pior caso O(n)
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0) {
        cout << "ERRO: Lista Vazia!" << endl;
        throw "";
    }

    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);

    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;

    if(p->prox == NULL) {
        ultimo = p;
    }

    return aux;
}

TipoItem ListaEncadeada::Pesquisa(TipoChave c) { // Melhor caso O(1), Pior caso O(n)
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0) {
        cout << "Pesquisa->ERRO: Lista vazia!" << endl;
        throw "";
    }

    p = primeiro->prox;
    aux.SetChave(-1);

    while (p!=NULL) {
        if (p->item.GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }

    return aux;
};

void ListaEncadeada::Imprime() {
    TipoCelula *p;
    p = primeiro->prox;

    if (tamanho == 0) {
        cout << "Imprime->ERRO: Lista vazia!" << endl;
        throw "";
    }

    cout << "[";

    while (p != NULL) { // O(n)
        if (p->prox == NULL) {
            cout << p->item.GetChave();
        }
        else {
            cout << p->item.GetChave() << ", ";
        }
        p = p->prox;
    }

    cout << "]";
    cout << endl;
};

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
};