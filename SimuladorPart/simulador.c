#include<stdio.h>
#include <stdlib.h>

#define largura 64
#define altura 32
char matriz[altura][largura];
char MatrizCopia[altura][largura];

void troca(int x1,int y1, int x2,int y2){
    char temp = MatrizCopia[x1][y1];
    MatrizCopia[x1][y1] = MatrizCopia[x2][y2];
    MatrizCopia[x2][y2] = temp;
}

void MovimentaAgua(int i,int j){    
    if(i+1 > altura || i+j > altura || j-1 < 0 ){
        return;
    }

    if(matriz[i+1][j] == ' '){        
        troca(i,j,i+1,j);
    }else if(matriz[i+1][j-1] == ' '){
        troca(i,j,i+1,j-1);
    }else if(matriz[i+1][j+1] == ' '){
        troca(i,j,i+1,j+1);
    }else if(matriz[i][j-1] == ' '){
        troca(i,j,i,j-1);
    }else if(matriz[i][j+1] == ' '){
        troca(i,j,i,j+1);
    }
}

void MovimentaAreia(int i,int j){   
    if(i+1 > altura || i+j > altura || j-1 < 0 ){
        return;
    }

    if(matriz[i+1][j] == ' ' || matriz[i+1][j]=='~'){        
        troca(i,j,i+1,j);
    }else if(matriz[i+1][j-1] == ' ' || matriz[i+1][j-1]=='~'){
        troca(i,j,i+1,j-1);
    }else if(matriz[i+1][j+1] == ' ' || matriz[i+1][j+1]=='~'){
        troca(i,j,i+1,j+1);
    }
}



int Fisica(){

    for(int i=0 ; i < altura; i++){
        for(int j=0; j < largura ; j++){
            MatrizCopia[i][j] = matriz[i][j];
        }
    }

    for(int i=0 ; i < altura; i++){
        for(int j=0; j < largura ; j++){

            switch (matriz[i][j])
            {
            case '#': MovimentaAreia(i,j);
                break;
            case '~': MovimentaAgua(i,j);
                break;
            }
        }
    }
}

int main(){
    int contador = 0,totalFrames, frame, coordX, coordY;
    char novaParticula;

    for(int i=0 ; i < altura; i++){
        for(int j=0; j < largura ; j++){
            matriz[i][j] = ' ';
        }
    }

    scanf("%i", &totalFrames); 

    while (contador < totalFrames) {
        int nLido = scanf(" %d: %d %d %c", &frame, &coordX, &coordY, &novaParticula);
        if(nLido == EOF){
            frame = totalFrames;
        }

        while (contador < frame) {
            system("clear");
            printf("frame: %d\n", contador + 1);            
            for(int i=0;i<altura;i++){
                for(int j=0;j<largura;j++){
                    printf("%c",MatrizCopia[i][j]);
                }
                printf("\n");
            }
            Fisica();
            contador++;
        }

        if(nLido != EOF){
            matriz[coordY][coordX] = novaParticula;
        }
    }
}