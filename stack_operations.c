#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
	int top;
	int item[MAX];
};
void push(struct stack *,int);
void pop(struct stack *);
void display(struct stack *);
void peek(struct stack *);
void isempty(struct stack *);
int main()
{
	struct stack st;
	st.top = -1;
	int choice,val;
	z:
	printf("1.push \t 2.pop \t 3.display \t 4.isempty \t 5.peek \t 6.exit \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf(" enter the element to be pushed into the stack : \n");
			scanf("%d",&val);
			push(&st,val);
			goto z;
			break;
		case 2:
			pop(&st);
			goto z;
			break;
		case 3:
			display(&st);
			goto z;
			break;
		case 4:
			isempty(&st);
			goto z;
			break;
		case 5:
			peek(&st);
			goto z;
			break;
		case 6:
			exit(0);
			break;
	}
}
void push(struct stack *st,int val)
{
	if(st->top == MAX-1)
	{
		printf(" -- stack overflow --\n");
	}else
	{
		st->top += 1;
		st->item[st->top] = val;
	}
}
void pop(struct stack *st)
{
	int x;
	if(st->top == -1)
	{
		printf(" -- stack underflow -- \n");
	}else
	{
		x = st->item[st->top];
		st->top = st->top-1;
		printf(" deleted element : |%d| \n",x);
	}
}
void display(struct stack *st)
{
	int i;
	if(st->top == -1)
	{
		printf(" -- stack is empty --\n");
	}else
	{
		for(i=st->top; i>=0; i--)
		{
			printf("|%d|\n",st->item[i]);
		}
	}
}
void isempty(struct stack *st)
{
	if(st->top == -1)
	{
		printf(" - stack underflow -- \n");
	}else
	{
		printf(" stack contain elements \n");
	}
}
void peek(struct stack *st)
{
	int x;
	if(st->top == -1)
	{
		printf(" -- stack underflow -- \n");
	}else
	{
		x = st->item[st->top];
		printf(" peek element : |%d| \n",x);
	}
}
