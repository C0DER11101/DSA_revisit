#ifndef RECUR_DFS_H
#define RECUR_DFS_H

void dfs(int startV, int nV)
{
	printf("%d ", startV);
	state[startV]=visited;

	for(int i=0; i<nV; i++)
	{
		if(adj[startV][i]==1 && state[i]==initial)
			dfs(i, nV);
	}

	if(state[startV]==visited) // base case -> if the no adjacent vertex in initial state exists or no adjacent vertex exists
		return;
}

void restore(int nV)
{
	for(int i=0; i<nV; i++)
		state[i]=initial;
}

#endif
