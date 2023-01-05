#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *getNode();
struct node *create(struct node *);
void insert(struct node *,struct node *);
void insert(struct node *,struct node *);
struct node *getnode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *create(struct node *root)
{
    struct node *newnode;
    newnode = getnode();
    printf(" enter the value except -99 : ");
    scanf("%d",&newnode->data);
    while(newnode->data != -99)
    {
         if(root == NULL)
        {
                root = newnode;
        }else
        {
             insert(root,newnode);
             newnode = getnode();
             printf(" enter the value except -99 : ");
            scanf("%d",&newnode->data);
        }
    }
    return root;
}
void insert(struct node *root,struct node *newnode)
{
    if(newnode->data < root->data)
    {
        if(root->left == NULL)
        {
            root->left = newnode;
        }
    }else
    {
        insert(root->left,newnode);
    }
    if(newnode->data > root->data)
    {
        if(root->right == NULL)
        {
            root->right = newnode;
        }
    }else
    {
        insert(root->right,newnode);
    }
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d->",root->data);
    }
}
int main()
{
    struct  node *root;
    root = NULL;
    int ch;
    root = create(root);
    while(1)
    {
        printf("1.inorder \t 2.preorder \t 3.postorder \t 4.exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}