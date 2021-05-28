#include<stdio.h>
int mensagem[10000];

int main(){
	char teclado[49];
	int msg_size, counter = 0;	
	
	while(counter < 49){
		char temp;
		scanf("%c",&temp);
		if(temp != ' '){
			teclado[counter] = temp;
			counter++;
		}
	}

	scanf("%i",&msg_size);	

	for(int i = 0; i < msg_size; i++){
		int temp;		
		if(scanf("%i",&temp)){
			mensagem[i] = temp;
		}
	}

	for(int i=0;i<msg_size;i++){	

		if(teclado[mensagem[i]] == '_'){
			printf(" ");
		}else if(teclado[mensagem[i]] == 'E'){
			printf("\n");
		}else{
			printf("%c",teclado[mensagem[i]]);	
		}
	}
	
	return 0;
}
