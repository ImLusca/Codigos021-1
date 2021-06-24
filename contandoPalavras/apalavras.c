#include<stdio.h>

int CaracterePalavra(char caractere){
    // int maiuscula = (caractere >= 65 && caractere <= 90);
    // int minuscula = (caractere >= 97 && caractere<= 122);
    // return (maiuscula || minuscula);

    switch (caractere)
    {
        case ' ':return 0;        
        case '\r': return 0;
        case '\t': return 0;
        case '\n': return 0;    
        default: return 1;        
    }

}


int main(){
    int ContPalavras=0, ContCaracteres=0,ContLinhas=0, Epalavra=0;
    char caractereLido;
    while((caractereLido=getchar()) != EOF){

        ContCaracteres++;
        
        if(caractereLido == '\n'){
            ContLinhas++;
        }
        if(!CaracterePalavra(caractereLido)){
            Epalavra = 0;
        }else if(!Epalavra){
            ContPalavras++;
            Epalavra = 1;
        }

    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%i\t%i\t%i\n",ContLinhas,ContPalavras,ContCaracteres);

    return 0;
}