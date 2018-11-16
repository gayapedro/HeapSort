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

int main(){
    return 0;
}
