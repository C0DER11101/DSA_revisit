#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "GraphMat.h"
#include "DFSrec.h"


int main(void)
{
	int opt, numV, startV, iV, tV, status;

	printf("enter number of vertices: ");
	scanf("%d", &numV);

	printf("Maximum Edges = %d\n", numV*(numV-1));
	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform DFS.\n");
		printf("4. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);
				
				if(iV>=numV*(numV-1) || tV>=numV*(numV-1))
				{
					printf("\ninvalid edge!!\n\n");
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
				printf("enter start vertex: ");
				scanf("%d", &startV);
				dfs(startV, numV);
				restore(numV);
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
