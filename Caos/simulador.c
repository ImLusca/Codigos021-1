//nome: Lucas Pereira Pacheco, nºusp: 12543930
//Admirável mundo caótico

#include<stdio.h>
#include<stdlib.h>

typedef struct matrizes
{
    int rows;    
    int cols;
    char **matriz;
    char **matrizCop;
} Matrizes;

void modeloNeuman(Matrizes dadosMat,int coordX,int coordY);
void modeloMoore(Matrizes dadosMat,int coordX,int coordY);
void sincronizaMatrizes(Matrizes dadosMat);

int main(){
    int linhas, colunas,geracoes,contador=0;
    char **mat = NULL, **matCopia=NULL;
    char vizinhanca;

    scanf("%i %i %i %c",&linhas,&colunas,&geracoes,&vizinhanca);

    if(linhas <= 0 || colunas <=0|| geracoes <=0){
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }
    if(vizinhanca != 'N' && vizinhanca != 'M'){
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }
    // Alocando as Matrizes
    mat = malloc(sizeof(char*)*linhas);
    matCopia = malloc(sizeof(char*)*linhas);
    for(int i=0;i< linhas;i++){
        mat[i] = malloc(sizeof(char)*colunas);
        matCopia[i] = malloc(sizeof(char)*colunas);
    }

    //Lendo matriz entrada
    for(int i =0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            char tempchar;
            tempchar = getchar();

            if(tempchar == '\n'){
                tempchar = getchar();
            }

            mat[i][j] = tempchar;
            matCopia[i][j] = tempchar;
        }
    }

    Matrizes dadosMatriz;
    dadosMatriz.rows = linhas;
    dadosMatriz.cols = colunas;
    dadosMatriz.matriz = mat;
    dadosMatriz.matrizCop = matCopia;

    while (contador < geracoes)
    {
        if(vizinhanca == 'N'){    
            for(int i =0;i< dadosMatriz.rows;i++){
                for(int j=0;j< dadosMatriz.cols; j++){
                    modeloNeuman(dadosMatriz,i,j);
                }
            }
        }
        else{
            for(int i =0;i< dadosMatriz.rows;i++){
                for(int j=0;j< dadosMatriz.cols; j++){
                    modeloMoore(dadosMatriz,i,j);
                }
            }
        }
        
        sincronizaMatrizes(dadosMatriz);
        contador++;
    }    

    //printando o resutado final
    for(int i = 0; i < dadosMatriz.rows ;i++){
        for(int j=0;j < dadosMatriz.cols;j++){
            printf("%c",dadosMatriz.matriz[i][j]);
        }
        printf("\n");
    }

    //Desalocando memória

    for(int i = 0; i< linhas; i++){
        free(mat[i]);
        free(matCopia[i]);
    }
    free(mat);
    free(matCopia);


    return 0;
}

void modeloNeuman(Matrizes dadosMat,int coordX,int coordY){
    int contadorCelulas = 0;

    for(int i = coordX - 2; i < coordX+3;i++){
        //passa pra cima ou baixo caso chegue na borda da matriz        
        int tempI =  i;
        if(i < 0 ) {tempI += dadosMat.rows; }
        if(i > dadosMat.rows - 1 ) {tempI -= dadosMat.rows ;}

        //Não conta a própria célula
        if(i == coordX){continue;}

        contadorCelulas += (dadosMat.matriz[tempI][coordY] == 'x');
    }

    for(int i = coordY - 2; i < coordY + 3;i++){
        //passa pra esquerda ou direita caso chegue na borda da matriz        
        int tempI =  i;
        if(i < 0 ) {tempI += dadosMat.cols; }
        if(i > dadosMat.cols-1) {tempI -= dadosMat.cols;}

        //Não conta a própria célula
        if(i == coordY){continue;}

        contadorCelulas += (dadosMat.matriz[coordX][tempI] == 'x');
    }

    if(dadosMat.matriz[coordX][coordY] == 'x'){
        if(contadorCelulas < 2 ){
            dadosMat.matrizCop[coordX][coordY] = '.';
        }else if(contadorCelulas > 3){
            dadosMat.matrizCop[coordX][coordY] = '.';            
        }
    }else{
        if(contadorCelulas == 3){
            dadosMat.matrizCop[coordX][coordY] = 'x';            
        }
    }
}

void modeloMoore(Matrizes dadosMat,int coordX,int coordY){
    int contadorCelulas = 0;

    for(int i = coordX - 1; i<coordX+2;i++){
        //passa pra cima ou baixo caso chegue na borda da matriz      
        int tempI = i;  
        if(i < 0 ) tempI += dadosMat.rows; 
        if(i >= dadosMat.rows ) tempI -= dadosMat.rows;

        for(int j = coordY -1; j< coordY+2;j++){
            //passa pra esquerda ou direita caso chegue na borda da matriz        
            int tempJ = j;
            if(j < 0 ) {tempJ += dadosMat.cols;}
            if(j >= dadosMat.cols) {tempJ -= dadosMat.cols;}

            //Não conta a própria célula
            if(i == coordX && j == coordY){continue;}
            
            contadorCelulas += (dadosMat.matriz[tempI][tempJ] == 'x');
        }
    }
    //usa a matriz original como referência para modificar a cópia   

    if(dadosMat.matriz[coordX][coordY] == 'x'){
        if(contadorCelulas < 2 ){
            dadosMat.matrizCop[coordX][coordY] = '.';
        }else if(contadorCelulas > 3){
            dadosMat.matrizCop[coordX][coordY] = '.';            
        }
    }else{
        if(contadorCelulas == 3){
            dadosMat.matrizCop[coordX][coordY] = 'x';            
        }
    }
}

void sincronizaMatrizes(Matrizes dadosMat){
    //Iguala a Matriz original com a cópia
    for(int i = 0; i < dadosMat.rows ;i++){
        for(int j=0;j < dadosMat.cols; j++){
            dadosMat.matriz[i][j] = dadosMat.matrizCop[i][j];
        }
    }
}


