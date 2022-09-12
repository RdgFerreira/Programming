#include "estudante.hpp"

float Estudante::calcularRSG(){
    float soma = 0.0;
    float num_notas = 5.0;
    for(int i=0; i<5; i++){
        soma += this->notas[i];
    }
    float media = soma/num_notas;
    return media;
}