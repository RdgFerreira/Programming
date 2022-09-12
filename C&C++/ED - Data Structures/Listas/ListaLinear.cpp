#include "ListaLinear.hpp"


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





// LISTA ARRANJO -----------------------------------------------------------------------------------------

TipoItem ListaArranjo::GetItem(int pos) {
    if ( (pos > tamanho) || (pos <= 0) ) {
        throw "ERRO: Posicao Invalida!";
    }

    return itens[pos-1];
}


void ListaArranjo::SetItem(TipoItem item, int pos) { // O(1)
    if ( (pos > tamanho) || (pos <= 0) ) {
        throw "ERRO: Posicao Invalida!";
    }

    itens[pos-1] = item;
}

void ListaArranjo::InsereInicio(TipoItem item) { // O(n) pior caso
    int i;
    if (tamanho == MAXTAM) {
        throw "ERRO: Lista cheia!";
    }
    
    tamanho++;
    for(i = tamanho-1; i > 0; i--) {
        itens[i] = itens[i-1];
    }
    
    itens[0] = item;
}

void ListaArranjo::InsereFinal(TipoItem item) { // O(1)
    if (tamanho == MAXTAM) {
        throw "ERRO: Lista cheia!";
    }

    itens[tamanho] = item;
    tamanho++;
}

void ListaArranjo::InserePosicao(TipoItem item, int pos) {
    int i;

    if (tamanho == MAXTAM) {
        throw "ERRO: Lista cheia!";
    }

    if ( (pos > tamanho+1) || (pos <= 0) ) {
        throw "ERRO: Posicao Invalida!";
    }

    if (pos == (tamanho+1)) {
        return InsereFinal(item);
    }
    else if (pos == 1) {
        return InsereInicio(item);
    }
    else {
        pos--; // posição no vetor = pos-1 (vetor começa em 0)
        tamanho++;
        for(i = tamanho-1; i > pos; i--) { // Pior Caso: O(n) (primeira posição)
            itens[i] = itens[i-1];
        }
        itens[pos] = item;
    }
}

TipoItem ListaArranjo::RemoveInicio() { // O(n)
    int i;
    TipoItem aux;

    if (tamanho == 0) {
        throw "ERRO: Lista vazia!";
    }

    aux = itens[0];

    for(i = 0; i < tamanho; i++) {
        itens[i] = itens[i+1];
    }

    tamanho--;
    return aux;
}

TipoItem ListaArranjo::RemoveFinal() { // O(1)
    TipoItem aux;

    if (tamanho == 0) {
        throw "ERRO: Lista vazia!";
    }

    tamanho--;
    aux = itens[tamanho];
    return aux;
}

TipoItem ListaArranjo::RemovePosicao(int pos) {
    int i; 
    TipoItem aux;

    if ( (pos > tamanho) || (pos <= 0) ) {
        throw "ERRO: Posicao Invalida!";
    }

    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    aux = itens[pos];

    for(i = pos; i < tamanho; i++) {
        itens[i] = itens[i+1];
    }

    tamanho--;
    return aux;
}

TipoItem ListaArranjo::Pesquisa(TipoChave c) { // O(n) pior caso, O(1) melhor caso
    int i; 
    TipoItem aux;

    if (tamanho == 0) {
        throw "ERRO: Lista vazia!";
    }

    aux.SetChave(-1); // indica pesquisa sem sucesso
    for(i = 0; i < tamanho; i++) {
        if(itens[i].GetChave() == c) {  
            aux = itens[i];
            break;
        }
    }
    return aux;
}

void ListaArranjo::Imprime() { // O(n)
    if (tamanho == 0) {
        cout << "ERRO: Lista vazia!" << endl;
        throw "";
    }

    int i;

    cout << "[";

    for (i = 0; i < tamanho; i++) {
        if (i == tamanho-1) {
            cout << itens[i].GetChave();
        }
        else {
            cout << itens[i].GetChave() << ", ";
        }
    }

    cout << "]";
    cout << endl;
}

void ListaArranjo::Limpa() {
    tamanho = 0;
}