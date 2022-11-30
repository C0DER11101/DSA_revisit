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

![alt text](<https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/DFSDiagraph.png>)
