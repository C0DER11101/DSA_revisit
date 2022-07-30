#include<stdio.h>
#include "gcd.h"

int main(void)
{
	int a, b;

	printf("enter two numbers: ");
	scanf("%d-%d", &a, &b);

	printf("GCD(%d, %d)= %d\n", a, b, gcd(a, b));

	return 0;
}
