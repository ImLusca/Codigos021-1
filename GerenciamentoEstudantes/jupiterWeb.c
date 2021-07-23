//Lucas Pereira Pacheco nºusp:12543930
//Gerenciamento de estudantes
#include<stdio.h>
#include<stdlib.h>

typedef struct aluno
{
    int nUsp;
    char *Nome;
    char *Curso;
    int idade;

} Aluno;

char *Readline(){
    int tamanhoString=20, contaCaracteres=0;
    char *linha, caractere;
    linha = malloc(tamanhoString);

    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }

    do{
        caractere = getchar();

        if(caractere == '\n'){
            caractere = '\0';
        }


        if(contaCaracteres == tamanhoString){
            tamanhoString += 20;
            linha = realloc(linha, tamanhoString);
        }

        linha[contaCaracteres] = caractere;
        contaCaracteres++;
    }while(caractere != '\0');

    linha = realloc(linha,contaCaracteres);

    return linha;
}

Aluno *ListaAlunos(){
    Aluno *listaAlunos;
    listaAlunos = malloc(sizeof(Aluno) * 30);
    int contAlunos = 0,idade;    
    long int nUsp;        
    do{        
        scanf("%li", &nUsp);

        if(nUsp == -1){
            break;
        }

        listaAlunos[contAlunos].nUsp  = nUsp;
        listaAlunos[contAlunos].Nome  = Readline();
        listaAlunos[contAlunos].Curso = Readline();

        scanf("%i", &idade);

        listaAlunos[contAlunos].idade = idade;
        contAlunos++;
    }while(nUsp != -1);

    listaAlunos = realloc(listaAlunos, sizeof(Aluno) * contAlunos);

    return listaAlunos;
}

int main(){
    Aluno *listaDeAlunos;
    listaDeAlunos = ListaAlunos();


    return 0;
}
