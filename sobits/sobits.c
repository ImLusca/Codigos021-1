#include<stdio.h>

int main(){
	unsigned int input;
	char a,b,c,d;
	
	scanf("%i", &input);
	
	d = (input & 255);
	c = (input & (255 << 8)) >> 8;
	b = (input & (255 << 16)) >> 16;
	a = (input & (255 << 24)) >> 24;
		
	printf("%c%c%c%c\n",a,b,c,d);
	return 0;	

}
