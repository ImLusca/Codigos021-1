#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *Readline();


int main(){
    // lê matriz
    int numLinhas,numCols,numBombs;
    char **campo = NULL, **copCampo = NULL;

    scanf("%i %i %i", &numLinhas, &numCols, &numBombs);

    campo = malloc(sizeof(char*) * numLinhas);
    copCampo = malloc(sizeof(char*) * numLinhas);


    for(int i =0; i < numLinhas; i++){
        campo[i] = Readline();
        copCampo[i] = Readline();
    }

    // conta pontos

    for(int i =0; i < numLinhas; i++){
        for(int j =0; j < numCols; j++){

            if(campo[i][j] == 46){
                //Função que conta números em volta
            }else{
                copCampo = 'X';
            }

        }
    }


    // Compara e reduz até passar por toda matriz
    for(int i =0; i < numLinhas; i++){
        for(int j =0; j < numCols; j++){

            if(copCampo[i][j] != 'X'){
                //Verifica se existe número maior

            }

        }
    }


    // verifica se os endereços das bombas são os mesmos
    // desaloca variaveis

    // 0 0 0 .   ||   X X X 1
    // 0 0 . .   ||   X X 4 2
    // 0 . . 0   ||   X 4 3 X
    // . 0 . .   ||   2 X 2 1

    // . . .     ||   0 0 1
    // . 0 .     ||   1 X 1
    // . . .     ||   1 1 1

    // X X X 1
    // X X 4 2
    // X 4 3 X
    // 2 X 2 1




}

char *Readline(){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    do{        
        caractere = getchar();

        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != '\n' && caractere != EOF);

    linha[contaCaracteres-1] = '\0';

    linha = realloc(linha,contaCaracteres);   

    return linha;
}
