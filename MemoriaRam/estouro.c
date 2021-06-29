#include<stdio.h>
#include<stdlib.h>

int main(){
    int espacoMegas;
    printf("Eae, chefe. Vai alocar quantos mbs na Heap hoje?\n");    
    scanf("%i",&espacoMegas);

    // Converte a quantidade solicitada para megabytes, então
    // pede para alocar essa quantidade de mbs na heap
    void *apontaHeap = malloc(1024 * 1024 * espacoMegas);

    if(apontaHeap != NULL){
        printf("Tudo Certo! %i mbs alocados com sucesso\n", espacoMegas);
    }else{
        printf("Deu Ruim. Acho que você não tem tudo isso de memória\n");
    }    
    free(apontaHeap);

    return 0;
}
