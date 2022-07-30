#include<stdio.h>
#include "primefac.h"

int main(void)
{
	int num;

	printf("enter a number: ");
	scanf("%d", &num);

	printf("\n\nprime factors of %d are:\n", num);

	factorize(num);

	printf("\n\n");

	return 0;
}
