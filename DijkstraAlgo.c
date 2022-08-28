#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "maxm.h"
#include "GraphMat.h"
#include "PathAlgo.h"

int main(void)
{
	int opt, numV, iV, tV, maxEdge, sourceV=-1;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);

	printf("\nMaximum edges in directed graph: %d\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Show adjacency matrix.\n");
		printf("3. Show weight matrix.\n");
		printf("4. Find pathlength of each vertex.\n");
		printf("5. Find the shortest path to a vertex.\n");
		printf("6. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(edgeCount>=maxEdge)
				{
					printf("\ncannot enter any more edges!!\n\n");
					break;
				}

				printf("enter edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);

				if(iV>=numV || tV>=numV)
				{
					printf("\n\ninvalid edge!!\n\n");
					break;
				}

				status=edge(iV, tV);

				if(status==ERR)
				{
					printf("\n\ninvalid edges!!\n\n");
					break;
				}

				GetWeight(iV, tV);
				edgeCount++;

				break;

			case 2:
				printf("\n\nAdjacency Matrix\n\n");
				showadj(numV);
				break;

			case 3:
				printf("\n\nWeight Matrix\n\n");
				showWeight(numV);
				break;

			case 4:
				initPathLen(); // initialize the path lenghts of each vertex!!!
				printf("enter a source vertex: ");
				scanf("%d", &sourceV);
				GetPath(sourceV, numV);
				showPathLen(numV);
				showPred(numV);
				break;

			case 5:
				if(sourceV==-1)
				{
					printf("\n\na source vertex must be selected!!\n\n");
					break;
				}

				printf("enter destination vertex: ");
				scanf("%d", &tV);

				shortestPath(sourceV, tV);
				break;

			case 6:
				printf("\n\nquitting..\n\n");
				exit(0);

			default:
				INVALID;
		}

	}

	return 0;
}
