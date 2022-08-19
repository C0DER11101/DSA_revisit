#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "stack.h"
#include "GraphMat.h"
#include "DFSpred.h"


int main(void)
{
	int opt, startV, numV, maxEdge, iV, tV, status;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);// DIRECTED GRAPH!!
	printf("\nMAXIMUM EDGES = %d\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform DFS.\n");
		printf("4. Spanning tree edges.\n");
		printf("5. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:

				printf("enter  edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);
				
				if(iV>=maxEdge || tV>=maxEdge)
				{
					printf("\n\ninvalid edge!!\n\n");
					break;
				}

				status=edge(iV, tV);

				if(status==ERR)
				{
					printf("\n\ninvalid edge!!\n\n");
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
				SpanningTree(numV);
				break;

			case 5:
				printf("\n\nquitting...\n\n");
				exit(0);

			default:
				INVALID;
		}

	}

	return 0;
}
