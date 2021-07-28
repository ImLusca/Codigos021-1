//Lucas Pereira Pacheco. nºUsp:12543930
//Pokedex
#include<stdio.h>
#include<stdlib.h>


typedef struct ataque{
    char nome[21];
    int  poderBase;
    float acuracia;
    char classe;
}Ataque;

typedef struct atributos{
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
}Atributos;

typedef struct pokemon{
    char nome[51];
    char tipoPrimario[21];
    char tipoSecundario[21];
    Atributos atributosPokemon;
    Ataque ataques[4];
    
}Pokemon;

typedef struct pokedex{
    Pokemon *listaPokemons;
    int countPokemons;
}Pokedex;


void AddPokemon(Pokedex *pokedex);

void AddAtaque(Pokedex *pokedex);

void ExibePokemon(Pokedex pokedex);

void ExibeAtaques(Pokedex pokedex);


int main(){
    Pokedex pokedex;
    int comando;

    pokedex.countPokemons = 1;

    do{
        scanf("%i", &comando);

        switch(comando)
        {
            case 1: AddPokemon(&pokedex);
            break;
            case 2: AddAtaque(&pokedex);
            break;
            case 3: ExibePokemon(pokedex);
            break;
            case 4: ExibeAtaques(pokedex);
            break;
        }       

    }while(comando != 0);

    free(pokedex.listaPokemons);

    return 0;
}

void AddPokemon(Pokedex *pokedex){
    int tamanhoLista = pokedex->countPokemons;
    
    pokedex->listaPokemons = realloc(pokedex->listaPokemons, sizeof(Pokemon) * tamanhoLista);
    Pokemon dadosPokemon;

    //Dados do pokemon
    scanf("%s %s %s",dadosPokemon.nome,dadosPokemon.tipoPrimario,dadosPokemon.tipoSecundario);

    //Atributos do pokemon
    scanf("%i %i",&dadosPokemon.atributosPokemon.hp,&dadosPokemon.atributosPokemon.ataque);
    scanf("%i %i",&dadosPokemon.atributosPokemon.defesa,&dadosPokemon.atributosPokemon.ataqueEspecial);
    scanf("%i %i",&dadosPokemon.atributosPokemon.defesaEspecial,&dadosPokemon.atributosPokemon.velocidade);

    pokedex->listaPokemons[tamanhoLista - 1] = dadosPokemon;
    pokedex->countPokemons = tamanhoLista + 1;
}

void AddAtaque(Pokedex *pokedex){

    int indicepokemon, indiceAtaque;
    Ataque dadosAtaque;

    //Indices
    scanf("%i %i", &indicepokemon,&indiceAtaque);

    //Dados do ataque
    scanf("%s %i",dadosAtaque.nome,&dadosAtaque.poderBase);
    scanf("%f %c",&dadosAtaque.acuracia,&dadosAtaque.classe);

    pokedex->listaPokemons[indicepokemon].ataques[indiceAtaque] = dadosAtaque;
}

void ExibePokemon(Pokedex pokedex){
    int indicePokemon;
    Pokemon dadosPokemon;

    scanf("%i", &indicePokemon);

    dadosPokemon = pokedex.listaPokemons[indicePokemon];

    //Dados Pokemon
    printf("Nome do Pokemon: %s\n",dadosPokemon.nome);
    printf("Tipo primario: %s\n",dadosPokemon.tipoPrimario);
    printf("Tipo secundario: %s\n",dadosPokemon.tipoSecundario);

    //Atributos Pokemon
    printf("Status:\n");
    printf("\tHP: %i\n",dadosPokemon.atributosPokemon.hp);
    printf("\tAtaque: %i\n",dadosPokemon.atributosPokemon.ataque);
    printf("\tDefesa: %i\n",dadosPokemon.atributosPokemon.defesa);
    printf("\tAtaque Especial: %i\n",dadosPokemon.atributosPokemon.ataqueEspecial);
    printf("\tDefesa Especial: %i\n",dadosPokemon.atributosPokemon.defesaEspecial);
    printf("\tVelocidade: %i\n\n",dadosPokemon.atributosPokemon.velocidade);
}

void ExibeAtaques(Pokedex pokedex){

    int indicePokemon, indiceAtaque;
    Ataque dadosAtaque;

    //Indices
    scanf("%i %i", &indicePokemon, &indiceAtaque);

    //Dados do ataque
    dadosAtaque = pokedex.listaPokemons[indicePokemon].ataques[indiceAtaque];

    printf("Nome do Ataque: %s\n", dadosAtaque.nome);
    printf("Poder base: %i\n", dadosAtaque.poderBase);
    printf("Acuracia: %f\n", dadosAtaque.acuracia);
    printf("Classe: %c\n\n", dadosAtaque.classe);
}



