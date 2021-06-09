//nome: Lucas Pereira Pacheco nºusp: 12543930
// Histograma
#include<stdio.h>

int main(){
    int histograma[25], contCores[5] ={0};
    for(int i =0;i<25;i++){
        scanf("%i",&histograma[i]);
        contCores[histograma[i]]++;
    }

    for(int i=0;i<5; i++){
        printf("%i: |",i);
        for(int j=0;j<25;j++){
            if(histograma[j] == i){
                printf("#");
            }
        }
        printf("\n");
    }
    // encontra a cor mais presente
    int MaisPresente=0;
    for(int i=0, maior =0;i<5;i++){
        if(contCores[i] > maior){
            maior = contCores[i];
            MaisPresente = i;
        }
    }

    for(int i =0;i<25;i++){
        if(histograma[i] == MaisPresente){
            printf("%i\n",i);
        }
    }

    return 0;
}