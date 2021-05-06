#include<stdio.h>

int main(){
	float velocidade, multa;
	scanf("%f",&velocidade);
	
	if(velocidade > 80){
		multa = 2 * (velocidade - 80);
		printf("Limite de velocidade excedido! Multado no valor de R$%.2f!\n",multa);
	}else{
		printf("Velocidade dentro do limite permitido.\n");
	}
	return 0;

}
