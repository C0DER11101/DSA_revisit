#ifndef DFS_H
#define DFS_H

void dfs(int startV, int numV)
{
	push(startV);
	pred[startV]=-1; // predecessor of starting vertex is -1

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
				pred[i]=startV;
				push(i);
			}
		}

	}


}

void SpanningTree(int numV)
{
	printf("\n\nSpanning tree edges:\nPredecessors and their successors:\n\n");

	for(int i=0; i<numV; i++)
	{
		if(pred[i]==-1)
			printf("%d\n", i);
		else
			printf("%d->%d\n", pred[i], i);
	}
}


#endif
