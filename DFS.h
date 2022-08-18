#ifndef DFS_H
#define DFS_H

void dfs(int startV, int numV)
{

	while(state[startV]==initial)
	{
		push(startV);
		while(Top()!=-1)
		{
			startV=pop();
			if(state[startV]==initial)
				printf("%d ", startV);

			state[startV]=visited;

			for(int i=0; i<numV; i++)
			{
				if(adj[startV][i]==1 && state[i]==initial)
					push(i);
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
}
#endif
