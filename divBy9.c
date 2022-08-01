#include<stdio.h>
#include "divby9.h"

int main(void)
{
	int n, result;

	printf("enter a number: ");
	scanf("%d", &n);

	result=divby9(n);

	if(result==1)
		printf("%d is divisible by 9\n\n", n);

	else
		printf("\n%d is not divisible by 9\n\n", n);

	return 0;

}
