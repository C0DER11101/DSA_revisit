#ifndef S_H
#define S_H
#define MAX 200

int top=-1;
char stack[MAX];

void push(char symbol)
{
	++top;
	stack[top]=symbol;
}


char pop()
{
	if(top==-1)
	{
		return '\0';
	}

	char symbol=stack[top];
	top--;
	return symbol;
}

char peek()
{
	return stack[top];
}

int Top()
{
	return top;
}

#endif
