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

Ataques *leAtaques(int *TotalAtaques){
    int numAtaques=20, contAtaques=0,poderAtaque, tipoAtacante;
    Ataques *ataquesPossiveis;
    ataquesPossiveis = malloc(sizeof(float) * numAtaques);

    do{
        scanf("%i",&poderAtaque);
        if(poderAtaque == -1){
            continue;
        }

        scanf("%i",&tipoAtacante);

        if(contAtaques == numAtaques){
            numAtaques += 20;
            ataquesPossiveis = realloc(ataquesPossiveis,sizeof(float)* numAtaques);
        }

        ataquesPossiveis[contAtaques].poderAtaque  = poderAtaque;
        ataquesPossiveis[contAtaques].indiceTipo = tipoAtacante;

        contAtaques++;

    }while (poderAtaque != -1);

    *TotalAtaques = contAtaques;
    return ataquesPossiveis;
}

int main(){
    int numTipos, numAtaques, tipoOponente;
    float **matrizMultiplicadores, maiorDano=0;
    Ataques *ataquesPossiveis, ataqueMaisEfetivo;

    scanf("%i",&numTipos);
    matrizMultiplicadores = alocaMatriz(numTipos);

    ataquesPossiveis = leAtaques(&numAtaques);
    
    scanf("%i",&tipoOponente);

    for(int i=0; i< numAtaques; i++){
        float multiplicadorDano = matrizMultiplicadores[ataquesPossiveis[i].indiceTipo][tipoOponente];
        int danoCausado = ataquesPossiveis[i].poderAtaque * multiplicadorDano;

        if(danoCausado > maiorDano){
            maiorDano = danoCausado;
            ataqueMaisEfetivo = ataquesPossiveis[i];
        }
    }

    printf("O melhor ataque possui indice %i e dano %.2f\n",ataqueMaisEfetivo.indiceTipo ,maiorDano);

    for(int i =0; i < numTipos;i++){
        free(matrizMultiplicadores[i]);
    }
    free(matrizMultiplicadores);
    free(ataquesPossiveis);


    return 0;
}