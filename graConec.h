#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

bool isConnected(int startV, int numV)
{
	nq(startV);
	state[startV]=waiting;

	while(Front()!=-1)
	{
		startV=dq();
		state[startV]=visited;

		for(int i=0; i<numV; i++)
		{
			if(adj[startV][i]==1 && state[i]==initial && adj[startV][i]!=0)
			{
				nq(i);
				state[i]=waiting;
			}
		}

		if(Front()==-1 && state[numV-1]==initial) // there is disconnectivity in the graph
		{
			for(int i=0; i<numV; i++) // restoring the states!
				state[i]=initial;
			return false;
		}

	}

	for(int i=0; i<numV; i++) // restoring the states!
		state[i]=initial;

	return true;
}

#endif
