#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "stack.h"
#include "GraphMat.h"
#include "dfs.h"


int main(void)
{
	int opt, numV, maxEdge, iV, tV, startV;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1)/2; // for undirected graphs!!

	printf("\n\nMaximum number of edges for undirected graph = %d\n", maxEdge);


	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform DFS.\n");
		printf("4. Show spanning tree edges.\n");
		printf("5. Show back edges.\n");
		printf("6. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(edgeCount>=maxEdge)
				{
					printf("\n\ncannot anymore edges!!\n\n");
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
				printf("Spanning tree edges!!\n\n");
				spanningTreeEdge(numV);
				break;

			case 5:
				backEdge(numV);
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
