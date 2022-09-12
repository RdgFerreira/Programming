#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
#include "headers.hpp"

using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[]) {

    /*Interpretação das informações enviadas nos argumentos.*/
    string line;
    ifstream ReadFile(argv[1]);
    int config = stoi(argv[2]);
    int N = stoi(argv[3]);
    int i = 0;

    /*Criação do vetor de Registros e preenchimento dos dados concomitantemente à leitura
    dos dados no arquivo de entradas.*/
    Registro* registros = new Registro[N];

    while (getline(ReadFile, line) && i < N) {
        stringstream reg(line);

        string name;
        getline(reg, name, ' ');
        registros[i].nome = name;

        string data;
        getline(reg, data, ' ');
        registros[i].dado = data;

        i++;
    }

    /*Fechamento da leitura do arquivo de texto.*/
    ReadFile.close();

    // cout << "Registros Originais:==========================================" << endl << endl << endl;
    // Imprime(registros, N);
    // cout << endl << endl << endl << endl;
    // cout << "Registros Ordenados:==========================================" << endl << endl << endl;


    

    if(config == 1) {
        /*Comando de início do timer.*/
        auto start = high_resolution_clock::now();

        Heapsort_int(registros, &N);
        QuickSort_str(registros, N);

        /*Comando de término do timer.*/
        auto stop = high_resolution_clock::now();
        /*Variavel que recebe o tempo de execução, subtraindo o tempo de término
        do tempo de início do timer.*/
        auto duration = duration_cast<microseconds>(stop - start);

        Imprime(registros, N);
        /*
        cout << endl << endl << endl << endl;
        cout << "Tempo tomado pelo metodo " << config << ": " << duration.count();
        cout << " microsegundos" << endl;
        */
    }
    else if(config == 2) {
        auto start = high_resolution_clock::now();

        RadixExchSort_int(registros, 0, N-1);
        QuickSort_str(registros, N);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        Imprime(registros, N);
        /*
        cout << endl << endl << endl << endl;
        cout << "Tempo tomado pelo metodo " << config << ": " << duration.count();
        cout << " microsegundos" << endl;
        */
    }
    else if(config == 3) {
        auto start = high_resolution_clock::now();

        Heapsort_int(registros, &N);
        Mergesort_str(registros, 0, N-1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        Imprime(registros, N);
        /*
        cout << endl << endl << endl << endl;
        cout << "Tempo tomado pelo metodo " << config << ": " << duration.count();
        cout << " microsegundos" << endl;
        */
    }
    else if(config == 4) {
        auto start = high_resolution_clock::now();

        RadixExchSort_int(registros, 0, N-1);
        Mergesort_str(registros, 0, N-1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        Imprime(registros, N);
        /*
        cout << endl << endl << endl << endl;
        cout << "Tempo tomado pelo metodo " << config << ": " << duration.count();
        cout << " microsegundos" << endl;
        */
    }

    delete [] registros;





    return 0;
}