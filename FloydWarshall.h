#ifndef FW_H
#define FW_H

void fw(int numV)
{
	/* any element D[i][j] is defined as:
	 *            _____
	 *           |
	 *           | weight of the edge from vertex i to vertex j
	 *           |
	 * D[i][j]= <
	 *           |
	 *           | infinity, if there is no edge from vertex i to vertex j
	 *           |
	 *            -----
	 */

	// D-1

	for(int i=0; i<numV;i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(weight[i][j]==0)
			{
				d[i][j]=INF;
				predV[i][j]=-1;
			}

			else
			{
				d[i][j]=weight[i][j];
				predV[i][j]=i;
			}
		}
	}


	// D0, D1, ...., DnumV-1

	for(int k=0; k<numV; k++)
	{
		for(int i=0; i<numV; i++)
		{
			for(int j=0; j<numV; j++)
			{
				if(k==0)
				{
					if(d[i][k]!=INF && d[k][j]!=INF)
					{

						if(d[i][k]+d[k][j]<d[i][j])
						{
							D[k][i][j]=d[i][k]+d[k][j];
							Pred[k][i][j]=k;
						}

						else
						{
							D[k][i][j]=d[i][j];
							Pred[k][i][j]=predV[i][j];
						}
					}

					else
					{
						D[k][i][j]=d[i][j];
						Pred[k][i][j]=predV[i][j];
					}
				}

				else
				{
					if(D[k-1][i][k]!=INF && D[k-1][k][j]!=INF)
					{
						if(D[k-1][i][k]+D[k-1][k][j]<D[k-1][i][j])
						{
							D[k][i][j]=D[k-1][i][k]+D[k-1][k][j];
							Pred[k][i][j]=k;
						}

						else
						{
							D[k][i][j]=D[k-1][i][j];
							Pred[k][i][j]=Pred[k-1][i][j];
						}
					}

					else
					{
						D[k][i][j]=D[k-1][i][j];
						Pred[k][i][j]=Pred[k-1][i][j];
					}
				}
			}
		}
	}
}


void showMat(int numV)
{
	printf("\n\nThe shortest path matrices:\n\n");

	for(int k=0; k<numV; k++)
	{
		for(int i=0; i<numV; i++)
		{
			for(int j=0; j<numV;j++)
			{
				printf("%d ", D[k][i][j]);
			}

			printf("\n");
		}

		printf("\n\n");
	}



	printf("\n\nPredecessors:\n\n");

	for(int k=0; k<numV; k++)
	{
		for(int i=0; i<numV; i++)
		{
			for(int j=0; j<numV; j++)
			{
				printf("%d ", Pred[k][i][j]);
			}

			printf("\n");
		}

		printf("\n\n");
	}
}

#endif
