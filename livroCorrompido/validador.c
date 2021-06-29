//nome:Lucas Pereira PaAcheco, nºusp:12543930
//Livro Corrompido
#include<stdio.h>
#include<stdlib.h>


char *readline(){
    int bloco = 100, contBlocos=1;    
    char* linha = (char*)malloc(bloco * sizeof(char));
    char* aux = linha;
    char caractere;
    do{
        caractere = getchar();
        caractere = (caractere == '\n') ?('\0'):(caractere);
        //Inicia com um bloco de 100 espaços que decrementa
        //sempre que um caractere é alocado. Quando o bloco se o
        //bloco for preechido, o sistema aumenta o seu tamanho em mais 100.
        if(bloco == 0){            
            bloco = 100;
            aux = realloc(aux, bloco * ++contBlocos * sizeof(char));
        }
        *linha = caractere;
        linha++;
        bloco--;
        
    }while(caractere != '\0');

    //Remove o Espaço extra do bloco
    aux = (char*)realloc(aux, (100*contBlocos) - bloco);

    return aux;
}

int main(){
    int numLinhas,NaoCorrompidas,indice;
    scanf("%i\n",&numLinhas);            
    char **MatrizLinhas = NULL;
    MatrizLinhas = malloc(numLinhas * sizeof(char*));
    
    for(int i =0;i<numLinhas;i++){
        MatrizLinhas[i] = readline();
    }

    //Lendo e printando as linhas não corrompidas
    scanf("%i",&NaoCorrompidas);
    for(int i = 0;i<NaoCorrompidas;i++){
        scanf("%i",&indice);
        printf("%s\n", MatrizLinhas[indice]);
    }
    //Desalocando a memória
    for(int i =0;i < numLinhas; i++){
        free(MatrizLinhas[i]);
    }
    free(MatrizLinhas);

    return 0;
}