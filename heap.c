#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "heap.h"

// FOR MAX HEAP!!!

int main(void)
{
	int size, opt, val;

	printf("enter number of elements: ");
	scanf("%d", &size);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert into heap.\n");
		printf("2. Display heap.\n");
		printf("3. Delete from heap.\n");
		printf("4. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);


		switch(opt)
		{
			case 1:
				printf("enter value: ");
				scanf("%d", &val);
				insert(val, size);
				break;

			case 2:
				display(size);
				break;

			case 3:
				del(size);
				break;

			case 4:
				printf("\n\nquitting...\n\n");
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
