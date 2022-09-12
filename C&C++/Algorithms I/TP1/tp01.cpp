#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;



/* Tipo de Dado que representa o cliente: possui id, localização,
id da loja alocada (junto com a distância para essa loja) e o ticket
(calculado e atribuído durante a leitura dos dados).*/
typedef struct Cliente {
    int id;
    int cliente_x;
    int cliente_y;
    int id_loja;
    int distancia_loja_alocada;
    double ticket;
} Cliente;


/*Tipo de dado que representa a loja: possui id, capacidade (estoque atual),
localização, número de clientes ofertados até então e um vetor de clientes
alocados para essa loja*/
typedef struct Loja {
    int id;
    int capacidade;
    int loja_x;
    int loja_y;
    int clientes_ofertados;

    vector<Cliente> clientes;
} Loja;



/*Função booleana usada para reger a ordenação de um vetor de clientes, de modo que,
uma vez que a lista de preferência de todas as lojas é a mesma (pois é baseada nos tickets),
a admissão/impressão de clientes usando esse vetor já respeite a ordem decrescente
de tickets e, em caso de empate, a ordem crescente de ids.*/
bool cmpCliente(Cliente a, Cliente b) {
    if(a.ticket > b.ticket) { 
        return true;
    } 
    else if(a.ticket == b.ticket) { 
        return a.id < b.id;
    }
    else {
        return false;
    }
}


/*Função usada no casamento para encontrar o indice de um cliente específico do vetor de clientes
de uma loja, a fim de removê-lo, pois é o caso de que escolheu uma loja mais perto.*/
int findIndexVector(vector<Cliente>& V, int &id) {
    int i = 0;
    while(V[i].id != id) {
        i += 1;
    }
    return i;
}

/*Procedimento que calcula a distância entre um cliente e uma loja.*/
int distancia(Cliente &C, Loja &L) {
    return max(abs(L.loja_x - C.cliente_x), abs(L.loja_y - C.cliente_y));
}

/*Procedimeto que realiza as modificações necessárias para a alocação de um cliente para uma loja*/
void alocacao(Cliente& C, Loja& L, int& index) {
    C.id_loja = index;
    C.distancia_loja_alocada = distancia(C, L);
    L.clientes.push_back(C);
    L.capacidade -= 1;
}

/*Função principal que realiza o casamento estável esperado entre lojas e clientes sob a lógica do algoritmo de Gale-Shapley.
Para uma loja específica, o loop principal checa se ainda há estoque disponível e essa loja ainda não ofereceu para todos
os clientes, isso significa que ela está apta a oferecer vaga aos clientes. O cliente aceitará a oferta se ele não recebeu nenhuma
ainda, ou a distância para a loja proponente é menor do que a distância para a loja alocada ou essas distâncias são iguais mas
o id da loja proponente é menor do que o id da loja alocada, tratando, assim, os casos de exceção. Como a lista de
preferência das lojas pelos clientes é a mesma, toda proposta que uma loja faz (aceita ou rejeitada) incrementa o contador de clientes ofertados
dessa loja, que é usado como ídice para a próxima proposta a ser feita. Desse modo, uma loja não propõe para um cliente mais
de uma vez. Além disso, caso uma loja "roube" o cliente de outra loja, o cliente é removido da loja antiga e o procedimento é chamado
recursivamente com o índice da loja antiga para que ela "tape o buraco feito", isto é, proponha para todos os clientes ou esgote o seu
estoque.*/
void casamento_estavel(vector<Loja> &Lojas, vector<Cliente> &Clientes, int n_lojas, int n_clientes, int &i) {
    int j;
    while(Lojas[i].clientes_ofertados < n_clientes && Lojas[i].capacidade > 0) {
        j = Lojas[i].clientes_ofertados;
        Lojas[i].clientes_ofertados += 1;

        /*Cliente aceita imediatamente caso não tenha sido alocado para alguma loja.*/
        if(Clientes[j].id_loja == -1) {
            alocacao(Clientes[j], Lojas[i], i);
        }

        else {
            int distancia_loja_alocada = 0, distancia_loja_atual = 0;
            distancia_loja_alocada = Clientes[j].distancia_loja_alocada;
            distancia_loja_atual = distancia(Clientes[j], Lojas[i]);

            if(distancia_loja_atual < distancia_loja_alocada ||
                (distancia_loja_atual == distancia_loja_alocada && Lojas[i].id < Clientes[j].id_loja)) { 
                
                // Remove antiga;
                int indice = findIndexVector(Lojas[Clientes[j].id_loja].clientes, Clientes[j].id);
                Lojas[Clientes[j].id_loja].clientes.erase(Lojas[Clientes[j].id_loja].clientes.begin() + indice);
                Lojas[Clientes[j].id_loja].capacidade += 1;

                // Tapa buraco;
                casamento_estavel(Lojas, Clientes, n_lojas, n_clientes, Clientes[j].id_loja);

                // Insere nova;
                alocacao(Clientes[j], Lojas[i], i);
            }
        }
    }
    return;
}

/*Vetores principais de Lojas e Clientes*/
vector<Loja> Lojas;
vector<Cliente> Clientes;

int main() {

    /*Leitura dos dados a partir da admissão do arquivo de texto na entrada padrão*/
    /*Leitura dos limites do grid e número de lojas.*/
    int X, Y, num_lojas;
    cin >> X >> Y >> num_lojas;

    /*Leitura das informações e preenchimento do vetor das lojas a partir do número de lojas. */
    for(int i = 0; i < num_lojas; i++) {
        Loja aux;
        aux.id = i;

        int cap, x, y;
        cin >> cap >> x >> y;
        aux.capacidade = cap;
        aux.loja_x = x;
        aux.loja_y = y;
        aux.clientes_ofertados = 0;

        Lojas.push_back(aux);
    }

    /*Leitura das informações e preenchimento do vetor dos clientes
    a partir do número de clientes lido. A idade, estado e forma de pagamento não
    fazem parte dos atributos do tipo cliente pois são utilizados apenas no cálculo
    do ticket. Para isso, são criados vetores auxiliares que traduzem os estados e
    formas de pagamento para os seus respectivos scores. O "id_loja" de cada cliente
    é inicializado com -1 para indicar que esse cliente ainda não foi alocado para alguma loja.*/
    int num_clientes;
    cin >> num_clientes;

    string estados[7] = {"MG", "PR", "SP", "SC", "RJ", "RN", "RS"};
    string pagamentos[3] = {"DINHEIRO", "DEBITO", "CREDITO"};
    for(int i = 0; i < num_clientes; i++) {
        Cliente aux;
        
        string state, payment;
        int age, x, y;
        cin >> age >> state >> payment >> x >> y;

        aux.id = i;
        int idade = age;
        string estado = state;
        string pagamento = payment;
        aux.cliente_x = x;
        aux.cliente_y = y;
        aux.id_loja = -1;

        int score_estado = 0, score_tipo_pagamento = 0;

        /*Cálculo do número de ticket*/
        for(int j = 0; j < 7; j++) {
            if(estados[j] == estado) {
                score_estado = j*10;
                break;
            }
        }

        for(int k = 0; k < 3; k++) {
            if(pagamentos[k] == pagamento) {
                score_tipo_pagamento = k + 1;
                break;
            }
        }

        aux.ticket = (double(abs(60 - idade)) + score_estado)/(double(score_tipo_pagamento));
        
        Clientes.push_back(aux);
    }

    /*Ordenação do vetor de clientes de acordo com as condições esperadas e exceções tratadas.*/
    sort(Clientes.begin(),Clientes.end(),cmpCliente);

    /*Casamento entre Lojas e Clientes:
    O indice i controla o índice da loja no vetor Lojas. Desse modo, dada a explicação da função casamento_estavel,
    ao final de uma iteração desse loop while, a loja i e todas as anteriores a ela no vetor estarão com seus "buracos tapados",
    ou seja, proporam para todos os clientes ou esgotaram seu estoque de acordo com as proposições feitas até a loja i.
    Desse modo, ao final desse loop while, a última loja e todas as anteriores estrão casadas estavelmente com os clientes.*/
   int i = 0;
   while(i < num_lojas) {
       casamento_estavel(Lojas, Clientes, num_lojas, num_clientes, i);
       i += 1;
   }
   

    /*Para todas as lojas, ordena o vetor de clientes admitidos de acordo com a
    condição exigida para a impressão: Ordem decrescente de tickets e, em caso de empate,
    ordem crescente de ids.*/
    for (int i = 0; i < num_lojas; i++) {
        sort(Lojas[i].clientes.begin(),Lojas[i].clientes.end(),cmpCliente);
    }

    /*Impressão dos ids das lojas e dos ids dos respectivos clientes alocados conforme esperado.*/
    for (int i = 0; i < num_lojas; i++) {
        cout << Lojas[i].id << endl;
        int clientes_alocados = Lojas[i].clientes.size();
        for (int j = 0; j < clientes_alocados; j++) {
            if(j) cout << " ";
            cout << Lojas[i].clientes[j].id;
        }
        cout << endl;
    }   

    return 0;
}