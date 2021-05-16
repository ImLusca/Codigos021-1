#include<stdio.h>

int main(){
	int estacao;

	scanf("%i", &estacao);
	
	if(estacao <= 5){
		do{	
			printf("* ");
			switch(estacao){
				case 0: printf("Morumbi");
						break;
				case 1: printf("Butanta");
						break;
				case 2: printf("Pinheiros");
						break;
				case 3: printf("Faria Lima");
						break;
				case 4: printf("Fradique Coutinho");
						break;
				case 5: printf("Oscar Freire");
						break;
			}
			if(estacao != 5 ){
				printf("\n|");
			}
			printf("\n");
			estacao ++;
		}while(estacao <= 5);
	}else{
		do{	
			printf("* ");
			switch(estacao){
				case 6: printf("Paulista");
						break;
				case 7: printf("Higienopolis-Mackenzie");
						break;
				case 8: printf("Republica");
						break;
				case 9: printf("Luz");
						break;	
			}
			if(estacao != 9){
				printf("\n|");		
			}
			printf("\n");
			estacao++;		
		} while(estacao <= 9);
	}



	return 0;
}
