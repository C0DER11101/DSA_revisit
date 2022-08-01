#include<stdio.h>
#include "dvby9.h"


int main(void)
{
	int n;

	printf("enter a number: ");
	scanf("%d", &n);

	if(divby9(n, 0)==1)
		printf("%d is divisible by 9!!\n\n", n);
	else
		printf("%d is not divisible by 9!!\n\n", n);

	return 0;
}
