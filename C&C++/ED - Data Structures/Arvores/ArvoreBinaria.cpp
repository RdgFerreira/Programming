#include "ArvoreBinaria.hpp"

// TIPO ITEM ===========================================================================================================================

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
    cout << chave << " ";
}








// FILA AUXILIAR ========================================================================================================================

FilaArranjo::FilaArranjo() : Fila() {
    frente = 0;
    tras = 0;
}

void FilaArranjo::Enfileira(TipoNo *no) {
    if (tamanho == MAXTAM) {
        cout << "Enfileira->ERRO: Fila cheia!";
        return;
    }

    nos[tras] = no;
    // fila circular
    tras = (tras + 1) % MAXTAM; 
    tamanho++;
}

TipoNo* FilaArranjo::Desenfileira() {
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


void FilaArranjo::Imprime() {
    if (tamanho == 0) {
        cout << "Desenfileira->ERRO: Fila vazia!";
        return;
    }

    for(int i = this->GetFrente(); i < this->GetTras(); i++) {
        (*nos[i]).Imprime();
    }
}


void FilaArranjo::Limpa() {
    frente = 0;
    tras = 0;
    tamanho = 0;
}









// ARVORE BINARIA ========================================================================================================================

TipoNo::TipoNo() {
    item.SetChave(-1);
    esq = NULL;
    dir = NULL;
}

ArvoreBinaria::ArvoreBinaria() {
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
}

void ArvoreBinaria::Insere(TipoItem item) {
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item) {
    if(p == NULL) {
        p = new TipoNo();
        p->item = item;
    }
    else if(item.GetChave() < p->item.GetChave()) {
        InsereRecursivo(p->esq, item);
    }
    else {
        InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p) {
    if(p != NULL) {
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p) {
    if(p != NULL) {
        PreOrdem(p->esq);
        p->item.Imprime();
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p) {
    if(p != NULL) {
        PreOrdem(p->esq);
        PreOrdem(p->dir);
        p->item.Imprime();
    }
}


void ArvoreBinaria::PorNivel() {
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

void ArvoreBinaria::Caminha(int tipo) {
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


void ArvoreBinaria::Limpa() {
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p) { // Apaga PosOrdem
    if(p != NULL) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
