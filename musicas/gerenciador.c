//nome:Lucas Pereira Pacheco nºusp:12543930
//Playlist sistema de gerenciamento de músicas
#include<stdio.h>
#include<stdlib.h>

typedef struct musica{
    char* nomeMusica;
    char* artista;
    int tocando;
    int duracao;
} Musica;
typedef struct playlist{
    char* nomePlaylist;
    int ContMusicas;
    Musica* listaMusicas;
} Playlist;


char* readline();
void AddMusica(Playlist* playlistAtual);
void ExibePlaylist(Playlist playlistAtual);
void ProxMusica(Playlist* playlistAtual);
void VoltaMusica(Playlist* playlistAtual);


int main(){
    Playlist PlaylistUser;
    int comando;

    PlaylistUser.nomePlaylist = readline();
    PlaylistUser.ContMusicas = 0;
    PlaylistUser.listaMusicas = malloc(sizeof(Musica)*15);
    
    do{
        scanf("%i",&comando);     
        fflush(stdin);
        switch (comando)
        {
        case 1:AddMusica(&PlaylistUser);        
            break;
        case 2: ExibePlaylist(PlaylistUser);
            break;
        case 3: ProxMusica(&PlaylistUser);
            break;
        case 4: VoltaMusica(&PlaylistUser);
            break;
        }

    } while (comando != 5);
    
    //Desalocando a memória
    free(PlaylistUser.nomePlaylist);
    for(int i=0;i< PlaylistUser.ContMusicas; i++){
        free(PlaylistUser.listaMusicas[i].artista);
        free(PlaylistUser.listaMusicas[i].nomeMusica);
    }
    free(PlaylistUser.listaMusicas);

    return 0;
}


char *readline(){    
    int bloco = 100, contBlocos=1;    
    char* linha = (char*)malloc(bloco * sizeof(char));
    char* aux = linha;
    char caractere;
    
    while((caractere = getchar()) == '\n');
    if(caractere != EOF){
        ungetc(caractere,stdin);
    }
    
    do{
        caractere = getchar();
        caractere = (caractere == '\n') ?('\0'):(caractere);
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

void AddMusica(Playlist* playlistAtual){
    
    if(playlistAtual->ContMusicas == 15){
        printf("Playlist cheia!\n");
        return;
    }


    int numMusicas = ++playlistAtual->ContMusicas;    
    struct musica novaMusica;

    //Cria uma nova instância de musica para atribuir à playlist depois
    novaMusica.nomeMusica = readline();
    novaMusica.artista = readline();
    scanf("%i", &novaMusica.duracao);
    //Se for a primeira música, marca como tocando
    novaMusica.tocando = (numMusicas == 1);

    //Passando a instância que criamos para a struct da playlist
    playlistAtual->listaMusicas[numMusicas -1] = novaMusica;

    printf("Musica %s de %s adicionada com sucesso.\n",
    novaMusica.nomeMusica,novaMusica.artista);

    return;
}

void ExibePlaylist(Playlist playlistAtual){
    printf("---- Playlist: %s ----\n",playlistAtual.nomePlaylist);
    printf("Total de musicas: %i\n\n",playlistAtual.ContMusicas);

    for(int i=0;i < playlistAtual.ContMusicas; i++){
        struct musica musicaAtual = playlistAtual.listaMusicas[i];

        if(musicaAtual.tocando == 1 ){
            printf("=== NOW PLAYING ===\n");
        }

        printf("(%i). '%s'\n",i+1,musicaAtual.nomeMusica);
        printf("Artista: %s\n",musicaAtual.artista);
        printf("Duracao: %i segundos\n",musicaAtual.duracao);
        printf("\n");

    }
    return;
}

void ProxMusica(Playlist* playlistAtual){
    for(int i =0;i < playlistAtual->ContMusicas;i++){
        if(playlistAtual->listaMusicas[i].tocando){
            playlistAtual->listaMusicas[i].tocando = 0;
            playlistAtual->listaMusicas[i+1].tocando = 1;
            break;
        }
    }
    return;
}

void VoltaMusica(Playlist* playlistAtual){
    for(int i =0;i < playlistAtual->ContMusicas;i++){
        if(playlistAtual->listaMusicas[i].tocando){
            playlistAtual->listaMusicas[i].tocando = 0;
            playlistAtual->listaMusicas[i-1].tocando = 1;
            break;
        }
    }
    return;
}
