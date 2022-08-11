#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "structDec.h"
#include "proc.h"
#include "TREESTACK.h"
#include "treei.h" // tree-input header file

// PREORDER TRAVERSAL OF A TREE USING STACK!!!!

int main(void)
{
	int opt, val, numNodes;

	char*inorder, *preorder;

	tree*root=NULL;

	inorder=(char*)malloc(100*sizeof(char));
	preorder=(char*)malloc(100*sizeof(char));

	printf("STRINGS:\n");
	printf("enter values in inorder sequence: ");
	scanf("%s", inorder);

	printf("enter values in preorder sequence: ");
	scanf("%s", preorder);
	
	root=CreBinaT(root, inorder, preorder);


	while(true)
	{
		printf("\n\n---menu---\n");
		printf("1. Preorder.\n");
		printf("2. Inorder.\n");
		printf("3. Postorder.\n");
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
