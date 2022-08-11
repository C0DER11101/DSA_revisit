#ifndef TREEI_H
#define TREEI_H



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

tree*CreBinaT(tree*root, char*inorder, char*preorder) // traverses both, the inorder array and the preorder array
{
	tree*temp=NULL;
	for(int i=0; i<strlen(preorder); i++)
	{
		for(int j=0; j<strlen(inorder); j++)
		{
			if(preorder[i]==inorder[j])
				root=ctree(root, preorder[i], inorder,  j);
		}
	}


	return root;
}

void Preorder(tree*root)
{
	tree*temp=root;
	if(root==NULL)
	{
		printf("\n\nbinary tree is empty!!\n\n");
		return;
	}

	push(root); // push the root before entering the loop

	while(retTop()!=-1)
	{
		temp=pop();
		printf("%c ", temp->data);

		if(temp->left!=NULL && temp->right!=NULL)
		{
			push(temp->right);
			push(temp->left);
		}

		else if(temp->right!=NULL && temp->left==NULL)
		{
			push(temp->right);
		}

		else if(temp->right==NULL && temp->left!=NULL)
		{
			push(temp->left);
		}
	}
}

void Inorder(tree*root)
{
	if(root==NULL)
	{
		printf("\n\nbinary tree is empty!!\n\n");
		return;
	}

	tree*temp=root;

	while(temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}

	tree*popped=NULL;
	while(retTop()!=-1)
	{
		popped=pop();
		printf("%c ", popped->data);
		
		if(popped->right!=NULL)
		{
			temp=popped->right;
			while(temp!=NULL)
			{
				push(temp);
				temp=temp->left;
			}
		}

	}


}

void Postorder(tree*root)
{
	if(root==NULL)
	{
		printf("\n\nbinary tree is empty!!\n\n");
		return;
	}

	tree*temp=root, *popped=NULL;

	while(temp!=NULL) // inserting all the left children first(since it is postorder traversal)!
	{
		push(temp);
		temp=temp->left;
	}

	while(retTop()!=-1)
	{
		temp=peek();
		if(temp->right!=NULL && temp->right!=popped) // checking if there is a right child and whether it is equal to popped or not!
		{
			temp=temp->right;
			while(temp!=NULL)
			{
				push(temp);
				temp=temp->left;
			}

			temp=peek(); // checking if this node has a right child!!
			if(temp->right!=NULL)
				continue;
		}

		popped=pop();
		printf("%c ", temp->data);
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

#endif
