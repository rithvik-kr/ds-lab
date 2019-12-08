#include<stdio.h>
#define size 5
int cq[size];
int f=-1;
int r=-1;
int count=0;

void enqueue(int x)
{
	if(f==-1 && r==-1)
	{
		f++; r++;
		cq[r]=x;
		count++;
	}
	else if(count<5)
	{
		r=(r+1)%size;
		cq[r]=x;
		count++;
	}
	else
		printf("Queue Overflow\n");
}

void dequeue()
{
	if(f==-1 || f==r)
		printf("Queue Underflow\n");
	else
	{
		count--;
		printf("The deleted element is %d \n", cq[f]);
		f=(f+1)%size;
	}
}

void display()
{
	if(f==-1 || f==r)
		printf("Queue Underflow\n");
	else
	{
		int j=f;
		for(int i=0; i<count; i++)
		{
			printf("%d \t", cq[j]);
			j=(j+1)%size;
		}
		printf("\n");
	}
}

void main()
{
	int n,ch;
	do
	{
		printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					printf("Enter the Value\n");
					scanf("%d",&n);
					enqueue(n);
					break;
			case 2: 
					dequeue();
					break;
			case 3:
					display();
					break;
		}
	}while(ch!=4);
}