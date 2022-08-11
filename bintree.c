#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "treeio.h" // tree input output!!
#include "leaf.h" // used for displaying the leaf nodes of a tree!!
#include "countNodes.h" // to count the number of nodes in the tree!!

int main(void)
{
	int opt, val;

	tree*root=NULL;

	int showleaf=false;

	printf("enter values into the tree:\n");
	printf("enter 0 when you are done giving input:\n");
input:
	printf("enter element: ");
	scanf("%d", &val);

	if(val==0)
		goto finish;

	else
		root=enter(root, val);
	goto input;

finish:
	printf("\n\nshowing the leaf nodes!!\n\n");
	leafnd(root);
	while(1)
	{
		printf("\n\n--menu--\n\n");
		printf("1. Preorder traversal.\n");
		printf("2. Inorder traversal.\n");
		printf("3. Postorder traversal.\n");
		printf("4. Count the number of nodes in the tree.\n");
		printf("5. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				preorder(root);
				break;

			case 2:
				inorder(root);
				break;

			case 3:
				postorder(root);
				break;

			case 4:
				printf("\nthe tree has %d nodes!!\n\n", countNd(root, 0));
				break;

			case 5:
				if(root!=NULL)
					terminate(root);
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
