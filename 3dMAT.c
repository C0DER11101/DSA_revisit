#include<stdio.h>
#include "3dmat.h"

int main(void)
{
	int n, r, c;

	printf("enter number of 2-d matrices: ");
	scanf("%d", &n);

	printf("enter number of rows and columns(r-c): ");
	scanf("%d-%d", &r, &c);

	initMat(n, r, c);

	printf("\n\ndisplaying the matrix....\n\n");


	dispMat(n, r, c);


	return 0;
}
