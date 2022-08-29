#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "queue.h"
#include "GraphMat.h"
#include "PathAlgo.h"

int main(void)
{
	int opt, numV, maxEdge, iV, tV, sourceV=-1;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);
	printf("\nMaximum number of edges in the directed graph will be %d\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Show adjacency matrix.\n");
		printf("3. Show weight matrix.\n");
		printf("4. Find pathlengths of vertices.\n");
		printf("5. Find shortest path using Bellman Ford Algorithm.\n");
		printf("6. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(edgeCount>=maxEdge)
				{
					printf("\n\nNumber of edges has maximum limit.\n\n");
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
					printf("\ninvalid edge!!\n\n");
					break;
				}

				GetWeight(iV, tV);

				edgeCount++;
				break;

			case 2:
				printf("\n\nADJACENCY MATRIX.\n");
				showadj(numV);
				break;

			case 3:
				printf("\n\nWEIGHT MATRIX.\n");
				showWeight(numV);
				break;

			case 4:
				printf("enter source Vertex: ");
				scanf("%d", &sourceV);

				initPathLen();
				GetPath(sourceV, numV);
				showPathLen(numV);
				printf("\n\nSpanning tree edges!!\n");
				showPred(numV);
				break;

			case 5:
				if(sourceV==-1)
				{
					printf("\n\nsource vertex has not been entered!!\n\n");
					break;
				}
				printf("enter destination vertex: ");
				scanf("%d", &tV);

				shortestPath(sourceV, tV);

				break;

			case 6:
				printf("\n\nquitting...\n\n");
				exit(0);

			default:
				INVALID;
		}
	}

	return 0;
}
