#include <iostream>
using namespace std;

#include <bits/stdc++.h>

#define numbits 8

typedef struct Registro {
    string nome;
    string dado;
} Registro;

void Particao_str(int Esq, int Dir, int *i, int *j, Registro *v);
void Ordena_str(int Esq, int Dir, Registro *v);
void QuickSort_str(Registro *v, int n);

void Refaz_int(int Esq, int Dir, Registro *v);
void Constroi_int(Registro *v, int n);
void Heapsort_int(Registro *v, int *n);

bool digit(string dado, int w);
void quicksortB_int(Registro *a, int l, int r, int w);
void RadixExchSort_int(Registro *a, int l, int r);

void merge_str(Registro *registros, int const nleft, int const mid, int const nright);
void Mergesort_str(Registro *registros, int const left, int const right);


void Imprime(Registro *registros, int N);