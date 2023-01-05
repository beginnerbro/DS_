#include<stdio.h>
#define MAX 5
struct queue
{
	int items[MAX];
	int front,rear;
};
void enqueue(struct queue *,int);
void dequeue(struct queue *);
void display(struct queue *);
int main()
{
	int choice,ele;
	struct queue q;
	q.front = 0;
	q.rear = -1;
	while(1)
	{
		printf("\n 1.enqueue \t 2.dequeue \t 3.display : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("  enter the element to be inserted : ");
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
void enqueue(struct queue *q,int ele)
{
	if(q->rear == MAX-1)
	{
		printf(" queue is overflow \n");
	}else
	{
		q->rear++;
		q->items[q->rear] = ele;
	}
}
void dequeue(struct queue *q)
{
	int x;
	if(q->rear < q->front)
	{
		printf(" queue is underflow \n");
	}else
	{
		x = q->items[q->front];
		q->front++;
		printf(" element  removed : %d \n",x);
	}
}
void display(struct queue *q)
{
	int i;
	if(q->rear < q->front)
	{
		printf(" queue is underflow \n");
	}else
	{
		for(i=q->front; i<=q->rear;  i++)
		{
			printf("%d |",q->items[i]);
		}
	}
}
