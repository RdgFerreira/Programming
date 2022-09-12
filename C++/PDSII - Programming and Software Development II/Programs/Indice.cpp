#include "Indice.hpp"
#include <iostream>
#include <list>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

void Texto::separa_e_porcentagem(Texto *texto2, std::vector<int> vint, std::vector<float> vfloat){
    int count = this->palavras.size();
    for(std::list<std::string>::iterator it=this->palavras.begin(); it != this->palavras.end(); ++it){
        if((*it).length() >= 3){
            texto2->palavras.push_back(*it);
        }
    }
    texto2->palavras.sort();
    int count2 = 0;
    for(std::list<std::string>::iterator it=texto2->palavras.begin(); it != texto2->palavras.end(); ++it){
        count = 0;
        for(std::list<std::string>::iterator it2=texto2->palavras.begin(); it2 != texto2->palavras.end(); ++it2){
            if(*it == *it2){
                count2++;
            }
        }
        vint.push_back(count);
        vfloat.push_back(float(count2)/float(count));
    }
}

void Texto::display(std::vector<int> vint, std::vector<float> vfloat){
    int i = 0;
    std::list<std::string>::iterator it=this->palavras.begin();
    while(it != this->palavras.end()){
        std::cout << *it << " " << vint[i] << " " << std::fixed << std::setprecision(2) << vfloat[i] << std::endl;
        ++it;
        i++;
    }
}

void Texto::teste(){
    std::cout << "Teste" << std::endl;
}