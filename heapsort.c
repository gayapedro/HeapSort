#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(){
    int sequencia[2000],tam;
    clock_t t;
    for(int i=0;i<2000;i++){
       sequencia[i] = i+1; 
    }
    tam = sizeof(sequencia)/sizeof(sequencia[0]);
    shuffle(sequencia,tam);
    printf("Sequencia desordenada:\n");
    for(int i=0;i<tam;i++){
        printf("%d\n",sequencia[i]);
    }
    t = clock();
    heapSort(sequencia,tam);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Sequencia ordenada:\n");
    for(int i=0;i<tam;i++){
        printf("%d\n",sequencia[i]);
    }
    printf("Tempo de execução: %f segundos\n",time_taken);
    return 0;
}
