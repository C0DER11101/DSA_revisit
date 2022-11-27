# Transitive closure of a directed graph and path matrix

Transitive closure of a graph G is a graph G' where G' contains the same set of vertices as G and whenever there is a path from a vertex i to vertex j in G, there is an edge from i to j in G'.

The path matrix of a graph G with n vertices is an $n\times n$ boolean matrix whose elements can be defined as:

P[i][j]=1, if there is a path from vertex i to vertex j, otherwise 0.

**The path matrix of a graph is also known as the transitive closure matrix of the graph.**

**Two methods to compute the path matrix:**

1. Using powers of adjacency matrix.
2. Warshall's algorithm.

**Important points**
- If P[i][j] is 1, then there is a path from vertex i to vertex j.
- If P[i][i] is 1, then the graph contains a cycle.
- If all elements in the path matrix are 1, then the graph is strongly connected.


# Computing path matrix from powers of adjacency matrix

If a graph G has $n$ vertices, then the path matrix P is calculated as:

$$P=A^1 + A^2 + A^3 + ....+ A^n$$

Where A is the adjacency matrix of the graph G.

# Computing path matrix using Warshall's Algorithm.

## Warshall's Algorithm

Let G be a graph of n vertices 0, 1, 2, 3.....n-1. We will define Boolean matrices $P_{-1}, P_0, P_1, ....P_{n-1}$,

where $P_k[i][j]$ is defined as:

- $P_k[i][j]=1$ _if there is a simple path from vertex i to vertex j with intermediate vertices 0, 1, ....., k_
- $P_k[i][j]=0$, _otherwise_


- $P_{-1}[i][j]=1$, _if there is a simple path from vertex i to vertex j which doesnot use any intermediate vertices_
- $P_0[i][j]=1$, _if there is a simple path from vertex i to vertex j using intermediate vertex 0._
- $P_1[i][j]=1$, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1._
- $P_2[i][j]=1$, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1, 2._
- $P_k[i][j]=1$, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1, 2, ....k._
- $P_{n-1}[i][j]=1$, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1,....n-1._

**Here, $P_{-1}$ represents the adjacency matrix and $P_{n-1}$ represents the path matrix.**


**If $P_{k-1}[i][j]=1$, then $P_k[i][j]=1$**

Explanation(according to what I understood):

Assume two places A and B. Now, to reach A and B, there are a bunch of roads that lead to B from A. Lets say we have 0 to k-1 roads.
That means, we cannot use any other paths/roads, except possibly those roads that already exist.

We may use any roads that are a part of those k-1 roads, but it's not necessary that we will have to use all the k-1 roads.

Let's say we reach to place B from A using roads 0, 1 and 3.

> Recall this above example was analogy for $P_{k-1}=1$

Now, let's assume there another road that leads to B from A. So the total number roads that we have now are road 0 to k.

But we will still use the roads 0, 1 and 3 to reach B, we may use other roads that lead to B(like road 2, road 4, .....).

That's why it's said that if $P_{k-1}[i][j]=1$ then $P_k[i][j]=1$


Now, $P_{k-1}[i][j]=0$ means that there is no path from vertex i to vertex j using intermediate vertices 0, 1....k-1.

But we cannot say that $P_k[i][j]=0$ just because $P_{k-1}[i][j]=0$. Look at the explanation below :point_down:

Let's say that we have to reach B and we are in place A.

There some roads numbered from 0 to k-1; but none of them leads to B(This is an analogy to $P_{k-1}[i][j]=0$).

But there an extra road, numbered k which leads to B, so now, we can reach B via this road(This analogy shows that $P_k[i][j]$ cannot be 0 just because $P_{k-1}[i][j]=0$, $P_k[i][j]$ may or maynot be 0).

Keeping that example in mind let's assume that the vertex k leads to vertex j from vertex i, and no other vertices from 0, 1...k-1 leads to vertex j, but we can use the vertices 0 to k-1(not necessarily all of them) to reach vertex k and from vertex k to vertex j.

Since vertex k leads to vertex j, that means we will have two paths i.e one path will go from vertex i to vertex k using intermediate vertices 0....k-1 and other path will be from vertex k to vertex j using intermediate vertices 0.....k-1.


So in simple words we can write that:

if $P_{k-1}[i][j]=0$, then

$P_k[i][j]=1$ if and only if $P_{k-1}[i][k]=1$ and $P_{k-1}[k][j]=1$ otherwise $P_k[i][j]=0$.

Consider a diagraph:

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/Digraph1.png?raw=true)

The adjacency matrix $P_{-1}$ will be:

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/AdjacencymatrixForDiagraph1.png?raw=true)

Now, for $P_0$, all those $1s$ of $P_{-1}$ will be included in matrix $P_0$.

$P_0$ means that the intermediate vertex is 0. So, if $P_{-1}[i][j]=0$ then $P_0[i][j]=1$ if and only if $P_0[i][0]=1$ and $P_0[0][j]=1$.

From the image we can see that $P_{-1}[1][1]=0$. So, now we see that $P_{-1}[1][0]=1$ and $P_{-1}[0][1]=1$ so, $P_0[1][1]=1$.
Continue following the above method for all the vertices of $P_0$ and this is what you will get.

Matrix $P_0$.

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/MatrixP0forDiagraph1.png?raw=true)

Similarly, create matrix $P_1$ from matrix $P_0$, matrix $P_2$ from matrix $P_1$ and so on...

Number of vertices is 4 (from vertex 0 to vertex 3), so 4 matrices will be formed i.e $P_{-1}, P_0, P_1, P_2, P_3$.

$P_3$ will be the required path matrix and $P_{-1}$ will be the adjacency matrix of the diagraph.

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/PathMatrixForDiagraph1.png?raw=true)

---
