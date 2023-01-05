#include<stdio.h>
void insertion_sort(int[],int);
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
	insertion_sort(a,size);
	printf("\nElements after swapping : \n");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}	
	
}
void insertion_sort(int a[10],int n)
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		temp = a[i];
		for(j=i-1; j>=0; j--)
		{
			if(a[j] > temp)
			{
				a[j+1] = a[j];
			}else
			{
				break;
			}
		}
		a[j+1] = temp;
	}
}

