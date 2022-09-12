#include "PilhaSequencial.hpp"

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





// PILHA ARRANJO -----------------------------------------------------------------------------------------

PilhaArranjo::PilhaArranjo() : Pilha() {
    topo = -1;
}

void PilhaArranjo::Empilha(TipoItem item){
    if(tamanho == MAXTAM) {
        cout << "Empilha->ERRO: A pilha está cheia!" << endl;
    }

    topo++;
    itens[topo] = item;
    tamanho++;
};

TipoItem PilhaArranjo::Desempilha(){
    TipoItem aux;

    if(tamanho == 0) {
        cout << "Desempilha->ERRO: A pilha está vazio!" << endl;
    }

    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
};

void PilhaArranjo::Imprime() {
    if (tamanho == 0) {
        cout << "Imprime->ERRO: Pilha vazia!" << endl;
    }

    for (int i = topo; i >= 0; i--) {
        itens[i].Imprime();
    }
}

void PilhaArranjo::Limpa() {
    topo = -1;
    tamanho = 0;
};
