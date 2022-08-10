#ifndef CTREE_H
#define CTREE_H

struct tree
{
	char data;
	struct tree*left;
	struct tree*right;
};

typedef struct tree tree;

tree*ctree(tree*root, char ch, char*inorder, int idx)
{
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=ch;
		root->left=NULL;
		root->right=NULL;

		return root;
	}

	int idxR=retInd(root->data, inorder);

	if(idx<idxR)
	{
		root->left=ctree(root->left, ch, inorder, idx);

		return root;
	}

	else
	{
		root->right=ctree(root->right, ch, inorder, idx);

		return root;
	}
}

tree*createTree(tree*root, char*inorder, char*postorder)
{
	for(int i=strlen(postorder)-1; i>=0; i--)
	{
		for(int j=0; j<strlen(inorder); j++)
		{
			if(postorder[i]==inorder[j])
				root=ctree(root, postorder[i], inorder, j);
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
