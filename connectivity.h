#ifndef CNTVT_H
#define CNTVT_H

void Times(int numV)
{
	for(int i=0; i<numV; i++)
	{
		printf("Vertex %d\n", i);
		printf("Starting time: %d\n", startTime[i]);
		printf("Finishing time: %d\n", finishTime[i]);
	}
}

void revGraph(int numV)
{
	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(adj[i][j]==1)
				revAdj[j][i]=1;
		}
	}
}

void dfs(int startV, int numV)
{
	printf("%d ", startV);
	state[startV]=visited;

	for(int i=0; i<numV; i++)
	{
		if(adj[startV][i]==1 && state[i]==initial)
			dfs(i, numV);
	}
}

void dfsRevGraph(int startV, int numV)
{
	if(state[startV]==initial)
	{
		printf(" %d ", startV);
		state[startV]=visited;
	}

	for(int i=0; i<numV; i++)
	{
		if(revAdj[startV][i]==1 && state[i]==initial)
			dfsRevGraph(i, numV);
	}
}

bool areVisited(int numV)
{
	for(int i=0; i<numV; i++)
	{
		if(state[i]==initial)
			return false;
	}

	return true;
}

void findComponents(int numV)
{
	int large=0, vertex=0;

	while(areVisited(numV)!=true)
	{
		printf("{");
		for(int i=0; i<numV; i++)
		{
			if(large<=finishTime[i] && state[i]==initial)
			{
				vertex=i;
				large=finishTime[i];
			}
		}

		dfsRevGraph(vertex, numV);
		printf("}\n");
		large=0;
	}
}


void DFS(int startV, int count, int numV) // for finding the strongly connected components!!
{
	TIME++;
	printf("%d ", startV);
	state[startV]=visited;
	startTime[startV]=TIME;

	for(int i=0; i<numV; i++)
	{
		if(adj[startV][i]==1 && state[i]==initial)
			DFS(i, count+1, numV);
	}

	if(count==0) // count keeps track of the number of vertices traversed(in a graph component)!
	{
		TIME++; // allocate the finishing time to the starting vertex(the one from which the actual traversal began) and then search for a new starting vertex
		finishTime[startV]=TIME;
		for(int i=0; i<numV; i++)
		{
			if(state[i]==initial)
			{
				startV=i;
				DFS(startV, count, numV);
			}
		}

	}

	else
	{
		TIME++;
		finishTime[startV]=TIME;
	}
}



#endif
