//Lucas Pereira Pacheco nºusp:12543930
//ASCII Artista

#include<stdio.h>
#include<stdlib.h>


void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY,int numLinhasMatriz);
void printaMatriz(char **matrizArte,int numLinhas);
char **leArquivoArte(int *numLinhas);
char *Readline(FILE *fptr,int *fimDeArquivo);

int main(){
    int qtdEtapas, coordX, coordY, numLinhasMatriz;
    char **matrizArte, charPreenchimento;

    matrizArte = leArquivoArte(&numLinhasMatriz);
    printaMatriz(matrizArte,numLinhasMatriz);
    
    scanf("%i",&qtdEtapas);
    for(int i =0;i< qtdEtapas;i++){
        charPreenchimento = getchar();
        scanf("%i %i", &coordX, &coordY);
        preencheEspaco(matrizArte,charPreenchimento,coordX,coordY, numLinhasMatriz);
        printf("Arte apos a etapa %i", i);
        printaMatriz(matrizArte,numLinhasMatriz);
    }   

    //Lembrar de liberar memória
    return 0;
}

void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY,int  numLinhasMatriz){

    matrizArte[coordX][coordY] = caractere;

    //Procura por espaços em branco nas quatro direções
    //Ao encontrar, chama esta mesma função que preenche
    //o espaço e repete o procedimento recursivamente
    if(coordX + 1 < numLinhasMatriz && matrizArte[coordX + 1][coordY] == 32){
        preencheEspaco(matrizArte,caractere,coordX+1,coordY,numLinhasMatriz);
    }
    if(coordX - 1 >= 0 &&  matrizArte[coordX - 1][coordY] == 32){
        preencheEspaco(matrizArte,caractere,coordX-1,coordY,numLinhasMatriz);
    }
    if(matrizArte[coordX][coordY + 1] == 32){
        //Não precisa de verificação de segfault, pois sempre vai ter um \n no final da linha;
        preencheEspaco(matrizArte,caractere,coordX,coordY + 1,numLinhasMatriz);
    }
    if(coordY-1 >= 0 && matrizArte[coordX][coordY - 1] == 32){
        preencheEspaco(matrizArte,caractere,coordX,coordY + 1,numLinhasMatriz);
    }
}

void printaMatriz(char **matrizArte,int numLinhas){    
    for(int i =0;i < numLinhas; i++){
        printf("%s", matrizArte[i]);
    }    
}

char **leArquivoArte(int *numLinhas){
    int contLinhasArte = 0, totLinhasArte = 200, fimDoArquivo=0;
    char **matrizArte = NULL, nomeArquivo[50]; 

    scanf("%s",nomeArquivo);

    FILE *fptr = fopen(nomeArquivo,"r");
    matrizArte = malloc(totLinhasArte * sizeof(char *));
    do{
        matrizArte[contLinhasArte] = Readline(fptr,&fimDoArquivo);
        
        if(totLinhasArte == contLinhasArte){
            printaMatriz(matrizArte, totLinhasArte);
            totLinhasArte += 5;
            int temp = sizeof(char*) * totLinhasArte;
            matrizArte = realloc(matrizArte, temp);
        }
        contLinhasArte++;
    }while(!fimDoArquivo);
    fclose(fptr);

    //lembrar de realocar matriz

    *numLinhas = contLinhasArte;
    return matrizArte;
}

char *Readline(FILE *fptr,int *fimDeArquivo){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    do{        
        caractere = fgetc(fptr);
        if(caractere == EOF){
            *fimDeArquivo = 1;
            caractere = '\n';
        }


        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != '\n' );

    linha = realloc(linha,contaCaracteres);   

    return linha;
}