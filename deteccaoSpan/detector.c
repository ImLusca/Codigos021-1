//nome: Lucas Pereira Pacheco. nºusp: 12543930
//Detecção de Spam

#include<stdio.h>
#include<string.h>
#include<ctype.h>
char linha[77];

int main(){
    char palavrasProibidas[23][20] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda","SOS",
                                "Gratuito", "Atencao", "Urgente", "Imediato", "Zoombie", "Oferta", "Dinheiro", "Renda", "Fundo", "Limitado", "Ajuda"};
    int contadorProibidas=0,contadorCaracteres=0;
    char caractere;
        
    for(;((caractere = getchar()) != EOF); ){

        linha[contadorCaracteres] = caractere;
        if(caractere == '\n'){
            contadorCaracteres = 0;
            for(int i =0;i<12;i++){
                char *repeticao; 
                repeticao = strstr(linha,palavrasProibidas[i]);
                if(repeticao != 0){                          
                    contadorProibidas++;                    
                }
                if(contadorProibidas == 2){
                    printf("Spam\n");
                    return 0;
                }
            }                    
            // limpando o vetor pra garantir que uma mesma palavra não seja contada duas
            // vezes na próxima verificação
            for(int i =0;i<76;i++){linha[i] =' ';}
        }else{
            contadorCaracteres ++;
        }
        
        if(contadorCaracteres > 76){
            printf("Spam\n");
            return 0;
        }
    }
    


    printf("Inbox\n");


    return 0;
}