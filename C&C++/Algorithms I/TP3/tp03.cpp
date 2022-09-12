#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Tipo Matriz que representa uma célula (macieira) do grid da plantação
// val: armazena a disponibilidade de cada macieira,
// acc: armazena o número total de maçãs colhidas até esta célula considerando um caminho maximal,
// idx: índice da macieira na linha de baixo que maximiza o acumulado de maçãs com a linha atual.
typedef struct Matriz{
    unsigned int val;
    unsigned long long acc;
    unsigned short idx;
} Matriz;


// Funções que retornam os máximos entre acumulados de colheita e que retornam os índices correspondentes.
// Como a colheitadeira pode seguir para 3 possíveis caminhos, realizamos esses cálculos dentre três valores,
// exceto se a colheitadeira se encontra em alguma das extremidades, daí calculamos os máximos e os índices dentre
// dois valores
unsigned long long max_3(unsigned long long a, unsigned long long b, unsigned long long c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

unsigned long long max(unsigned long long a, unsigned long long b) {
    if (a >= b) return a;
    return b;
}

unsigned short index_of_max(unsigned long long a, unsigned long long b, unsigned short a_i, unsigned short b_i) {
    if (a >= b) return a_i;
    return b_i;
}

unsigned short index_of_max_3(unsigned long long a, unsigned long long b, unsigned long long c, unsigned short a_i, unsigned short b_i, unsigned short c_i) {
    if (a >= b && a >= c) return a_i;
    if (b >= a && b >= c) return b_i;
    return c_i;
}

int main(int argc, char * argv[]) {
    // Leitura do Input e definição da Matriz Colheita de acordo com F e W.
    unsigned int F;
    unsigned short W;
    cin >> F >> W;
    vector<vector<Matriz>> Colheita(F,vector<Matriz>(W));

    for (unsigned int i = 0; i < F; i++) {
        for (unsigned short j = 0; j < W; j++) {
            cin >> Colheita[i][j].val;
            // Os campos idx e acc da última linha da matriz serão os próprios índices e os valores de
            // capacidade (Qi) das macieiras.
            if (i == F - 1) {
                Colheita[i][j].acc = Colheita[i][j].val;
                Colheita[i][j].idx = j;
            }
            else {
                Colheita[i][j].acc = 0;
                Colheita[i][j].idx = 0;
            }
        }
    }

    unsigned long long val_max = 0;
    unsigned short idx_max;
    unsigned long long aux;

    // Loop principal do cálculo do caminho de colheita máxima. Para cada célula da matriz, calcula
    // o acumulado de colheita (acc) somando o valor atual (Qi) com o acumulado máximo (Qi+1) dentre as macieiras
    // acessíveis pela colheitadeira na linha de baixo da matriz, armazenando o índice deste máximo na célula atual,
    // indicando um caminho para a colheitadeira para a linha de baixo. Além disso, os valores e os índices da célula
    // com o maior acumulado de maçãs são registrados a cada linha, de modo que, ao fim do loop, teremos o índice
    // da célula com o maior acumulado da matriz na primeira linha, onde começa a colheita. 
    for (unsigned int i = F - 2; i >= 0; i--) {
        val_max = 0;
        for (unsigned short j = 0; j < W; j++) {
            aux = Colheita[i][j].val;

            if (j == 0) {
                Colheita[i][j].acc = aux + max(Colheita[i+1][j].acc, Colheita[i+1][j+1].acc);
                Colheita[i][j].idx = index_of_max(Colheita[i+1][j].acc, Colheita[i+1][j+1].acc, j, j+1);
                if (Colheita[i][j].acc > val_max) {
                    idx_max = j;
                    val_max = Colheita[i][j].acc;
                }
            }
            else if (j == W - 1) {
                Colheita[i][j].acc = aux + max(Colheita[i+1][j-1].acc, Colheita[i+1][j].acc);
                Colheita[i][j].idx = index_of_max(Colheita[i+1][j-1].acc, Colheita[i+1][j].acc, j-1, j);
                if (Colheita[i][j].acc > val_max) {
                    idx_max = j;
                    val_max = Colheita[i][j].acc;
                }
            }
            else {
                Colheita[i][j].acc = aux + max_3(
                    Colheita[i+1][j-1].acc,
                    Colheita[i+1][j].acc,
                    Colheita[i+1][j+1].acc
                );
                Colheita[i][j].idx = index_of_max_3(
                    Colheita[i+1][j-1].acc, Colheita[i+1][j].acc, Colheita[i+1][j+1].acc, j-1, j, j+1
                );
                if (Colheita[i][j].acc > val_max) {
                    idx_max = j;
                    val_max = Colheita[i][j].acc;
                }
            }
        }
        if (i == 0) break;
    }
    

    // Impressão do acumulado máximo da primeira linha, que representa a soma de maçãs do caminho de
    // colheita máxima.
    cout << val_max << endl;
    cout << idx_max << " ";
    
    // Impressão dos índices que representam um caminho de colheita máxima na matriz.
    // A impressão inicia a partir do índice do acumulado máximo e, para cada linha,
    // é impresso o índice armazenado no campo idx da célula e, esse mesmo índice é
    // usado para acessar a célula da linha de baixo, imprimindo os índices com backtracking.
    for (unsigned int i = 0; i < F - 1; i++) {
        if (i) cout << " ";
        cout << Colheita[i][idx_max].idx;
        idx_max = Colheita[i][idx_max].idx;
    }
    return 0;
}