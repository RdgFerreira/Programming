#ifndef TEXTO_H
#define TEXTO_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

struct Texto{
    std::list<std::string> palavras;

    void separa_e_porcentagem(Texto *texto2, std::vector<int> vint, std::vector<float> vfloat);
    void display(std::vector<int> vint, std::vector<float> vfloat);
    void teste();
};
#endif