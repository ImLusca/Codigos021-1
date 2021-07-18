//nome: Lucas Pereira Pacheco   nºusp:12543930 
//Padding de Imagens
#include<stdio.h>
#include<stdlib.h>

int main(){
    int **imagem =NULL,**imagemComPadding = NULL;
    int larguraImagem,alturaImagem,padding;
    
    scanf("%i %i", &larguraImagem,&alturaImagem);

    imagem = malloc(sizeof(int*)*alturaImagem);
    for(int i=0; i<alturaImagem; i++){
        imagem[i] = malloc(sizeof(int)*larguraImagem);
    }
    
    for(int i =0; i<alturaImagem;i++){
        for(int j=0; j< larguraImagem;j++){
            scanf("%i",&imagem[i][j]);
        }
    }

    scanf("%i",&padding);
    
    imagemComPadding = malloc(sizeof(int*)*(alturaImagem + (padding*2) ));
    for(int i =0;i<(alturaImagem + (padding*2) );i++){
        imagemComPadding[i] = (int*)calloc( larguraImagem + (padding*2), sizeof(int));
    }

    for(int i =0 ; i< alturaImagem ;i++){
        for(int j=0; j<larguraImagem ; j++){
            imagemComPadding[i+padding][j+padding] = imagem[i][j];
        }
    }
    
    for(int i =0;i<(alturaImagem + (padding*2) );i++){
        for(int j=0;j<(larguraImagem + (padding*2) ); j++){
            printf("%i ",imagemComPadding[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i =0;i<alturaImagem;i++){
        for(int j=0;j<larguraImagem; j++){
            printf("%i ",imagem[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<alturaImagem; i++){
        free(imagem[i]);
    }
    for(int i=0; i<alturaImagem + (padding*2); i++){
        free(imagemComPadding[i]);
    }
    free(imagem);
    free(imagemComPadding);
    
    
    return 0;
}
