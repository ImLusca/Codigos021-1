//Lucas Pereira Pacheco nºusp:12543930
//ASCII Artista

#include<stdio.h>
#include<stdlib.h>


void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY,int numLinhasMatriz);
void printaMatriz(char **matrizArte,int numLinhas);
char **leArquivoArte(int *numLinhas);
char *Readline(FILE *fptr,int *fimDeArquivo);

int main(){
    int qtdEtapas, coordX, coordY, numLinhasMatriz;
    char **matrizArte, charPreenchimento;

    matrizArte = leArquivoArte(&numLinhasMatriz);

    printf("Arte inicial:\n");
    printaMatriz(matrizArte,numLinhasMatriz);
    
    scanf("%i",&qtdEtapas);
    for(int i =0;i< qtdEtapas;i++){
                
        //tira \n do buffer
        while((charPreenchimento = getchar()) == '\n');

        scanf("%i %i", &coordX, &coordY);
        preencheEspaco(matrizArte,charPreenchimento,coordX,coordY, numLinhasMatriz);

        printf("Arte apos a etapa %i:\n", i);
        printaMatriz(matrizArte,numLinhasMatriz);
    }   

    //Lembrar de liberar memória
    return 0;
}

void preencheEspaco(char **matrizArte,char caractere,int coordX,int coordY,int  numLinhasMatriz){
    char charPreenchimento = matrizArte[coordX][coordY];
    matrizArte[coordX][coordY] = caractere;

    //Procura por caracteres iguais nas quatro direções
    //Ao encontrar, chama esta mesma função que substitui
    //o caractere e repete o procedimento recursivamente
    if(coordX + 1 < numLinhasMatriz && matrizArte[coordX + 1][coordY] == charPreenchimento){
        //printaMatriz(matrizArte,numLinhasMatriz);
        preencheEspaco(matrizArte,caractere,coordX+1,coordY,numLinhasMatriz);
    }

    if(coordX - 1 >= 0 &&  matrizArte[coordX - 1][coordY] == charPreenchimento){
        //printaMatriz(matrizArte,numLinhasMatriz);
        preencheEspaco(matrizArte,caractere,coordX-1,coordY,numLinhasMatriz);
    }

    if(matrizArte[coordX][coordY + 1] == charPreenchimento){
        //Não precisa de verificação de segfault, pois sempre vai ter um \n no final da linha;
        //printaMatriz(matrizArte,numLinhasMatriz);
        preencheEspaco(matrizArte,caractere,coordX,coordY + 1,numLinhasMatriz);
    }

    if(coordY-1 >= 0 && matrizArte[coordX][coordY - 1] == charPreenchimento){
        //printaMatriz(matrizArte,numLinhasMatriz);
        preencheEspaco(matrizArte,caractere,coordX,coordY - 1,numLinhasMatriz);
    }
}

void printaMatriz(char **matrizArte,int numLinhas){    
    for(int i =0;i < numLinhas; i++){
        printf("%s", matrizArte[i]);
    }    
}

char **leArquivoArte(int *numLinhas){
    int contLinhasArte = 0, maxLinhasArte = 200, fimDoArquivo=0;
    char **matrizArte = NULL, nomeArquivo[50]; 

    scanf("%s",nomeArquivo);

    FILE *fptr = fopen(nomeArquivo,"r");
    matrizArte = malloc(maxLinhasArte * sizeof(char *));
    do{
        matrizArte[contLinhasArte] = Readline(fptr,&fimDoArquivo);
        
        if(maxLinhasArte == contLinhasArte){
            printaMatriz(matrizArte, maxLinhasArte);
            maxLinhasArte += 5;
            int temp = sizeof(char*) * maxLinhasArte;
            matrizArte = realloc(matrizArte, temp);
        }
        contLinhasArte++;
    }while(!fimDoArquivo);
    fclose(fptr);

    //lembrar de realocar matriz

    *numLinhas = contLinhasArte;
    return matrizArte;
}

char *Readline(FILE *fptr,int *fimDeArquivo){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    do{        
        caractere = fgetc(fptr);
        if(caractere == EOF){
            *fimDeArquivo = 1;
            caractere = '\n';
        }

        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != '\n' );

    linha = realloc(linha,contaCaracteres);   

    return linha;
}

void LiberaMemoria(char **matrizArte, int numLinhas){
    for(int i =0;i < numLinhas; i++){
        free(matrizArte[i]);
    }  
    free(matrizArte);
}


void enquadra_arte(
	char *nome_do_arquivo_da_arte,
	int  altura_do_quadro,
	int  largura_do_quadro
) {
	FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
	if (f_arte_ptr == NULL) {
		printf(
			"Erro na abertura do arquivo, "
			"Você esqueceu de fechar o arquivo antes? "
			"Ou deu free na string com o nome sem querer?\n"
		);

		exit(EXIT_FAILURE);
	}

	int qtd_espc_comeco;
	const char *apoio;
	if (largura_do_quadro % 2 == 0) {
		qtd_espc_comeco = largura_do_quadro / 2;
		apoio           = "/\\";
	} else {
		qtd_espc_comeco = largura_do_quadro / 2 + 1;
		apoio           = "Ʌ";
	}

	for (int i = 0; i < qtd_espc_comeco; i++) printf(" ");
	printf("%s\n", apoio);

	printf("╭");
	for (int i = 0; i < largura_do_quadro; i++) printf("—");
	printf("╮\n");

	for (int i = 0; i < altura_do_quadro; i++) {
		printf("|");
		for (int j = 0; j < largura_do_quadro; j++) {
			char pixel_atual = fgetc(f_arte_ptr);
			printf("%c", pixel_atual);
		}
		printf("|");

		char quebra = fgetc(f_arte_ptr);
		if (quebra != EOF) printf("%c", quebra);
	};
	fclose(f_arte_ptr);

	printf("\n╰");
	for (int i = 0; i < largura_do_quadro; i++) printf("—");
	printf("╯\n");
}