#include <iostream>

int fatorial(int n) {
    if (n > 1)
        return n*fatorial(n-1);
    else return 1;
}

int main() {
    int fat1 = fatorial(3);             //Chamadas de funções vão para o stack
    std::cout << fat1 << std::endl;
    int fat2 = fatorial(10);
    std::cout << fat2 << std::endl;
    return 0;
}
