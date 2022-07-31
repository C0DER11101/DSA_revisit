#include<stdio.h>
#include "fib.h"

int main(void)
{
	int n;

	printf("enter length of the fibonacci series: ");
	scanf("%d", &n);

	fibo(0, 1, n);

	printf("\n");

	return 0;
}
