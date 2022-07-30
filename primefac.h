#ifndef PRIMEFAC_H
#define PRIMEFAC_H

void factorize(int n)
{
	if(n==1)
		return;

	for(int i=2; i<=n; i++)
	{
		if(n%i==0)
		{
			printf("%d, ", i);
			factorize(n/i);
			return;
		}
	}

}
#endif
