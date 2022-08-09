#ifndef DGRAPH_H
#define DGRAPH_H
#define MAX 100

int adjMatrix[MAX][MAX];

void createAdj(int n, int mxEd)
{
	int initV, dstV;
	printf("enter edges between vertices: ");
	printf("enter two negative numbers to stop giving input:\n");

	for(int i=0; i<mxEd;)
	{
		printf("Edge %d\n", i+1);
		printf("enter two vertices(v1-v2): ");
		scanf("%d-%d", &initV, &dstV);

		if(initV<0 && dstV<0)
		{
			printf("\n--STOPPED--\n");
			return;
		}

		if(initV>=mxEd || dstV>=mxEd)
		{
			printf("\n\ninvalid vertices!!\n\n");
			continue;
		}

		adjMatrix[initV][dstV]=1;
		i++;
	}

}

void showAdj(int nV)
{
	printf("\n\nADJACENCY MATRIX!!\n\n");
	printf("        v%d\t", 0);

	for(int j=1; j<nV; j++)
		printf("v%d\t", j);
	printf("\n");

	for(int i=0; i<nV; i++)
	{
		printf("v%d\t", i);
		for(int j=0; j<nV; j++)
			printf("%d\t", adjMatrix[i][j]);
		printf("\n");
	}
}
#endif
