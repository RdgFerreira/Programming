#include <iostream>

using namespace std; //exclui a necessidade de usar constantemente "std::"

int main() {

    unsigned int values[5] = {2, 4, 6, 8, 10};
    unsigned int *v_ptr = nullptr;
    for(int i=0; i<5; i++){
        cout << values[i] << " ";
    }
    
    cout << endl;
    
    v_ptr = &(*values);
    cout << *v_ptr << endl;
    v_ptr = values;
    cout << *v_ptr << endl;

    /*
    int *ptr_a = nullptr;
    // ptr_a = new int;

    if (ptr_a == nullptr) {
        cout << "Memoria nao alocada!" << endl;
    }

    cout << "Endereco de ptr_a: " << ptr_a << endl;
    *ptr_a = 90;
    cout << "Conteudo de ptr_a: " << *ptr_a << endl;
    delete ptr_a;
    */





    return 0;
}
