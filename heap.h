#ifndef HEAP_H
#define HEAP_H

int heap[MAX];
static int hsize;

void insert(int val, int size)
{

	hsize++;

	if(hsize>size)
	{
		printf("\n\ncannot insert any more elements!!\n\n");
		return;
	}

	heap[hsize]=val;

	int cnt=hsize;

	if(heap[cnt]>heap[cnt/2]) // checking whether the newly inserted element is greater than its root!!
	{
		int temp;
		while(heap[cnt]>heap[cnt/2] && cnt!=1)
		{
			temp=heap[cnt];
			heap[cnt]=heap[cnt/2];
			heap[cnt/2]=temp;
			cnt/=2;
		}
	}

}

void del(int size)
{
	if(hsize==0)
	{
		printf("\n\nheap is empty!!\n\n");
		return;
	}

	heap[1]=heap[hsize];
	heap[hsize]=0; // removing the last element in the heap(since it has been moved to the root now)!!
	hsize--;

	// restoring the heap order property!!
	
	int i=1;

	while(heap[i]<heap[2*i] || heap[i]<heap[2*i+1])
	{
		if(heap[i]<heap[2*i] && heap[i]<heap[2*i+1])
		{
			if(heap[2*i]>heap[2*i+1])
			{
				int temp=heap[i];
				heap[i]=heap[2*i];
				heap[2*i]=temp;
				i*=2;
			}

			else
			{
				int temp=heap[i];
				heap[i]=heap[2*i+1];
				heap[2*i+1]=temp;
				i=2*i+1;
			}
		}

		else if(heap[i]<heap[2*i])
		{
			int temp=heap[i];
			heap[i]=heap[2*i];
			heap[2*i]=temp;
			i*=2;
		}

		else if(heap[i]<heap[2*i+1])
		{
			int temp=heap[i];
			heap[i]=heap[2*i+1];
			heap[2*i+1]=temp;
			i=2*i+1;
		}
	}

}

void display(int size)
{
	printf("\n\n|HEAP|\n");
	for(int i=1; i<=hsize; i++)
		printf("%d ", heap[i]);
}


#endif
