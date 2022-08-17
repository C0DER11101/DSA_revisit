#ifndef BFS_UNG_H // BFS FOR UNDIRECTED GRAPH!
#define BFS_UNG_H

void bfs(int startV, int numV)
{
	nq(startV);
	state[startV]=waiting;

	while(Front()!=-1)
	{
		startV=dq();
		state[startV]=visited;
		printf("%d ", startV);

		for(int i=0; i<numV; i++)
		{
			if(adj[startV][i]==1 and state[i]==initial)
			{
				nq(i);
				state[i]=waiting;
			}
		}
	}


	// restoring the states
	
	for(int i=0; i<numV; i++)
		state[i]=initial;
}
#endif
