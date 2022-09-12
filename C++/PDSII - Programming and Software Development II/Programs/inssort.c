#include <stdio.h>

void imprime_seq(int n, int seq[]){
    for(int i=0; i<n; i++){
        printf("%d ", seq[i]);
    }
}

void insertion(int n, int seq[]){
    int i = 0, m = 0, aux = 0;
    for(int j=2; j<n; j++){
        i=1;
        while(seq[j]>seq[i]){
            i++;
        }
        m = seq[j];
        for(int k=0; k<=j-i-1; k++){
            aux = seq[j-k];
            seq[j-k] = seq[j-k-1];
            seq[j-k-1] = aux;
        }
        seq[i] = m;
    }
}

int main(){
    int seq[] = {7, 2, 1, 4, 5, 9};
    int n = 6;
    imprime_seq(6,seq);
    insertion(6,seq);
    printf("\n");
    imprime_seq(6,seq);
    return 0;
}