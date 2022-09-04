#include<stdio.h>
#include<stdlib.h>
#include "Practice.h"
#include "RevHeader.h"
#include "Struct.h"
#include "Queue.h"
#include "LevelTraverse.h"


int main(void)
{
	int size;

	tree*root=NULL;

	printf("enter number of nodes in the tree: ");
	scanf("%d", &size);

#if dtype==2
	printf("enter the elements in inorder sequence(only characters, not integers):\n");

	for(int i=0; i<size; i++)
	{
		printf(">");
		scanf(" %c", &inorder[i]);
	}
	getchar();

	printf("enter the elements in preorder sequence:\n");

	for(int i=0; i<size; i++)
	{
		printf(">");
		scanf(" %c", &preorder[i]);
	}

#else
	printf("enter the elements in inorder sequence(only integers, not characters): ");

	for(int i=0; i<size; i++)
	{
		printf(">");
		scanf("%d", &inorder[i]);
	}

	printf("enter the elements in preorder sequence: ");

	for(int i=0; i<size; i++)
	{
		printf(">");
		scanf("%d", &preorder[i]);
	}

#endif

	// creating the binary tree from inorder and preorder traversals!!

	for(int i=0; i<size; i++) // for preorder
	{
		for(int j=0; j<size; j++) // for inorder
		{
			if(preorder[i]==inorder[j])
				root=insert(root, j);
		}
	}

	printf("\nPreorder traversalA:\n\n");
	Preorder(root);

	printf("\nInorder traversal:\n");
	Inorder(root);

	printf("\nPostorder traversal:\n");
	Postorder(root);


	printf("\n\nthe level order traversal of the tree is:\n\n");
	LevelTrav(root);

	terminate(root);
	printf("\n");

	return 0;
}
