#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "maxm.h"
#include "queue.h"
#include "GraphMat.h"
#include "graConec.h" // to check connectivity of the undirected graph
#include "bfsun.h" // for undirected graphs


int main(void)
{
	int opt, numV, maxEdge, iV, tV, startV;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1)/2; // FOR DIRECTED GRAPH!!!
	printf("\n\nthe undirected graph will have a maximum of %d edges!!\n\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Insert edge.\n");
		printf("2. Show adjacency matrix.\n");
		printf("3. Perform BF traversal.\n");
		printf("4. Check connectivity of the graph.\n");
		printf("5. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(edgeCount==maxEdge)
				{
					printf("\n\nno more edges can be inserted!!\n\n");
					break;
				}

				printf("enter edge %d(initial vertex-terminal vertex): ", edgeCount+1);
				scanf("%d-%d", &iV, &tV);
				edge(iV, tV);
				edgeCount++;

				break;

			case 2:
				showadj(numV);
				break;

			case 3:
				printf("enter starting vertex: ");
				scanf("%d", &startV);

				bfs(startV, numV);

				break;

			case 4:
				printf("\nenter starting vertex: ");
				scanf("%d", &startV);

				if(isConnected(startV, numV)==true)
					printf("\n\nthe graph is connected!!\n\n");
				else
					printf("\n\nthe graph is not connected!!\n\n");

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
