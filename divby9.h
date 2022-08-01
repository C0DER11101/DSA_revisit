#ifndef DIV_H
#define DIV_H

int divby9(int n)
{
	if(n<10 && n%9==0)
		return 1;
	else if(n<10 && n%9!=0)
		return 0;

	int sum=0;

	while(n!=0)
	{
		sum+=n%10; // taking the last digit
		n/=10;
	}

	divby9(sum);
}

#endif
