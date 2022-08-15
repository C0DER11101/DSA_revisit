#ifndef HEAPIFY_H
#define HEAPIFY_H

int heap[MAX];
static int hsize;

void build(int arr[], int size)
{

	for(int i=1; i<=size; i++)
		heap[++hsize]=arr[i];
	printf("\n\nheap built successfully!!\n\n");
}

void restoreHeapStruct()  // to restore heap structure property!!
{
	printf("\nRESTORING HEAP ORDER PROPERTY!!!\n\n");

	int i=hsize/2; // the last non-leaf node!!

	while(i!=0)
	{
		if(heap[i]<heap[2*i] or heap[i]<heap[2*i+1])
		{
			if(heap[2*i]>heap[2*i+1])
			{
				int temp=heap[i];
				heap[i]=heap[2*i];
				heap[2*i]=temp;
				int j=2*i;
				while(j<=hsize) // for further restoration of the children elements!!
				{
					if(heap[j]<heap[2*j] or heap[j]<heap[2*j+1])
					{
						if(heap[2*j]>heap[2*j+1])
						{
							int temp=heap[j];
							heap[j]=heap[2*j];
							heap[2*j]=temp;
							j*=2;
						}

						else
						{
							int temp=heap[j];
							heap[j]=heap[2*j+1];
							heap[2*j+1]=temp;
							j=2*j+1;
						}
					}

					else
					{
						j++;
					}
				}
			}

			else
			{
				int temp=heap[i];
				heap[i]=heap[2*i+1];
				heap[2*i+1]=temp;
				int j=2*i+1;

				while(j<=hsize)
				{
					if(heap[j]<heap[2*j] or heap[j]<heap[2*j+1])
					{
						if(heap[2*j]>heap[2*j+1])
						{
							int temp=heap[j];
							heap[j]=heap[2*j];
							heap[2*j]=temp;
							j*=2;
						}

						else
						{
							int temp=heap[j];
							heap[j]=heap[2*j+1];
							heap[2*j+1]=temp;
							j=2*j+1;
						}
					}

					else
					{
						j++;
					}
				}
			}
		}

		i--;
	}
}

void display()
{
	for(int i=1; i<=hsize; i++)
		printf("%d ", heap[i]);
}

#endif
