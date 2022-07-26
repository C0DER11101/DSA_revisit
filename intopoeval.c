#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "stackexp.h"
#include "intopo.h"

// program to convert an infix expression to postfix expression!!


int main(void)
{
	char*infix;
	
	infix=(char*)malloc(100*sizeof(char));

	printf("enter an infix expression: ");
	scanf("%s", infix);


	scanexp(infix);

	printf("\n\nevaluating the expression\n\n\n");

	evaluate();

	printf("\n\n\n");

	free(infix);
	return 0;
}
