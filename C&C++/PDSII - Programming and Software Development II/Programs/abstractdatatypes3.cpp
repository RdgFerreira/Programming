#include <iostream>

// Declaração do TAD
struct MyTAD {
    int x = 0;
    void set_x(int x) {
        this->x = x;
    }
    void who_am_i() {
        std::cout << this << std::endl;
    }
};

int main(){
    
    MyTAD tad_stack; // Referência, STACK

    std::cout << &tad_stack << std::endl; //0x61ff04 (e.g)
    tad_stack.who_am_i(); //0x61ff04

    tad_stack.set_x(55);  //Acesso aos dados via método
    std::cout << tad_stack.x << std::endl;
    tad_stack.x = 99; //Acesso direto aos dados
    std::cout << tad_stack.x << std::endl;

    MyTAD *tad_heap = new MyTAD(); // Ponteiro, HEAP

    std::cout << tad_heap << std::endl; //0xeb7f70
    tad_heap->who_am_i(); //0xeb7f70

    delete tad_heap;

    MyTAD outra_var_stack;
    outra_var_stack = tad_stack; //Cópia dos valores

    MyTAD *outra_var_heap;
    outra_var_heap = &tad_stack; //Aponta para o endereço

    return 0;
}















