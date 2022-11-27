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
- $P_{-1}[i][j]$=1, _if there is a simple path from vertex i to vertex j which doesnot use any intermediate vertices_
- $P_0[i][j]$=1, _if there is a simple path from vertex i to vertex j using intermediate vertex 0._
- $P_1[i][j]$=1, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1._
- $P_2[i][j]$=1, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1, 2._
- $P_k[i][j]$=1, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1, 2, ....k._
- $P_{n-1}[i][j]$=1, _if there is a simple path from vertex i to vertex j using intermediate vertices 0, 1,....n-1._


**Here, $P_{-1}$ represents the adjacency matrix and $P_{n-1}$ represents the path matrix.**


**_If $P_{k-1}[i][j]=1$, then $P_k[i][j]=1$_**

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

But we cannot say that $P_k[i][j]=0$. Look at the explanation below :point_down:

---
