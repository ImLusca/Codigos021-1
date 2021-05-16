#include<stdio.h>
#include<math.h>

int main(){	
	float a1,q,n,an,sum;
	scanf("%f %f %f", &a1, &q, &n);

	an = a1 * pow(q,(n-1));

	sum = a1*(1-pow(q,n));
	sum /= 1-q;


	printf("%.2f\n%.2f\n",an, sum);
	
	return 0;

}
