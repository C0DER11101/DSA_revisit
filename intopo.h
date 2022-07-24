#ifndef P_H
#define P_H

#include "stackexp.h"
#include<string.h>

int precedence(char symbol)
{
	switch(symbol)
	{
		case '+': case '-':
			return 1;

		case '*': case '/':
			return 2;

		case '^':
			return 3;

		default:
			return 0;
	}

}


void scanexp(char*infix)
{
	char sym=' ';
	int preinfix; // precedence of the the operator in the infix expression
	for(int i=0; i<strlen(infix); i++)
	{
		switch(infix[i])
		{
			case '(':
				push(infix[i]); // push into stack
				break;

			case ')':
				sym=pop();
				while(sym!='(')
				{
					insert(sym);
					sym=pop();
				}


				break;

			case '-': case '+': case '*': case '/': case '^':
				preinfix=precedence(infix[i]);

				while(preinfix<=precStack())
				{
					insert(pop());
				}

				push(infix[i]);

				break;

			default:
				insert(infix[i]);
		}
	}

	while(returnTop()!=-1)
	{
		insert(pop());
	}


	display();
}
#endif
