#include<stdio.h>
#include<stdlib.h>
#include "adjlist.h"

// WORKS FOR DIRECTED GRAPH!!
int main(void)
{
	int opt, vertexVal, initV, dstV;

	/* initV -> initial vertex
	   dstV -> destination vertex
	   these two will be used in options 3 and 4.
	   --------------------------------------------

	   vertexVal will be used in options 1 and 2.
	*/

	Vertex*v=NULL;

	while(1)
	{
		printf("\n\n---menu---\n\n");
		printf("1. Insert vertex.\n");
		printf("2. Delete vertex.\n");
		printf("3. Insert edge.\n");
		printf("4. Delete edge.\n");
		printf("5. Display graph.\n");
		printf("6. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value of vertex: ");
				scanf("%d", &vertexVal);

				v=insertVertex(v, vertexVal);

				break;

			case 2:
				printf("enter value of vertex: ");
				scanf("%d", &vertexVal);

				v=delVertex(v, vertexVal);

				break;

			case 3:
				printf("enter initial vertex: ");
				scanf("%d", &initV);
				printf("enter destination vertex: ");
				scanf("%d", &dstV);

				v=insertEdge(v, initV, dstV);
				break;

			case 4:
				printf("enter initial vertex: ");
				scanf("%d", &initV);
				printf("enter destination vertex: ");
				scanf("%d", &dstV);

				v=delEdge(v, initV, dstV);
				break;

			case 5:
				dispGraph(v);
				break;

			case 6:
				if(v!=NULL) // if the user exits without freeing up space
					terminate(v);

				exit(0);

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}
	return 0;
}
