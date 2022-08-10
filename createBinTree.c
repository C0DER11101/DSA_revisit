#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "proc.h"
#include "BinTree.h"

//CREATING A BINARY TREE FROM INORDER AND PREORDER TRAVERSALS!!!!

int main(void)
{
	char*preorder, *inorder;
	int opt;

	tree*root=NULL;

	preorder=(char*)malloc(100*sizeof(char));
	inorder=(char*)malloc(100*sizeof(char));

	printf("enter nodes in inorder sequence:\nInorder sequence: ");
	scanf("%s", inorder);

	printf("enter nodes in preorder sequence:\nPreorder sequence: ");
	scanf("%s", preorder);

	root=CreBinaT(root, inorder, preorder);


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
				free(preorder);

				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}
	}

	return 0;
}
