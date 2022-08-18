#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "stack.h"
#include "GraphMat.h"
#include "DFS.h"


int main(void)
{
	int opt, startV, numV, iV, tV, maxEdge, status;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1); // DIRECTED GRAPH

	printf("\n\nMAXIMUM EDGES = %d\n", maxEdge);


	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edges.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform DFS.\n");
		printf("4. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:

				if(edgeCount>=maxEdge)
				{
					printf("\n\ncannot enter anymore edges!!\n\n");
					break;
				}

				printf("enter edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);

				if(iV>=maxEdge || tV>=maxEdge)
				{
					printf("\ninvalid vertices!\n\n");
					break;
				}

				status=edge(iV, tV);

				if(status==ERR)
				{
					printf("\ninvalid vertices!\n\n");
					break;
				}

				edgeCount++;

				break;

			case 2:
				showadj(numV);
				break;

			case 3:
				printf("enter starting vertex: ");
				scanf("%d", &startV);
				dfs(startV, numV);
				break;

			case 4:
				printf("\n\nquitting...\n\n");
				exit(0);

			default:
				INVALID;
		}
	}

	return 0;
}
