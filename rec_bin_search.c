#include<stdio.h>
#define MAX 10
int rec_bin_search(int [],int,int,int);
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
	res = rec_bin_search(arr,0,size,k);
	if(res == -1)
	{
		printf("\n element not found \n");
	}else
	{
		printf(" \n element found at %d index",res);
	}
}
int rec_bin_search(int a[],int low,int high,int key)
{
	int mid;
	if(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid] == key)
		{
			return mid;
		}else if(a[mid] < key)
		{
			return rec_bin_search(a,mid+1,high,key);
		}else
		{
			return rec_bin_search(a,low,mid-1,key);
		}
	}
	return -1;
}
