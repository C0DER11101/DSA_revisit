#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define FLAG 1
#include "stackexp.h"
#include "intopre.h"


int main(void)
{
	char*infix;

	infix=(char*)malloc(100*sizeof(char));

	printf("enter infix expression: ");
	scanf("%s", infix);

	char*revexp;
	int idx=-1;

	revexp=(char*)malloc(100*sizeof(char));

	for(int i=strlen(infix)-1; i>=0; i--)
	{
		if(infix[i]==')')
		{
			idx++;
			revexp[idx]='(';
		}

		else if(infix[i]=='(')
		{
			idx++;
			revexp[idx]=')';
		}

		else
		{
			idx++;
			revexp[idx]=infix[i];
		}

	}


	scanexp(revexp);

	printf("\n\nevaluating the prefix expression!!\n\n");

	evaluate();

	free(infix);
	free(revexp);
	printf("\n\n\n");

	return 0;
}
