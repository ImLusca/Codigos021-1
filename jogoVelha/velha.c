//nome: Lucas Pereira Pacheco nºusp:12543930
// Estado do jogo da Velha
#include<stdio.h>

int main(){
    char tabuleiro[3][3],lixo;
    int counterEspaco = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%c",&tabuleiro[i][j]);
            if(tabuleiro[i][j] == '-'){
                counterEspaco++;
            }
            // descarta caracteres à direta como ' ' e '\n'
            scanf("%c",&lixo);
        }
    }

    //verifica cada linha
    for(int i = 0;i < 3;i++){
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]){
            if(tabuleiro[i][0] != '-'){
                printf("%c ganhou", tabuleiro[i][0]);
                return 0;
            }
        }
    }

    //verifica cada coluna
    for(int j = 0;j < 3;j++){
        if(tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[0][j] == tabuleiro[2][j]){
            if(tabuleiro[0][j] != '-'){
                printf("%c ganhou", tabuleiro[0][j]);
                return 0;
            }
        }
    }

    //verifica diagonais
    if(tabuleiro[1][1] != '-'){
        if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]){
            printf("%c ganhou", tabuleiro[1][1]);
            return 0;
        }
        if(tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[2][0] == tabuleiro[0][2]){
            printf("%c ganhou", tabuleiro[1][1]);
            return 0;
        }
    }
       
    if(counterEspaco == 0){
        printf("empate");
    }else{
        printf("em jogo");
    }
    return 0;
}

