#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "GraphMat.h"
#include "BFS.h"


// BFS!! FOR DIRECTED GRAPH!!!


int main(void)
{
	// FOR DIRECTED GRAPHS

	int opt, numV, maxEdge, initV, dstV, val;

	printf("enter number of vertices!!\n\n");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);
	int edgeCount=0;


	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform Breadth First Search.\n");
		printf("4. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(edgeCount>=maxEdge)
				{
					printf("\nALL THE EDGES HAVE BEEN ENTERED!! CANNOT ENTER ANY MORE!!\n\n");
					break;
				}

				printf("enter edge %d\n", edgeCount+1);
				printf("initial vertex-terminal vertex: ");
				scanf("%d-%d", &initV, &dstV);

				edge(initV, dstV);

				edgeCount++;

				break;
				
			case 2:
				showadj(numV);
				break;

			case 3:
				printf("enter the starting vertex: ");
				scanf("%d", &val);
				
				bfs(val, numV);

				break;

			case 4:
				printf("\n\nquitting....\n\n");
				exit(0);

			default:
				INVALID;
		}
	}

	return 0;
}
