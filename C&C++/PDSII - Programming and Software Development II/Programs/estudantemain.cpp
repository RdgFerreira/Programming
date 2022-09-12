#include <iostream>
#include <iomanip>
#include <string>
#include "Estudante.hpp"

using namespace std;

void SelectionSort(Estudante estudantes[], double vetor[], int tam) {
    for (int indice = 0; indice < tam; ++indice) {
        int indiceMenor = indice; 
        for (int indiceSeguinte = indice+1; indiceSeguinte < tam; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        float aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
        Estudante aux2 = estudantes[indice];
        estudantes[indice] = estudantes[indiceMenor];
        estudantes[indiceMenor] = aux2;
    }
}


int main(){
    Estudante estudantes[10];
    double rsg_alunos[10];
    
    for(int i=0; i<10; i++){
        cin >> estudantes[i].matricula;
        cin >> estudantes[i].nome;
        for(int j=0; j<5; j++){
            cin >> estudantes[i].notas[j];
            estudantes[i].notas[j] = float(estudantes[i].notas[j]);
        }
        
        rsg_alunos[i] = estudantes[i].calcularRSG();
    }
    
    SelectionSort(estudantes, rsg_alunos, 10);
    
    Estudante aux;
    
    for(int i=0; i<3; i++){
        if((rsg_alunos[9-i] == rsg_alunos[9-i-1]) && (estudantes[9-i-1].matricula < estudantes[9-i].matricula)){
            aux = estudantes[9-i];
            estudantes[9-i] = estudantes[9-i-1];
            estudantes[9-i-1] = aux;
        }
        cout << estudantes[9-i].matricula << " ";
        cout << estudantes[9-i].nome << " ";
        cout << fixed << setprecision(2) << rsg_alunos[9-i] << endl;
    }