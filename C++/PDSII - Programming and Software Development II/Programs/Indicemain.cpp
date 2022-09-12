#include "Indice.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

/*
void slice(std::string palavra, std::list<std::string> &palavras) {
    std::string aux = "";
    for(auto &i:palavra){
        if(i == ' '){
            palavras.push_back(aux);
            aux = "";
        }else{
            aux += i;
        }
    }
    palavras.push_back(aux);
}
*/

int main(){
    Texto *texto1 = new Texto;
    std::string palavra;
    Texto* texto2 = new Texto;
    std::vector<int> vint;
    std::vector<float> vfloat;
    //texto1.teste();
    
    //getline(std::cin, palavra);
    
    while(std::cin >> palavra){ //!palavra.empty()
        //std::cout << palavra << std::endl;
        texto1->palavras.push_back(palavra);
        //std::cout << texto1->palavras.back() << " ";
    }
    
    for(std::list<std::string>::iterator it=texto1->palavras.begin(); it != texto1->palavras.end(); ++it){
        std::cout << *it << " ";
    }
    texto1->separa_e_porcentagem(texto2, vint, vfloat);
    
    texto2->display(vint, vfloat);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
    