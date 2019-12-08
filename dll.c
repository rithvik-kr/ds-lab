#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*ptr;

void insert()
{
	int x;
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter the value:\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(start==NULL)
		start=newnode;
	else if(newnode->data < start->data)
	{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
	else if(newnode->data > start->data)
	{
		ptr=start;
		while(newnode->data > ptr->data && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
		newnode->prev=ptr;
		ptr=ptr->next;
		ptr->prev=newnode;
	}
}

void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void main()
{
	int ch;
	do
	{
		printf("1. Insert\n2. Display\n3. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: display();
					break;
		}
	}while(ch!=3);
}
