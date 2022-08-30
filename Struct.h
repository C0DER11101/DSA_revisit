#ifndef Struct_H
#define Struct_H

struct tree
{
	int data;
	struct tree*left;
	struct tree*right;
};

typedef struct tree tree;

tree*insert(tree*root, int idx)
{
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=inorder[idx];
		root->left=NULL;
		root->right=NULL;

		return root;
	}

	if(idx>RetIdx(root->data))
		root->right=insert(root->right, idx);
	else
		root->left=insert(root->left, idx);

	return root;
}

void Inorder(tree*root)
{
	if(root==NULL)
		return;

	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

void Preorder(tree*root)
{
	if(root==NULL)
		return;

	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(tree*root)
{
	if(root==NULL)
		return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}

void terminate(tree*root)
{
	if(root==NULL)
		return;

	terminate(root->left);
	terminate(root->right);
	free(root);
}


#endif
