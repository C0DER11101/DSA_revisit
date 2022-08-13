#ifndef MAT_H
#define MAT_H
#define MAX 100

int mats[MAX][MAX][MAX], adjmat[MAX][MAX];

void insertEdges(int numV, int maxEd)
{
	int initV, dstV;
	printf("\nenter (-1 -1) to stop inserting edges!!\n\n");
	for(int i=0; i<maxEd; i++)
	{
		printf("enter initial and final vertices of edge %d: ", i+1);
		scanf("%d %d", &initV, &dstV);

		if(initV<0 && dstV<0)
		{
			printf("\n\nSTOPPED!!\n\n");
			break;
		}

		else if(initV<0 || dstV<0)
		{
			printf("\n\ninvalid vertices!!\n\n");
			i--;
		}

		else if(initV>=maxEd || dstV>=maxEd)
		{
			printf("\n\ninvalid vertices!!\n\n");
			i--;
		}

		else
		{
			adjmat[initV][dstV]=1;
		}
	}
}

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
			printf("%d\t", adjmat[i][j]);
		printf("\n");
	}
}

#endif
