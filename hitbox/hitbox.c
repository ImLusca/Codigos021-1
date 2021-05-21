#include<stdio.h>
#include<stdlib.h>
int main(){

	long long int x[2],y[2],xLarg[2],yAlt[2],temp;
	long long int xdir,ydir;
	scanf("%Li %Li %Li %Li",&x[0],&y[0],&xLarg[0],&yAlt[0]);
	scanf("%Li %Li %Li %Li",&x[1],&y[1],&xLarg[1],&yAlt[1]);	

	//garantindo que o x0 seja o mais à esquerda
	if(x[1] < x[0]){
		//trocando as coords de posição
		temp = x[0];x[0] = x[1];x[1] = temp;
		temp = xLarg[0];xLarg[0] = xLarg[1];xLarg[1]=temp;
	}
	//idem y
	if(y[1] < y[0]){	
		temp = y[0];y[0] = y[1];y[1] = temp;
        temp = yAlt[0];yAlt[0] = yAlt[1];yAlt[1]=temp;
	}
	//Ao realizarmos a seguinte operação, encontramos o par ordenado
	//do canto inferior direito da área de intersecção
	xdir = (x[0] + xLarg[0] < x[1] + xLarg[1])?(x[0]+xLarg[0]):(x[1] +xLarg[1]);
	ydir = (y[0] + yAlt[0] < y[1] + yAlt[1]) ?(y[0] + yAlt[0]):(y[1] + yAlt[1]);



	if(abs(x[0] - x[1]) <= xLarg[0] && abs(y[0] - y[1]) <= yAlt[0] ){
		printf("HIT: %Li %Li ",x[1],y[1]);		
		printf("%Li ", xdir-x[1]);
		printf("%Li", ydir-y[1]);

	}else
		printf("MISS");
	printf("\n");
	// sobre a qualidade desse código:
	//https://i.redd.it/yr52gvdx3qo21.jpg
	return 0;
}




