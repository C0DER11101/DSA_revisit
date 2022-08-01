#include<stdio.h>
#include "div11.h"

int main(void)
{
	int num, count=0, result;

	printf("enter a number: ");
	scanf("%d", &num);

	{
		int copy=num;
		while(copy!=0)
		{
			count++;
			copy/=10;
		}

		printf("\n\n%d has %d digits\n\n", num, count);
	}

	result=div(num, count, 0, 0);

	if(result==1)
		printf("%d is divisible by 11\n\n", num);

	else
		printf("%d is not divisible by 11\n\n", num);

	return 0;
}
