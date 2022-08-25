#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "maxm.h"
#include "GraphMat.h"
#include "connectivity.h"

int main(void)
{
        int opt, numV, iV, tV, maxEdge, startV;
        
        printf("enter number of vertices: ");
        scanf("%d", &numV);
        
        maxEdge=numV*(numV-1);
        
        printf("Maximum edges of directed graph: %d\n", maxEdge);
        
        while(1)
        {
                printf("\n\n---menu---\n");
                printf("1. Insert edge.\n");
                printf("2. Show adjacency matrix.\n");
                printf("3. Check connectivity of graph.\n");
                printf("4. Find strongly connected components(if any).\n");
                printf("5. Exit.\n");
                printf("<option> ");
                scanf("%d", &opt);
                
                switch(opt)
                {
                        case 1:
                                if(edgeCount>=maxEdge)
                                {
                                        printf("\n\ncannot enter anymore edges!!\n\n");
                                        break;
                                }
                                
                                printf("enter edge %d: ", edgeCount+1);
                                scanf("%d %d", &iV, &tV);
                                
                                if(iV>=numV || tV>=numV)
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
                                printf("\n\nADJACENCY MATRIX\n\n");
                                showadj(numV);
                                break;
                                
                        case 3:
                                break;
                                
                        case 4:
                                printf("enter start vertex: ");
                                scanf("%d", &startV);
                                
                                DFS(startV, 0, numV);
                                printf("\n");
                                Times(numV);
                                break;
                                
                        case 5:
                                break;
                                
                        case 6:
                                printf("\n\nquitting...\n\n");
                                exit(0);
                                
                        default:
                                INVALID;
                }
        }
        
        return 0;
}
