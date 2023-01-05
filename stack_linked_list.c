#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
struct node *getnode();
void push(struct stack *,int);
void pop(struct stack *);
void peek(struct stack *);
void empty(struct stack *);
void display(struct stack *);
int main()
{
    struct stack s;
    s.top = NULL;
    int ch,ele;
    while(1)
    {
         printf("\n 1.push \t 2. pop \t 3.peek \t 4.display \t 5.empty \t 6.exit \n");
         scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf(" enter the element to be pushed : ");
            scanf("%d",&ele);
            push(&s,ele);
            display(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            display(&s);
            break;
        case 5:
            empty(&s);
            break;
        case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
struct node *getnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}
void display(struct stack *st)
{
    struct node *temp;
    temp = st->top;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}
void push(struct stack *st,int ele)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = ele;
    if(st->top == NULL)
    {
        st->top = newnode;
    }else
    {
        newnode->next = st->top;
        st->top = newnode;
    }
}
void pop(struct stack *st)
{
    int x;
    if(st->top == NULL)
    {
        printf(" \n stack is empty \n");
    }else
    {
        x = st->top->data;
        st->top = st->top->next;
        printf("\n | deleted element : %d | \n",x);
    }
}
void peek(struct stack *st)
{
    int res;
    if(st->top == NULL)
    {
        printf(" \n stack is empty \n");
    }else
    {
        res = st->top->data;
        printf(" \n | peek element : %d | \n",res);
    }
}
void empty(struct stack *st)
{
    if(st->top == NULL)
    {
        printf("  \n stack is emptyy \n");
    }else
    {
        printf(" \n stack contain elements \n");
    }
}