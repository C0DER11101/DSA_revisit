#ifndef LIST_H
#define LIST_H

struct node
{
	int data;
	struct node*link;
};

typedef struct node node;

node*addNode(node*h, int value)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=value;
		h->link=NULL;

		return h;
	}

	h->link=addNode(h->link, value);

	return h;
}

void display(node*h)
{
	if(h==NULL)
	{
		printf("NULL\n");
		return;
	}

	printf("%d->", h->data);
	display(h->link);
}

void  displayRL(node*h)
{
	if(h==NULL)
		return;

	displayRL(h->link);
	printf("%d->", h->data);
}

node*revL(node*h)
{
	if(h->link==NULL)
		return h;
	h->link=revL(h->link);

	node*temp=h->link;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=h;

	temp=h->link;
	h->link=NULL;
	return temp;
}

int len(node*h)
{
	if(h==NULL)
		return 0;

	return 1+len(h->link);
}

int addEl(node*h)
{
	if(h==NULL)
		return 0;

	return h->data+addEl(h->link);
}

int searchNode(node*h, int value)
{
	if(h==NULL)
		return 0;
	else if(h->data==value)
		return 1;

	searchNode(h->link, value);
}

node*rmNode(node*h)
{
	if(h->link==NULL) // last node
	{
		free(h);
		return NULL;
	}

	h->link=rmNode(h->link);

	return h;
}

node*terminate(node*h)
{
	printf("\n\nAll nodes removed!!\n\n");
	node*temp;

	while(h!=NULL)
	{
		temp=h;
		h=h->link;
		free(temp);
	}

	return NULL;
}

#endif
