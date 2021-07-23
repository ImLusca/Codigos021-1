//Lucas Pereira Pacheco nºusp:12543930
//Ataques e Tipos
#include<stdio.h>
#include<stdlib.h>

typedef struct ataques{
    int poderAtaque;
    int indiceTipo;
}Ataques;

float **alocaMatriz(int numTipos){
    float **matrizMultiplicadores = NULL;
    matrizMultiplicadores = malloc(sizeof(float*) * numTipos);

    for(int i =0; i< numTipos; i++){
        matrizMultiplicadores[i] = malloc(sizeof(float) * numTipos);
    }

    for(int i =0;i < numTipos; i++){
        for(int j=0;j < numTipos; j++){
            scanf("%f",&matrizMultiplicadores[i][j]);
        }
    }
    return matrizMultiplicadores;
}

int leAtaques(int **ataquesPossiveis){
    int numAtaques=20, contAtaques=0,poderAtaque, tipoAtacante;
    *ataquesPossiveis = malloc(sizeof(float) * numAtaques);

    do{
        scanf("%i",&poderAtaque);
        scanf("%i",&tipoAtacante);

        if(poderAtaque == -1){
            continue;
        }

        if(contAtaques == numAtaques){
            numAtaques += 20;
            *ataquesPossiveis = realloc(sizeof(float)* numAtaques);
        }

        *ataquesPossiveis[contAtaques].poderAtaque = poderAtaque;
        *ataquesPossiveis[contAtaques].indiceTipo = tipoAtacante;

        contAtaques++;

    }(while poderAtaque != -1)

    *ataquesPossiveis = realloc(sizeof(float) * contAtaques);

    return contAtaques;
}

int main(){
    int numTipos, numAtaques, tipoOponente, maiorDano=0;
    float **matrizMultiplicadores;
    Ataques *ataquesPossiveis, *ataqueMaisEfetivo;

    scanf("%i",&numTipos);
    matrizMultiplicadores = alocaMatriz(numTipos);

    numAtaques = leAtaques(&ataquesPossiveis);

    
    scanf("%i",&tipoOponente);

    for(int i=0; i< numAtaques; i++){
        float multiplicadorDano = matrizMultiplicadores[ataquesPossiveis->indiceTipo][tipoOponente];
        int danoCausado = ataquesPossiveis[i].poderAtaque * multiplicadorDano;

        if(danoCausado > maiorDano){
            maiorDano = danoCausado;
            ataqueMaisEfetivo = ataquesPossiveis[i];
        }
    }

    printf("O melhor ataque possui indice %i e dano %.2f",ataqueMaisEfetivo->indiceTipo,maiorDano);

    //Liberar memória dps

    return 0;
}