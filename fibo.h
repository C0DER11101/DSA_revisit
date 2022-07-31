#ifndef FIB_H
#define FIB_H

/* --- recursive definition of fibonacci series:
 *           _
 *          |
 *          | 1,  n=0 or 1
 *          /
 * fib(n)= -
 *          \ fib(n-1)+fib(n-2), n>1
 *          |
 *          |_
 */

int fib(int n)
{
	if(n==0 || n==1)
		return 1;

	return fib(n-1)+fib(n-2);
}

#endif
