#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "GraphMat.h"
#include "FloydWarshall.h"


int main(void)
{
	int opt, numV, maxEdge, iV, tV, wgt;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);

	initPred(); // initializing all the predecessors of vertices to -1

	printf("\n\nmaximum edges that the graph can have is %d\n\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Insert edges with weights.\n");
		printf("2. Show weighted adjacency matrix.\n");
		printf("3. Apply Floyd's algorithm on the graph.\n");
		printf("4. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:

				if(edgeCount>=maxEdge)
				{
					printf("\nMaximum edge limit has been reached!!\n\n");
					break;
				}

				printf("enter edge %d:\n", edgeCount+1);
				scanf("%d %d", &iV, &tV);

				if(iV>=numV || tV>=numV)
				{
					printf("\n\ninvalid edge!!\n\n");
					break;
				}

				else if(iV<0 || tV<0)
				{
					printf("\n\ninvalid edge!!\n\n");
					break;
				}

				GetWeight(iV, tV);

				edgeCount++;

				break;

			case 2:
				printf("\n\nWeighted adjacency matrix:\n\n");
				showWeight(numV);
				break;

			case 3:
				fw(numV); // perform Floyd-Warshall algorithm!!
				showMat(numV);
				break;

			case 4:

				printf("\n\nquitting...\n\n");
				exit(0);
				break;

			default:
				INVALID;
		}
	}

	return 0;
}
