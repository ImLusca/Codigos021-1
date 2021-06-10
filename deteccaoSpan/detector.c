//nome: Lucas Pereira Pacheco. nºusp: 12543930
//Detecção de Spam

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(){
    char palavrasProibidas[25][12] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda","SOS"};
    char email[10000], caractere;
    int contadorProibidas=0,contadorCaracteres=0,i=0;
        
    while(scanf("%c", &caractere) != EOF && contadorCaracteres <= 77){   
             
        email[i] = tolower(caractere);
        if(caractere == '\n'){
            contadorCaracteres = 0;
        }else{
            contadorCaracteres ++;
        }
        i++;
    }    
    if(contadorCaracteres  == 77){
        printf("Spam");
        return 0;
    }

    for(int i =0;i<12;i++){
        char *repeticao;
        printf("%s",palavrasProibidas[i]);
        repeticao =  strstr(palavrasProibidas[i],email);
        if(repeticao == 0){           
            contadorProibidas++;
        }
        if(contadorProibidas == 2){
            printf("Spam");
            return 0;
        }
    }

    printf("Inbox");


    return 0;
}