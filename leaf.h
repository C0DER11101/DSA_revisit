// HEADER FILE TO SHOW THE LEAF NODES OF A TREE!!

#ifndef LEAF_H
#define LEAF_H

void leafnd(tree*root)
{
	if(root==NULL)
		return;

	leafnd(root->left);

	if(root->left==NULL && root->right==NULL)
	{
		printf("%d ", root->data);
		return;
	}

	leafnd(root->right);
	
}

#endif
