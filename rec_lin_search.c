#include<stdio.h>
#define MAX 10
int rec_linear_search(int [],int,int);
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
	res = rec_linear_search(arr,size,k);
	if(res == -1)
	{
		printf("\n element not found \n");
	}else
	{
		printf(" \n element found at %d index",res);
	}
}
int rec_linear_search(int a[],int s,int key)
{
	if(key < 0)
	{
		return -1;
	}else if(a[s] == key)
	{
		return s;
	}else
	{
		return rec_linear_search(a,s-1,key);
	}
}
