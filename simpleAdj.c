#include<stdio.h>
#include "DgraphAdjM.h"
#include "PMatrix.h"


int main(void)
{
	int numV;

	printf("\n\nFOR DIRECTED GRAPH!!\n\n");
	printf("enter number of vertices: ");
	scanf("%d", &numV);

	printf("\n\nthe directed graph can have a maximum of %d edges!!\n\n", numV*(numV-1));

	printf("create the adjacency matrix: ");
	
	createAdj(numV, numV*(numV-1));

	showAdj(numV);

	powerAdj(numV);


	return 0;
}
