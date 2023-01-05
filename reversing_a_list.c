#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode();
struct node *create();
struct node *reverse(struct node *);
void traversal(struct node *);
int main()
{
    struct node *np,*rnpp;
    np = create();
    traversal(np);
    printf("\n reversing a list : \n");
    rnpp = reverse(np);
    traversal(rnpp);
}
struct node *getnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}
struct node *create()
{
    struct node *first,*head,*newnode;
    first = getnode();
    head = first;
    newnode = getnode();
    printf(" enter a value except -99 :");
    scanf("%d",&newnode->data);
    while(newnode->data != -99)
    {
        first->next = newnode;
        first = newnode;
        newnode = getnode();
        printf(" enter a value except -99 :");
        scanf("%d",&newnode->data);
    }
    return head->next;
}
void traversal(struct node *head)
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}
struct node *reverse(struct node *head)
{
    struct node *temp,*rhead,*newnode;
    temp = head;
    rhead = getnode();
    rhead->data = temp->data;
    while(temp->next != NULL)
    {
        temp = temp->next;
        newnode = getnode();
        newnode->data = temp->data;
        newnode->next = rhead;
        rhead = newnode;
    }
    return rhead;
}
