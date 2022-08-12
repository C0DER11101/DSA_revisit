#include<stdio.h>
#include<stdlib.h>
#include "structDec.h"
#include "TreeIn.h"
#include "leaf.h"
#include "countNodes.h"
#include "TREESTACK.h"  // stack operations for trees!!!
#include "travwStack.h"  // traverse the tree with stack


int main(void)
{
	int opt, val;

	tree*root=NULL;

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert node.\n");
		printf("2. Traverse.\n");
		printf("3. Show leaf nodes.\n");
		printf("4. Count the total number nodes.\n");
		printf("5. [Exit].\n");
		printf("-option- ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter node value: ");
				scanf("%d", &val);
				root=enter(root, val);
				break;

			case 2:
trav:
				printf("\n\n-SUBMENU-\n");
				printf("\n\n1> Preorder traversal.\n");
				printf("2> Inorder traversal.\n");
				printf("3> Postorder traversal.\n");
				printf("4> Quit.\n");
				printf("= option = ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						preorder(root);
						goto trav;

					case 2:
						inorder(root);
						goto trav;

					case 3:
						postorder(root);
						goto trav;

					case 4:
						break;
				}

				break;

			case 3:
				leafnd(root);
				break;

			case 4:
				countNd(root, 0);
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
