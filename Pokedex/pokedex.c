//Lucas Pereira Pacheco. nºUsp:12543930
//Pokedex

typedef struct pokedex{
    Pokemon *listaPokemons;
    int countPokemons;
}Pokedex;

typedef struct pokemon{
    char nome[51];
    char tipoPrimario[21];
    char tipoSecundario[21];
    Atributos atributosPokemon;
    Ataque ataques[4];
    
}Pokemon;

typedef struct atributos{
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
}Atributos;

typedef struct ataque{
    char nome[21];
    int  poderBase;
    float acuracia;
    char classe;
}Ataque;




int main(){
    Pokedex pokedex;
    int comando;

    do{
        switch(comando)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:            
            break;
            case 4:
            break;
        }       

    }while(comando != 0);

    //Liberar Memória

    return 0;
}





