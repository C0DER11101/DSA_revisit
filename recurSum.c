#include<stdio.h>
#include "dosum.h"

int main(void)
{
	int n;

	printf("enter n: ");
	scanf("%d", &n);

	/* -- finding summation of 1 to n -- */

	printf("\n\nSummation of 1 to %d is = %d\n\n", n, sum(n));
	return 0;
}
