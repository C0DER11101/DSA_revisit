#include<stdio.h>
#include "adjmat2.h"

int main(void)
{
	int opt, vertices, maxEdges;

	char graphtype=' ';


menu:
	while(1)
	{
		printf("\n\n---menu---\n");
		printf("1. Undirected graph.\n");
		printf("2. Directed graph.\n");
		printf("3. Exit.\n");

		printf("<option> ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				if(graphtype=='d')
				{
					re_initialize(vertices, 'u');
				}

				graphtype='u'; // 'u' for 'undirected graph'

				printf("enter number of vertices: ");
				scanf("%d", &vertices);
				maxEdges=vertices*(vertices-1)/2;
				printf("\n\nThe undirected graph can have a maximum of %d edges!!\n\n", maxEdges);
submenu1:

				printf("1> Insert edge.\n");
				printf("2> Delete edge.\n");
				printf("3> Show.\n");
				printf("4> Quit to menu.\n");
				printf("<choose> ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						insertEdge(vertices, graphtype);

						goto submenu1;

					case 2:
						deleteEdge(vertices, graphtype);
						goto submenu1;

					case 3:
						showadj(vertices);
						goto submenu1;

					case 4:
						goto menu;

					default:
						printf("\n\ninvalid option!!\n\n");
				}

				break;

			case 2:

				if(graphtype=='u')
				{
					re_initialize(vertices, 'd');
				}

				graphtype='d'; // 'd' for 'directed graph'

				printf("enter number of vertices: ");
				scanf("%d", &vertices);
				maxEdges=vertices*(vertices-1);
				printf("\n\nThe directed graph can have a maximum of %d edges!!\n\n", maxEdges);
submenu2:

				printf("1> Insert edge.\n");
				printf("2> Delete edge.\n");
				printf("3> Show.\n");
				printf("4> Quit to menu.\n");
				printf("<choose> ");
				scanf("%d", &opt);

				switch(opt)
				{
					case 1:
						insertEdge(vertices, graphtype);

						goto submenu2;

					case 2:
						deleteEdge(vertices, graphtype);
						goto submenu2;

					case 3:
						showadj(vertices);
						goto submenu2;

					case 4:
						goto menu;
						
					default:
						printf("\n\ninvalid option!!\n\n");
				}

				break;

			case 3:
				printf("\n\nquitting...\n\n");
				return 0;

			default:
				printf("\n\ninvalid option!!\n\n");
		}

	}

	return 0;
}
