#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    for(int i = 10; i >= 1; i--) {
        s.insert(i);
    }

    s.insert(7); //Nao faz nada, 7 ja esta no conjunto

    for(int i = 2; i <= 10; i += 2) {
        s.erase(i);
    }

    std::cout << "(" << s.size() << ")" << std::endl;

    for (int e : s) {
        std::cout << e << std::endl; //Como os elementos estao armazenados em uma BST, eles serao impressos em ordem.
    }
    
    return 0;
}
