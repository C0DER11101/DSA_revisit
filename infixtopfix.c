#include<stdio.h>
#include<stdlib.h>
#include "intopo.h"

// program to convert an infix expression to postfix expression!!


int main(void)
{
	char*infix;
	
	infix=(char*)malloc(100*sizeof(char));

	printf("enter an infix expression: ");
	scanf("%s", infix);


	scanexp(infix);

	printf("\n\n\n");

	free(infix);
	return 0;
}
