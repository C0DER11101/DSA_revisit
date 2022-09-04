#ifndef RH_H
#define RH_H

#if dtype==1
int inorder[MAX], preorder[MAX], postorder[MAX];

#else
char inorder[MAX], preorder[MAX], postorder[MAX];
#endif

int RetIdx(int node)
{
	for(int i=0; i<MAX; i++)
	{
		if(inorder[i]==node)
			return i; // success
	}


	return -1; // failure
}

#endif
