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
/* --- end --- */

/* for graphs!!! */

/* BFS AND DFS */
#define initial 0 // initial state of vertex(used in BFS and DFS)
#define waiting 1 // waiting state of vertex(used in only BFS)
#define visited 2 // visited state of vertex(used in BFS and DFS)
/* --- END --- */

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

/* DIJKSTRA'S ALGORITHM */
#define INF 9999 // INF -> INFINITY( this will be used in Floyd's algorithm as well)
#define Temp 0 // Temporary state -> shortest path to the vertex has not yet been found
#define Perm 1 // Permanent state -> shortest path to the vertex has been found
#define NIL -1 // Will also be used in Floyd's algorithm!!
#define DJKAL 0 // 1 indicates that we are working on Dijkstra's algorithm(0 indicates that we are not)!!

int weight[MAX][MAX]; // weight of each edge in the directed graph(will also be used in Floyd's algorithm)
int pathLen[MAX]; // path length of each vertex

void initPathLen()
{
	for(int i=0; i<MAX; i++)
	{
		pathLen[i]=INF;
	}
}

int STATE[MAX]={Temp}; // state of each vertex in Dijkstra's algorithm(whether the vertex in temporary state or permanent state)
/* --- END --- */

/* --- BELLMAN FORD ALGORITHM --- */
#define absent 0 // the vertex is absent from the queue
#define present 1 // the vertex is present in the queue
int signal[MAX]={absent}; // indicates the signal of each vertex(if it's present in the queue, then its signal will be present otherwise absent)
int vertexInsertnFreq[MAX]; // number of times a vertex was inserted into the queue, if it exceeds numV, then there is a negative cycle in the graph!
/* --- END --- */

/* --- FLOYD'S ALGORITHM --- */
int D[MAX][MAX][MAX]; // shortest path matrix
int d[MAX][MAX]; // D -1
int Pred[MAX][MAX][MAX]; // predecessors !!
int predV[MAX][MAX]; // for pred -1
void initPred()
{
	for(int l=0; l<MAX; l++)
	{
		for(int i=0; i<MAX; i++)
		{
			for(int j=0; j<MAX; j++)
				Pred[l][i][j]=NIL;
		}
	}
}

/* --- END --- */

int adj[MAX][MAX]; // adjacency matrix
int state[MAX]={initial}; // the states of each vertex in bfs(and dfs), whether it is in initial state or waiting state or visited state
/* in dfs, the vertex is either in initial state or visited state(it has no waiting state)*/
int pred[MAX]={NIL}; // predecessor of a vertex -> BFS for finding the shortest path, also for DFS and in Shortest path problems
int dist[MAX]; // distance value of a vertex -> BFS for finding the shortest path
int SPath[MAX]; // stores the shortest path from starting vertex to end vertex
int Spidx; // keeps track of number of vertices in SPath that form the shortest path
int edgeCount; // for eounting number of edges!!
int status; // status of edge() in GraphMat.h
int startTime[MAX]; // FOR DFS(connected components) starting time of a vertex, this is used when DFS is implemented recursively!!
int finishTime[MAX]; // FOR DFS(connected components) finishing time of a vertex, this is used when DFS is implemented recursively!!
int revAdj[MAX][MAX]; // reverse adjacency matrix, to check the connectivity of a directed graph(using DFS)
static int TIME; // time for each vertex(starting time and finishing time)!!

/* --- end --- */

#endif
