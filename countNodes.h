#ifndef COUNT_H
#define COUNT_H

int countNd(tree*root, int cnd)
{
	if(root==NULL)
		return cnd;

	cnd=countNd(root->left, cnd);
	cnd=countNd(root->right, cnd);
	return (++cnd);
}

#endif
