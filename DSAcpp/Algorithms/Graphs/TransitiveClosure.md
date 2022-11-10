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

---
