#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node NODE;

NODE* maketree(int x)
{
	NODE* newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void setleft(NODE* p, int x)
{
	if(p==NULL)
		printf("\n Null Node");
	else
		p->left=maketree(x);
}

void setright(NODE* p, int x)
{
	if(p==NULL)
		printf("\n Null Node");
	else
		p->right=maketree(x);
}

void display(NODE* root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%d \t", root->data);
		display(root->right);
	}
}

void bst(int x, NODE* root)
{
	NODE* p;
	NODE* q;
	p=q=root;
	while(x!=p->data && q!=NULL)
	{
		p=q;
		if(x<p->data)
			q=p->left;
		else
			q=p->right;
	}
	if(x==p->data)
		printf("\n Duplicate");
	else if(x<p->data)
		setleft(p,x);
	else
		setright(p,x);
}

void main()
{
	int x,ch,n;
	NODE* root;
	printf("\n Enter the Root Value\n");
	scanf("%d",&x);
	root=maketree(x);
	do
	{
		printf("\n 1. Enter New Value\n 2. Display\n 3. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					printf("Enter the Value : \n");
					scanf("%d", &n);
					bst(n,root);
					break;
			case 2: 
					display(root);
					break;
			default:
					printf("\n Invalid Choice\n");
		}
	}while(ch!=3);
}