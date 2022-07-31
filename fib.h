#ifndef FIB_H
#define FIB_H

void fibo(int first, int second, int length)
{
	if(length==0)
		return;

	if(first==0)
	{
		printf("%d %d ", first, second);
		length-=1;
	}

	else
	{
		printf("%d ", second);
	}

	fibo(second, first+second, length-1);
}

#endif
