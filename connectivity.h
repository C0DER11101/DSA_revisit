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


void DFS(int startV, int count, int numV)
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
