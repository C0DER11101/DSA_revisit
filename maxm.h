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

/* for graphs!!! */
/* BFS */

#define initial 0 // initial state of vertex
#define waiting 1 // waiting state of vertex
#define visited 2 // visited state of vertex
// more symbolic constants awaiting to be defined!!
int state[MAX]; // the status of each vertex in bfs, whether it is in initial state or waiting state or visited state!!
#endif
