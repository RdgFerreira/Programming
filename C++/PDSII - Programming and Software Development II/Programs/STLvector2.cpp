#include <iostream>
#include <vector>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

int main() {
    Pessoa p1;
    p1.nome = "Ana";
    p1.idade = 25;

    Pessoa p2;
    p2.nome = "Pedro";
    p2.idade = 18;

    Pessoa p3;
    p3.nome = "Douglas";
    p3.idade = 30; 

    vector<Pessoa> pessoas;

    pessoas.push_back(p1);
    pessoas.push_back(p2);
    pessoas.push_back(p3);

    // Primeira forma de acesso
    cout << pessoas[0].nome << endl;
    cout << pessoas[1].nome << endl;

    // Segunda forma, com at
    cout << pessoas.at(2).nome << endl;

    for(Pessoa p : pessoas){
        cout << p.nome << "\t" << p.idade << endl;
    }
    
    return 0;
}
