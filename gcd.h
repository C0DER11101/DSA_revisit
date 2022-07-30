#ifndef GCD_H
#define GCD_H

/* --- EUCLIDEAN ALGORITHM ---
 * a=210, b=45
 *
 * 1) Divide a by b and get the result 4 with a remainder 30:
 * 210=45*4+30; a=45 and b=30
 *
 * 2) Divide a by b and get the result 1 with a remainder 15:
 * 45=30*1+15; a=30 and b=15
 *
 * 3) Divide a by b and get the result 2 with a remainder 0:
 * 30=15*2+0
 * So, gcd(210, 45) = 15
 * 
 * Source: https://sites.math.rutgers.edu/~greenfie/gs2004/euclid.html#:~:text=The%20Euclidean%20algorithm%20is%20a,%3D1%C2%B730%2B15.
 */

int gcd(int a, int b)
{
	if(b==0)
		return a;

	gcd(b, a%b);
}

#endif
