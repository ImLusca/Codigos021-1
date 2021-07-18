//nome:Lucas Pereira Pacheco nºusp:12543930
//Sistema de Gerenciamento de Playlists
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void DesalocaPlaylist(Playlist *PlaylistUser);
void SalvaPlaylist(Playlist playlistAtual);
void binaryToNum(char *binFilename);
void CarregaPlaylist(Playlist *playlistAtual);

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
        case 5: SalvaPlaylist(PlaylistUser);
            break;
        case 6: CarregaPlaylist(&PlaylistUser);
            break;
        }

    } while (comando != 7);

    DesalocaPlaylist(&PlaylistUser);

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

void DesalocaPlaylist(Playlist *PlaylistUser){
    free(PlaylistUser->nomePlaylist);
    for(int i=0;i< PlaylistUser->ContMusicas; i++){
        free(PlaylistUser->listaMusicas[i].artista);
        free(PlaylistUser->listaMusicas[i].nomeMusica);
    }
    free(PlaylistUser->listaMusicas);
}

void SalvaPlaylist(Playlist playlistAtual){
    FILE *arquivo;
    char *nomeArquivo = readline();

    arquivo = fopen(nomeArquivo,"wb");

    //Cabecalho
    int tamanhoStr = strlen(playlistAtual.nomePlaylist);
    
    fwrite(&tamanhoStr,sizeof(int),1, arquivo);
    fwrite(playlistAtual.nomePlaylist,tamanhoStr,1, arquivo);
    fwrite(&playlistAtual.ContMusicas,sizeof(int),1, arquivo);

    //Musicas
    for(int i=0; i < playlistAtual.ContMusicas; i++){        
        Musica tempMusica = playlistAtual.listaMusicas[i];  
              
        int tamanhoStr = strlen(tempMusica.nomeMusica);

        fwrite(&tamanhoStr,sizeof(int),1,arquivo);
        fwrite(tempMusica.nomeMusica,tamanhoStr,1,arquivo);

        tamanhoStr = strlen(tempMusica.artista);

        fwrite(&tamanhoStr,sizeof(int),1,arquivo);
        fwrite(tempMusica.artista,tamanhoStr,1,arquivo);

        fwrite(&tempMusica.duracao,sizeof(int),1,arquivo);
    }

    fclose(arquivo);    
    printf("Playlist %s salva com sucesso.\n",nomeArquivo);
    binaryToNum(nomeArquivo);
}

void CarregaPlaylist(Playlist *playlistAtual){
    FILE *arquivo;
    char *nomeArquivo = readline();

    //lê Cabecalho    
    arquivo = fopen(nomeArquivo,"rb");

    if(arquivo == NULL){
        printf("Arquivo %s nao existe.\n",nomeArquivo);
        free(nomeArquivo);
        DesalocaPlaylist(playlistAtual);
        exit(1);
    }

    //Desaloca playlist atual da Ram
    DesalocaPlaylist(playlistAtual);


    int tamanhoStr;
    fread(&tamanhoStr,sizeof(int),1,arquivo);    
    playlistAtual->nomePlaylist = malloc(++tamanhoStr);
    fread(playlistAtual->nomePlaylist,tamanhoStr,1, arquivo);
    playlistAtual->nomePlaylist[tamanhoStr -1] = '\0';

    fread(&playlistAtual->ContMusicas,sizeof(int),1, arquivo);

    //Musicas
    playlistAtual->listaMusicas = malloc(sizeof(Musica)*15);

    for(int i=0; i < playlistAtual->ContMusicas; i++){        
        Musica tempMusica;  

        fread(&tamanhoStr,sizeof(int),1,arquivo);
        tempMusica.nomeMusica = malloc(++tamanhoStr);
        fread(tempMusica.nomeMusica,tamanhoStr,1,arquivo);
        tempMusica.nomeMusica[tamanhoStr-1] = '\0';

        fread(&tamanhoStr,sizeof(int),1,arquivo);
        tempMusica.artista = malloc(++tamanhoStr);
        fread(tempMusica.artista,tamanhoStr,1,arquivo);
        tempMusica.nomeMusica[tamanhoStr-1] = '\0';

        fread(&tempMusica.duracao,sizeof(int),1,arquivo);

        playlistAtual->listaMusicas[i] = tempMusica;
    }

    fclose(arquivo);    
    free(nomeArquivo);
    printf("Playlist %s carregada com sucesso\n",nomeArquivo);
    binaryToNum(nomeArquivo);    
}


void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)){
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}
