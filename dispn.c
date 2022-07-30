#include<stdio.h>
#include "dispn.h"


int main(void)
{
	int n;

	printf("enter n: ");
	scanf("%d", &n);

	/* -- displaying numbers from 1 to n -- */
	printf("displaying numbers from 1 to %d\n\n", n);

	display(n);

	printf("\n\n");

	return 0;
}
