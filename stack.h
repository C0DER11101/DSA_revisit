#ifndef STACK_H
#define STACK_H

int top=-1;

int Top() // shows the value of top
{
	return top;
}

#if elType==0

int stack[MAX];

void push(int val)
{
	top++;
	stack[top]=val;
}

int pop()
{
	int el=stack[top];
	stack[top]=0;
	top--;

	return el;
}

int peek()
{
	return stack[top];
}

#elif elType==1 // for element type char

char stack[MAX];

void push(char val)
{
	top++;
	stack[top]=val;
}

char pop()
{
	char el=stack[top];
	stack[top]='\0';

	top--;

	return el;
}

char peek()
{
	return stack[top];
}

#elif elType==2

float stack[MAX];

void push(float val)
{
	top++;
	stack[top]=val;
}

float pop()
{
	float el=stack[top];
	stack[top]=0.0;

	top--;

	return el;
}

float peek()
{
	return stack[top];
}

#elif elType==3

double stack[MAX];

void push(double val)
{
	top++;
	stack[top]=val;
}

double pop()
{
	double el=stack[top];
	stack[top]=0.0;

	top--;

	return el;
}

double peek()
{
	return stack[top];
}
#endif


#endif
