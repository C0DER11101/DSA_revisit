#include<stdio.h>
#include<stdlib.h>
#include "ListD.h"

int main(void)
{
	int opt, value, nodeval;

	node*head=NULL;


	while(1)
	{
menu:
		printf("\n\n---menu---\n\n");
		printf("1. Insert node.\n");
		printf("2. Display list.\n");
		printf("3. Delete node.\n");
		printf("4. Search a node.\n");
		printf("5. Calculate sum of the nodes.\n");
		printf("6. Display list in reverse order.\n");
		printf("7. Reverse the list.\n");
		printf("8. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
submenu1:
				printf("<INSERT NODE>\n");
				printf("{1} In the beginning.\n");
				printf("{2} At the end.\n");
				printf("{3} In between nodes.\n");
				printf("{4} Return to main menu.\n");
				printf("<select> ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						printf("\nenter value: ");
						scanf("%d", &value);
						head=InsertBeg(head, value);
						goto submenu1;

					case 2:
						printf("\nenter value: ");
						scanf("%d", &value);
						head=Append(head, value);
						goto submenu1;

					case 3:
						printf("\nenter value: ");
						scanf("%d", &value);

						printf("enter node value to link this new node with.\n");
						scanf("%d", &nodeval);

						head=AddMid(head, value, nodeval);

						goto submenu1;

					case 4:
						goto menu;

					default:
						printf("\n\ninvalid option\n\n");
						goto submenu1;
				}

			case 2:
				showList(head);
				break;

			case 3:
submenu2:

				printf("{1} Delete from the beginning.\n");
				printf("{2} Delete from the end.\n");
				printf("{3} Delete from the middle.\n");
				printf("{4} Return to main menu.\n");
				printf("<select> ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						head=delBeg(head);
						goto submenu2;

					case 2:
						head=delEnd(head);
						goto submenu2;

					case 3:
						printf("enter value to be deleted: ");
						scanf("%d", &value);
						head=delRandom(head, value);
						goto submenu2;

					case 4:
						goto menu;

					default:
						printf("\n\ninvalid option!!\n\n");
						goto submenu2;
				}


			case 4:
				printf("enter a node value: ");
				scanf("%d", &value);

				if(dig(head, value)<0)
					printf("\n%d is not in the list!!!\n\n", value);
				else
					printf("\n%d is in the list!!!\n\n", value);
				break;

			case 5:
				if(head==NULL)
				{
					printf("\n\nthe list is empty!!\n\n");
					break;
				}

				printf("\n\nThe sum of the elements in the list is: %d\n", addNodes(head, 0));
				break;

			case 6:
				revDisp(head);
				break;

			case 7:
				head=RevL(head);
				break;

			case 8:
				if(head!=NULL)
					terminate(head);

				printf("\n\nquitting....\n\n");
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");

		}

	}

	if(head!=NULL)
		terminate(head);

	return 0;
}
