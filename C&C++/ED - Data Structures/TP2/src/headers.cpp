#include "headers.hpp"

/*Procedimento particao do Quicksort em duas seções de 
tamanho aproximadamente igual, que irá particionar
o array de Registros, em que os nomes no array da esquerda
estarão menores ou iguais (em ordem alfabética) do que o 
nome do registro cujo índice é o pivô, e no array da 
direita estarão os maiores ou iguais do que o do pivô. */
void Particao_str(int Esq, int Dir, int *i, int *j, Registro *v) { 
    Registro x, w;
    *i = Esq;
    *j = Dir;
    x = v[(*i + *j)/2];

    do {
        while (x.nome > v[*i].nome) {
            (*i)++;
        }
        while (x.nome < v[*j].nome) {
            (*j)--;
        }
        if (*i <= *j) { 
            w = v[*i]; 
            v[*i] = v[*j]; 
            v[*j] = w;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

/*Procedimento que particiona o array para então realizar chamadas
recursivas para seções à esquerda do array e, depois, para seções à direita. */
void Ordena_str(int Esq, int Dir, Registro *v) {
    int i, j;
    Particao_str(Esq, Dir, &i, &j, v);
    if (Esq < j) Ordena_str(Esq, j, v);
    if (i < Dir) Ordena_str(i, Dir, v);
}

/*Função principal que chama o procedimento Ordena com o array
de registros originais e com os índices dos extremos, explicitados
pelo tamanho da entrada*/
void QuickSort_str(Registro *v, int n) { 
    Ordena_str(0, n-1, v); 
}

// ==========================================================================================

/*Procedimento do heapsort que refaz a condição do heap,
considerando o campo dados*/
void Refaz_int(int Esq, int Dir, Registro *v) {
    int i, j;
    Registro x;
    i = Esq;
    j = i * 2;
    x = v[i-1];

    while (j <= Dir) {
        if (j < Dir) {
            if (v[j-1].dado < v[j].dado) {
                j++;
            }
        }

        if (x.dado >= v[j-1].dado) {
            break;
        }

        v[i-1] = v[j-1];
        i = j;
        j = i * 2;
    }
    v[i-1] = x;
}

/*Constroi o heap, chamando o procedimento Refaz com o decrescimento 
de um índice Esq que começa a partir do meio do array e termina quando Esq == 1.*/
void Constroi_int(Registro *v, int n) {
    int Esq;
    Esq = (n / 2) + 1;
    while (Esq > 1) {
        Esq--;
        Refaz_int(Esq, n, v);
    }
}

/*Função principal do Heapsort: Constroi o heap a partir do array
original, define índices com os extremos do array e, refaz o heap
enquanto seleciona o maior elemento e o coloca na posição correta*/
void Heapsort_int(Registro *v, int *n) {
    int Esq, Dir;
    Registro x;
    Constroi_int(v, *n);
    Esq = 1; 
    Dir = (*n);

    while (Dir > 1) {
        x = v[0]; 
        v[0] = v[Dir-1]; 
        v[Dir-1] = x; 
        Dir--;
        Refaz_int(Esq, Dir, v);
    }
}

// ============================================================================================

/*Método que retorna verdadeiro (1) caso o bit da string de dado
seja igual a 1, e falso (0) caso contrário.*/
bool digit(string dado, int w) {
    return dado[numbits - 1 - w] == '1';
}

/*Quicksort binário: semelhante ao original, contudo, em uma função,
realiza troca entre bits 0 e 1 da string de bits de modo a
trocá-los colocando-os na ordem correta, seguido de duas chamadas
recursivas particionando o array em dois de tamanho aproximadamente igual*/
void quicksortB_int(Registro *a, int l, int r, int w) {
    int i = l, j = r;
    if (r <= l || w < 0) {
         return;
    }
    while (j != i) { 
        while (digit(a[i].dado, w) == 0 && (i < j)) i++;
        while (digit(a[j].dado, w) == 1 && (j > i)) j--;
        Registro aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }
    if (digit(a[r].dado, w) == 0) j++;
    quicksortB_int(a, l, j-1, w-1);
    quicksortB_int(a, j, r, w-1);
 }

/*Procedmiento principal do Radix Exchange Sort, que chama o quicksort
binário com o array original, os índices dos extremos e o número de bits
padrão do array de dado (8).*/
void RadixExchSort_int(Registro *a, int l, int r) {
    quicksortB_int(a, l, r, numbits - 1);
}
// ==========================================================================================

/*Procedimento merge padrão do Mergesort, que, nesse caso, aloca memória para a criação
de 2 sub-arrays de Registro, preenche-os com os nomes nas posições adequadas e junta
os arrays (merge) ordenando-os adequadamente.*/
void merge_str(Registro *registros, int const nleft, int const mid, int const nright) {
    auto const l_size = mid - nleft + 1;
	auto const r_size = nright - mid;

	auto *vleft = new Registro[l_size];
    auto *vright = new Registro[r_size];

	for (auto i1 = 0; i1 < l_size; i1++) {
		vleft[i1] = registros[nleft + i1];
    }
	for (auto j1 = 0; j1 < r_size; j1++) {
		vright[j1] = registros[mid + 1 + j1];
    }

    auto i = 0;
    auto j = 0;
    int k = nleft;

    while (i < l_size && j < r_size) {
        if (vleft[i].nome <= vright[j].nome) {
            registros[k] = vleft[i];
            i++;
        } else {
            registros[k] = vright[j];
            j++;
        }
        k++;
    }

    while (i < l_size) {
		registros[k] = vleft[i];
		i++;
		k++;
	}
	while (j < r_size) {
		registros[k] = vright[j];
		j++;
		k++;
	}

    delete [] vleft;
    delete [] vright;
}

/*Função principal do Mergesort, que realiza chamadas recursivas para a parte esquerda
e direita do array (nessa ordem), seguido do procedimento merge sob esses sub-arrays da
esquerda e direita*/
void Mergesort_str(Registro *registros, int const left, int const right) {
    if(left < right) {
        auto mid = left + (right - left)/2;

        Mergesort_str(registros, left, mid);
        Mergesort_str(registros, mid+1, right);
        merge_str(registros, left, mid, right);
    }
}

// ===================================================================================================

/*Imprime todas as linhas do vetor de registros no formato: <NOME> <DADO>*/
void Imprime(Registro *registros, int N) {
    for(int i = 0; i < N; i++) {
        cout << registros[i].nome << " ";
        cout << registros[i].dado << endl;
    }
}

// ==========================================================================