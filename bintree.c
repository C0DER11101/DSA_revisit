#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "treeio.h" // tree input output!!
#include "leaf.h" // used for displaying the leaf nodes of a tree!!

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
	if(showleaf==false)
	{
		printf("\n\nshowing the leaf nodes!!\n\n");
		leafnd(root);
		showleaf=true;
	}
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
				preorder(root);
				goto finish;

			case 2:
				inorder(root);
				goto finish;

			case 3:
				postorder(root);
				goto finish;
			case 4:
				if(root!=NULL)
					terminate(root);
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
