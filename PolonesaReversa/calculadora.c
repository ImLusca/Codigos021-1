//nome:Lucas Pereira Pacheco nºusp:12543930
//Notação Polonesa Reversa
#include<stdio.h>
#include<stdlib.h>

struct stack{
    double *numeros;
    int indiceTopo;
};

struct stack Pilha;


void stackPush(double numero){
    if((Pilha.indiceTopo % 50) == 1 && Pilha.indiceTopo != 1){
        Pilha.numeros = realloc(Pilha.numeros, sizeof(double) * (Pilha.indiceTopo + 50));
    }

    Pilha.numeros[Pilha.indiceTopo] = numero;
    Pilha.indiceTopo++;
}

double stackPop(){
    Pilha.indiceTopo--;
    return Pilha.numeros[Pilha.indiceTopo];
}

void fazOperacao(char operacao){
    double primeiroNumero, segundoNumero, resultado;

    segundoNumero = stackPop();
    primeiroNumero = stackPop();

    switch (operacao)
    {
        case '+': resultado = (primeiroNumero + segundoNumero);
        break;

        case '-': resultado = (primeiroNumero - segundoNumero);
        break;

        case '*': resultado = (primeiroNumero * segundoNumero);
        break;

        case '/': resultado = (primeiroNumero / segundoNumero);
        break;
    }

    stackPush(resultado);
}


int main(){
    char caractere;
    double numero;   

    Pilha.indiceTopo = 0;
    Pilha.numeros = malloc(sizeof(double)*50);

    do{
        caractere = getchar();

        if(caractere == 32){
            continue;
        }

        if( caractere >= 48 && caractere <= 57 ){
            ungetc(caractere,stdin);
            scanf("%lf", &numero);

            stackPush(numero);
            continue;
        }

        fazOperacao(caractere);    

    }while(caractere != EOF);

    printf("Resultado: %.6lf\n",Pilha.numeros[0]);

    free(Pilha.numeros);

    return 0;
}