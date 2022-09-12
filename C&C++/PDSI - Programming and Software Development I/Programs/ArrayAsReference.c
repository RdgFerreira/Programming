#include <stdio.h>

typedef struct data  {
    int Dia, Mes, Ano;
} DATA;

typedef struct pessoa {
    int Nome;
    int Idade;
    float Salario;
    DATA Nasc;
} PESSOA;

void Ler(PESSOA *ptr)
{
    printf("Qual o Nome             : "); 
    scanf("%d", &(*ptr).Nome);
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
    printf("%d", p.Nome);
    printf("%d\n", p.Idade);
    printf("%f\n", p.Salario);
    printf("%d\n", p.Nasc.Dia);
    return 0;
}
