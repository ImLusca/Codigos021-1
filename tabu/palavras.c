//nome:Lucas Pereira Pacheco nºusp:12543930
//Retirar palavra tabu

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *readline(char *Tabu,int *contador){    
    int bloco = 100, contBlocos=1;    
    char* linha = (char*)malloc(bloco * sizeof(char));
    char* aux = linha;
    char caractere;
    
    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }
    
    do{
        caractere = getchar();
        caractere = (caractere == '$') ?('\0'):(caractere);

        //se caracter for igual a primeira letra da palavra tabu,
        //Compara o restante
        if(caractere == Tabu[0]){
            *contador+=1;
            for(int i =1;i < (int)strlen(Tabu);i++){
                caractere = getchar();
                //Se o restante não for igual, adiciona a 
                //linha oque foi lido até então
                if(caractere != Tabu[i]){
                    for(int j = 0; j < i ;j++){
                        if(bloco == 0){bloco = 100;
                            aux = realloc(aux, bloco * ++contBlocos * sizeof(char));
                        }
                        *linha = Tabu[j];                        
                        linha++;
                        bloco--;
                    }

                    if(bloco == 0){bloco = 100;
                        aux = realloc(aux, bloco * ++contBlocos * sizeof(char));
                    }
                    *linha= caractere;
                    linha++;
                    bloco--;

                    *contador-=1;
                    break;
                }
            }
            continue;
        }

        if(bloco == 0){            
            bloco = 100;
            aux = realloc(aux, bloco * ++contBlocos * sizeof(char));
        }
        *linha = caractere;
        linha++; bloco--;        
    }while(caractere != '\0');

    aux = (char*)realloc(aux, (100*contBlocos) - bloco);

    return aux;
}


int main(){
    char PalavraTabu[20],*frase;
    int contadorTabu=0;

    scanf("%s\n",&PalavraTabu[0]);
    frase = readline(PalavraTabu,&contadorTabu);

    printf("A palavra tabu foi encontrada %i vezes\n", contadorTabu);
    printf("Frase: %s", frase);

    free(frase);
    return 0;
}
