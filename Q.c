#include<stdio.h>
#include<stdlib.h>
#include "Q.h"

int main(void)
{
	int opt, value;

	node*front=NULL;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("3. Count.\n");
		printf("4. Display.\n");
		printf("5. Exit.\n");
		printf(">");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value to be enqeued: ");
				scanf("%d", &value);

				front=nq(value, front);

				break;

			case 2:
				front=dq(front);
				break;

			case 3:
				value=count(front);

				printf("\nthere are %d elements in the queue!!!\n\n", value);
				break;

			case 4:
				printf("\n\nhere is the queue!!!!\n\n");
				show(front);
				break;

			case 5:
				printf("\n\nquitting...\n\n");
				Kill(front);

				return 0;

			default:
				printf("\n\ninvalid option!!!\n\n");

		}

	}

	return 0;
}
