#include <iostream>
#include <iomanip>

int valor_global = 100; //stack(variável global)

double dobrar (double input){
    double dobro = input * 2.0; //stack(variável local)
    return dobro;
}

int main(){
    int idade = 30; //stack(variável local)
    double salario = 12345.67; //stack(variável local)
    double lista[3] = {1.2, 2.3, 3.4}; //stack(variável local)

    std::cout << std::fixed << std::setprecision(2) << dobrar(salario);
    return 0;
}