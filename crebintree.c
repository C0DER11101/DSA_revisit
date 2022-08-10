// CREATING A BINARY TREE FROM INORDER AND POSTORDER TRAVERSALS!!!!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "proc.h"
#include "ctree.h"

int main(void)
{
	int opt;
	char *inorder, *postorder;

	tree*root=NULL;

	inorder=(char*)malloc(sizeof(char));
	postorder=(char*)malloc(sizeof(char));

	printf("enter nodes in inorder sequence: ");
	scanf("%s", inorder);

	printf("enter nodes in postorder sequence: ");
	scanf("%s", postorder);

	root=createTree(root, inorder, postorder);


	while(1)
	{
		printf("\n\n--menu--\n\n");
		printf("1. Preorder traversal.\n");
		printf("2. Inorder traversal.\n");
		printf("3. Postorder traversal.\n");
		printf("4. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				Preorder(root);
				break;

			case 2:
				Inorder(root);
				break;

			case 3:
				Postorder(root);
				break;

			case 4:
				if(root!=NULL)
					terminate(root);
				free(inorder);
				free(postorder);

				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}


	return 0;
}
