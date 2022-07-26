# Breadth First Search(BFS)

**Simply speaking: first we visit the starting vertex and then we visit all the adjacent vertices of the starting vertex. After that we pick these adjacent vertices one by one and visit their adjacent vertices and this process goes on.**


`BFS is equivalent to level order traversal of trees.`

Here vertices have 3 states:
1. Initial -> when the vertex is not inserted into the queue.
2. Waiting -> when the vertex is in the queue.
3. Visited -> when the vertex has been removed the queue.

Consider the graph below:

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/Diagraph2.png?raw=true)

**BFS is implemented using a queue.**

**Remember one thing:**

` The adjacent vertices of a vertex is/are searched only after removing that vertex from the queue. `


## Algorithm

1. Insert the starting vertex into the queue, change its state from initial to waiting.
2. Delete front element from the queue and visit it, change its state to visited.
3. Look for adjacent vertices of this deleted vertices and from these insert only those vertices into the queue which are in the initial state. Change the state of these inserted vertices to waiting.
4. Repeat steps 2 and 3 until the queue is empty.

Let's apply the algorithm on the above graph.

**Step-1: Insert the starting vertex, which in this case is 0, change the state of vertex 0 to waiting.**

**Step-2: Delete front element from the queue, in this case vertex 0, change its state to visited.**

**Step-3: Adjacent vertices of vertex 0 found: 1, 3, 4. Insert these vertices into queue, change their states to waiting.**

**Step-4: Delete vertex 1 from the queue, change state of vertex 1 to visited.**

**Step-5: Adjacent vertices of vertex 1 found: 2, 4[already in queue]. Insert vertex 2 into queue, change its state to waiting.**

**Step-6: Delete vertex 3, change state of vertex 3 to visited.**

**Step-7: Adjacent vertices of vertex 3 found: 4[already in queue], 6. Insert vertex 6 into queue, change its state to waiting.**

**Step-8: Delete vertex 4, change state of vertex 4 to visited.**

**Step-9: Adjacent vertices of vertex 4 found: 5, 7. Insert these vertices into queue, change their state to waiting.**

**Step-10: Delete vertex 2, change state of vertex 2 to visited.**

**Step-11: Adjacent vertices of vertex 2 found: 5[already in queue]. No insertion into queue done.**

**Step-12: Delete vertex 6, change state of vertex 6 to visited.**

**Step-13: Adjacent vertices of vertex 6 found: 4[already visited], 7[already in queue]. No insertion into queue done.**

**Step-14: Delete vertex 5, change state of vertex 5 to visited.**

**Step-15: No adjacent vertices of vertex 5 found. No insertion done into queue.**

**Step-16: Delete vertex 7, change state of vertex 7 to visited.**

**Step-17: Adjacent vertices of vertex 7 found: 5[already visited], 8. Insert vertex 8 into queue, change its state to waiting.**

**Step-18: Delete vertex 8, change state of vertex 8 to visited.**

**Step-19: No adjacent vertices of vertex 8 found. No insertion done into queue.**

**Step-20: Queue is empty!!**

[So the required order is: 0 1 3 4 2 6 5 7 8]

Here, the traversal is shown with the help of a GIF.

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/BFS.gif?raw=true)


# More on BFS

Let's say that while performing BFS, we assign two values to each vertex in the graph - _a predecessor_ and _a distance value_.

**Whenever we insert a vertex in the queue we set its predecessor and distance values.**

**The predecessor of the starting vertex is taken as -1 or NIL.**

**Distance value of starting vertex is taken as 0.**

**The distance value of any other vertex is one more than the distance value of its predecessor.**

**IF WE DRAW ONLY THOSE EDGES WHICH CONNECT A VERTEX TO ITS PREDECESSOR THEN WE GET A _SPANNING TREE_.**


_BFS in an undirected graph is performed in the same manner as in a directed graph._

## BFS to check connectivity of an undirected graph

> _An undirected graph is said to be connected if we can visit all the vertices taking any arbitrary start vertex, and there is no need to choose another start vertex._


---
