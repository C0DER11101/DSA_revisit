#include<stdio.h>
#include<stdlib.h>
#include "List.h"


// THIS PROGRAM DOESNOT IMPLEMENT ALL THE OPERATIONS ON THE LINKED LISTS.
// THIS PROGRAM ONLY SHOWS THE OPERATIONS THAT WE CAN PERFORM ON A LINKED LIST USING RECURSIONS.
int main(void)
{
	int opt, value;
	node*head=NULL;


	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Insert element into list.\n"); // insert element at the end of the list
		printf("2. Display list.\n");
		printf("3. Display list in reverse order.\n");
		printf("4. Reverse the list.\n");
		printf("5. Find length of the list.\n");
		printf("6. Find sum of the elements in the list.\n");
		printf("7. Search for an element in the list.\n");
		printf("8. Delete node.\n"); // delete last node
		printf("9. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("\nenter value: ");
				scanf("%d", &value);

				head=addNode(head, value);
				break;

			case 2:
				display(head);
				break;

			case 3:
				displayRL(head);
				break;

			case 4:
				head=revL(head);
				break;
				
			case 5:
				if(head==NULL)
				{
					printf("\n\nthe list is empty!!\n\n");
					break;
				}

				printf("\n\nlength of the list = %d\n", len(head));
				break;

			case 6:
				if(head==NULL)
				{
					printf("\n\nthe list is empty!!\n\n");
					break;
				}

				printf("\n\nsum of the elements of the list is %d\n", addEl(head));
				break;

			case 7:
				printf("\nenter element to be searched: ");
				scanf("%d", &value);

				if(searchNode(head, value)==1)
					printf("\n\n%d exists in the list!!\n\n", value);
				else
					printf("\n\n%d doesnot exist in the list!\n\n", value);
				break;

			case 8:
				rmNode(head);
				break;

			case 9:
				if(head!=NULL)
					head=terminate(head);

				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	terminate(head);


	return 0;
}
