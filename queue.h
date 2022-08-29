#ifndef QUEUE_H
#define QUEUE_H

int front=-1, rear=-1, queue[MAX];
int Front() // returns the value of front
{
	return front;
}

void nq(int val)
{
	if(rear==MAX-1)
	{
		printf("\n\nqueue is full!!!!\n\n");
		return;
	}

	else if(front==-1 && rear==-1)
	{
		front++, rear++;
		queue[front]=val;
	}

	else
	{
		rear++;
		queue[rear]=val;
	}
}

int dq()
{
	if(front==-1)
	{
		printf("\n\nqueue is empty!!\n\n");
		return ERR;
	}

	else if(front==rear)
	{
		int frontEl=queue[front];
		queue[front]=0;
		front=rear=-1;
		return frontEl;
	}

	else
	{
		int frontEl=queue[front];
		front++;
		return frontEl;
	}
}
#endif
