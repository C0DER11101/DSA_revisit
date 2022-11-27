# Breadth First Search(BFS)

**Simply speaking: first we visit the starting vertex and then we visit all the adjacent vertices of the starting vertex. After that we pick these adjacent vertices one by one and visit their adjacent vertices and this process goes on.**


`BFS is equivalent to level order traversal of trees.`

Here vertices have 3 states:
1. Initial -> when the vertex is not inserted into the queue.
2. Waiting -> when the vertex is in the queue.
3. Visited -> when the vertex has been removed the queue.

Consider the graph below:

![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/Diagraph2.png?raw=true)

We will implement BFS using a **queue**.


## Algorithm

1. Insert the starting vertex into the queue, change its state from initial to waiting.
2. Delete from element from the queue and visit it, change its state to visited.
3. Look for adjacent vertices of this deleted vertices and from these insert only those vertices into the queue which are in the initial state. Change the state of these inserted vertices to waiting.
4. Repeat steps 2 and 3 until the queue is empty.


![image](https://github.com/C0DER11101/DSA_revisit/blob/master/DSAcpp/Algorithms/Graphs/BFS.gif?raw=true)
