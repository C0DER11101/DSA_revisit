#include<stdio.h>
#include "Stack.h"

int main(void)
{
	int opt, element;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("<1> [Push]\n");
		printf("<2> [Pop]\n");
		printf("<3> [Peek]\n");
		printf("<4> [Show]\n");
		printf("<5> [Exit]\n");

		printf(">");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter element to be pushed: ");
				scanf("%d", &element);
				push(element);

				break;

			case 2:
				element=pop();
				printf("%d removed from stack..\n\n", element);

				break;

			case 3:
				printf("\nelement at the top is %d\n", peek());

				break;

			case 4:
				show();

				break;

			case 5:
				printf("\n\nquitting....\n\n");
				return 0;

			default:
				printf("\n\nInvalid option!!\n\n");

		}

	}

	return 0;
}
