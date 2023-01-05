#include<stdio.h>
#define MAX 5
struct cqueue
{
	int items[MAX];
	int front,rear;
};
void enqueue(struct cqueue *,int);
void dequeue(struct cqueue *);
void display(struct cqueue *);
int main()
{
	int choice,ele;
	struct cqueue q;
	q.rear = -1;
	q.front = -1;
	while(1)
	{
		printf(" \n 1.enqueue \t 2.dequeue \t 3.display : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf(" enter the element to be inserted  : ");
				scanf("%d",&ele);
				enqueue(&q,ele);
				display(&q);
				break;
			case 2:
				dequeue(&q);
				display(&q);
				break;
			case 3:
				display(&q);
				break;
		}
	}
}
void enqueue(struct cqueue *q,int ele)
{
	if((q->front == 0 && q->rear == MAX-1)||(q->front == q->rear+1))
	{
		printf(" \n queue is overflow \n");
		return;
	}
	if(q->front == -1)
	{
		q->front = 0;
		q->rear = 0;
	}else
	{
		if(q->rear == MAX-1)
		{
			q->rear = 0;
		}else
		{
			q->rear++;
		}
	}
	q->items[q->rear] = ele;
}
void dequeue(struct cqueue *q)
{
	int ele;
	if(q->front == -1)
	{
		printf(" \n queue is underflow \n");
		return;
	}
	ele = q->items[q->front];
	if(q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}else
	{
		if(q->front == MAX-1)
		{
			q->front = 0;
		}else
		{
			q->front++;
		}
	}
	printf(" element removed  : %d \n ",ele);
}
void display(struct cqueue *q)
{
	int i;
	if(q->front == -1)
	{
		printf(" \n queue is underflow \n");
	}else
	{
		if(q->front <= q->rear)
		{
			for(i=q->front; i<=q->rear; i++)
			{
				printf(" | %d ",q->items[i]);
			}
		}else
		{
			for(i=q->front; i<=MAX-1; i++)
			{
				printf(" | %d ",q->items[i]);
			}
			for(i=0; i<=q->rear; i++)
			{
				printf(" | %d ",q->items[i]);
			}
		}
	}
}
