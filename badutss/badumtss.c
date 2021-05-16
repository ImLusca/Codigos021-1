#include<stdio.h>

int main(){
	int num, cont=0,vet[3];
	scanf("%i", &num);

	vet[0] = (num % 11 == 0);
	vet[1] = (num % 13 == 0);
	vet[2] = (num % 19 == 0);

	for(int i=0;i < 3;i++){
		cont += (vet[i] == 1);
	}
	//casos fixos
	if(cont == 0){
		printf("%i\n", num);
		return 0;
	}else if(cont == 3){
		printf("BaDumTssTss\n");
		return	0;
	}	
	if(cont == 1)
		printf("Ba");			
	
	if(vet[0] == 1)
		printf("Ba");
	else if(vet[1] == 1)
		printf("Dum");
	else
		printf("Tss");
	
	if(cont == 2){
		printf("Dum");
		 if(vet[1] == 1 && vet[0] == 1)
			  printf("Dum");
	     else
		     printf("Tss");	
	}
	printf("\n");
	return 0;
}
