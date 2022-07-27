#include<stdio.h>
#include<stdbool.h>
#include "adjmat.h"

int main(void)
{
	int n, opt;
	bool created;

	printf("\n\nChoose any one from the following:\n\n");

	printf("1. Undirected graph.\n");
	printf("2. Directed graph.\n");

	printf("<option> ");
	scanf("%d", &opt);

	switch(opt)
	{
		case 1:
			printf("\n\nenter number of vertices: ");
			scanf("%d", &n);
			created=createAdjMat(opt, n);

			if(created==true)
				showadj(n);

			else
				printf("\n\nfailed to create adjacency matrix!!!\n\n");
			break;

		case 2:
			printf("\n\nenter number of vertices: ");
			scanf("%d", &n);
			created=createAdjMat(opt, n);

			if(created==true)
				showadj(n);

			else
				printf("\n\nfailed to create adjacency matrix!!!\n\n");
			break;

		default:
			printf("\n\ninvalid option!!!\n\n");
	}

	return 0;
}
