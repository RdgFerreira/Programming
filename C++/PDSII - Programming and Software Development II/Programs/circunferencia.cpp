#include "circunferencia.hpp"

Circunferencia::Circunferencia(double x, double y, double r){
    xc = x;
    yc = y;
    raio = r;
}

double Circunferencia::calcularArea(){
   return M_PI * pow(this->raio, 2);
}

bool Circunferencia::possuiIntersecao(Circunferencia *c){
    double dxy = sqrt(pow(c->xc - this->xc, 2) + pow(c->yc - this->yc, 2));
    double soma_dos_raios = c->raio + this->raio;
    if(dxy <= soma_dos_raios)
        return true;
    return false;
}
