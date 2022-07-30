#include<stdio.h>
#include "sumDigits.h"

int main(void)
{
	int num;

	printf("enter a number: ");
	scanf("%d", &num);

	printf("\n\nSum of the digits of %d is\n\n", num);

	printf("%d\n", sum(num));


	return 0;
}
