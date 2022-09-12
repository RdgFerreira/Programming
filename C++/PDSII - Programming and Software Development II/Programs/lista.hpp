#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    void insertNode(int data);
    void removeNode(int data);
    Node* busca(int x, List* lista);
    bool busca_recursiva(int x, Node* noh);
    void busca_e_insere(int x, int y, Node* noh);
    void busca_e_remove(int x, Node* noh);
    void display();
};
#endif
