#ifndef P_H
#define P_H

int precedence(char symbol)
{
	switch(symbol)
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


void scanexp(char*infx)
{
	char sym;

	for(int i=0; i<strlen(infx); i++)
	{
		switch(infx[i])
		{
			case '(':
				
				push(infx[i]);

				break;

			case ')':
				sym=pop();
				while(sym!='(')
				{
					insertpre(sym);
					sym=pop();
				}

				break;

			case '-': case '+': case '*': case '/': case'^':
				if(returnTop()==-1)
				{
					push(infx[i]);

				}

				else if(precedence(infx[i])==precStack() && infx[i]=='^')
				{
					while(precedence(infx[i])==precStack() && returnTop()!=-1)
					{
						insertpre(pop());
					}

					push(infx[i]);
				}

				else if(precedence(infx[i])>=precStack())
				{
					push(infx[i]);
				}

				else if(precedence(infx[i])<precStack())
				{
					while(precedence(infx[i])<precStack() && returnTop()!=-1)
					{
						insertpre(pop());
					}

					push(infx[i]);
				}

				break;

			default:
				insertpre(infx[i]);
		}
	}

	while(returnTop()!=-1)
	{
		insertpre(pop());
	}

	show();
}

void evaluate()
{
	int a, b;

	for(int i=0; i<=idx2; i++)
	{
		switch(prefix[i])
		{
			case '+':
				a=Pop();
				b=Pop();
				Push(a+b);
				break;

			case '-':
				a=Pop();
				b=Pop();
				Push(a-b);
				break;

			case '*':
				a=Pop();
				b=Pop();
				Push(a*b);
				break;

			case '/':
				a=Pop();
				b=Pop();
				Push(a/b);
				break;

			case '^':
				a=Pop();
				b=Pop();
				Push(pow(a, b));
				break;

			default:
				Push(prefix[i]-'0');
		}
	}

	printf("\n\nvalue of the prefix expression is: %d\n\n", showTop());
}


#endif
