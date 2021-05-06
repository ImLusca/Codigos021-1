#include<stdio.h>

int main(){
	float n1,n2, res;
	
	scanf("%f %f",&n1,&n2);
	res = (n2 != 0) ? (n1) : (1);	
	for(int i = 1; i < n2 ;i++){
		res *= n1;	
	}

	printf("%.4f\n", res);

}
