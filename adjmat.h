#ifndef ADJ_H
#define ADJ_H
#define MAX 100

int adjMatrix[MAX][MAX];

bool createAdjMat(int opt, int numVertices)
{
	int maxEdges, initialVertex, finalVertex;

	if(opt==1)
	{
		maxEdges=numVertices*(numVertices-1)/2;
		printf("\nThe graph can have a maximum of %d edges\n\n", maxEdges);

		for(int i=0; i<maxEdges;) 
		{
			printf("\nEnter two negative numbers to exit..\n\n");
			printf("\nenter initial vertex and final vertex for edge %d(initialVertex-finalVertex): ", i+1);
			scanf("%d-%d", &initialVertex, &finalVertex);

			if(initialVertex<0 && finalVertex<0)
			{
				printf("\nAdjacency matrix created!!!\n\n");
				break;
			}

			else if(initialVertex>=numVertices && finalVertex>=numVertices)
			{
				printf("\n\nInvalid vertices!!\n\n");
				continue;
			}

			else
			{
				/*
				   in an undirected graph -> edges have no direction, so any two vertices connected are same if taken
				   in the other way around

				   v0-v1 is same as v1-v0
				*/
				adjMatrix[initialVertex][finalVertex]=1;
				adjMatrix[finalVertex][initialVertex]=1;
			}

			i++;
		}
	}

	else if(opt==2)
	{
		maxEdges=numVertices*(numVertices-1);
		printf("\nThe graph can have a maximum of %d edges\n\n", maxEdges);

		for(int i=0; i<maxEdges;) 
		{
			printf("\nEnter two negative numbers to exit..\n\n");
			printf("\nenter initial vertex and final vertex for edge %d(initialVertex-finalVertex): ", i+1);
			scanf("%d-%d", &initialVertex, &finalVertex);

			if(initialVertex<0 && finalVertex<0)
			{
				printf("\nAdjacency matrix created!!!\n\n");
				break;
			}

			else if(initialVertex>=numVertices && finalVertex>=numVertices)
			{
				printf("\n\nInvalid vertices!!\n\n");
				continue;
			}

			else
			{
				adjMatrix[initialVertex][finalVertex]=1;
			}

			i++;
		}
	}


	return true;
}

void showadj(int numVertices)
{
	printf("        v%d\t", 0);

	for(int j=1; j<numVertices; j++)
		printf("v%d\t", j);
	printf("\n");

	for(int i=0; i<numVertices; i++)
	{
		printf("v%d\t", i);
		for(int j=0; j<numVertices; j++)
			printf("%d\t", adjMatrix[i][j]);
		printf("\n");
	}
}

#endif
