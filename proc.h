#ifndef PROC_H
#define PROC_H

int retInd(char ch, char*inorder)
{
	for(int i=0; i<strlen(inorder); i++)
	{
		if(ch==inorder[i])
			return i;
	}

	return -1;
}
#endif
