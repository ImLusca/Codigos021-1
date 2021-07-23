//nome:Lucas Pereira Pacheco nºusp:12543930
//Notação Polonesa Reversa
#include<stdio.h>
#include<stdlib.h>

struct stack{
    double *numeros;
    int indiceTopo;
    int tamanhoPilha;
};

struct stack Pilha;


void stackPush(double numero){
    if(Pilha.indiceTopo == Pilha.tamanhoPilha){
        Pilha.tamanhoPilha += 20;        
        Pilha.numeros = realloc(Pilha.numeros, sizeof(double) * (Pilha.tamanhoPilha));
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
    Pilha.tamanhoPilha = 50;

    do{
        caractere = getchar();

        if(caractere == 32 || caractere == EOF){
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