#ifndef M_PI
#define M_PI 3.14
#endif

#include <cmath>
#include <iomanip>

struct Circunferencia {
    double xc;
    double yc;
    double raio;

    Circunferencia(double, double, double);
    double calcularArea();
    bool possuiIntersecao(Circunferencia*);
};