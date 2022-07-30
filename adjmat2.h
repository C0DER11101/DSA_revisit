#ifndef ADJ_H
#define ADJ_H
#define MAX 100

int AdjMat[MAX][MAX];

void re_initialize(int numv, char type)
{
	int maxEdges;
	if(type=='u')
	{
		maxEdges=numv*(numv-1)/2;

		for(int i=0; i<maxEdges; i++)
			for(int j=0; j<maxEdges; j++)
				AdjMat[i][j]=0;

	}

	else if(type=='d') // 'd' for 'directed graph'
	{
		maxEdges=numv*(numv-1);

		for(int i=0; i<maxEdges; i++)
			for(int j=0; j<maxEdges; j++)
				AdjMat[i][j]=0;
	}
}

void insertEdge(int numv, char type)
{
	int initialvertex, finalvertex, maxEdges;

	if(type=='u')
	{
		maxEdges=numv*(numv-1)/2;
		printf("enter initial and final vertices(initial-final): ");
		scanf("%d-%d", &initialvertex, &finalvertex);

		if(initialvertex<0 || finalvertex<0)
		{
			printf("\n\ninvalid initial or final vertex!!\n\n");
			return;
		}

		else if(initialvertex>=numv || finalvertex>=numv)
		{
			printf("\n\nvertices should be in the range [%d, %d]\n\n", 0, maxEdges-1);
			return;
		}

		else
		{
			AdjMat[initialvertex][finalvertex]=1;
			AdjMat[finalvertex][initialvertex]=1;
		}
	}

	else if(type=='d') // 'd' for 'directed graph'
	{
		maxEdges=numv*(numv-1);
		printf("enter initial and final vertices(initial-final): ");
		scanf("%d-%d", &initialvertex, &finalvertex);

		if(initialvertex<0 || finalvertex<0)
		{
			printf("\n\ninvalid initial or final vertex!!\n\n");
			return;
		}

		else if(initialvertex>=numv || finalvertex>=numv)
		{
			printf("\n\nvertices should be in the range [%d, %d]\n\n", 0, maxEdges-1);
			return;
		}

		else
		{
			AdjMat[initialvertex][finalvertex]=1;
		}
	}

	else
	{
		printf("\n\nNo graph type\n\n");
		return;
	}
}

void deleteEdge(int numv, char type)
{
	int initialvertex, finalvertex, maxEdges;

	if(type=='u')
	{
		printf("enter initial and final edges(initial-final): ");
		scanf("%d-%d", &initialvertex, &finalvertex);

		maxEdges=numv*(numv-1)/2;
		if(initialvertex<0 || finalvertex<0)
		{
			printf("\n\ninvalid initial or final vertex!!\n\n");
			return;
		}

		else if(initialvertex>=numv || finalvertex>=numv)
		{
			printf("\n\nvertices should be in the range [%d, %d]\n\n", 0, maxEdges-1);
			return;
		}

		else
		{
			AdjMat[initialvertex][finalvertex]=0;
			AdjMat[finalvertex][initialvertex]=0;
		}
	}

	else if(type=='d')
	{
		printf("enter initial and final edges(initial-final): ");
		scanf("%d-%d", &initialvertex, &finalvertex);
		maxEdges=numv*(numv-1);

		if(initialvertex<0 || finalvertex<0)
		{
			printf("\n\ninvalid initial or final vertex!!\n\n");
			return;
		}

		else if(initialvertex>=numv || finalvertex>=numv)
		{
			printf("\n\nvertices should be in the range [%d, %d]\n\n", 0, maxEdges-1);
			return;
		}

		else
		{
			AdjMat[initialvertex][finalvertex]=0;
		}
	
	}

	else
	{
		printf("\n\nno graph type specified!!\n\n");
	}
}

void showadj(int numv)
{
	printf("        v%d\t", 0);

	for(int j=1; j<numv; j++)
		printf("v%d\t", j);
	printf("\n");

	for(int i=0; i<numv; i++)
	{
		printf("v%d\t", i);
		for(int j=0; j<numv; j++)
			printf("%d\t", AdjMat[i][j]);
		printf("\n");
	}
}

#endif
