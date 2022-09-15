#ifndef SLQ_H
#define SLQ_H


int f=-1, r=-1, queue[MAX];

int frt()
{
	return f;
}

void nq(int val)
{
	if(r==MAX)
	{
		cout<<"\nQueue overflow!\n\n";
		return;
	}

	if(f==-1 && r==-1)
	{
		f++, r++;
		queue[f]=val;
	}

	else
	{
		r++;
		queue[r]=val;
	}
}

int dq()
{
	if(f==-1 && r==-1)
	{
		cout<<"\nQueue underflow!!\n\n";
		return -1;
	}

	else if(f==r)
	{
		int temp=queue[f];
		f=r=-1;

		return temp;
	}

	else
	{
		int temp=queue[f];
		f++;
		return temp;
	}
}
#endif // SLQ_H
