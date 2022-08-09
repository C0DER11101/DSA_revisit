// COMPUTING THE PATH MATRIX!!

#ifndef PMAT_H
#define PMAT_H
#define MAX 100

int pathMat[MAX][MAX], addMat[MAX][MAX], multMat[MAX][MAX][MAX];

int check(int numV) // check if path matrix has been calculated or not!!
{
	int filled=-1;
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(addMat[i][j]!=0)
			{
				filled=1;
				break;
			}
		}
	}

	return filled;

}

void powerAdj(int numV) // calculates the powers of the adjacency matrix of the graph
{
	for(int i=0; i<numV-1; i++)
	{
		for(int j=0; j<numV; j++)
		{
			for(int k=0; k<numV; k++)
			{
				for(int m=0; m<numV; m++)
				{
					if(i==0)
					{
						multMat[i][j][k]+=adjMatrix[j][m]*adjMatrix[m][k];
					}

					else
					{
						multMat[i][j][k]+=multMat[i-1][j][m]*adjMatrix[m][k];
					}
				}
			}
		}
	}

	printf("\n\nshowing the powers of the adjacency matrix....\n\n");

	printf("AM1\n");
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
			printf("%d ", adjMatrix[i][j]);
		printf("\n");
	}


	for(int i=0; i<numV-1; i++)
	{
		printf("\nAM%d\n\n", i+2);
		for(int j=0; j<numV; j++)
		{
			for(int k=0; k<numV; k++)
			{
				printf("%d ", multMat[i][j][k]);
			}

			printf("\n");
		}
		printf("\n\n");
	}
}

void PathMatrix(int numV)
{
	int Allones=1, diagones=1;
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(pathMat[i][j]==0)
				Allones=0;
			if(pathMat[i][j]==0)
				diagones=0;
			printf("%d ", pathMat[i][j]);
		}

		printf("\n");
	}


	if(Allones==1) // if all the elements of the path matrix are ones
	{
		printf("\nthe graph is a strongly connected graph!!\n\n");
		return;
	}

	if(diagones==1) // if only the diagonal elements are ones
	{
		printf("\nthe graph has a cycle!!\n\n");
		return;
	}
}

void addPow(int numV) // add the powers of the adjacency matrix
{
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			for(int k=0; k<numV; k++)
			{
				addMat[j][k]+=multMat[i][j][k];
			}
		}
	}

	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(addMat[i][j]!=0)
				pathMat[i][j]=1;
			/* where the sum of the powers of the adjacency matrix is non-zero, the corresponding element will
			 * be 1 in the path matrix
			 */
		}
	}

}

#endif
