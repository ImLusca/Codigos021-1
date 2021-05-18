#include<stdio.h>

int main(){
	
	int n, espacos;
	char e;
	
	scanf("%i %c",&n,&e);

	if(n < 1 || n > 26){
		printf("Altura invalida");
		return 0;
	}		
	espacos = (n*2)-1;
	
	for(int i =n-1; i >= 0 ; i--){
		
		for(int j=0; j < espacos; j++){
			if(j >= i && j < (espacos - i))
				printf("%c", e);
			else
				printf(" ");
		}
		printf("\n");
	}
	


	return 0;
}
