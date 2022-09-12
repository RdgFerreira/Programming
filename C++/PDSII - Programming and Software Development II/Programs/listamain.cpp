#include <iostream>
#include "lista.hpp"

int main() {
    List lista;

    lista.insertNode(111);
    lista.insertNode(222);
    lista.insertNode(333);
    lista.removeNode(222);
    lista.display();

    Node* aux = lista.busca(111, &lista);
    std::cout << aux->data << std::endl;

    bool aux2 = lista.busca_recursiva(111, lista.head);
    std::cout << aux2 << std::endl;

    lista.busca_e_insere(3, 333, lista.head);
    lista.display();

    lista.busca_e_remove(3, lista.head);
    lista.display();




    
    return 0;
}
