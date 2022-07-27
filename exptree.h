#ifndef P_H
#define P_H
#define MAX 200


int idx2=-1;
char postfix[MAX];

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

void insert(char symbol)
{
	idx2++;
	postfix[idx2]=symbol;
}

void display()
{
	printf("\n\nThe postfix expression is:\n%s\n", postfix);
}

void scanexp(char*infix)
{
	char sym;
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

				while(precedence(infix[i])<=precStack())
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

void createTree() // scan the postfix expression from left to right!!
{
	for(int i=0; i<strlen(postfix); i++)
	{
		Push(postfix[i]);
	}
}



#endif
