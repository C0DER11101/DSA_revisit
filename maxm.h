#ifndef maxm_H
#define maxm_H
#define MAX 100
#define TRUE 1
#define FALSE 0
#define INVALID printf("invalid option!!\n\n")
#define and &&
#define or ||
#define OK 1
#define ERR -1
#define STOP 0
#define TYPE 1 // TYPE represents the graph type - directed or undirected( 0 is for undirected  )
/* for stack */
#define elType 0 // elType represents the the type of element(whether it's a char or int or float); by default it's of type int(i.e 0)
/* 0 -> int
 * 1 -> char
 * 2 -> float
 * 3 -> double
 */

/* for graphs!!! */
/* BFS */

#define initial 0 // initial state of vertex
#define waiting 1 // waiting state of vertex
#define visited 2 // visited state of vertex
// more symbolic constants awaiting to be defined
int state[MAX]={initial}; // the states of each vertex in bfs(and dfs), whether it is in initial state or waiting state or visited state
/* in dfs, the vertex is either in initial state or visited state(it has no waiting state)*/
int pred[MAX]; // predecessor of a vertex -> BFS for finding the shortest path, also for DFS
int dist[MAX]; // distance value of a vertex -> BFS for finding the shortest path
int SPath[MAX]; // stores the shortest path from starting vertex to end vertex
int Spidx; // keeps track of number of vertices in SPath that form the shortest path
int edgeCount; // for eounting number of edges!!
int status; // status of edge() in GraphMat.h
int startTime[MAX]; // FOR DFS(connected components) starting time of a vertex, when the vertex is pushed into the stack, then that becomes its starting time!!
int finishTime[MAX]; // FOR DFS(connected components) finishing time of a vertex, when the vertex is popped from the stack, then that becomes its finishing time!!
int revAdj[MAX][MAX]; // reverse adjacency matrix, to check the connectivity of a directed graph!!!
static int TIME; // time for each vertex(starting time and finishing time)!!

#endif
