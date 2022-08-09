#include<stdio.h>
#include<stdlib.h>
#include "DgraphAdjM.h"
#include "PMatrix.h"

int main(void)
{
	int numV, opt;

	while(1)
	{
		printf("enter number of vertices: ");
		scanf("%d", &numV);

menu:
		printf("\n\n---menu---\n");
		printf("\n^DIRECTED GRAPH^\n");
		printf("1. Create adjacency matrix.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Find the transitive closure matrix of the graph.\n");
		printf("4. Display the transitive closure matrix of the graph.\n");
		printf("5. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("\nthe  directed graph can have a maximum of %d edges!!\n\n", numV*(numV-1));
				createAdj(numV, numV*(numV-1));
				goto menu;

			case 2:
				showAdj(numV);
				goto menu;

			case 3:

				if(check(numV)<0)
				{
					printf("\n\ntransitive closure matrix of the graph is:\n\n");
					powerAdj(numV);
					addPow(numV);
				}

				else
					printf("\n\nalready calculated transitive closure matrix of graph!!\n\n");
				goto menu;

			case 4:
				PathMatrix(numV);
				goto menu;

			case 5:
				printf("\nquitting....\n\n");
				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
				goto menu;
		}

	}

	return 0;
}
