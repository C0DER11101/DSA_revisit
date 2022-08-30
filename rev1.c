#include<stdio.h>
#include<stdlib.h>
#include "RevHeader.h"
#include "Struct.h"


// construct a binary tree from inorder and preorder traversals!!
int main(void)
{
	int numNodes;

	tree*root=NULL;
	printf("enter number of nodes: ");
	scanf("%d", &numNodes);

	printf("enter nodes in inorder sequence:\n>");
	for(int i=0; i<numNodes; i++)
		scanf("%d", inorder+i);

	printf("enter the nodes in preorder sequence:\n>");
	for(int i=0; i<numNodes; i++)
		scanf("%d", preorder+i);

	// creating the binary tree!!!
	for(int i=0; i<numNodes; i++)
	{
		for(int j=0; j<numNodes; j++)
		{
			if(preorder[i]==inorder[j])
			{
				root=insert(root, j);
				break;
			}
		}
	}

	printf("\n\nPREORDER TRAVERSAL:\n\n");
	Preorder(root);
	printf("\n\nINORDER TRAVERSAL:\n\n");
	Inorder(root);
	printf("\n\nPOSTORDER TRAVERSAL:\n\n");
	Postorder(root);

	terminate(root);
	printf("\n\n");

	return 0;
}
