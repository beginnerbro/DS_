#include<stdio.h>
#define MAX 10
void bubble_sort(int [],int);
int main()
{
	int a[MAX],i,size;
	printf(" enter the size of the array : ");
	scanf("%d",&size);
	printf(" enter the elements : \n");
	for(i=0; i<size; i++)
	{
		scanf("%d",&a[i]);
	}
	printf(" before sorting : \n");
	for(i=0; i<size; i++)
	{
		printf("%d \t",a[i]);
	}
	bubble_sort(a,size);
	printf("\n after sorting : \n");
	for(i=0; i<size; i++)
	{
		printf("%d \t",a[i]);
	}
}
void bubble_sort(int arr[],int n)
{
	int temp,i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j+1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
