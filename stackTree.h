#ifndef S_T
#define S_T

struct node
{
	char symbol;
	struct node*left;
	struct node*right;
};

typedef struct node node;

node*Stack[MAX];

node* Pop()
{
	node*n=Stack[top];

	top--;
	return n;
}

void Push(char symbol)
{
	node*n1;
	node*n2;
	node*n3;
	switch(symbol)
	{
		case '-': case '+': case '*': case '/': case '^':
			n2=Pop();
			n3=Pop();
			n1=(node*)malloc(sizeof(node));
			n1->symbol=symbol;
			n1->left=n3;
			n1->right=n2;
			top++;
			Stack[top]=n1;
			break;

		default:
			n1=(node*)malloc(sizeof(node));
			n1->symbol=symbol;
			n1->left=n1->right=NULL;
			top++;
			Stack[top]=n1;
	}
}


void inorder(node*head)
{
	if(head==NULL)
		return;

	inorder(head->left);
	printf("%c", head->symbol);
	inorder(head->right);
}

void preorder(node*head)
{
	if(head==NULL)
		return;

	printf("%c", head->symbol);
	preorder(head->left);
	preorder(head->right);
}

void postorder(node*head)
{
	if(head==NULL)
		return;

	postorder(head->left);
	postorder(head->right);
	printf("%c", head->symbol);
}

void terminate(node*head)
{
	if(head==NULL)
		return;

	terminate(head->left);
	terminate(head->right);
	free(head);
}

#endif
