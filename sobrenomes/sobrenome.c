//nome:Lucas Pereira Pacheco nºusp:12543930
//Adicionando Sobrenomes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *readline(int *fimLeitura, char** ultimoSobrenome,int sobrenomeImpar){    
    int bloco = 250, contBlocos=1;    
    char *linha = (char*)malloc(bloco * sizeof(char));
    char *aux = linha, *sobrenomeAtual = linha;
    char caractere;
    

    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }
    
    do{
        caractere = getchar();
        caractere = (caractere == '\n') ?('\0'):(caractere);
        if(caractere == 36){
            *fimLeitura = 1;
            caractere = '\0';
        }


        if(sobrenomeAtual == NULL && !sobrenomeImpar){
            //Como foi zerado no último loop, assume o endereço
            //do primeiro char do próximo sobrenome
            sobrenomeAtual = linha ;
        }

        if(caractere == ' '&& !sobrenomeImpar){
            //O espaço indica a existência de um sobrenome posterior ao
            //atual, então zeramos o ponteiro, pois o sobrenome atual não nos interessa salvar
            sobrenomeAtual = NULL;
        }

        if(bloco == 0){            
            bloco = 250;
            aux = realloc(aux, bloco * ++contBlocos * sizeof(char));
        }
        *linha = caractere;
        linha++; bloco--;        
    }while(caractere != '\0');

    aux = (char*)realloc(aux, (250*contBlocos) - bloco);

    if(sobrenomeImpar){
        return aux;
    }

    //Passa último sobrenome pro ponteiro
    int numLetrasSobrenome = strlen(sobrenomeAtual);    

    ultimoSobrenome[0] = malloc(numLetrasSobrenome + 1);

    for(int i=0;i < numLetrasSobrenome; i++){
        ultimoSobrenome[0][i] = sobrenomeAtual[i];
    }    
    ultimoSobrenome[0][numLetrasSobrenome] = '\0';

    return aux;
}


char *addSobrenome(char *nome,char *ultimoSobrenome){
    int nLetrasSobrenome= strlen(ultimoSobrenome);
    int nLetrasNome = strlen(nome);

    nome = realloc(nome,nLetrasNome + nLetrasSobrenome + 1);
    
    //trocando '\0' por espaço
    nome[nLetrasNome] = ' ';   

    //adicionando sobrenome ao nome
    for(int i = 1;i <= (int)strlen(ultimoSobrenome); i++){        
        nome[nLetrasNome + i] = ultimoSobrenome[i - 1];
    }

    nome[nLetrasNome + nLetrasSobrenome +1] = '\0';

    return nome;
}


int main(){
    char *nome, *ultimoSobrenome=NULL;
    int FimLeitura =0, contaSobrenomes=0;

    while(!FimLeitura){        
        nome = readline(&FimLeitura, &ultimoSobrenome, contaSobrenomes%2);
        if(contaSobrenomes % 2 ){
            nome = addSobrenome(nome,ultimoSobrenome);
            free(ultimoSobrenome);
        }

        printf("%s\n", nome);

        contaSobrenomes++;
        free(nome);
    }


    return 0;
}
