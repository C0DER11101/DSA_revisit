#ifndef EXP_H
#define EXP_H
#define MAX 200

int top=-1;
char stack[MAX];

int precStack()
{
	switch(stack[top])
	{
		case '-': case '+':
			return 1;

		case '*': case '/':
			return 2;

		case '^':
			return 3;

		default:
			return 0;
	}
}

int returnTop()
{
	return top;
}

void push(char symbol)
{
	top++;
	stack[top]=symbol;
}


char pop()
{
	char symbol=stack[top];
	top--;
	return symbol;
}

char peek()
{
	return stack[top];
}

#endif
