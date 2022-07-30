#include<stdio.h>
#include "baseconvert.h"


int main(void)
{
	int n;

	printf("enter a number: ");
	scanf("%d", &n);


	printf("\nbinary equivalent of %d is\n", n);
	baseConvert(n);

	printf("\n");

	return 0;
}
