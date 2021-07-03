//nome:Lucas Pereira Pacheco nºusp:12543930
//Playlist sistema de gerenciamento de músicas
#include<stdio.h>
#include<stdlib.h>

typedef struct musica{
    char* nomeMusica;
    char* artista;
    int tocando;
    unsigned short duracao;
} Musica;
typedef struct playlist{
    char* nomePlaylist;
    short ContMusicas;
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
    int numMusicas = playlistAtual->ContMusicas++;
    struct musica novaMusica;

    //Cria uma nova instância de musica para atribuir à playlist depois
    novaMusica.nomeMusica = readline();
    novaMusica.artista = readline();
    scanf("%hn", &novaMusica.duracao);
    //Se for a primeira música, marca como tocando
    novaMusica.tocando = (numMusicas == 1);

    //Passando a instância que criamos para a struct da playlist
    playlistAtual->listaMusicas = realloc(playlistAtual->listaMusicas,
    sizeof(Musica) * numMusicas);

    playlistAtual->listaMusicas[numMusicas -1] = novaMusica;

    printf("Musica %s de %s adicionada com sucesso.",
    novaMusica.nomeMusica,novaMusica.artista);

    return;
}

void ExibePlaylist(Playlist playlistAtual){
    printf("---- Playlist: %s ----\n",playlistAtual.nomePlaylist);
    printf("Total de musicas: %hn\n",&playlistAtual.ContMusicas);

    for(int i=0;i < playlistAtual.ContMusicas; i++){
        printf("\n");
        struct musica musicaAtual = playlistAtual.listaMusicas[i];

        if(musicaAtual.tocando == 1 ){
            printf("=== NOW PLAYING ===");
        }

        printf("(%i). '%s'\n",i,musicaAtual.nomeMusica);
        printf("Artista: %s\n",musicaAtual.artista);
        printf("Dureacao: %hn segundos\n",&musicaAtual.duracao);
    }
    return;
}

void ProxMusica(Playlist* playlistAtual){
    for(int i =0;i < playlistAtual->ContMusicas;i++){
        if(playlistAtual->listaMusicas[i].tocando){
            playlistAtual->listaMusicas[i+1].tocando = 1;
            break;
        }
    }
    return;
}

void VoltaMusica(Playlist* playlistAtual){
    for(int i =0;i < playlistAtual->ContMusicas;i++){
        if(playlistAtual->listaMusicas[i].tocando){
            playlistAtual->listaMusicas[i-1].tocando = 1;
            break;
        }
    }
    return;
}