#include <iostream>

int main(){
    int *a = nullptr; //NULL (inválido, não inicializado)
    int b = 10;
    std::cout << b << std::endl;
    a = new int; //malloc
    *a = 20;
    std::cout << *a << std::endl;
    delete a; //free (não apaga, deixa de reservar o endereço de memória)
    a = &b;
    *a = 30;
    std::cout << *a << std::endl;
    std::cout << b << std::endl;
    delete a;

    //vetores:
    int *p = new int[10];
    p[0] = 99;
    p[1] = 98;
    for(int i = 2; i<10; i++){
        p[i] = 2*i;
        std::cout << p[i] << std::endl;
    }
    delete[] p;





    return 0;
}