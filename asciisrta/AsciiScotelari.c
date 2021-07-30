//Lucas Pereira Pacheco nºusp:12543930
//ASCII Artista

#include<stdio.h>
#include<stdlib.h>

int main(){
    int qtdEtapas, coordX, coordY, numLinhasMatriz;
    char **matrizArte, charPreenchimento;

    matrizArte = leArquivoArte(&numLinhasMatriz);
    printaMatriz(matrizArte,numLinhasMatriz);
    
    scanf("%i",&qtdEtapas);
    for(int i =0;i< qtdEtapas;i++){
        scanf("%c %i %i",&charPreenchimento, &coordX, &coordY);

    }


    return 0;
}

void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY){
    matrizArte[coordX][coordY] = caractere;

    if(matrizArte[coordX +]){

    }

}


void printaMatriz(char **matrizArte, numLinhas){    
    for(int i =0;i < numLinhas; i++){
        printf("%s", matrizArte[i]);
    }    
}

char **leArquivoArte(int *numLinhas){
    int contLinhasArte = 0, totLinhasArte = 5;
    char **matrizArte = NULL, nomeArquivo[50]; 

    scanf("%s",nomeArquivo);

    FILE *fptr = fopen(nomeArquivo,"r");
    **matrizArte = malloc(totLinhasArte * sizeof(char *));
    do{
        matrizArte[contLinhasArte] = Readline(fptr);
        
        if(totLinhasArte == contLinhasArte){
            totLinhasArte += 5;
            matrizArte = realloc(matrizArte, sizeof(char*) * totLinhasArte);
        }
        contLinhasArte++;
    }while(matrizArte[contLinhasArte] != EOF);
    fclose(fptr);

    //REalocar matriz

    numLinhas = contLinhasArte;

}


char *Readline(FILE *fptr){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    // while((caractere = getchar()) == '\n');
    // if(caractere != EOF){
    //     ungetc(caractere,stdin);
    // }

    do{
        fscanf(fptr,"%c",&caractere);

        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != EOF && caractere != '\n' );

    linha = realloc(linha,contaCaracteres);

    return linha;
}