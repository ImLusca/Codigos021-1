//Lucas Pereira Pacheco. nºusp: 12543930
#include<stdio.h>

int main(){
    char Fabrica[32][64], ultimoAcao = '[';
    int counterMov = 0,linha =0 ,coluna = 0;

    for(int i =0; i < 32;i++){
        for(int j= 0; j<64; j++){            
            scanf("%c",&Fabrica[i][j]);
            if(Fabrica[i][j] == '['){
                linha = i;                
                coluna = j+2;
            }
        }               
        //descarta o \n
        char lixo;
        scanf("%c", &lixo);
    }

    while(ultimoAcao != ' ' && ultimoAcao !=']'){
        switch (Fabrica[linha][coluna]){
            case '>': Fabrica[linha][coluna] = '.';
                coluna += 2;                
                ultimoAcao = '>';
            break;

            case '<': Fabrica[linha][coluna] = '.';
                coluna-= 2;  
                ultimoAcao = '<';          
            break;

            case '^': Fabrica[linha][coluna] = '.';
                linha -= 1;
                ultimoAcao = '^';
            break;

            case 'v': Fabrica[linha][coluna] = '.';
                linha+= 1;
                ultimoAcao = 'v';
            break;

            case '#': 
                if(ultimoAcao == '^' || ultimoAcao == 'v'){
                    linha += (ultimoAcao == '^') ? (-1) :(1);
                }else{
                    coluna += (ultimoAcao == '>') ? (2) : (-2);
                }
                
            break;

            case ']':
                printf("Ok.\n");
                ultimoAcao = ']';                
            break;

            case ' ':
                printf("Falha na esteira.\n");
                ultimoAcao = ' ';
            break;
        }
        counterMov++;
        if(counterMov == 2048){      
            printf("Loop infinito.\n");
            break;
        } 
    }       

    for(int i =0; i < 32;i++){
        for(int j= 0; j < 64; j++){
            printf("%c", Fabrica[i][j]);            
        }                
        printf("\n");
    }



    return 0;
}

