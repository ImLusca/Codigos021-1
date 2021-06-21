//nome: Lucas Pereira Pacheco. nºusp:12543930
//Manhattan's Delivery Service
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int posXAtual, posYAtual,posXCasa,posYCasa;


float DistHerman(int coordX,int coordY,int tipoTerr){
    int eixoX,eixoY;
    float totalPercorrido;
    eixoX = abs(posXAtual - coordX);
    eixoY = abs(posYAtual - coordY);

    switch (tipoTerr){
        case -1: totalPercorrido = sqrt(pow(eixoX,2) + pow(eixoY,2));
            break;
        case 0: totalPercorrido = eixoX + eixoY;
            break;
        case 1: totalPercorrido = eixoX + eixoY;           
    }

    return totalPercorrido;

}

float DistEuclides(int coordX,int coordY,int tipoTerr){
    int eixoX,eixoY;
    float totalPercorrido;
    eixoX = abs(posXAtual - coordX);
    eixoY = abs(posYAtual - coordY);

    switch (tipoTerr){
        case -1: totalPercorrido = sqrt(pow(eixoX,2) + pow(eixoY,2));
            break;
        case 0: totalPercorrido = eixoX + eixoY;
            break;
        case 1: totalPercorrido = sqrt(pow(eixoX,2) + pow(eixoY,2));           
    }

    return totalPercorrido;

}

int main(){
    int numLocais,tipoTerreno, xProxEntrega, yProxEntrega, contTipoTerreno[3] = {};
    float totalDistHerman =0, totalDistEuclides =0;
    scanf("%i",&numLocais);

    if(numLocais <= 1){
        printf("Falha no processamento dos dados.\n");
        return 0;
    }

    for(int i =0;i<numLocais;i++){
        if(i == 0){
            scanf("%i %i %i",&posXAtual,&posYAtual,&tipoTerreno);
            if(abs(tipoTerreno) > 1){
               printf("Falha no processamento dos dados.\n");
               return 0; 
            }
            contTipoTerreno[tipoTerreno + 1] ++;
            posXCasa = posXAtual;
            posYCasa = posYAtual;
            continue;
        }
        scanf("%i %i",&xProxEntrega,&yProxEntrega);
        totalDistHerman += DistHerman(xProxEntrega,yProxEntrega,tipoTerreno);
        totalDistEuclides += DistEuclides(xProxEntrega,yProxEntrega,tipoTerreno);        

        posXAtual = xProxEntrega;
        posYAtual = yProxEntrega;
        scanf("%i",&tipoTerreno);
        if(abs(tipoTerreno) > 1){
            printf("Falha no processamento dos dados.\n");
            return 0; 
        }
        contTipoTerreno[tipoTerreno + 1] ++;
    }

    totalDistHerman += DistHerman(posXCasa,posYCasa,tipoTerreno);
    totalDistEuclides += DistEuclides(posXCasa,posYCasa,tipoTerreno);   

    printf("Ao todo, foi passado por %i terrenos baldios, ", contTipoTerreno[0]);
    printf("%i terrenos residenciais e ",contTipoTerreno[1]);
    printf("%i parques.\n",contTipoTerreno[2]);
    printf("A diferenca total de distancia percorrida foi de %.2f metros.\n",fabs(totalDistHerman - totalDistEuclides));

    
    return 0;
}