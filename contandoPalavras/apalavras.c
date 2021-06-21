#include<stdio.h>

int VerificaSeEValido(char caractere){
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
    int ContPalavras=0, ContCaracteres=0,ContLinhas=0;
    char caractereLido, CharInicioPalavra=' ';
    while((caractereLido=getchar()) != EOF){
        MeSintoVelho:
        ContCaracteres++;
        //marca o início de uma palavra
        if(CharInicioPalavra == ' ' && VerificaSeEValido(caractereLido)){
            CharInicioPalavra = caractereLido;
        }

        //pega o final da palavra e conta
        if(CharInicioPalavra != ' ' && !VerificaSeEValido(caractereLido)){
            ContPalavras++;
            CharInicioPalavra = ' ';
        }

        if(caractereLido == '\n'){
            ContLinhas++;
        }
        if(caractereLido == '\r'){
            caractereLido = getchar();            
            ContLinhas++;
            // caso seja \r\n conta só um caractere e finaliza a palavra
            if(caractereLido == '\n'){   
                ContCaracteres++;             
                continue;
            }
            //caso seja \r'algum outro char' finaliza a linha e incializa uma nova palavra
            printf("Velho\n");
            goto MeSintoVelho;                        
        }

    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%i\t%i\t%i\n",ContLinhas,ContPalavras,ContCaracteres);

    return 0;
}