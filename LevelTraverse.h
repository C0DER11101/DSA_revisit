#ifndef LT_H
#define LT_H

void LevelTrav(tree*root)
{
	tree*temp=NULL;
	nq(root);

	while(Front()!=-1)
	{
		temp=dq();
#if dtype==1
		printf("%d ", temp->data);
#else
		printf("%c ", temp->data);
#endif

		if(temp->left!=NULL || temp->right!=NULL)
		{
			if(temp->left!=NULL && temp->right!=NULL)
			{
				nq(temp->left);
				nq(temp->right);
			}

			else if(temp->left!=NULL)
			{
				nq(temp->left);
			}

			else if(temp->right!=NULL)
			{
				nq(temp->right);
			}
		}
	}
}

#endif
