#include<stdio.h>
#include<stdlib.h>
#include "dec.h"
#include "def.h"


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
		printf("<4> [Count]\n");
		printf("<5> [Search]\n");
		printf("<6> {Exit}\n");

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
				printf("\n\nthere are %d element(s) in the list...\n\n", count(head));
				break;


			case 5:
				printf("enter value to be searched: ");
				scanf("%d", &value);
				isThere=search(value, head);
				
				if(isThere==true)
					printf("\n%d is in the list\n\n", value);

				else
					printf("\n%d is not in the list\n\n", value);
				break;

			case 6:

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
