#ifndef TreeINP_H
#define TreeINP_H

tree*enter(tree*root, int val)
{
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=val;
		root->left=NULL;
		root->right=NULL;

		return root;
	}

	if(val<root->data)
	{
		root->left=enter(root->left, val);
		return root;
	}

	else if(val>root->data)
	{
		root->right=enter(root->right, val);
		return root;
	}

}

#endif
