#ifndef GRAPH_MAT
#define GRAPH_MAT

// HEADER FILE FOR ADJACENCY MATRIX!!!

int adj[MAX][MAX];

#if TYPE==1 // 1 is for directed graph (TYPE is defined in "maxm.h")
int edge(int iV, int tV)
{
        if(iV<0 || tV<0)
                return ERR;
        
        else
                adj[iV][tV]=1;
        
        return OK;
}

#else

int edge(int iV, int tV)
{
        if(iV<0 || tV<0)
                return ERR;
        
        else
        {
                adj[iV][tV]=1;
                adj[tV][iV]=1;
        }
        
        return OK;
}
#endif

void showadj(int numV)
{
        printf("        v%d\t", 0);
        
        for(int j=1; j<numV; j++)
                printf("v%d\t", j);
        printf("\n");
        
        for(int i=0; i<numV; i++)
        {
                printf("v%d\t", i);
                for(int j=0; j<numV; j++)
                        printf("%d\t", adj[i][j]);
                printf("\n");
        }
}

#endif
