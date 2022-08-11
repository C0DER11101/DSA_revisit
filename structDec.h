#ifndef STRUCT_H
#define STRUCT_H
struct tree
{
	char data;
	struct tree*left;
	struct tree*right;
};

typedef struct tree tree;

#endif
