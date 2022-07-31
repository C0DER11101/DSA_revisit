#ifndef BST_H
#define BST_H

struct node
{
	int key;
	struct node*right;
	struct node*left;
};

typedef struct node node;

/* --- loop version of insertKey() !Not sure if this works, never tried it!
 * void insertKey(node*r, int value)
 * {
 * 	node*prev, node*copy=r;
 *
 * 	while(r!=NULL)
 * 	{
 		prev=r

		if(value<r->key)
			r=r->left;
		else if(value>r->key)
			r=r->right;
	}

	if(value<prev->key)
	{
		r=(node*)malloc(sizeof(node));
		r->key=value;
		prev->left=r;
	}

	else if(value>prev->key)
	{
		r=(node*)malloc(sizeof(node));
		r->key=value;
		prev->right=r;
	}

	r=copy; // restoring the r of the tree!!
   }

*/

node*insertKey(node*r, int value)
{
	if(r==NULL)
	{
		r=(node*)malloc(sizeof(node));
		r->key=value;
		r->left=NULL;
		r->right=NULL;

		return r;
	}

	if(value<r->key)
	{
		r->left=insertKey(r->left, value);
		return r;
	}

	else if(value>r->key)
	{
		r->right=insertKey(r->right, value);
		return r;
	}
	
	else if(value==r->key)
	{
		printf("\n\nduplicate keys are not allowed!!\n\n");
		return r;
	}
}

node*deleteKey(node*r, int value)
{
	if(r==NULL)
	{
		printf("\n\nEither the tree is empty or the node to be deleted doesnot exist in the tree!!\n\n");
		return r;
	}

	if(value<r->key)
	{
		r->left=deleteKey(r->left, value);
		return r;
	}

	else if(value>r->key)
	{
		r->right=deleteKey(r->right, value);
		return r;
	}

	else if(value==r->key)
	{
		if(r->left==NULL && r->right==NULL) // working okay!!
		{
			free(r);
			return NULL;
		}

		else if(r->left==NULL && r->right!=NULL) // working okay!!
		{
			node*temp=r;
			r=r->right;
			free(temp);

			return r;
		}

		else if(r->left!=NULL && r->right==NULL) // working okay!!
		{
			node*temp=r;

			r=r->left;

			free(temp);

			return r;
		}

		else if(r->left!=NULL && r->right!=NULL) // node to be deleted has two chlidren
		{
			node*temp=r, *prev;

			if(r->right->left==NULL) // checking if right child of r is the inorder successor!!
			{
				r->key=r->right->key;
				if(r->right->right==NULL)
				{
					temp=r->right;
					free(temp);

					r->right=NULL;
				}

				else if(r->right->right!=NULL)
				{
					temp=r->right;
					node*t=temp;
					r->right=temp->right;
					free(temp);
				}

				return r;
			}

			temp=temp->right;
			prev=temp;

			while(temp->left!=NULL) // finding the inorder successor!!
			{
				prev=temp;
				temp=temp->left;
			}

			if(temp->right==NULL)
			{
				r->key=temp->key;

				free(temp);
				prev->left=NULL;

				return r;
			}

			else if(temp->right!=NULL)
			{
				node*t=temp;
				r->key=temp->key;
				temp=temp->right;
				prev->left=temp;
				free(t);

				return r;
			}

		}
	}

} 

int height(node*r)
{
	int hL, hR;

	if(r==NULL)
		return 0;


	hL=1+height(r->left);
	hR=1+height(r->right);

	if(hL>hR)
		return hL;
	else
		return hR;
}

void inorder(node*r)
{
	if(r==NULL)
		return;

	inorder(r->left);
	printf("%d ", r->key);
	inorder(r->right);
}

void preorder(node*r)
{
	if(r==NULL)
		return;

	printf("%d ", r->key);
	preorder(r->left);
	preorder(r->right);
}

void postorder(node*r)
{
	if(r==NULL)
		return;

	postorder(r->left);
	postorder(r->right);
	printf("%d ", r->key);
}

void terminate(node*r)
{
	if(r==NULL)
		return;
	terminate(r->left);
	terminate(r->right);
	free(r);
}


#endif
