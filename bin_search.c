#include<stdio.h>
#define MAX 10
int bin_search(int [],int,int,int);
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
	res = bin_search(arr,0,size,k);
	if(res == -1)
	{
		printf("\n element not found \n");
	}else
	{
		printf(" \n element found at %d index",res);
	}
}
int bin_search(int a[],int low,int high,int key)
{
	int mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid] == key)
		{
			return mid;
		}else if(a[mid] < key)
		{
			low = mid+1;
		}else
		{
			high = mid-1;
		}
	}
	return -1;
}
