#ifndef SUM_H
#define SUM_H

int sum(int n)
{
	if(n==0)
		return 0;

	return n+sum(n-1);
}

#endif
