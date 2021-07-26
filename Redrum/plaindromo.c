//Lucas Pereira Pacheco nºusp:12543930
//Redrum
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct palavras{
    char *stringEntrada;
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

int VerificaPalindromo(structPalavras *Palavras,int indice){

    int totCaracteres = Palavras->qtdCaracteres;

    //Se o indice for igual a quantidade de caracteres
    //significa que todos caracteres das duas strings são iguais
    if(indice == (Palavras->qtdCaracteres / 2) + 1){
        return 1;
    }
    //Se os caracteres forem diferentes, retorna false e para a verificacao
    if(Palavras->stringEntrada[indice] != Palavras->stringEntrada[totCaracteres - indice - 1]){
        return 0;
    }

    //Se os caracteres deste indice forem iguais, compara os próximos
    return VerificaPalindromo(Palavras,++indice);
}

void LimpaString(structPalavras* Palavras){
    char caractere, tempStr[Palavras->qtdCaracteres + 1];
    int indiceCaractere=0;    
    
    for(int i =0;i < Palavras->qtdCaracteres; i++){
        caractere = Palavras->stringEntrada[i];

        //Remove espacos e barras 
        if(isalnum(caractere)){
            tempStr[indiceCaractere] = caractere;
            indiceCaractere++;
        }
    }

    tempStr[indiceCaractere] = '\0';
    Palavras->qtdCaracteres = indiceCaractere;

    for(int i =0; i <= Palavras->qtdCaracteres; i++){
        Palavras->stringEntrada[i] = tempStr[i];
    }

}

int main(){
   structPalavras Palavras; 

    Palavras.stringEntrada = Readline();
    Palavras.qtdCaracteres = strlen(Palavras.stringEntrada);

    if(VerificaPalindromo(&Palavras,0)){
        printf("Palindromo direto\n");
        free(Palavras.stringEntrada);        
        return 0;
    }

    LimpaString(&Palavras);
    
    if(VerificaPalindromo(&Palavras,0)){
        printf("Palindromo indireto\n");
        free(Palavras.stringEntrada);
        return 0;
    }

    printf("Nao eh um palindromo\n");
    
    free(Palavras.stringEntrada);

    return 0;
}