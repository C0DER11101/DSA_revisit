#ifndef DIV_H
#define DIV_H

int div(int n, int count, int sumEven, int sumOdd)
{
	if(n==0)
	{
		if(sumEven>sumOdd)
		{
			if((sumEven-sumOdd)%11==0)
				return 1;
			else
				return 0;
		}

		else
		{
			if((sumOdd-sumEven)%11==0)
				return 1;
			else
				return 0;
		}
	}

	if(count%2==0)
		sumEven+=n%10;
	else
		sumOdd+=n%10;

	div(n/10, count-1, sumEven, sumOdd);
}

#endif
