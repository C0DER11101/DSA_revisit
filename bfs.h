#ifndef BFS_H
#define BFS_H

// ANY VERTEX BEFORE INSERTION INTO QUEUE IS IN INITIAL STATE. 
// AFTER ENQUEUING THAT VERTEX INTO THE QUEUE, ITS STATE CHANGES TO WAITING STATE.
// AFTER DEQUEUING THE VERTEX FROM THE QUEUE, ITS STATE AGAIN CHANGES TO VISITED STATE!!

void bfs(int val, int numV) // bfs() for assigning predecessor and distance value to each vertex
{
	// after enqueuing a vertex into the queue, we assign it a predecessor and a distance value
	nq(val);
	state[val]=waiting; // waiting state!!
	pred[val]=-1; // predecessor of starting vertex is -1(meaning starting vertex has no predecessor)
	dist[val]=0; // distance value of starting vertex is 0

	while(Front()!=-1)
	{
		val=dq();
		state[val]=visited; // visited state!!

		for(int i=0; i<numV; i++)
		{
			if(adj[val][i]==1 && state[i]==initial)
			{
				nq(i);
				pred[i]=val; // val becomes the predecessor of its adjacent vertices!!
				dist[i]=dist[val]+1; // distance value of adjacent vertex is one more than its predecessor!!
				state[i]=waiting;
			}
		}
	}


	for(int i=0; i<numV; i++) // restoring the states of the vertices!!!
		state[i]=initial;
}

#endif
