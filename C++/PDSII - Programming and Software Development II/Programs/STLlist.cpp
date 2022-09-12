#include <iostream>
#include <list>

int main() {
    std::list<std::string> l = {"ola", "mundo", "hello", "world"};
    // Adicionar um número inteiro no início (frente) da lista
    l.push_front("25");
    // Adicionar um número inteiro no final da lista
    l.push_back("25");
    
    for (std::list<std::string>::iterator it=l.begin(); it != l.end(); ++it) {
        std::cout << *it << " " << (*it).size() <<  std::endl;
    }
    std::cout << l.size();

    return 0;
}
