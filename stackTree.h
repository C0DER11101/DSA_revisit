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
	node*n1, *n2, *n3;
	switch(symbol)
	{
		case '-': case '+': case '*': case '/': case '^':
			/* if an operator is encountered then pop two pointers from the stack */

			n2=Pop(); /* first pointer popped */
			n3=Pop(); /* second pointer popped */
			n1=(node*)malloc(sizeof(node));
			n1->symbol=symbol;
			n1->left=n3; // pointer popped second becomes the left child
			n1->right=n2; // pointer popped first becomes the right child 
			top++;
			Stack[top]=n1;
			break;

		default:

			/* operand is encountered then simply push into stack */

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
