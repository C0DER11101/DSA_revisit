#ifndef DIV_H
#define DIV_H

int divby9(int n, int sum)
{
	if(n==0)
	{
		if(sum%9==0)
			return 1;
		else
			return 0;
	}

	sum+=n%10;
	divby9(n/10, sum);
}


#endif
