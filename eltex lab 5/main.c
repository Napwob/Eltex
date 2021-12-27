#include "calc.h"
#include <stdio.h>

int main()
{
	printf("Supported operations:\n");
	printf("1 - for plus\n");
	printf("2 - for minus\n");
	printf("3 - for multiplication\n");
	printf("4 - for devide\n");
	int a,b,c;
	printf("Please, enter type of operation: ");
	scanf("%d",&c);
	printf("Please, first variable: ");
	scanf("%d",&a);
	printf("Please, second variable: ");
	scanf("%d",&b);
	printf("Result of calculation:\n");
	if(c == 1)
		printf("%d+%d=%d",a,b,plus(a,b));
	if(c == 2)
		printf("%d-%d=%d",a,b,minus(a,b));
	if(c == 3)
		printf("%d*%d=%d",a,b,multiplication(a,b));
	if(c == 4)
		printf("%d/%d=%d",a,b,devide(a,b));
	printf("\n");
	return 0;
	
	
}
