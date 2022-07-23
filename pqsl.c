#include<stdio.h>
#include<stdlib.h>
#include "pqsl.h"

int main(void)
{
	int opt, value, priority;

	node*front=NULL;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("<1> [Insert]\n");
		printf("<2> [Delete]\n");
		printf("<3> [Display]\n");
		printf("<4> [Count]\n");
		printf("<5> [Exit]\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value: ");
				scanf("%d", &value);

				printf("enter priority: ");
				scanf("%d", &priority);

				front=insert(value, priority, front);
				break;

			case 2:
				front=del(front);
				break;

			case 3:
				show(front);
				break;

			case 4:

				printf("\n\nthere are %d element(s) in the priority queue\n\n", count(front));
				break;

			case 5:
				if(front!=NULL)
					terminate(front);
				return 0;

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
