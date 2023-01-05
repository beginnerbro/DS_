#include<stdio.h>
#define MAX 10
int linear_search(int [],int,int);
int main()
{
	int arr[MAX],k,size,res,i;
	printf(" enter the size of the array : ");
	scanf("%d",&size);
	printf("\n enter the elements : ");
	for(i=0; i<size; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf(" enter the key element : ");
	scanf("%d",&k);
	res = linear_search(arr,size,k);
	if(res == -1)
	{
		printf("\n element not found \n");
	}else
	{
		printf(" \n element found at %d index",res);
	}
}
int linear_search(int a[],int s,int key)
{
	int i;
	for(i=0; i<s; i++)
	{
		if(a[i] == key)
		{
			return i;
			break;
		}
	}
	return -1;
}
