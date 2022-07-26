#ifndef C_H
#define C_H

/*
   ASCII VALUES OF THE BRACKETS:

   { -> 123

   } -> 125

   ( -> 40

   ) -> 41

   [ -> 91

   ] -> 93

*/

bool testexp(char*exprs)
{
	char bracket;
	for(int i=0; i<strlen(exprs); i++)
	{
		switch(exprs[i])
		{
			case '(': case '{': case '[':
				push(exprs[i]);

				break;

			case ')': case '}': case ']':
				bracket=peek();

				if((int)bracket==(int)exprs[i]-1)
					pop();

				else if((int)bracket==(int)exprs[i]-2)
					pop();

				else
					return false;

				break;
		}

	}

	if(Top()!=-1)
	{
		return false;
	}

	else
	{
		return true;
	}
}

#endif
