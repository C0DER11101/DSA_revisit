#ifndef DFS_H
#define DFS_H

#if TYPE==1 // 1 is for directed graphs
void dfs(int startV, int numV)
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
                printf("%d->%d\n", pred[j], i);
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

#else

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
