#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "headers.hpp"

using namespace std;


int main(int argc, char *argv[]) {

    /*Interpretação das informações enviadas nos argumentos.*/
    string line;
    ifstream ReadFile(argv[1]);

    /*Leitura da primeira linha do arquivo para admissão da quantidade
    de registros a serem processados.*/
    getline(ReadFile, line);
    stringstream reg(line);
    string N;
    getline(reg, N, ' ');
    int maxtam = stoi(N);

    /*Criação da árvore binária que armazenará os nomes e dados.*/
    ArvoreBinaria T;
    string name, data;
    int i = 0;

    /*Loop de leitura controlado pela quantidade de registros no
    arquivo de entrada. Aqui os nomes e dados são admitidos linha
    a linha e tratados no método Insere da árvore binária.*/
    while (i < maxtam) {
        getline(ReadFile, line);
        stringstream reg(line);

        getline(reg, name, ' ');
        getline(reg, data, ' ');

        T.Insere(name, data);
        
        ++i;
    }

    /*Método para a impressão InOrdem da árvore gerada, em que
    as chaves de cada nó correspondem aos nomes.*/
    T.Imprime_Arvore();
    cout << "\n";

    /*Loop de leitura do restante do arquivo de entrada. Aqui
    são lidos os nomes para serem removidos da árvore.*/
    while(getline(ReadFile, line)) { 
        stringstream reg(line);
        getline(reg, name, ' ');

        /*Remoção e impressão do nome e os respectivos dados
        somados*/
        T.Remove_e_Imprime(name);
    }

    /*Impressão da árvore remanescente. Método Reset controla uma
    variável para manter o espaçamento correto na saída padrão.*/
    T.Reset();
    T.Imprime_Arvore();

    /*Fechamento da leitura do arquivo de texto.*/
    ReadFile.close();




    return 0;
}