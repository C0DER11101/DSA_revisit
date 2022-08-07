#ifndef MAT_H
#define MAT_H
#define MAX 100

int mat[MAX][MAX][MAX];

void initMat(int num, int row, int col)
{
	for(int i=0; i<num; i++)
	{
		printf("enter values for matrix %d\n", i+1);

		for(int j=0; j<row; j++)
		{
			for(int k=0; k<col; k++)
			{
				printf("[%d][%d]: ", j, k);
				scanf("%d", &mat[i][j][k]);
			}
		}
	}

}

void dispMat(int num, int row, int col)
{
	for(int i=0; i<num; i++)
	{
		printf("\nvalues of matrix %d\n", i+1);

		for(int j=0; j<row; j++)
		{
			for(int k=0; k<col; k++)
			{
				printf("%d ", mat[i][j][k]);
			}
			printf("\n");
		}


		printf("\n");
	}

}
#endif
