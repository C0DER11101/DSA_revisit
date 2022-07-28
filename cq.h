#ifndef C_H
#define C_H

#define MAX 5

int front=-1, rear=-1, cq[MAX];

void showIndex()
{
	printf("[front]=%d\n[rear]=%d\n", front, rear);
}

void enqueue(int val)
{
	if(front==-1 && rear==-1)
	{
		front++, rear++;
		cq[front]=val;
	}

	else if((rear+1)%MAX==front)
	{
		printf("\n\ncircular queue is full!!\n\n");
		return;
	}

	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		cq[rear]=val;
	}

	else
	{
		rear++;
		cq[rear]=val;
	}

	showIndex();
}

int dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\ncircular queue is empty!!!\n\n");
		showIndex();
		return -1;
	}

	else if(front==MAX-1)
	{
		int value=cq[front];
		cq[front]=0;
		front=0;

		showIndex();
		return value;
	}

	else if(front==rear)
	{
		int value=cq[front];
		cq[front]=0;
		front=rear=-1;
		showIndex();
		return value;
	}

	else
	{
		int value=cq[front];
		cq[front]=0;
		front++;
		showIndex();
		return value;
	}
}

int peek()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\ncircular queue is empty!!!\n\n");
		return -1;
	}

	return cq[front];
}

void display()
{
	for(int i=front; ;i++)
	{
		if(i%MAX==front && i!=front)
		{
			printf("%d ", cq[i%MAX]);
			break;
		}
		printf("%d ", cq[i%MAX]);
	}
}


#endif
