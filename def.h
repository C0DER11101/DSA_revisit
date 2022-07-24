// DEFINITIONS

#ifndef DEF_H
#define DEF_H

node*insert(int value, node*h)
{
	if(h==NULL)
	{
		h=(node*)malloc(sizeof(node));
		h->data=value;
		h->link=NULL;

		return h;
	}

	h->link=insert(value, h->link);

	return h;
}


node*del(int value, node*h)
{


	if(h==NULL)
	{
		printf("\n\n%d is not in the list!!\n\n", value);
		return h;
	}

	if(h->data==value)
	{
		if(h->link==NULL)
		{
			node*temp=h;
			free(temp);

			return NULL;
		}

		else
		{
			node*temp=h;
			h=h->link;
			free(temp);

			return h;
		}
	}

	h->link=del(value, h->link);

	return h;
}

void display(node*h)
{

	if(h==NULL)
	{
		printf("\n\nlist is empty!!\n\n");
		return;
	}

	while(h!=NULL)
	{
		printf("%d -> ", h->data);
		h=h->link;
	}
}

int count(node*h)
{

	if(h==NULL)
	{
		printf("\n\nlist is empty!!\n\n");
		return 0;
	}

	int counter=0;

	while(h!=NULL)
	{
		counter++;

		h=h->link;
	}

	return counter;

}

bool search(int value, node*h)
{
	if(h==NULL)
	{
		return false;
	}

	else if(value==h->data)
	{
		return true;
	}

	search(value, h->link);

}

void terminate(node*h)
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
