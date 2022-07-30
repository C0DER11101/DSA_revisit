#include<stdio.h>
#include<stdlib.h>
#include "cql.h"

int main(void)
{
	int opt, value;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("3. Display.\n");
		printf("4. Peek.\n");
		printf("5. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value: ");
				scanf("%d", &value);

				enqueue(value);
				break;

			case 2:
				value=dequeue();
				if(value==-1)
					break;

				printf("\n\n%d dequeued!!\n\n", value);
				break;

			case 3:
				display();
				break;

			case 4:
				peek();
				break;

			case 5:
				if(checkNull()!=NULL)
					terminate();

				exit(0);
				
			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
