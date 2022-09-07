#ifndef Array_H
#define Array_H
#define MAX 100

int arr[MAX], temp, small=INT_MAX, idx=0;

void Selsort(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++) // finding the smallest number between arr[j] and arr[n-1]
		{
			if(arr[j]<small)
			{
				small=arr[j];
				idx=j;
			}
		}

		temp=arr[i];
		arr[i]=arr[idx];
		arr[idx]=temp;

		small=INT_MAX;
	}
}

void Bsort(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void InsSort(int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j>0; j--)
		{
			if(arr[j]<arr[j-1])
			{
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
}

#endif
