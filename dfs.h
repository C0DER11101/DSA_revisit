#ifndef DFS_H
#define DFS_H

#if TYPE==1 // 1 is for directed graphs
void dfs(int startV, int numV)
{

	while(state[startV]==initial)
	{
		push(startV);
		pred[startV]=-1;

		while(Top()!=-1)
		{
			startV=pop();
			if(state[startV]==initial)
				printf("%d ", startV);
			state[startV]=visited;

			for(int i=numV-1; i>=0; i--)
			{
				if(adj[startV][i]==1 && state[i]==initial)
				{
					push(i);
					pred[i]=startV;
				}
			}
		}

		for(int i=0; i<numV; i++)
		{
			if(state[i]==initial)
			{
				startV=i;
				break;
			}
		}
	}

	// restoring the states of the vertices

	for(int i=0; i<numV; i++)
		state[i]=initial;

}

void spanningTreeEdge(int numV)
{
	for(int i=0; i<numV; i++)
	{
		if(pred[i]!=-1)
			printf("%d->%d\n", pred[i], i);
	}
}

void backEdge(int numV)
{
	for(int i=numV-1; i>=0; i--)
	{
		for(int j=i; pred[j]!=-1; j=pred[j])
		{
			if(adj[i][pred[j]]==1 && j!=i)
				printf("%d->%d\n", i, pred[j]);
		}
	}
}

void forwardEdge(int numV)
{
	for(int i=0; i<numV; i++)
	{
		for(int j=i; pred[j]!=-1; j=pred[j])
		{
			if(adj[pred[j]][i]==1 && j!=i)
				printf("%d->%d\n", pred[j], i);
		}
	}
}

void crossEdge(int numV)
{
	bool isValid=true;

	for(int i=0; i<numV; i++)
	{
		for(int j=0; j<numV; j++)
		{
			if(adj[i][j]==1)
			{
				for(int k=pred[i]; k!=-1; k=pred[k]) // predecessor list of i
				{
					if(j==k) // j falls in the predecessor list of i then i and j cannot form cross edge!
					{
						isValid=false;
						break;
					}
				}

				if(isValid==true)
				{
					for(int k=pred[j]; k!=-1; k=pred[k]) // if i falls in the predecessor list of j then they can't form cross edge!
					{
						if(i==k)
						{
							isValid=false;
							break;
						}
					}
				}

				if(isValid==true)
					printf("%d->%d\n", i, j);
				else
					isValid=true;
			}
		}
	}
}


#else // for undirected graphs!!

void dfs(int startV, int numV)
{
	push(startV);

	while(Top()!=-1)
	{
		startV=pop();
		if(state[startV]==initial)
			printf("%d ", startV);
		state[startV]=visited;

		for(int i=numV-1; i>=0; i--)
		{
			if(adj[startV][i]==1 && state[i]==initial)
				push(i);
		}
	}
}

#endif // TYPE

#endif // DFS_H
