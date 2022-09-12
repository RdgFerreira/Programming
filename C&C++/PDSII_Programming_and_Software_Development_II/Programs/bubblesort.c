#include <stdio.h>

void imprime_seq(int n, int seq[]){
    for(int i=0; i<n; i++){
        printf("%d ", seq[i]);
    }
}

void passada(int n, int seq[]){
    for(int it=n; it>1; it--){
        int aux = 0;
        for(int i=0; i<it-1; i++){
            if(seq[i]>seq[i+1]){
                aux = seq[i];
                seq[i] = seq[i+1];
                seq[i+1] = aux;
            }
        }
    }
}

int main(){
    int seq[] = {3, 27, 10, 16, 76, 2};
    //int n = 6;
    
    imprime_seq(6,seq);
    /*
    for(int i=n; i>1; i--){
        passada(i,seq);
    }
    */
    passada(6,seq);
    printf("\n");
    imprime_seq(6,seq);
    return 0;
}