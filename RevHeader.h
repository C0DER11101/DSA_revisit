#ifndef RH_H
#define RH_H
#define visited 1
#define unvisited 0
#define done 1
#define MAX 100

int inorder[MAX], preorder[MAX], postorder[MAX];

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
