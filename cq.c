#include<stdio.h>
#include<stdlib.h>

#include "cq.h"

int main(void)
{
	int opt, val;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("3. Peek.\n");
		printf("4. Display.\n");
		printf("5. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value: ");
				scanf("%d", &val);
				enqueue(val);

				break;

			case 2:
				val=dequeue();

				if(val==-1)
					break;

				printf("\n\n%d dequeued!!\n\n", val);
				break;

			case 3:
				val=peek();
				if(val==-1)
					break;

				printf("\n\nfront of circular queue = %d\n\n", val);
				break;

			case 4:
				display();
				break;

			case 5:
				printf("\n\nquitting....\n\n");

				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}
	}

	return 0;
}
