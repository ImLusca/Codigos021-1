//Lucas Pereira Pacheco nºusp:12543930
//Redrum
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct palavras{
    char *palavraInicial;
    char *palavraInvertida;
    int   qtdCaracteres;
} structPalavras;


char *Readline(){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }

    do{
        caractere = tolower(getchar());

        if(caractere == '\n'){
            caractere = '\0';
        }

        if(!isalnum(caractere) && caractere != 32 && caractere != 47){
            continue;
        }

        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != '\0');

    linha = realloc(linha,contaCaracteres);

    return linha;
}

char *ObtemInversa(char* stringAserInvertida){
    int numCaractere = strlen(stringAserInvertida);

    char *PalavraInvertida = malloc(numCaractere + 1);
    for(int i =0; i< numCaractere;i++){        
        PalavraInvertida[i] = stringAserInvertida[numCaractere-i-1];
    }

    PalavraInvertida[numCaractere] = '\0';

    return PalavraInvertida;
}

int verificaPalindromo(structPalavras Palavras,int indice){
    //Se o indice for igual a quantidade de caracteres
    //significa que todos caracteres das duas strings são iguais
    if(indice == Palavras.qtdCaracteres){
        return 1;
    }
    //Se os caracteres forem diferentes, retorna false e para a verificacao
    if(Palavras.palavraInicial[indice] != Palavras.palavraInvertida[indice]){
        return 0;
    }

    //Se os caracteres deste indice forem iguais, compara os próximos
    return verificaPalindromo(Palavras,++indice);
}

int main(){
   structPalavras Palavras; 

    Palavras.palavraInicial = Readline();
    Palavras.palavraInvertida = ObtemInversa(Palavras.palavraInicial);
    Palavras.qtdCaracteres = strlen(Palavras.palavraInicial);

    if(verificaPalindromo(Palavras,0)){
        printf("Palindromo direto");
        return 0;
    }

    
    free(Palavras.palavraInicial);
    free(Palavras.palavraInvertida);

    return 0;
}