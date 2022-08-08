#include<stdio.h>
#include<stdlib.h>
#include "Undiadjl.h"

int main(void)
{
	int opt, vertexVal, initV, dstV;

	vertex*v=NULL;

	char gtype;

	while(1)
	{
selectType:
		printf("\n\n--CHOOSE GRAPH TYPE--\n\n");
		printf("[d]___(Directed graph).\n");
		printf("[u]___(Undirected graph).\n");
		printf("[e]___<Exit>\n");
		printf("option:\\>");
		scanf(" %c", &gtype);

		switch(gtype)
		{
			case 'u': case 'U':
				break;

			case 'd': case 'D':
				break;

			case 'e': case 'E':
				exit(0);

			default:
				printf("\n\ninvalid option!\n\n");
				continue;
		}
		
menu:
		printf("\n\n---menu---\n\n");
		printf("1. Insert vertex.\n");
		printf("2. Delete vertex.\n");
		printf("3. Insert edge.\n");
		printf("4. Delete edge.\n");
		printf("5. Display graph.\n");
		printf("6. Change graph type.\n");
		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("enter value for the vertex: ");
				scanf("%d", &vertexVal);
				v=insertVertex(v, v, vertexVal);
				goto menu;

			case 2:
				printf("enter value of the vertex: ");
				scanf("%d", &vertexVal);
				v=delVertex(v, vertexVal);
				goto menu;

			case 3:
				printf("enter initial vertex: ");
				scanf("%d", &initV);
				printf("enter destination vertex: ");
				scanf("%d", &dstV);

				if(gtype=='u' || gtype=='U')
					v=insertEdgeU(v, initV, dstV);

				else
					v=insertEdgeD(v, initV, dstV);

				goto menu;

			case 4:
				printf("enter initial vertex: ");
				scanf("%d", &initV);
				printf("enter destination vertex: ");
				scanf("%d", &dstV);

				if(gtype=='u' || gtype=='U')
					v=delEdgeU(v, initV, dstV);
				else
					v=delEdgeD(v, initV, dstV);

				goto menu;

			case 5:
				dispGraph(v);
				goto menu;

			case 6:
				if(v!=NULL)
					v=terminate(v);
				goto selectType;
				
			default:
				printf("\n\ninvalid option!!\n\n");
				goto menu;
		}
	}

	return 0;
}
