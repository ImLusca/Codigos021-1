//nome: Lucas Pereira Pacheco. nºusp: 12543930
// Maior, Menor, Média e Moda
#include<stdio.h>
int numeros[10];

int maior();
int menor();
float media();
int moda();


int main(){
    for(int i=0;i<10;i++){
        scanf("%i",&numeros[i]);
    }
    printf("%i",maior());
    printf(" %i",menor());
    printf(" %.2f",media());
    printf(" %i\n",moda());
    return 0;
}

int maior(){
    int maiorNum=0;
    for(int i=0;i<10;i++){
        if(numeros[i] > maiorNum){
            maiorNum = numeros[i];
        }
    }
    return maiorNum;
}
int menor(){
    int menorNum= numeros[0];
    for(int i=1;i<10;i++){
        if(numeros[i] < menorNum){
            menorNum = numeros[i];
        }
    }
    return menorNum;
}
float media(){
    int somaTermos = 0;
    for(int i=0;i<10;i++){
        somaTermos+= numeros[i];
    }
    return somaTermos /10.0;
}
int moda(){
    int numsXocorrencia[10][2]= {0};
    int NumMaiorOcorrencia=0;
    // relaciona o número à sua quantidade de ocorrências
    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            //verifica se número já esta listado no vetor 
            if(numsXocorrencia[j][0] == numeros[i]){
                numsXocorrencia[j][1]++;
                break;
            }else if(numsXocorrencia[j][0] == 0 && numsXocorrencia[j][1] == 0){    
                numsXocorrencia[j][0] = numeros[i];
                numsXocorrencia[j][1]++;
                break;
            }
        }
    }
    
    for(int i=0,maiorOcorrencia=0;i<10;i++){
        if(numsXocorrencia[i][1] > maiorOcorrencia){
            maiorOcorrencia = numsXocorrencia[i][1];
            NumMaiorOcorrencia = numsXocorrencia[i][0];
        }
    }
    return NumMaiorOcorrencia;
}