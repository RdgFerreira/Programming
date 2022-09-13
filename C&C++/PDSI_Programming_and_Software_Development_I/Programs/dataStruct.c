#include <stdio.h>

typedef struct data  {
    int Dia, Mes, Ano;
} DATA;

typedef struct pessoa {
    char Nome[100];
    int Idade;
    float Salario;
    DATA Nasc;
} PESSOA;

void Ler(PESSOA * ptr)
{
    printf("Qual o Nome             : "); 
    scanf("%s", &(*ptr).Nome);
    printf("Qual a Idade            : "); 
    scanf("%d", &(*ptr).Idade);
    printf("Qual o Salario          : "); 
    scanf("%f", &(*ptr).Salario);
    printf("Qual a Data Nascm.      : ");
    scanf("%d %d %d", &(*ptr).Nasc.Dia, &(*ptr).Nasc.Mes, &(*ptr).Nasc.Ano);
}

int main() {
    PESSOA p;

    Ler(&p);
    printf("Nome: %s\n", p.Nome);
    printf("Idade: %d\n", p.Idade);
    printf("Salario: %f\n", p.Salario);
    printf("Ano Nascimento: %d\n", p.Nasc.Ano);
    return 0;
}
