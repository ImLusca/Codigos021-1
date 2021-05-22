#include<stdio.h>
int mensagem[1000];

int main(){
	char teclado[50];
	int msg_size;	
	
	for(int i=0; i<49; i++){
		
		scanf("%c",&teclado[i]);	
	}
	printf("Tamanho");
	scanf("%i",&msg_size);
	
	for(int i=0;i<msg_size;i++){
		scanf("%i", &mensagem[i]);
	}	
	
	for(int i=0;i<msg_size;i++){
		if(teclado[mensagem[i+1]] == '_'){
			printf(" ");
			continue;
		}else if(teclado[mensagem[i+1]] == 'E'){
			printf("\n");
			continue;
		}else{
			printf("%c",teclado[mensagem[i+1]]);	
		}			
	}
	

	
	return 0;
}
