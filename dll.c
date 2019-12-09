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
	NODE* prev = NULL;
	NODE* cur = start;
	while(cur && newnode -> data > cur -> data) {
		prev = cur;
		cur = cur -> next;
	}
	if(!prev) {
		newnode -> next = start;
		if(start)
			start -> prev = newnode;
		start = newnode;
	}
	else {
		newnode -> next = cur;
		newnode -> prev = prev;
		prev -> next = newnode;		
		if(cur)
			cur -> prev = newnode;
			
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
