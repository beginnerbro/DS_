#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode();
struct node *create();
void display(struct node *);
struct node *insert(struct node *);
struct node *deleted(struct node *);
int main()
{
    int ch;
    struct node *np;
    np = create();
    display(np);
    while(1)
    {
        printf(" \n 1.INSERT \t 2.DISPLAY \t 3.DELETE \t 4.EXIT : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                 np = insert(np);
                 display(np);
                 break;
            case 2:
                 display(np);
                 break;
            case 3:
                 np = deleted(np);
                 display(np);
                 break;
            case 4:
                 exit(0);
                 break;
        }
    }
    return 0;
}
struct node *getnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}
struct node *create()
{
    struct node *head,*first,*newnode;
    first = getnode();
    head = first;
    newnode = getnode();
    printf(" enter value except -9 : ");
    scanf("%d",&newnode->data);
    while(newnode->data != -9)
    {
        first->next = newnode;
        first = newnode;
        newnode = getnode();
        printf(" enter value except -9 : ");
        scanf("%d",&newnode->data);
    }
    return head->next;
}
void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}
struct node *insert(struct node *head)
{
    int ch1,pos,i;
    struct node *newnode,*temp;
    newnode = getnode();
    temp = head;
    printf(" enter the value : ");
    scanf("%d",&newnode->data);
    printf(" \n 1. AT BEGINING \t 2. AT END \t 3. AT SPECIFIC POSITION : ");
    scanf("%d",&ch1);
    switch(ch1)
    {
        case 1:
             newnode->next = head;
             head = newnode;
             return head;
             break;
        case 2:
            while(temp->next != NULL)
            {
                  temp = temp->next;
            }
             temp->next = newnode;
              return head;
              break;
        case 3:
            printf(" enter the specific position : ");
            scanf("%d",&pos);
            if(pos == 1)
            {
                 newnode->next = head;
                head = newnode;
                return head;
            }else
            {
                for(i=1; i<pos-1; i++)
                {
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
                return head;
                break;
            }
    }
}
struct node *deleted(struct node *head)
{
    int ch2,pos1,i;
    struct node *temp;
    temp = head;
    if(head == NULL)
    {
        printf("\n linked list is empty \n");
        return head;
    }else
    {
         printf(" \n 1.AT BEGINING \t 2. AT END \t 3. AT SPECIFIC POSITION : ");
         scanf("%d",&ch2);
         switch(ch2)
         {
            case 1:
                head = head->next;
                temp->next = NULL;
                return head;
                break;
            case 2:
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
                return head;
                break;
            case 3:
                printf(" enter the position : ");
                scanf("%d",&pos1);
                if(pos1 == 1)
                {
                    head = head->next;
                    temp->next = NULL;
                    return head;
                }else
                {
                    for(i=1; i<pos1-1; i++)
                    {
                        temp = temp->next;
                    }
                    temp->next = temp->next->next;
                    return head;
                    break;
                }
         }
    }
}
