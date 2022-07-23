// PRIORITY QUEUE USING SORTED LIST!!

#ifndef PQ_H
#define PQ_H

struct node
{
	int data;
	int priority;
	struct node*link;
};

typedef struct node node;

node*insert(int value, int priority, node*h)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=value;
		h->priority=priority;
		h->link=NULL;
		return h;
	}

	else
	{

		node*prev=h;
		node*temp=h;

		while(temp!=NULL)
		{
			if(priority==temp->priority && temp==h)  // if priorities are same, then compare by value!!!
			{
				if(value<=temp->data)
				{
					h=(node*)malloc(sizeof(node));
					h->data=value;
					h->priority=priority;
					h->link=temp;

					return h;
				}

				else
				{
					h=(node*)malloc(sizeof(node));
					h->data=value;
					h->priority=priority;
					h->link=temp->link;
					temp->link=h;
					h=temp;

					return h;
				}
			}

			else if(priority==temp->priority && temp->link==NULL)
			{
				if(value<=temp->data)
				{
					node*t=(node*)malloc(sizeof(node));
					t->data=value;
					t->priority=priority;
					t->link=temp;
					prev->link=t;
					break;
				}

				else
				{
					node*t=(node*)malloc(sizeof(node));
					t->data=value;
					t->priority=priority;
					t->link=NULL;
					temp->link=t;
					break;
				}
			}

			else if(priority==temp->priority)
			{
				if(value<=temp->data)
				{
					node*t=(node*)malloc(sizeof(node));
					t->data=value;
					t->priority=priority;
					t->link=temp;
					prev->link=t;
					break;
				}

				else
				{
					node*t=(node*)malloc(sizeof(node));
					t->data=value;
					t->priority=priority;
					t->link=temp->link;
					temp->link=t;
					break;
				}
			}

			else if(priority>temp->priority && temp==h)
			{
				h=(node*)malloc(sizeof(node));
				h->data=value;
				h->priority=priority;
				h->link=temp;

				return h;
			}

			else if(priority<temp->priority && temp->link==NULL)
			{
				node*h2;
				h2=(node*)malloc(sizeof(node));
				h2->data=value;
				h2->priority=priority;
				h2->link=NULL;
				temp->link=h2;
				break;
			}

			else if(priority<temp->priority && priority>temp->link->priority)
			{
				node*h2=(node*)malloc(sizeof(node));
				h2->data=value;
				h2->priority=priority;
				h2->link=temp->link;
				temp->link=h2;
				break;
			}

			prev=temp;

			temp=temp->link;
		}
	}

	return h;
}

node*del(node*h)
{

	if(h==NULL)
	{
		printf("\n\npriority queue is empty!!\n\n");
		return NULL;
	}

	node*temp=h;

	h=h->link;
	free(temp);

	return h;
}

void show(node*h)
{
	if(h==NULL)
	{
		printf("\n\npriority queue is empty!!\n\n");
	}

	printf("\n\n| value | priority | -->\n\n");

	while(h!=NULL)
	{
		printf("| %d | %d | --> ", h->data, h->priority);
		h=h->link;
	}

}

int count(node*h)
{
	int counter=0;
	while(h!=NULL)
	{
		counter++;
		h=h->link;
	}

	return counter;
}

void terminate(node*h)
{
	node*temp=h;

	while(h!=NULL)
	{
		h=h->link;
		free(temp);
		temp=h;
	}
}
#endif
