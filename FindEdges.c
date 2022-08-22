#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "maxm.h"
#include "stack.h"
#include "GraphMat.h"
#include "dfs.h"

// DIRECTED GRAPHS!

int main(void)
{
	int opt, numV, maxEdge, iV, tV, startV;

	printf("enter the number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1);
	printf("\n\nthe directed graph can have a maximum of %d edges\n\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display the adjacency matrix.\n");
		printf("3. DFS.\n");
		printf("4. Show spanning tree edges.\n");
		printf("5. Show back edges.\n");
		printf("6. Show forward edges.\n");
		printf("7. Show cross edges.\n");
		printf("8. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);


		switch(opt)
		{
			case 1:
				printf("enter edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);

				if(iV>=maxEdge || tV>=maxEdge)
				{
					printf("\ninvalid edge!\n\n");
					break;
				}

				status=edge(iV, tV);

				if(status==ERR)
				{
					printf("\ninvalid edge!\n\n");
					break;
				}

				edgeCount++;

				break;

			case 2:
				showadj(numV);
				break;

			case 3:
				printf("enter start vertex: ");
				scanf("%d", &startV);

				dfs(startV, numV);

				break;

			case 4:
				printf("\n\nhere are the spanning tree edges:\n\n");
				spanningTreeEdge(numV);
				break;

			case 5:
				printf("\n\nback edges:\n");
				backEdge(numV);
				break;

			case 6:
				printf("\n\nforward edges:\n");
				forwardEdge(numV);
				break;

			case 7:
				printf("\n\ncross edges:\n");
				crossEdge(numV);
				break;

			case 8:
				printf("\n\nquitting...\n\n");
				exit(0);

			default:
				INVALID;
		}
	}

	return 0;
}
