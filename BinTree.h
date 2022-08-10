#ifndef TREE_H
#define TREE_H

struct tree
{
	char data;
	struct tree*left;
	struct tree*right;
};

typedef struct tree tree;

// functions!!

tree*CTree(tree*root, char ch, char*inorder, int idx)
{
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=ch;
		root->left=root->right=NULL;

		return root;
	}

	else
	{
		int idxR=retInd(root->data, inorder);
		if(idx<idxR)
		{
			root->left=CTree(root->left, ch, inorder, idx);

			return root;
		}

		else if(idx>idxR)
		{
			root->right=CTree(root->right, ch, inorder, idx);

			return root;
		}

	}
}

tree*CreBinaT(tree*root, char*inorder, char*preorder) // traverses both, the inorder array and the preorder array
{
	tree*temp=NULL;
	for(int i=0; i<strlen(preorder); i++)
	{
		for(int j=0; j<strlen(inorder); j++)
		{
			if(preorder[i]==inorder[j])
				root=CTree(root, preorder[i], inorder,  j);
		}
	}


	return root;
}


void Preorder(tree*root)
{
	if(root==NULL)
		return;

	printf("%c ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(tree*root)
{
	if(root==NULL)
		return;

	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}

void Postorder(tree*root)
{
	if(root==NULL)
		return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->data);
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
