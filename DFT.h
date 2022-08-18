// DEPT FIRST TRAVERSAL

#ifndef DFT_H
#define DFT_H

void dft(int startV, int numV)
{
	// In stack implementation of DFS, each vertex has two states 'initial' and 'visited'
	// when a vertex is popped from the stack, then its state changes to 'visited'.

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


	// restoring the states of each vertex
	
	for(int i=0; i<numV; i++)
		state[i]=initial;
}
#endif
