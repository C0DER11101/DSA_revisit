#ifndef GRAPH_MAT // Graph Materials!!
#define GRAPH_MAT


void restoreState(int numV) // restore the states of each vertex!!!
{
	for(int i=0; i<numV; i++)
		state[i]=initial;
}

#if TYPE==1 // 1 is for directed graph (TYPE is defined in "maxm.h")
int edge(int iV, int tV)
{
	if(iV<0 || tV<0)
		return ERR;

	else
		adj[iV][tV]=1;

	return OK;
}

void GetWeight(int iV, int tV)
{
	int w;
enterWeight:
	printf("\nenter weight of the edge(%d,%d): ", iV, tV);
	scanf("%d", &w);

#if DJKAL == 1
	if(weight<0)
	{
		printf("\n\nDijkstra's algorithm doesnot work on negative weights!!\n\n");
		goto enterWeight;
	}

	else
	{
		weight[iV][tV]=w;
	}

#else
	weight[iV][tV]=w;

#endif

}


#else

int edge(int iV, int tV)
{
	if(iV<0 || tV<0)
		return ERR;

	else
	{
		adj[iV][tV]=1;
		adj[tV][iV]=1;
	}

	return OK;
}
#endif

void showadj(int numV)
{
	printf("        v%d\t", 0);

	for(int j=1; j<numV; j++)
		printf("v%d\t", j);
	printf("\n");

	for(int i=0; i<numV; i++)
	{
		printf("v%d\t", i);
		for(int j=0; j<numV; j++)
			printf("%d\t", adj[i][j]);
		printf("\n");
	}
}


void showWeight(int numV)
{
	printf("        v%d\t", 0);

	for(int j=1; j<numV; j++)
		printf("v%d\t", j);
	printf("\n");

	for(int i=0; i<numV; i++)
	{
		printf("v%d\t", i);
		for(int j=0; j<numV; j++)
			printf("%d\t", weight[i][j]);
		printf("\n");
	}
}

int Weight(int iV, int tV)
{
	return weight[iV][tV];
}

#endif
