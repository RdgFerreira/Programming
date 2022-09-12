#include "BST.hpp"

NodeT* createNode(int data) {
    NodeT* aux = new NodeT;
    aux->data = data;
    aux->esq = nullptr;
    aux->dir = nullptr;
    return aux;
}

void inorder(NodeT* n){
    if(n == nullptr)
        return;
    inorder(n->esq);
    cout << n->data << " ";
    inorder(n->dir);
}

void BST::insertNodeHelper(NodeT* n, int data){
    if (data < n->data) {             //Caminha p/ esquerda
        if (n->esq == nullptr) {
            n->esq = createNode(data);
        } else {
            insertNodeHelper(n->esq, data);
        }  
    } else if (data > n->data) {       //Caminha p/ direita
        if (n->dir == nullptr) {
                n->dir = createNode(data);
        } else {
            insertNodeHelper(n->dir, data);
        }
    }
}

void BST::insertNode(int data) {
    if (root != nullptr) {
        insertNodeHelper(root, data);
    } else {
        root = createNode(data);
    }
}

void BST::display(){
    inorder(root);
    cout << endl;
}
