#include <stdio.h>

void aplicarMaxHeap(int sequencia[], int n, int i){
    int maiorElemento, filhoEsquerda, filhoDireita, aux;
    maiorElemento = i;
    filhoEsquerda = 2*i+1;
    filhoDireita = 2*i+2;
    aux = 0;
    if(filhoEsquerda<n && sequencia[filhoEsquerda]>sequencia[maiorElemento]){
        maiorElemento = filhoEsquerda;
    }
    if(filhoDireita<n && sequencia[filhoDireita]>sequencia[maiorElemento]){
        maiorElemento = filhoDireita;
    }
    if(maiorElemento != i){
        aux = sequencia[maiorElemento];
        sequencia[maiorElemento] = sequencia[i];
        sequencia[i] = aux;
        aplicarMaxHeap(sequencia,n,maiorElemento);
    }
}

void heapSort(int sequencia[], int n){
    int aux;
    for(int i=n/2-1;i>=0;i--){
        aplicarMaxHeap(sequencia,n,i);
    }
    for(int i=n-1;i>=0;i--){
        aux = sequencia[i];
        sequencia[i] = sequencia[0];
        sequencia[0] = aux;
        aplicarMaxHeap(sequencia,i,0);
    }
}

int main(){
    int sequencia[6] = {1,12,9,5,6,10},tam;
    tam = sizeof(sequencia)/sizeof(sequencia[0]);
    printf("Sequencia desordenada :");
    for(int i=0;i<tam;i++){
        printf(" %d",sequencia[i]);
    }
    heapSort(sequencia,tam);
    printf("\nSequencia ordenada    :");
    for(int i=0;i<tam;i++){
        printf(" %d",sequencia[i]);
    }
    printf("\n");
    return 0;
}
