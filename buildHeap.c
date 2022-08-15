#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "heapify.h"

// BUILDING A HEAP!!!!!

int main(void)
{
	int arr[MAX], size;

	printf("enter size of the array to build the heap: ");
	scanf("%d", &size);

	printf("\nenter elements into the array:\n\n");
	
	for(int i=1;i<=size; i++)
	{
		printf("[%d]: ", i);
		scanf("%d", arr+i);
	}

	build(arr, size);

	restoreHeapStruct();

	display();

	return 0;
}
