#ifndef LL_H
#define LL_H

#include<stdbool.h>
struct node
{
	int data;
	struct node*link;
};

typedef struct node node;

node*insert(int, node*);
node*del(int, node*);
int count(node*);
bool search(int, node*);
void terminate(node*);


#endif
