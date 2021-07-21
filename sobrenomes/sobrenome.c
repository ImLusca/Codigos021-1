//nome:Lucas Pereira Pacheco nºusp:12543930
//Adicionando Sobrenomes
#include<stdio.h>

char *readline(int *FimLeitura, char* ultimoSobrenome){    
    int bloco = 100, contBlocos=1;    
    char* linha = (char*)malloc(bloco * sizeof(char));
    char* aux = linha;
    char caractere;
    ultimoSobrenome = linha;

    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }
    
    do{
        caractere = getchar();
        caractere = (caractere == '\n') ?('\0'):(caractere);
        if(caractere == 36){
            *FimLeitura = 1;
            caractere = '\0';
        }


        if(ultimoSobrenome == NULL){
            //Como foi zerado no último loop, assume o endereço
            //do primeiro char do próximo sobrenome
            //(Pode dar problema se a pessoa colocar dois espaços rs) 
            ultimoSobrenome = linha + 1;
        }

        if(caractere == ' '){
            ultimoSobrenome = NULL;
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


void addSobrenome(char *nome,char *ultimoSobrenome){

    

}


int main(){
    char *nome, *ultimoSobrenome;
    int FimLeitura =0, contaSobrenomes=0;

    while(!FimLeitura){
        *nome = readline(&FimLeitura, ultimoSobrenome);

        printf("%s\n", nome);

    }


    return 0;
}
