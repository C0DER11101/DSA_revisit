#ifndef GRAPH_MAT
#define GRAPH_MAT

// HEADER FILE FOR ADJACENCY MATRIX!!!

int adj[MAX][MAX];

int edge(int intV, int dstV)
{
	if(intV<0 && dstV<0)
	{
		printf("\n\nSTOPPED!!\n\n");
		return ERR;
	}

	else if(intV<0 || dstV<0)
	{
		printf("\n\ninvalid vertex!!\n\n");
		return ERR;
	}

	else
	{
		adj[intV][dstV]=1;
		return OK;
	}

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
			printf("%d\t", adj[i][j]);
		printf("\n");
	}
}

#endif
