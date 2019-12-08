#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{ 
	int coef;
	int power;
	struct node *link;
};
typedef struct node NODE;
NODE *temp,*start=NULL,*ptr,*currptr;

void insert()
{
	temp=(NODE*)malloc(sizeof(NODE));
	temp->link=NULL;
	printf("Enter the Coefficient of the Polynomial\n");
	scanf("%d",&temp->coef);
	printf("Enter the Power of the Polynomial\n");
	scanf("%d",&temp->power);
	if(start==NULL)
		start=temp;
	else if (temp->power > start->power)
		{
			temp->link=start;
			start=temp;
		}
	else
	{
		ptr=start;
		while(temp->power < ptr->power && ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
}

void display()
{
	if (start == NULL)
	printf(" Empty List");
	else
	{
		ptr = start;
		while (ptr != NULL)
		{
			printf("%d*x^%d+  ",ptr->coef,ptr->power);
			ptr = ptr->link;
		}
		printf("0\n");
	}
}

void evaluate()
{	
	int x,result=0;
	ptr = start;
	printf(" Enter the value of x");
	scanf("%d",&x);
	
	while (ptr !=NULL)
	{	
		result = result + ptr->coef * pow(x,ptr->power);
		ptr = ptr->link;
	}
	printf(" The result of the expression is %d\n", result);
}

void main()
{
	int ch;
	do
	{
		printf(" 1. Insert\n 2. Display\n 3. Evaluate\n 4. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					insert();
					break;
			case 2: 
					display();
					break;
			case 3:
					evaluate();
					break;
		}
	}while(ch!=4);
}