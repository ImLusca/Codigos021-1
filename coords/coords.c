#include<stdio.h>

int main(){
	int eixoX=0, eixoY=0;
	char input;
	
	for(int i = 0; i<6; i++){
		scanf("%c", &input);
		switch(input){
			case 'W': eixoY++;
				break;
			case 'S': eixoY--;
				break;
			case 'D': eixoX++;
				break;
			case 'A': eixoX--;
		}
	}
	
	printf("%i %i\n", eixoX,eixoY);

	return 0;
}
