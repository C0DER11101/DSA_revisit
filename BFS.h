#ifndef BFS_H
#define BFS_H

int front=-1, rear=-1, queue[MAX];

int Front()
{
	return front;
}

void nq(int val)
{
	if(rear==MAX-1)
	{
		printf("\n\nqueue is full!!\n\n");
		return;
	}

	if(front==-1 && rear==-1)
	{
		front++, rear++;
		queue[front]=val;
	}
	
	else
	{
		++rear;
		queue[rear]=val;
	}

}

int dq()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\nqueue is empty!!\n\n");
		return -1;
	}

	else if(front==rear)
	{
		int topEl=queue[front];
		queue[front]=0;

		front=rear=-1;

		return topEl;
	}


	else
	{
		int topEl=queue[front];
		queue[front]=0;
		front++;

		return topEl;
	}
}

void bfs(int val, int numV)
{
	int element;

	nq(val);

	state[val]=1; // waiting state!!

	while(Front()!=-1)
	{
		element=dq();
		printf("%d ", element);
		state[element]=2; // visited state!!

		for(int i=0; i<numV; i++)
		{
			if((adj[element][i]==1 && state[i]!=2) && (adj[element][i]==1 && state[i]!=1))
			{
				nq(i);
				state[i]=1;
			}
		}
	}
}


#endif
