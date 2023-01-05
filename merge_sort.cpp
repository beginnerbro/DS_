#include<stdio.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);
int main()
{
	int a[100],size,i;
	printf(" enter size of the array : \n");
	scanf("%d",&size);
	printf("enter elements into the array : \n");
	for(i=0; i<size; i++)
	{
		scanf("%d",&a[i]);
	}
	printf(" elements before swapping : \n");
	for(i=0; i<size; i++)
	{
		printf("%d \t",a[i]);
	}
	mergesort(a,0,size-1);
	printf("\n elements after sorting : \n");
	for(i=0; i<size; i++)
	{
		printf("%d \t",a[i]);
	}
}
void mergesort(int a[100],int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[100],int low,int mid,int high)
{
	int b[100],i,j,k;
	i = low;
	j = mid+1;
	k = low;
	while(i<=mid && j<=high)
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	if(i > mid)
	{
		while(j <= mid)
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}else
	{
		while(i <= high)
		{
			b[k] = a[i];
			k++;
			i++;
		}
	}
	for(i=low; i<=high; i++)
	{
		a[i] = b[i];
	}
}

