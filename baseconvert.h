#ifndef BASE_H
#define BASE_H

void baseConvert(int n)
{
	if(n==0)
	{
		printf("%d", n);
		return;
	}

	baseConvert(n/2);
	printf("%d", n%2);
}

#endif
