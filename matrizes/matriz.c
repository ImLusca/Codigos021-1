#include<stdio.h>
#include<stdlib.h>

int main(){
    int La,Lb,Ca,Cb,S, Ma[1000][1000],Mb[1000][1000],temp;

    scanf("%i %i %i %i %i",&La,&Ca,&Lb,&Cb,&S);
    srand(S);

    if(Ca != Lb || La < 0 || Lb < 0 || Cb < 0){
        printf("Valores invalidos para a multiplicacao.");
        return 0;
    }

    for(int i=0 ; i< La;i++){
        for(int j=0;j < Ca; j++){
            Ma[i][j] = rand()%50 - 25;
        }
    }

    for(int i=0 ; i< Lb;i++){
        for(int j=0;j < Cb; j++){
            Mb[i][j] = rand()%50 - 25;
        }
    }

    for(int i=0;i<La;i++){
        printf("Linha %i: ", i);
        for(int j=0; j<Cb;j++){
            temp = 0;

            for(int l =0;l<Lb;l++){
                temp+=(Ma[i][l] * Mb[l][j]);
            }

            printf("%i ",temp);
        }        
        printf("\n");
    }


    return 0;
}