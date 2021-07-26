//Lucas Pereira Pacheco nºusp:12543930
//Gerenciamento de estudantes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno
{
    long int nUsp;
    char *Nome;
    char *Curso;
    int idade;
} Aluno;

typedef struct jupiterWeb
{
  Aluno *listaAlunos;
  int contAlunos;  
}JupiterWeb;


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

void AlimentaBanco(JupiterWeb* bancoDeAlunos){
    Aluno *listaAlunos;
    listaAlunos = malloc(sizeof(Aluno) * 30);
    int contAlunos = 0,idade;    
    long int nUsp;        
    do{        
        scanf("%li", &nUsp);

        if(nUsp == -1){
            continue;
        }

        listaAlunos[contAlunos].nUsp  = nUsp;
        listaAlunos[contAlunos].Nome  = Readline();
        listaAlunos[contAlunos].Curso = Readline();

        scanf("%i", &idade);

        listaAlunos[contAlunos].idade = idade;
        contAlunos++;
    }while(nUsp != -1);

    listaAlunos = realloc(listaAlunos, sizeof(Aluno) * contAlunos);

    bancoDeAlunos->listaAlunos = listaAlunos;
    bancoDeAlunos->contAlunos = contAlunos;

}

void PrintaAluno(Aluno dadosAluno){
    printf("Nome: %s\n", dadosAluno.Nome);
    printf("Curso: %s\n", dadosAluno.Curso);
    printf("N USP: %li\n", dadosAluno.nUsp);
    printf("IDADE: %i\n", dadosAluno.idade);
    printf("\n");
}

void BuscaPorNusp(JupiterWeb *bancoDeAlunos){
    long int nUsp;
    scanf("%li",&nUsp);

    for(int i =0; i< bancoDeAlunos->contAlunos; i++){

        if(bancoDeAlunos->listaAlunos[i].nUsp == nUsp){
            PrintaAluno(bancoDeAlunos->listaAlunos[i]);
        }

    }

}

void BuscaPorCurso(JupiterWeb *bancoDeAlunos){
    char *curso = Readline();
    for(int i =0; i< bancoDeAlunos->contAlunos; i++){         
        
        if(!strcmp(bancoDeAlunos->listaAlunos[i].Curso,curso)){
            PrintaAluno(bancoDeAlunos->listaAlunos[i]);
        }

    }

    free(curso);

}

void ListaTodosAlunos(JupiterWeb *bancoDeAlunos){

    for(int i =0; i< bancoDeAlunos->contAlunos; i++){

        PrintaAluno(bancoDeAlunos->listaAlunos[i]);

    }
}

void LiberaMemoria(JupiterWeb *bancoDeAlunos){

    for(int i =0;i< bancoDeAlunos->contAlunos;i++){
        free(bancoDeAlunos->listaAlunos[i].Nome);
        free(bancoDeAlunos->listaAlunos[i].Curso);
    }
}

int main(){
    JupiterWeb bancoDeAlunos;
    AlimentaBanco(&bancoDeAlunos);
    int entrada;

    do{
        scanf("%i", &entrada);

        switch (entrada)
        {
        case 1:BuscaPorNusp(&bancoDeAlunos);
            break;
        case 2:BuscaPorCurso(&bancoDeAlunos);
            break;
        case 3:ListaTodosAlunos(&bancoDeAlunos);
            break;
        }

    }while(entrada != -1);
    
    LiberaMemoria(&bancoDeAlunos);

    return 0;
}
