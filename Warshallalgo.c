#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "MATS.h"
#include "Warshall.h"

int main(void)
{
	int opt, numV;

	printf("enter number of vertices: ");
	scanf("%d", &numV);


	printf("\n\nthe graph will have a maximum of %d edges!!\n\n", numV*(numV-1));

	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Insert edges.\n");
		printf("2. Find the transitive closure matrix using Warshall's Algorithm.\n");
		printf("3. Display the path matrix.\n");
		printf("4. Display the adjacency matrix.\n");
		printf("5. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				insertEdges(numV, numV*(numV-1));
				break;

			case 2:
				createPM(numV);
				break;

			case 3:
				PathMrx(numV);
				break;

			case 4:
				showadj(numV);
				break;

			case 5:
				exit(0);

			default:
				printf("\n\ninvalid option!!!\n\n");
		}
	}
	return 0;
}
