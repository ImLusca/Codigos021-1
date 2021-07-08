#include<stdio.h>
#include <stdlib.h>
#include <unistd.h> 


#define BLU "\e[0;34m"
#define YEL "\e[0;33m"

#define altura 32
#define largura 64
char matriz[altura][largura];
char MatrizCopia[altura][largura];

void troca(int x1,int y1, int x2,int y2){
    char temp = MatrizCopia[x1][y1];
    MatrizCopia[x1][y1] = MatrizCopia[x2][y2];
    MatrizCopia[x2][y2] = temp;
}

void MovimentaAgua(int i,int j){    

    //se tiver ar e não for borda, faz a troca

    if(matriz[i+1][j] == 32 && i+1 <= altura){     
        troca(i,j,i+1,j);
    }else if(matriz[i+1][j-1] == 32 && i+1 <= altura && j-1 >= 0){
        troca(i,j,i+1,j-1);
    }else if(matriz[i+1][j+1] == 32 && i+1 <= altura && j+1 <= largura){
        troca(i,j,i+1,j+1);
    }else if(matriz[i][j-1] == 32 && j-1 >= 0){
        troca(i,j,i,j-1);
    }else if(matriz[i][j+1] == 32 && j+1 <= largura){
        troca(i,j,i,j+1);
    }
}

void MovimentaAreia(int i,int j){   
    if( i+1 > altura){
        return;
    }
    //se tiver ar ou água e não for borda, faz a troca
    if(matriz[i+1][j] == 32 || matriz[i+1][j]==126 ){        
        troca(i,j,i+1,j);
    }else if((matriz[i+1][j-1] == 32 || matriz[i+1][j-1]==126) && j-1 >= 0 ){
        troca(i,j,i+1,j-1);
    }else if((matriz[i+1][j+1] == 32 || matriz[i+1][j+1]==126) && j+1 <= largura ){
        troca(i,j,i+1,j+1);
    }
}



void Fisica(){

    //Procura por areia e àgua para aplicar a física
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

    for(int i=0 ; i < altura; i++){
        for(int j=0; j < largura ; j++){
            matriz[i][j] = MatrizCopia[i][j];
        }
    }
}

int main(){
    int contador = 0,totalFrames, frame, coordX, coordY;
    char novaParticula;

    for(int i=0 ; i < altura; i++){
        for(int j=0; j < largura ; j++){
            matriz[i][j] = 32;
            MatrizCopia[i][j] = 32;
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
                    if(matriz[i][j] == '#'){
                        printf(YEL "%c" ,matriz[i][j]);                        
                        continue;
                    }else if(matriz[i][j] == '~'){
                        printf(BLU "%c" ,matriz[i][j]);
                        continue;
                    }
                    printf("%c" ,matriz[i][j]);

                }
                printf("\n");
            }
            Fisica();
            contador++;
            usleep(20000);
        }

        if(nLido != EOF){
            matriz[coordY][coordX] = novaParticula;
            MatrizCopia[coordY][coordX] = novaParticula;      
        }
    }
}