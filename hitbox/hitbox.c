#include<stdio.h>
#include<stdlib.h>
int main(){

	int x[2],y[2],xLarg[2],yAlt[2],temp;

	scanf("%i %i %i %i",&x[0],&y[0],&xLarg[0],&yAlt[0]);
	scanf("%i %i %i %i",&x[1],&y[1],&xLarg[1],&yAlt[1]);	

	//garantindo que o x1 seja o mais à esquerda
	if(x[1] < x[0]){
		//trocando as coords de posição
		temp = x[0];x[0] = x[1];x[1] = temp;
		temp = xLarg[0];xLarg[0] = xLarg[1];xLarg[1]=temp;
	}
	//idem y
	if(y[1] < y[0]){
		temp = y[0];y[0] = y[1];y[0] = temp;
        temp = yAlt[0];yAlt[0] = yAlt[1];yAlt[1]=temp;
	}

	printf("obj: %i %i\n",x[0],y[0]);
	printf("obj: %i %i\n",x[1],y[1]);

		
	if(abs(x[0] - x[1]) <= xLarg[0] && abs(y[0] - y[1]) >= yAlt[1] ){
		printf("HIT: ");
		printf("%i ",x[1]);
		printf("%i ",y[1]);
		printf("%i ",(x[0]+xLarg[0])-x[1]);
		printf("%i",(y[0]+yAlt[0])-y[1]);
	}else
		printf("MISS");
	printf("\n");
	//https://i.redd.it/yr52gvdx3qo21.jpg
	return 0;
}




