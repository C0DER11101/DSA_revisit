#ifndef Q_H
#define Q_H

struct node
{
	int data;
	struct node*link;
};

typedef struct node node;


node*nq(int value, node*n)
{
	if(n==NULL)
	{
		n=(node*)malloc(sizeof(node));
		n->data=value;
		n->link=NULL;
		
		return n;
	}

	n->link=nq(value, n->link);

	return n;
}

node*dq(node*h)
{
	if(h==NULL)
	{
		printf("\n\nthe queue is empty!!\n");
		return NULL;
	}

	node*temp;
	temp=h->link;
	free(h); // deleting the element at the front!!!

	return temp;
}

int count(node*h) // to count the number of nodes!!!
{
	int counter=0;

	while(h!=NULL)
	{
		counter++;
		h=h->link;
	}

	return counter;
}

void show(node*h)
{
	if(h==NULL)
	{
		printf("\n\nthe queue is empty!!!\n\n");
		return;
	}

	printf("\n\n|\nv\n");

	while(h!=NULL)
	{
		printf("%d->", h->data);
		h=h->link;
	}

	printf("NULL\n\n");
}

void Kill(node*h)
{
	node*temp=NULL;

	while(h!=NULL)
	{
		temp=h;
		h=h->link;
		free(temp);
	}
}

#endif
