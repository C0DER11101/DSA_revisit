#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "Array.h"

int main(void)
{
	int size;

	printf("enter number of elements: ");
	scanf("%d", &size);

	printf("enter elements:\n\n");

	for(int i=0; i<size; i++)
	{
		printf("element %d: ", i+1);
		scanf("%d", arr+i);
	}

	InsSort(size);


	printf("\n\nsorted array:\n\n");

	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
