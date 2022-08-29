#ifndef P_H
#define P_H

/* --- COMMON FUNCTIONS FOR DIJKSTRA'S ALGORITHM AND BELLMAN FORD ALGORITHM --- */
void shortestPath(int sourceV, int dstV)
{
	if(pred[dstV]==-1 && dstV==sourceV)
	{
		printf("\n\nPath length of source vertex is %d\n", pathLen[sourceV]);
		return;
	}

	else if(pathLen[dstV]==INF)
	{
		printf("\nthere is no path between %d and %d\n", sourceV, dstV);
		return;
	}

	for(int i=dstV; i!=-1; i=pred[i])
	{
		SPath[Spidx]=i;
		Spidx++;
	}

	for(int i=Spidx-1; i>=0; i--)
	{
		printf("%d->", SPath[i]);
	}

	printf("X\n");
	printf("Length = %d\n", pathLen[dstV]);

	Spidx=0;
}


void showPathLen(int numV)
{
	for(int i=0; i<numV; i++)
		printf("Vertex %d\nPath length = %d\n", i, pathLen[i]);
}

void showPred(int numV)
{
	for(int i=0; i<numV; i++)
	{
		if(pred[i]!=-1)
			printf("%d -> %d\n", pred[i], i);
	}
}
/* --- END --- */

#if DJKAL == 1
/* --- DIJKSTRA'S ALGORITHM --- */
bool arePermanent(int numV)
{
	for(int i=0; i<numV; i++)
	{
		if(STATE[i]==Temp)
			return false;
	}

	return true;
}

void GetPath(int sV, int numV)
{
	int current=sV, tempV=sV, small=INF;
	pathLen[current]=0;
	STATE[current]=Perm;

	while(!arePermanent(numV))
	{
		for(int i=0; i<numV; i++)
		{
			if(adj[current][i]==1 && STATE[i]==Temp)
			{
				if((pathLen[current]+Weight(current, i))<pathLen[i])
				{
					pathLen[i]=pathLen[current]+Weight(current, i);
					pred[i]=current;
				}
			}
		}

		// out of the adjacent temporary vertices of current, find the one with the smallest path length
		for(int i=0; i<numV; i++)
		{
			if(adj[current][i]==1 && STATE[i]==Temp)
			{
				if(pathLen[i]<small)
				{
					tempV=i;
					small=pathLen[i];
				}
			}
		}


		if(tempV==current) // if current vertex doesnot have any adjacent vertices or all its adjacent vertices are in permanent state!!
		{
			for(int i=0; i<numV; i++)
			{
				if(pathLen[i]<=small && STATE[i]==Temp)
				{
					tempV=i;
					small=pathLen[i];
				}
			}
		}

		current=tempV;
		STATE[current]=Perm;
		small=INF;
	}
}
/* --- END --- */



#else
/* --- BELLMAN FORD ALGORITHM --- */
void GetPath(int sourceV, int numV)
{
	int current=sourceV;
	pathLen[current]=0; // pathlength of the source vertex is always 0
	nq(current); // enqueue the source vertex into the queue!!
	pred[current]=-1;
	signal[current]=present; // source vertex is present in the queue!!
	vertexInsertnFreq[current]++;

	while(Front()!=-1)
	{
		current=dq();
		signal[current]=absent; // vertex is absent from the queue!!

		// search for adjacent vertices of current

		for(int i=0; i<numV; i++)
		{
			if(adj[current][i]==1) // current has adjacent vertices
			{
				if((pathLen[current]+Weight(current, i))<pathLen[i]) // found pathlength tha's less than pathlength of vertex i
				{
					pathLen[i]=pathLen[current]+Weight(current, i);
					pred[i]=current;

					if(signal[i]==absent) // vertex i is absent from queue
					{
						nq(i);
						if(vertexInsertnFreq[i]>=numV) // Bellman Ford Algorithm doesnot work for negative cycles!!
						{
							printf("\n\ngraph has negative cycle!!\n\n");
							return;
						}

						vertexInsertnFreq[i]++;
						signal[i]=present;
					}
				}
			}
		}
	}
}

/* --- END --- */
#endif
#endif
