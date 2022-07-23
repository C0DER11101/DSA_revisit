// PRIORITY QUEUE USING QUEUE

#ifndef LLIST_H
#define LLIST_H

struct node
{
	int data;
	int priority;
	struct node*link;
};

typedef struct node node;

node*nq(int value, int priority, node*h)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=value;
		h->priority=priority;
		h->link=NULL;

		return h;
	}

	h->link=nq(value, priority, h->link);

	return h;
}

node*dq(node*h)
{

	if(h==NULL)
	{
		printf("\n\npriority queue is empty!!\n\n");
		return NULL;
	}

	node*temp=h;
	int large=0;

	while(temp!=NULL)
	{
		if(temp->priority>large)
			large=temp->priority;

		temp=temp->link;
	}

	temp=h;

	while(temp!=NULL)
	{
		if(temp->priority==large)
		{
			break;
		}

		temp=temp->link;
	}

	if(temp==h) // first node will be deleted
	{
		h=h->link;
		free(temp);
		return h;
	}
		
	else if(temp->link==NULL) // last node will be deleted
	{
		node*t1=h;
		while(t1->link!=temp)
		{
			t1=t1->link;
		}

		t1->link=NULL;
		free(temp);
	}

	else
	{
		node*t1=h;

		while(t1->link!=temp)
		{
			t1=t1->link;
		}

		t1->link=temp->link;
		free(temp);
	}

	return h;
}

void show(node*h)
{
	if(h==NULL)
	{
		printf("\n\npriority queue is empty!!!\n\n");
		return;
	}

	printf("\n\n| value | priority |\n\n");

	while(h!=NULL)
	{
		printf("| %d | %d | --> ", h->data, h->priority);
		h=h->link;
	}

}

int count(node*h)
{
	int counter=0;

	if(h==NULL)
	{
		printf("\n\npriority queue is empty!!\n\n");
		return -1;
	}

	while(h!=NULL)
	{
		counter++;
		h=h->link;
	}

	return counter;

}

void terminate(node*h)
{
	if(h==NULL)
	{
		return;
	}

	node*temp=NULL;

	while(h!=NULL)
	{
		temp=h;
		h=h->link;

		free(temp);
	}
}

#endif
