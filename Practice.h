#ifndef P_H
#define P_H
#define MAX 100
/* dtype specifies the data type
 * 1 -> integer
 * 2 -> char
 */

#define dtype 2
//-------------------------------------------------------------------------------------------------------

#if dtype == 1
int inorder[MAX], preorder[MAX], postorder[MAX];

#else
char inorder[MAX], preorder[MAX], postorder[MAX];

#endif
#endif
