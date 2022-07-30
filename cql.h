#ifndef CQ_H
#define CQ_H

struct node
{
	int data;
	struct node*link;
};

typedef struct node node;

node*front=NULL, *rear=NULL;

void enqueue(int value)
{
	if(front==NULL)
	{
		front=(node*)malloc(sizeof(node));
		front->data=value;
		front->link=front;
		rear=front;
	}

	else // insertion at rear
	{
		node*temp=(node*)malloc(sizeof(node));
		temp->data=value;
		temp->link=front;
		rear->link=temp;
		rear=temp;
	}
}

int dequeue()
{
	if(front==NULL)
	{
		printf("\n\ncircular queue is empty!!\n\n");
		return -1;
	}

	if(front->link==front)
	{
		int val;
		val=front->data;
		free(front);
		front=NULL;
		return val;
	}

	node*temp=front;
	front=front->link;
	int val=temp->data;
	free(temp);

	rear->link=front;

	return val;
}

void display()
{
	if(front==NULL)
	{
		printf("\n\ncircular queue is empty!!\n\n");
		return;
	}

	node*temp=front;
	while(temp->link!=front)
	{
		printf("%d->", temp->data);
		temp=temp->link;
	}

	printf("%d->%d->..", temp->data, temp->link->data);
}

node*checkNull()
{
	return front;
}

void peek()
{
	if(front==NULL)
	{
		printf("\n\ncircular queue empty!!\n\n");
		return;
	}

	printf("\n[front]=%d\n[rear]=%d\n", front->data, rear->data);

}

void terminate()
{
	node*temp=front, *temp2;
	temp=temp->link;
	while(temp->link!=front)
	{
		temp2=temp;
		temp=temp->link;
		free(temp2);
	}

	temp2=temp->link;

	free(temp);
	free(temp2);

	front=NULL;
}

#endif
