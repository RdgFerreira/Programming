#include "lista.hpp"

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;   //cria o node
    aux->next = nullptr;

    if (head == nullptr) {
        head = aux;
        tail = aux;      //ajusta head/tail
    } else {
    tail->next = aux;
    tail = aux;
    }
}

void List::removeNode(int data) {
    Node *current = head;
    Node *previous = nullptr;
                                    //percorre a lista a partir do início
    while (current != nullptr) {
        if (current->data == data) {
            if (previous == nullptr) { //HEAD: Cabeça aponta para o próximo do Node removido
                head = current->next;
            } else if (current->next == nullptr) { //TAIL: Node anterior não aponta mais para ninguém. Node anterior vida Cauda
                previous->next = nullptr;
                tail = previous;
            } else {
                previous->next = current->next; //OUTRO: Node anterior aponta para o próximo do removido
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void List::display() {
    Node *aux = head;

    while (aux != nullptr) {
        cout << aux->data << "\t";
        aux = aux->next;
    }
    cout << endl;
}

Node* List::busca(int x, List* lista){
   Node *p;
   p = lista->head;
   while (p != nullptr && p->data != x) 
      p = p->next; 
   return p;
}

bool List::busca_recursiva(int x, Node* noh){
    if(noh == nullptr) return false;
    if(noh->data == x) return true;
    return busca_recursiva(x, noh->next);
}

void List::busca_e_insere(int x, int y, Node* noh){
    Node *p, *q, *nova;
    nova = new Node;
    nova->data = x;
    p = noh;
    q = noh->next;
    while(q != nullptr && q->data != y){
        p = q;
        q = q->next;
    }
    nova->next = q;
    p->next = nova;
}

void List::busca_e_remove(int x, Node* noh){
    Node *p, *q;
    p = noh;
    q = noh->next;
    while(q != nullptr && q->data != x){
        p = q;
        q = q->next;
    }
    if(q!=nullptr){
        p->next = q->next;
        delete q;
    }
}