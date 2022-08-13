#ifndef W_H
#define W_H

int pathMat[MAX][MAX], mats[MAX][MAX][MAX];

void createPM(int numV)
{
	// creating matrices P0, P1, P2, P3,...PnumV
	
	printf("\nP-1(adjacency matrix)\n");

	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
			printf("%d ", adjmat[i][j]);
		printf("\n");
	}
	printf("\n");
	
	for(int a=0; a<numV; a++)
	{
		if(a==0) // P0
		{
			for(int i=0; i<numV; i++)
			{
				for(int j=0; j<numV; j++)
				{
					if(adjmat[i][j]==1)
					{
						mats[a][i][j]=adjmat[i][j];
					}

					else
					{
						int k=0;

						if(adjmat[i][k]==1 && adjmat[k][j]==1)
							mats[a][i][j]=1;
					}
				}
			}
		} // end of if for P0


		else // P1, P2....PnumV
		{
			for(int i=0; i<numV; i++)
			{
				for(int j=0; j<numV;j++)
				{
					if(mats[a-1][i][j]==1)
					{
						mats[a][i][j]=mats[a-1][i][j];
					}

					else
					{
						for(int k=0; k<=a; k++) // intermediate vertices!!
						{
							/* if there is no direct path from vertex i to vertex j
							 * then, there exists an intermediate vertex for which
							 * there exists a path from vertex i to vertex k and from vertex k to 
							 * vertex j
							 */

							if(mats[a-1][i][k]==1 && mats[a-1][k][j]==1)
								mats[a][i][j]=1;
						}
					}
				}
			}
		}


		printf("P%d\n", a);


		// for displaying the matrices P0, P1, .....PnumV
		for(int i=0; i<numV; i++)
		{
			for(int j=0; j<numV; j++)
				printf("%d ", mats[a][i][j]);
			printf("\n");
		}
		printf("\n");
	}


	// THE PATH MATRIX!!!!!
	for(int a=numV-1; a<numV; a++)
	{
		for(int i=0; i<numV; i++)
		{
			for(int j=0; j<numV; j++)
			{
				pathMat[i][j]=mats[a][i][j];
			}
		}
	}


}

void PathMrx(int numV)
{
	bool AllOnes=true, DiagOnes=true;
	printf("\n\nPATH MATRIX!!!\n\n");
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			printf("%d ", pathMat[i][j]);
		}

		printf("\n");
	}

	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(pathMat[i][j]==0)
			{
				AllOnes=false;
			}

			else if(pathMat[i][i]==0)
			{
				DiagOnes=false;
			}
		}
	}

	if(AllOnes==true)
		printf("\n\nThe graph is a strongly connected graph!\n\n");

	else if(DiagOnes==true)
		printf("\n\nThe graph contains cycles!\n\n");

}

#endif // W_H
