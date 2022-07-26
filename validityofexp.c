#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "stackop.h"
#include "checkvalid.h"

int main(void)
{
	char*exp;

	bool isValid;
	exp=(char*)malloc(100*sizeof(char));

	printf("enter an expression: ");
	scanf("%s", exp);

	isValid=testexp(exp);

	if(isValid==true)
		printf("\n\nExpression is valid!!\n\n");

	else
		printf("\n\nExpression is invalid!!!\n\n");


	free(exp);

	return 0;
}
