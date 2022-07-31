#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

int main(void)
{
	int opt, key;

	node*root=NULL;

	while(1)
	{
menu:
		printf("\n\n---menu---\n\n");

		printf("1. Insert key.\n");
		printf("2. Delete key.\n");
		printf("3. Traverse.\n");
		printf("4. Height.\n");
		printf("5. =Exit=\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter key: ");
				scanf("%d", &key);

				root=insertKey(root, key);
				break;

			case 2:
				printf("enter key to be deleted: ");
				scanf("%d", &key);

				if(root==NULL)
				{
					printf("\n\nthe binary search tree is empty!!\n\n");
					break;
				}

				root=deleteKey(root, key);
				break;


			case 3:
				if(root==NULL)
				{
					printf("\n\nthe binary search tree is empty!!\n\n");
					break;
				}
submenu:
				printf("1> Preorder traversal.\n");
				printf("2> Inorder traversal.\n");
				printf("3> Postorder traversal.\n");
				printf("4> Return to main menu.\n");
				printf("<choose> ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						preorder(root);
						printf("\n");
						goto submenu;

					case 2:
						inorder(root);
						printf("\n");
						goto submenu;

					case 3:
						postorder(root);
						printf("\n");
						goto submenu;

					case 4:
						goto menu;

					default:
						printf("\n\ninvalid option!!\n\n");
						goto submenu;
				}

				break;

			case 4:
				if(root==NULL)
				{
					printf("\n\nbinary search tree is empty!!\n\n");
					break;
				}

				printf("\n\nthe height of the tree is %d\n\n", height(root));

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
