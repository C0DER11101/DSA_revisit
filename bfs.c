#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "queue.h" // for queue functions!!
#include "GraphMat.h"
#include "bfs.h"


// FOR DIRECTED GRAPHS!!!!

int main(void)
{
	int opt, numV, maxEdge, initV, dstV, startV, endV;

	printf("enter number of vertices: ");
	scanf("%d", &numV);


	maxEdge=numV*(numV-1); // maximum number of edges in the directed graph!!
	printf("\nMaximum edges = %d\n", maxEdge);

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edge.\n");
		printf("2. Display adjacency matrix.\n");
		printf("3. Perform BFS(find shortest path).\n");
		printf("4. Exit.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter an edge(initial vertex-terminal vertex): ");
				scanf("%d-%d", &initV, &dstV);
				if(initV>=maxEdge or dstV>=maxEdge)
				{
					printf("\n\ninvalid edge!!\n\n");
					break;
				}

				edge(initV, dstV);
				break;

			case 2:
				showadj(numV);
				break;

			case 3:
				printf("enter starting vertex: ");
				scanf("%d", &startV);

				bfs(startV, numV);

				printf("enter destination vertex: ");
				scanf("%d", &endV);

				int temp=endV;

				while(endV!=-1)
				{
					SPath[Spidx]=endV;
					endV=pred[endV];
					Spidx++;
				}


				printf("\n\nshortest path from %d to %d is:\n\n", startV, temp);

				for(int i=Spidx-1; i>=0; i--)
					printf("%d->", SPath[i]);

				// restore the SPath and Spidx;

				for(int i=0; i<Spidx; i++)
					SPath[i]=0;
				Spidx=0;
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
