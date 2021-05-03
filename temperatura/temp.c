#include <stdio.h>

int main(){
	float celsius, fahrenheit;
	scanf("%f",&fahrenheit);
	
	// C/5 = (F-32)/9
	// C = ((F-32)*5)/9
	celsius = ((fahrenheit - 32) * 5) / 9;
	printf("%.2f\n", celsius);
}
