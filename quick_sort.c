#include<stdio.h>
int partition(int[],int,int);
void quickSort(int[],int,int);
int main()
{
	int a[10],i,size;
	printf("Enter size of the array : \n");
	scanf("%d",&size);
	printf("Enter elements in array : \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Elements before swapping : \n");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
	quickSort(a,0,size-1);
	
	printf("\nElements after swapping : \n");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}	
	
}
void quickSort(int a[10],int low, int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quickSort(a,low,j-1);
		quickSort(a,j+1,high);
	}
}
int partition(int a[10],int low,int high)
{
	int i,j,pivot,temp;
	pivot=a[low];
	i=low;
	j=high;
	while(i<j)
	{
		while(a[i]<=pivot && i<high)
		{
			i++;
		}
		while(a[j]>pivot && j>low)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
