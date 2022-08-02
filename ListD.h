#ifndef DList_H
#define DLIST_H

/* --- FOR A NODE --- */
struct node
{
	int data;
	struct node*next;
	struct node*prev;
};

typedef struct node node;
/* --- <END> ---*/

/* --- FUNCTIONS FOR INSERTING OF NODE --- */

node*InsertBeg(node*h, int val)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=val;
		h->next=NULL;
		h->prev=NULL;

		return h;
	}

	node*temp=h;
	h=(node*)malloc(sizeof(node));
	h->data=val;
	h->next=temp;
	temp->prev=h;
	h->prev=NULL;
	return h;
}

node*Append(node*h, int val)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=val;
		h->next=NULL;
		h->prev=NULL;
		return h;
	}

	node*temp=h, *prev;
	while(temp!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}

	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	temp->prev=prev;
	prev->next=temp;

	return h;
}

node*AddMid(node*h, int val, int nodeVal)
{
	if(h==NULL)
	{
		printf("\n\nCannot add node in the middle, list is empty!!\n\n");
		return NULL;
	}
	node*preserve=h;

	while(h->data!=nodeVal)
		h=h->next;

	if(h->next==NULL) // value has to be inserted after the last node
	{
		node*temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->next=NULL;
		temp->prev=h;
		h->next=temp;
		
		return preserve;
	}

	node*temp=(node*)malloc(sizeof(node));

	temp->data=val;
	temp->next=h->next;
	h->next->prev=temp;
	h->next=temp;
	temp->prev=h;

	return preserve==h? h:preserve;
}

/* --- <END> --- */

/* --- FUNCTIONS FOR DELETING A NODE FROM THE DOUBLE LINKED LIST --- */

node*delBeg(node*h)
{
	if(h==NULL)
	{
		printf("\n\nlist is empty!!!\n\n");
		return h;
	}

	if(h->next==NULL) // there is only one node in the double linked list!!
	{
		free(h);
		h=NULL;
		return h;
	}

	node*temp=h;
	h=h->next;
	h->prev=NULL;
	free(temp);

	return h;
}

node*delEnd(node*h)
{
	if(h==NULL)
	{
		printf("\n\nlist is empty!!\n\n");
		return h;
	}

	if(h->next==NULL) // there is only one node in the double linked list!!
	{
		free(h);
		h=NULL;
		return h;
	}

	node*temp=h, *prev;

	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}

	prev->next=NULL;
	temp->prev=NULL;
	free(temp);

	return h;
}

node*delRandom(node*h, int val)
{
	if(h==NULL)
	{
		printf("\n\nlist is empty!!\n\n");
		return h;
	}

	if(h->next==NULL) // there is only one node in the double linked list!!
	{
		free(h);
		h=NULL;
		return h;
	}

	node*preserve=h;

	if(h->data==val && h->next!=NULL) // node to be deleted is the first node
	{
		node*temp=h;
		h=h->next;
		h->prev=NULL;
		temp->next=NULL;
		free(temp);
		return h;
	}

	node*prev;

	while(h->data!=val)
	{
		prev=h;
		h=h->next;
	}

	if(h==NULL)
	{
		printf("\n%d is not in the list!!\n\n", val);
		return preserve;
	}

	if(h->next==NULL) // node to be deleted is the last node
	{
		prev->next=NULL;
		h->prev=NULL;
		free(h);
		
		return preserve;
	}

	prev->next=h->next;
	h->next->prev=prev;

	h->next=NULL;
	h->prev=NULL;

	free(h);

	return preserve;
}

/* --- <END> --- */

/* --- FUNCTIONS FOR SEARCHING AND ADDING NODES --- */

int dig(node*h, int val)
{
	if(h==NULL)
		return -1;
	else if(h->data==val)
		return 1;

	dig(h->next, val);
}

int addNodes(node*h, int sum)
{
	if(h==NULL)
		return sum;

	sum+=h->data;

	addNodes(h->next, sum);
}

/* --- <END> --- */

/* --- FUNCTIONS FOR DISPLAYING THE DOUBLE LINKED LIST --- */

void showList(node*h)
{
	if(h==NULL)
	{
		printf("\n\nthe list is emtpy!\n\n");
		return;
	}

	while(h->next!=NULL)
	{
		printf("%d<->", h->data);
		h=h->next;
	}

	printf("%d->NULL", h->data);
}

void revDisp(node*h)
{
	if(h==NULL)
	{
		printf("\n\nthe list is emtpy!\n\n");
		return;
	}

	if(h==NULL)
		return;

	revDisp(h->next);
	printf("%d<->", h->data);
}

/* --- <END> --- */

/* --- FUNCTION TO REVERSE THE DOUBLE LINKED LIST --- */

node*RevL(node*h)
{
	if(h==NULL)
	{
		printf("\n\nthe list is emtpy!\n\n");
		return h;
	}

	if(h->next==NULL)
		return h;

	h->next=RevL(h->next);
	node*temp=h->next;
	while(temp->next!=NULL)
		temp=temp->next;

	temp->next=h;
	h->prev=temp;
	temp=h->next;
	
	if(temp->prev!=NULL)
		temp->prev=NULL;
	h->next=NULL;
	return temp;
}


/* --- <END> --- */

/* --- FUNCTION TO FREE ALL THE NODES --- */
void terminate(node*h)
{
	node*temp=h;

	while(h!=NULL)
	{
		h=h->next;
		free(temp);
		temp=h;
	}
}

/* --- <END> --- */

#endif
