// DOUBLE ENDED QUEUE!!!


#ifndef DECK
#define DECK
#define MAX 7

int front=-1, rear=-1, deck[MAX];

void showIndex()
{
	printf("[front]=%d\n[rear]=%d\n", front, rear);
}

void nqfront(int val)
{
	if(front==-1 && rear==-1)
	{
		front++, rear++;
		deck[front]=val;
		showIndex();
	}

	else if(front-1==rear)
	{
		printf("\n\ndeck is full!!!\n\n");
		return;
	}

	else if(front==0 && deck[front]!=0)
	{
		front=MAX-1;
		deck[front]=val;
		showIndex();
	}

	else
	{
		front--;
		deck[front]=val;
		showIndex();
	}

}

void nqrear(int val)
{
	if(front==-1 && rear==-1)
	{
		front++, rear++;
		deck[rear]=val;
		showIndex();
	}

	else if(rear+1==front)
	{
		printf("\n\ndeck is full!!\n\n");
		return;
	}

	else if(rear==MAX-1)
	{
		if(front==0)
		{
			printf("\n\ndeck is full!!\n\n");
			showIndex();
			return;
		}

		rear=0;
		deck[rear]=val;
	}

	else
	{
		rear++;
		deck[rear]=val;
		showIndex();
	}
}

int dqfront()
{
	if(front==-1 && rear==-1)
	{
		printf("\ndeck is empty!!\n\n");
		showIndex();
		return -1;
	}


	else if(front==rear)
	{
		int value=deck[front];
		deck[front]=0;
		front=rear=-1;
		showIndex();
		return value;
	}

	else if(front==MAX-1)
	{
		int value=deck[front];
		deck[front]=0;
		front=0;
		showIndex();
		return value;
	}

	else
	{
		int value=deck[front];
		deck[front]=0;
		front++;
		showIndex();
		return value;
	}

}


int dqrear()
{
	if(front==-1 && rear==-1)
	{
		printf("\ndeck is empty!!\n\n");
		showIndex();
		return -1;
	}

	else if(rear==front)
	{
		int value=deck[front];
		deck[front]=0;
		front=rear=-1;

		showIndex();
		return value;
	}


	else
	{
		int value=deck[rear];
		deck[rear]=0;
		rear--;
		
		if(rear==-1)
		{
			rear=MAX-1;
		}

		showIndex();
		return value;
	}
}

void display()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\ndeck is empty!!\n\n");
		return;
	}

	printf("|");
	int i=front;

	for(int i=0; i<=MAX-1; i++)
		printf(" %d |", deck[i]);
}

#endif
