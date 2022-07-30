#ifndef STR_H
#define STR_H
#define MAX 100

int top=-1;
char stack[MAX];

void peek()
{
	printf("\nTop = %c\n", stack[top]);
}

void push(char str)
{
	top++;
	stack[top]=str;
	printf("\nPushed %c into stack\n", stack[top]);
	peek();
}

char pop()
{
	char str=stack[top];
	top--;
	return str;
}


#endif
