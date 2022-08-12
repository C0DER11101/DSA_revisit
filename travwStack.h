#ifndef TRAVSTK_H
#define TRAVSTK_H

void preorder(tree*root)
{
	if(root==NULL)
	{
		printf("\n\nthe tree is empty!!\n\n");
		return;
	}

	push(root);
	tree*temp=NULL;

	while(retTop()!=-1)
	{
		temp=pop();
		printf("%d ", temp->data);

		if(temp->right!=NULL && temp->left!=NULL)
		{
			push(temp->right);
			push(temp->left);
		}

		else if(temp->right==NULL && temp->left!=NULL)
		{
			push(temp->left);
		}

		else if(temp->right!=NULL && temp->left==NULL)
		{
			push(temp->right);
		}
	}

}

void inorder(tree*root)
{
	if(root==NULL)
	{
		printf("\n\nthe tree is empty!!\n\n");
		return;
	}

	tree*temp=root;

	while(temp!=NULL)  // pushing the left children into the stack first!!
	{
		push(temp);
		temp=temp->left;
	}

	while(retTop()!=-1)
	{
		temp=pop();
		printf("%d ", temp->data);

		if(temp->right!=NULL)
		{
			temp=temp->right;

			while(temp!=NULL)
			{
				push(temp);
				temp=temp->left;
			}

		}
	}
}

void postorder(tree*root)
{
	if(root==NULL)
	{
		printf("\n\nthe tree is empty!!\n\n");
		return;
	}

	tree*temp=root, *popped=NULL;

	while(temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}

	while(retTop()!=-1)
	{
		temp=peek();
		if(temp->right!=NULL && temp->right!=popped)
		{
			temp=temp->right;
			while(temp!=NULL)
			{
				push(temp);
				temp=temp->left;
			}

			if(peek()->right!=NULL)
				continue;

		}


		popped=pop();
		printf("%d ", popped->data);
	}
}


void terminate(tree*root)
{
	if(root==NULL)
		return;

	terminate(root->left);
	terminate(root->right);
	free(root);
}

#endif // TRAVSTK_H
