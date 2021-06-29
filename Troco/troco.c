#include<stdio.h>
 
int NumMoedas(int* valorAtual, int valMoeda){
    int quantMoedas = *valorAtual / valMoeda;
    *valorAtual -= quantMoedas * valMoeda;
    return quantMoedas;
}


int main(){
    int valoresDasMoedas[6] = {100,50,25,10,5,1};
    int ValorDoTroco;
    scanf("%i",&ValorDoTroco);
    
    for(int i=0; i<6; i++){
        switch (i)
        {
        case 0: printf("O valor consiste em %i moedas de 1 real\n",NumMoedas(&ValorDoTroco,100));            
            break;
        case 5: printf("O valor consiste em %i moedas de 1 centavo\n",NumMoedas(&ValorDoTroco,1));            
            break;        
        default: printf("O valor consiste em %i ",NumMoedas(&ValorDoTroco,valoresDasMoedas[i]));            
            printf("moedas de %i centavos\n",valoresDasMoedas[i]);
            break;
        }
    }
    return 0;
}