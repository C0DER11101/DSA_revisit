#ifndef Q_H
#define Q_H

int front=-1, rear=-1;
tree*q[MAX];

int Front()
{
	return front;
}

#if dtype==1 // integer
void nq(tree*node)
{
	if(rear==MAX-1)
	{
		printf("\n\nqueue overflow!!!\n\n");
		return;
	}

	else if(front==-1 && rear==-1)
	{
		front++, rear++;
		q[front]=node;
		return;
	}

	rear++;
	q[rear]=node;

}

tree*dq()
{
	if(front==-1)
	{
		printf("\n\nQUEUE EMPTY!!\n\n");
		return NULL;
	}

	else if(front==rear)
	{
		tree*temp=q[front];
		front=rear=-1;
		return temp;
	}

	int temp=q[front];
	front++;

	return temp;
}
#else

void nq(tree*node)
{
	if(front==-1 && rear==-1)
	{
		front++, rear++;
		q[front]=node;
		return;
	}

	else if(rear==MAX-1)
	{
		printf("queue overflow!!\n\n");
		return;
	}

	rear++;
	q[rear]=node;
}

tree*dq()
{
	if(front==-1)
	{
		printf("QUEUE EMPTY!!\n\n");
		return NULL;
	}

	else if(front==rear)
	{
		tree*temp=q[front];
		front=rear=-1;

		return temp;
	}

	else
	{
		tree*temp=q[front];
		front++;
		return temp;
	}
}

#endif
#endif
