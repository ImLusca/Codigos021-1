#include<stdio.h>

int main(){

    int rodadas,jogadores, pinguVez, rodadaAtual=0;    
    scanf("%i %i %i",&rodadas,&jogadores,&pinguVez);
    
    if(pinguVez == jogadores){
        pinguVez = 0;
    }

    for(int i = 1; i < rodadas; i++){

        for(int j = 0; j < i; j++){
            rodadaAtual++;
            if(rodadaAtual % jogadores == pinguVez){

                if(rodadaAtual == 1){
                    printf("%i pinguim\n", i);
                }else{
                    printf("%i pinguins\n", i);
                }

            }
            if(rodadaAtual == rodadas)
            break;
        }
        if(rodadaAtual == rodadas){
            break;
        }

        for(int j = 0; j < i; j++){
            rodadaAtual++;
            if(rodadaAtual % jogadores == pinguVez){
                printf("no gelo\n");
            }
            if(rodadaAtual == rodadas)
            break;
        }
        if(rodadaAtual == rodadas){
            break;
        }

        for(int j = 0; j < i; j++){
            rodadaAtual++;
            if(rodadaAtual % jogadores == pinguVez){
                printf("uhuu!\n");
            }
            if(rodadaAtual == rodadas)
            break;
        }
        if(rodadaAtual == rodadas){
            break;
        }
    }



    return 0;
}