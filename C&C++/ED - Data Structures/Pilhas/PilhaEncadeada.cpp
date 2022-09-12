#include "PilhaEncadeada.hpp"

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
    cout << "[" << chave << "]" << endl;
}





// PILHA ENCADEADA -----------------------------------------------------------------------------------------

TipoCelula::TipoCelula() {
    item.SetChave(-1);
    prox = NULL;
};

PilhaEncadeada::PilhaEncadeada() : Pilha() {
    topo = NULL;
};

PilhaEncadeada::~PilhaEncadeada() {
    Limpa();
};

TipoChave PilhaEncadeada::GetTopo() {
    if (tamanho == 0) {
        cout << "NULL" << endl << endl;
        throw "";
    }
    else {
        return topo->item.GetChave();
    }
};

void PilhaEncadeada::Empilha(TipoItem item){
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;

    nova->prox = topo;
    topo = nova;
    tamanho++;
};

TipoItem PilhaEncadeada::Desempilha(){
    TipoItem aux; TipoCelula *p;

    if(tamanho == 0) {
        cout << "Desempilha->ERRO:A pilha esta vazia!" << endl;
        throw "";
    }

    aux = topo->item;

    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
};

void PilhaEncadeada::Imprime() {
    if (tamanho == 0) {
        cout << "Imprime->ERRO: Pilha vazia!" << endl;
        return;
    }
    
    TipoCelula* p = topo;
    while (p != NULL) {
        p->item.Imprime();
        p = p->prox;
    }
};

void PilhaEncadeada::Limpa() {
    while(!Vazia()) {
        Desempilha();
    }
};


