#include<stdio.h>
#include "fibo.h"

int main(void)
{
	int n;
	printf("\n\nhow many elements do you want to print in fibonacci series? ");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		printf("%d ", fib(i));

	printf("\n");
	return 0;
}
