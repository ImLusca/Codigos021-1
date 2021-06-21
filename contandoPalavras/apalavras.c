#include<stdio.h>

int VerificaSeeLetra(char caractere){
    int maiuscula = (caractere >= 65 && caractere <= 90);
    int minuscula = (caractere >= 97 && caractere<= 122);
    return (maiuscula || minuscula);
}


int main(){
    int ContPalavras=0, ContCaracteres=0,ContLinhas=0;
    char caractereLido, CharInicioPalavra=' ';
    while((caractereLido=getchar()) != EOF){
        if(caractereLido == '\r'){
            caractereLido = '\n';
        }

        ContCaracteres++;



        if(CharInicioPalavra == ' ' && VerificaSeeLetra(caractereLido)){
            CharInicioPalavra = caractereLido;
        }

        if(CharInicioPalavra != ' ' && (caractereLido == ' ' || caractereLido == '\n')){
            ContPalavras++;
            CharInicioPalavra = ' ';
        }


        if(caractereLido == '\n'){
            ContLinhas++;
        }
    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%i\t%i\t%i\n",ContLinhas,ContPalavras,ContCaracteres);

    return 0;
}