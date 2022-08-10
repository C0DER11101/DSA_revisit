#ifndef TREEIO_H
#define TREEIO_H

struct tree
{
	int data;
	struct tree*left;
	struct tree*right;
};

typedef struct tree tree;


/* take input from the user */
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

	else
	{
		root->right=enter(root->right, val);
		return root;
	}

}
/* -- END -- */

/* traverse the tree*/
void preorder(tree*root)
{
	if(root==NULL)
		return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(tree*root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(tree*root)
{
	if(root==NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}
/* -- END -- */

/* free all the nodes */
void terminate(tree*root)
{
	if(root==NULL)
		return;

	terminate(root->left);
	terminate(root->right);
	free(root);
}
/* -- END -- */

#endif
