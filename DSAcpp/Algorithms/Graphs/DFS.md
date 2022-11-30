# Depth First Search(DFS)

**DFS is carried out using a stack.**

**It is like traversing a maze.**

**Here the process of _backtracking_ is used.**

_Here, we travel along a path in the graph and when we reach a vertex with no adjacent vertices, we backtrack._


**Simply speaking, we do this:**

_First the starting vertex is visited and then we will pick up any path that starts from the starting vertex and visit all the vertices in this path till we reach a vertex that has no adjacent vertices._

This statement simply means this:

**Visit the starting vertex(say `v1`) and visit any vertex adjacent to this starting vertex(say `v2`). Now, `v2` has any other vertex adjacent to it which has no been visited then visit it, and we will move so on.**

`We will backtrack till we reach a vertex that has any unvisited adjacent vertex.`


# Implementing DFS using a stack

**Here, vertices have two states:**
1. Initial -> when the vertex is pushed into the stack.
2. Visited -> when it is popped from the stack and visited.

## Algorithm of DFS using stack

1. Push starting vertex on the stack.
2. Pop a vertex from the stack.
3. If popped vertex is in initial state, visit it and change its state to visited. Push all unvisited vertices adjacent to the popped vertex.
4. Repeat steps 2 and 3 until the stack is empty.

Consider the graph below:

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/DFSDiagraph.png)


Now, we will apply the algorithm, to this graph:

### Steps:

Starting vertex: 0

1. Push `0` into stack.
2. Pop `0` from stack.
3. Visit `0`, change its state to visited. Check if `0` has any adjacent vertices.
**Adjacent vertices of `0` found:** `3` and `1`. Push into stack.
4. Pop `1`.
5. Visit `1`, change state of `1` to visited.
**Adjacent vertices of `1` found:** `5`, `4` and `2`. Push into stack.
6. Pop `2`.
7. Visit `2`, change state of `2` to visited.
**Adjacent vertices of `2` found:** `5` and `3`. Push into stack.
8. Pop `3`.
9. Visit `3`, change state of `3` to visited.
**Adjacent vertices of `3` found:** `6`. Push into stack.
10. Pop `6`.
11. Visit `6`, change state of `6` to visited.
**Adjacent vertices of `6` found:** `9`. Push into stack.
12. Pop `9`.
13. visit `9`, change state of `9` to visited.
**No adjacent vertices of `9` found.**
14. Pop `5`.
15. Visit `5`, change state of `5` to visited.
**Adjacent vertices of `5` found:** `8`, `7` and `6`[already visited]. Push `8` and `7`.
16. Pop `7`.
17. Visit `7`, change state of `7` to visited.
**Adjacent vertices of `7` found:** `8`. Push into stack.
18. Pop `8`.
19. Visit `8`, change state of `8` to visited.
**Adjacent vertices of `8` found:** `9`[already visited]. Nothing pushed into stack.
20. Pop `8` again, but this time `8` is visited. So do nothing. Move on.
21. Pop `4`.
22. Visit `4`, change state of `4` to visited.
**Adjacent vertices of 4 found:** `7`[already visited].
23. Pop `5` again, but it has visited already. Do nothing. Move on.
24. Pop `3` again, but it has also been visited already. Do nothing.
25. STACK EMPTY!! Stop DFS.


**So the traversal of the graph is:** _[0 1 2 3 6 9 5 7 8 4]_

The traversal is shown below:


<img src="https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/DFS.gif?raw=true"/>


**In DFS, if a vertex is already present in the stack it can re-pushed into the stack if it's still in _initial_ state.**

_If all vertices are not reachable from the start vertex then we need to repeat the procedure taking some other start vertex._

**DFS can also be implemented recursively.**


# Classification of edges in DFS

1. Tree edge: _Edge included in the DFS spanning tree._
2. Back edge: _Edge from a vertex to its spanning tree ancestor._
3. Forward edge: _Edge from a vertex to a spanning tree non-son descendant._
4. Cross edge: _An edge between two vertices `u` and `v` is said to be cross edge if there is no ancestor or descendant relationshipbetween `u` and `v` in the spanning forest. Cross edges can be between vertices of same spanning tree or vertices of different spanning trees._



---
