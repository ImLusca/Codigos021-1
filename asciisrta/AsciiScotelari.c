//Lucas Pereira Pacheco nºusp:12543930
//ASCII Artista

#include<stdio.h>
#include<stdlib.h>


void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY);
void printaMatriz(char **matrizArte,int numLinhas);
char **leArquivoArte(int *numLinhas);
char *Readline(FILE *fptr);

int main(){
    int qtdEtapas, coordX, coordY, numLinhasMatriz;
    char **matrizArte, charPreenchimento;

    matrizArte = leArquivoArte(&numLinhasMatriz);
    printaMatriz(matrizArte,numLinhasMatriz);
    
    scanf("%i",&qtdEtapas);
    for(int i =0;i< qtdEtapas;i++){
        scanf("%c %i %i",&charPreenchimento, &coordX, &coordY);
        preencheEspaco(matrizArte,charPreenchimento,coordX,coordY);
        printf("Arte apos a etapa %i", i);
        printaMatriz(matrizArte,numLinhasMatriz);
    }   

    //Lembrar de liberar memória
    return 0;
}

void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY){

    matrizArte[coordX][coordY] = caractere;

    //Procura por espaços em branco nas quatro direções
    //Ao encontrar, chama esta mesma função que preenche
    //o espaço e repete o procedimento recursivamente
    if(matrizArte[coordX +1][coordY] == 32){
        preencheEspaco(matrizArte,caractere,coordX+1,coordY);
    }
    if(matrizArte[coordX - 1][coordY] == 32){
        preencheEspaco(matrizArte,caractere,coordX-1,coordY);
    }
    if(matrizArte[coordX][coordY + 1] == 32){
        preencheEspaco(matrizArte,caractere,coordX,coordY + 1);
    }
    if(matrizArte[coordX][coordY - 1] == 32){
        preencheEspaco(matrizArte,caractere,coordX,coordY + 1);
    }
}

void printaMatriz(char **matrizArte,int numLinhas){    
    for(int i =0;i < numLinhas; i++){
        printf("%s", matrizArte[i]);
    }    
}

char **leArquivoArte(int *numLinhas){
    int contLinhasArte = 0, totLinhasArte = 5;
    char **matrizArte = NULL, nomeArquivo[50]; 

    scanf("%s",nomeArquivo);

    FILE *fptr = fopen(nomeArquivo,"r");
    matrizArte = malloc(totLinhasArte * sizeof(char *));
    do{
        matrizArte[contLinhasArte] = Readline(fptr);
        
        if(totLinhasArte == contLinhasArte){
            totLinhasArte += 5;
            matrizArte = realloc(matrizArte, sizeof(char *) * totLinhasArte);
        }
        contLinhasArte++;
    }while(matrizArte[contLinhasArte-1][0] != EOF);
    fclose(fptr);

    //Realocar matriz

    *numLinhas = contLinhasArte;
    return matrizArte;
}

char *Readline(FILE *fptr){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

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