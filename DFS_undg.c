#include<stdio.h>
#include<stdlib.h>
#include "maxm.h"
#include "stack.h"
#include "GraphMat.h"
#include "dfs.h"

int main(void)
{
    int opt, numV, iV, tV, maxEdge, startV;

    printf("enter number of vertices: ");
    scanf("%d", &numV);

    maxEdge=numV*(numV-1)/2; // for undirected graph!!

    while(1)
    {
        printf("\n\n---menu---\n");
        printf("1. Insert edge.\n");
        printf("2. Display adjacency matrix.\n");
        printf("3. DFS.\n");
        printf("4. Exit.\n");
        printf("<option> ");
        scanf("%d", &opt);

        switch(opt)
        {
        case 1:
            printf("enter edge %d: ", edgeCount+1);
            scanf("%d %d", &iV, &tV);

            if(iV>=maxEdge || tV>=maxEdge)
            {
                printf("\n\ninvalid edge!!\n\n");
                break;
            }
            status=edge(iV, tV);

            if(status==ERR)
            {
                printf("\ninvalid edge!!\n\n");
                break;
            }

            edgeCount++;
            break;

        case 2:
            showadj(numV);
            break;

        case 3:
            printf("enter start vertex: ");
            scanf("%d", &startV);
            dfs(startV, numV);
            break;

        case 4:
            printf("\n\nquitting....\n\n");
            exit(0);

        default:
            INVALID;
        }
    }

    return 0;
}
