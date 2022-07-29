#include<stdio.h>
#include<stdlib.h>
#include "deck.h"

int main(void)
{
	int opt, value;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Insert at the front end.\n");
		printf("2. Insert at the rear end.\n");
		printf("3. Delete from the front end.\n");
		printf("4. Delete from the rear end.\n");
		printf("5. Display.\n");
		printf("6. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value: ");
				scanf("%d", &value);

				nqfront(value);
				break;

			case 2:
				printf("enter value: ");
				scanf("%d", &value);

				nqrear(value);
				break;

			case 3:
				value=dqfront();

				if(value==-1)
					break;

				printf("\n\n%d dequeued from front end\n\n", value);
				break;

			case 4:
				value=dqrear();

				if(value==-1)
					break;

				printf("\n\n%d dequeued from rear end\n\n", value);
				break;

			case 5:
				display();
				break;

			case 6:
				printf("\n\nquitting....\n\n");
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
