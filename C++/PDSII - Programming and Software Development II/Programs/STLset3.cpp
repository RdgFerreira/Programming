#include <iostream>
#include <set>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

// Comparador verifica apenas < (outros baseados nele)
struct compara_pessoa_f {
    bool operator()(const Pessoa& p1, const Pessoa& p2) {
        return p1.idade < p2.idade;
    }
};                            //|
                              //|
                              //|------> ordena por ordem crescente de idade
                              //| 
int main() {                  //|
    std::set<Pessoa, compara_pessoa_f> pessoas;

    pessoas.insert({"Douglas", 30});
    pessoas.insert({"Pedro", 18});
    pessoas.insert({"Ana", 25});

    for (Pessoa p : pessoas)
        std::cout << p.nome << std::endl;

    return 0;
}
