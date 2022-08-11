#ifndef TREESTACK_H
#define TREESTACK_H
#define MAX 100

int top=-1;
tree*stack[MAX];

void push(tree*node)
{
	top++;
	stack[top]=node;
}

tree*pop()
{
	tree*temp=stack[top];
	top--;
	return temp;
}

int retTop() // returns the status of top
{
	return top;
}

tree*peek()
{
	return stack[top];
}

#endif
