#include<stdio.h>
#include<stdlib.h>
#include "ll2.h"
#include "ll2def.h"


int main(void)
{
	bool isThere;

	int opt, value;

	node*head=NULL;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("<1> [Insert]\n");
		printf("<2> [Display]\n");
		printf("<3> [Delete]\n");
		printf("<4> [Display list in Reverse order]\n");
		printf("<5> [Reverse list]\n");
		printf("<6> [Count]\n");
		printf("<7> [Search]\n");
		printf("<8> {Exit}\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter element to be inserted: ");
				scanf("%d", &value);

				head=insert(value, head);
				break;

			case 2:
				display(head);
				break;

			case 3:
				printf("enter value to be deleted: ");
				scanf("%d", &value);

				if(head==NULL)
				{
					printf("\n\nlist is empty!!\n\n");
					break;
				}

				head=del(value, head);
				break;

			case 4:
				if(head==NULL)
				{
					printf("\n\nlist is empty!!\n\n");
					break;
				}

				disprev(head);
				break;

			case 5:
				if(head==NULL)
				{
					printf("\n\nlist is empty!!\n\n");
					break;
				}

				head=revlist(head);
				break;

			case 6:
				printf("\n\nthere are %d element(s) in the list...\n\n", count(head));
				break;


			case 7:
				printf("enter value to be searched: ");
				scanf("%d", &value);
				isThere=search(value, head);

				if(isThere==true)
					printf("\n%d is in the list\n\n", value);

				else
					printf("\n%d is not in the list\n\n", value);
				break;

			case 8:

				if(head!=NULL)
					terminate(head);

				return 0;
				break;

			default:
				printf("\n\ninvalid option!!\n\n");

		}

	}


	return 0;
}
