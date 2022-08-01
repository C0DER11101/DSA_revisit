#include<stdio.h>
#include<stdlib.h>
#include "String.h"

int main(void)
{
	char*str;

	int opt;

	str=(char*)malloc(100*sizeof(char));

	printf("enter a string; ");
	scanf("%s", str);

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Find length of the string.\n");
		printf("2. Display string.\n");
		printf("3. Display string in reverse order.\n");
		printf("4. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("\n\nthe length of the string is %d\n\n", len(str));
				break;

			case 2:
				printf("\n\nThis is the string:\n\n");
				showstr(str);
				break;
				
			case 3:
				printf("\n\nThis is the string in reverse order:\n\n");
				rev(str);
				break;

			case 4:
				free(str);
				printf("\n\nquitting....\n\n");
				return 0;

			default:
				printf("\n\ninvalid option!!!\n\n");
		}

	}

	free(str);

	return 0;
}
