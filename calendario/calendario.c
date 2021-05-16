#include<stdio.h>

int main(){
	
	int dia;
	
	scanf("%i", &dia);
	
	//cabeçalho + primeira semana
	printf("         Abril 2021         \n");
	printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
	printf("                ");
	
	//alimenta calendario
	int ultimoDia =0;
	for(int i = 0; i<5 ; i++){	
		for(int j = 0; j < 7 ; j ++){
			ultimoDia++;
			if(ultimoDia != 31)	{
				if(ultimoDia == dia)
					printf("(%2d)",ultimoDia);
				else
					printf(" %2d ",ultimoDia);
				
				if(ultimoDia == 3)
					break;
			}else
				printf("    ");
		}
		printf("\n");
	}

	return 0;
}
