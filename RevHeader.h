#ifndef RH_H
#define RH_H


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
