#ifndef STACK_H
#define STACK_H
#define MAX 5

int top=-1, stack[MAX];

void push(int element)
{
	top++;
	if(top==MAX)
	{
		printf("\nStack overflow!!\n\n");
		top--;
		return;
	}

	else
	{
		stack[top]=element;
	}

}

int pop()
{
	if(top==-1)
	{
		printf("\n\nStack underflow!!!\n\n");
		return -1;
	}

	else
	{
		return stack[top--];
	}
}

int peek()
{
	if(top==-1)
	{
		printf("\n\nStack is empty!!\n\n");
		return -1;
	}

	else
	{
		return stack[top];
	}

}

void show()
{
	if(top==-1)
	{
		printf("\nStack is empty!!\n\n");
		return;
	}
	printf("\n\nHere is the stack...\n\n");

	printf("\n\nTOP->");

	for(int i=top; i>=0; i--)
		printf("%d\n", stack[i]);
}

#endif
