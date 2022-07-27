#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "exptreestack.h"
#include "stackTree.h"
#include "exptree.h"

int main(void)
{
	char*infix;
	int opt;

	infix=(char*)malloc(100*sizeof(char));

	printf("enter an infix expression: ");
	scanf("%s", infix);

	scanexp(infix);

	createTree();

	while(1)
	{

		printf("\n\nChoose one from the following>..\n\n");

		printf("1. Inorder traversal.\n");
		printf("2. Preorder traversal.\n");
		printf("3. Postorder traversal.\n");
		printf("4. Exit.\n");
		printf("<option>");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				inorder(Stack[top]);
				break;

			case 2:
				preorder(Stack[top]);
				break;

			case 3:
				postorder(Stack[top]);
				break;

			case 4:
				printf("\n\nQuitting....\n\n");
				terminate(Stack[top]);

				free(infix);

				exit(0);

			default:
				printf("\n\ninvalid option!!!\n\n");
		}
	}

	terminate(Stack[top]);

	free(infix);

	return 0;
}
