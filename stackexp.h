#ifndef S_H
#define S_H
#define MAX 200


int top=-1, stack[MAX];

int indx=-1;
char postfix[MAX];

/* --- STACK FUNCTIONS --- */

int returnTop()
{
	return top;
}

void push(char symbol)
{
	top++;
	stack[top]=symbol;
}

void Push(int value)
{
	top++;
	stack[top]=value;

}

int Pop()
{
	int value=stack[top];
	top--;
	return value;
}

char pop()
{
	char symbol;

	symbol=stack[top];
	top--;

	return symbol;
}

int showTop()
{
	return stack[top];
}

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

/* ---<END>--- */



/* --- POSTFIX FUNCTIONS --- */
#ifndef FLAG
void insert(char symbol)
{
	++indx;
	postfix[indx]=symbol;
}

void evaluate()
{
	int a, b;

	for(int i=0; i<strlen(postfix); i++)
	{
		switch(postfix[i])
		{
			case '+':
				a=Pop();
				b=Pop();
				
				Push(b+a);
				break;

			case '-':
				a=Pop();
				b=Pop();

				Push(b-a);
				break;

			case '/':
				a=Pop();
				b=Pop();

				Push(b/a);
				break;

			case '*':
				a=Pop();
				b=Pop();

				Push(b*a);
				break;
				
			case '^':
				a=Pop();
				b=Pop();

				Push(pow(b, a));
				break;

			default:
				Push(postfix[i]-'0');
		}
	}


	printf("\n\nthe value of the postfix expression is: %d\n\n", showTop());
}

void display()
{
	printf("\n\nPostfix expression is:\n\n");
	printf("%s", postfix);
}

#endif
/* ---<END>--- */

/* --- PREFIX FUNCTIONS --- */
#if FLAG==1
int idx2=-1;
char prefix[MAX];

void insertpre(char symbol)
{
	++idx2;
	prefix[idx2]=symbol;
}

void show()
{
	printf("\n\nPrefix expression is:\n\n");
	for(int i=idx2; i>=0; i--)
		printf("%c", prefix[i]);
}

#endif
/* ---<END>--- */

#endif
