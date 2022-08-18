#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "GraphMat.h"
#include "stack.h"
#include "DFT.h"


int main(void)
{
	int opt, iV, tV, maxEdge, numV, status, startV;


	printf("enter number of vertices: ");
	scanf("%d", &numV);

	maxEdge=numV*(numV-1); // for directed graph!!
	printf("\n\nthe directed graph can have a maximum of %d edges\n\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Show the adjacency matrix.\n");
		printf("3. Perform Depth First Traversal.\n");
		printf("4. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter edge %d: ", edgeCount+1);
				scanf("%d %d", &iV, &tV);

				if(iV>=maxEdge || tV>=maxEdge)
				{
					printf("\n\ninvalid vertices!!\n\n");
					break;
				}

				status=edge(iV, tV);

				if(status==ERR)
				{
					printf("\n\ninvalid vertices!!\n\n");
					break;
				}

				edgeCount++;

				break;

			case 2:
				printf("\n\nADJACENCY MATRIX\n\n");
				showadj(numV);

				break;

			case 3:
				printf("enter start vertex: ");
				scanf("%d", &startV);
				dft(startV, numV);
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
