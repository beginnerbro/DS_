#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front,*rear;
};
struct node *getnode();
void insert(struct queue *,int);
void deleted(struct queue *);
void display(struct queue *);
int main()
{
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    int ch,ele;
    while(1)
    {
        printf("1.insert \t 2.delete \t 3.display : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf(" enter the element to be inserted : ");
                scanf("%d",&ele);
                insert(&q,ele);
                display(&q);
                break;
            case 2:
                deleted(&q);
                display(&q);
                break;
            case 3:
                display(&q);
                break;
        }
    }
    return 0;
}
struct node *getnode()
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}
void insert(struct queue *q,int ele)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = ele;
    if(q->front == NULL)
    {
        q->rear = q->rear = newnode;
    }else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}
void deleted(struct queue *q)
{
    int x;
    if(q->front > q->rear)
    {
        printf("\n -- list is empty -- \n");
    }else
    {
        x = q->front->data;
        q->front = q->front->next;
        printf("deleted element : %d",x);
    }
}
void display(struct queue *q)
{
    struct node *temp;
    temp = q;
    while(temp->next != NULL)
    {
        printf("\n %d->",temp->data);
        temp = temp->next;
    }
}