#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 20
struct stack
{
    int a[max];
    int top;
};
double eval(char []);
double oper(char,double,double);
void push(struct stack*,double);
double pop(struct stack*);
int empty(struct stack*);
int isoperand(char);
int main()
{
    char a[max];
    printf("Enter the string  :  ");
    scanf("%s",a);
    printf("the value is %f",eval(a));
    return 0;
}
int isoperand(char c)
{
    if(c>='0'&&c<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double eval(char a[])
{
    int i;
    char c;
    double op1,op2,val;
    struct stack s;
    s.top=-1;
    for(i=0;(c=a[i])!='\0';i++)
    {
        if(isoperand(c))
        {
            push(&s,(double)c-'0');
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val=oper(c,op1,op2);
            push(&s,val);
        }
    }
    return pop(&s);
}
double oper(char c,double op1,double op2)
{
    switch (c)
    {
    case '+':
        /* code */
        return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    case '$':return pow(op1,op2);
    
    default:
        break;
    }
}
void push(struct stack *s,double c)
{
    if(s->top==max-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        s->top++;
        s->a[s->top]=c;
    }
}
double pop(struct stack *s)
{
    double c;
    if(s->top==-1)
    {
        return -1;
    }
    else
    {
        c=s->a[s->top];
        s->top--;
        return c;
    }
}
int empty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
