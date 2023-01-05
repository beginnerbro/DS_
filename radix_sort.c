#include<stdio.h>
void radixsort(int [],int);
int largest(int [],int);
int no_of_digits(int);
int main()
{
	int arr[20],i,n;
	printf(" enter the size of the array : ");
	scanf("%d",&n);
	printf(" enter the elements : \n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf(" before sorting : \n");
	for(i=0; i<n; i++)
	{
		printf("%d \t ",arr[i]);
	}
	radixsort(arr,n);
	printf("\n after sorting : \n");
	for(i=0; i<n; i++)
	{
		printf("%d \t",arr[i]);
	}
}
int largest(int a[],int n)
{
	int large=a[0],i;
	for(i=1; i<n; i++)
	{
		if(a[i] > large)
		{
			large = a[i];
		}
	}
	return large;
}
int no_of_digits(int num)
{
	int digits=0;
	while(num > 0)
	{
		digits += 1;
		num = num/10;
	}
	return digits;
}
void radixsort(int a[],int n)
{
	int pass,nopass,i,j,k,rem,div=1;
	int bucket[10][12],bc[10];
	int large;
	large = largest(a,n);
	nopass = no_of_digits(large);
	for(pass=0; pass<nopass; pass++)
	{
		for(i=0; i<10; i++)
		{
			bc[i]=0;
		}
		for(i=0; i<n; i++)
		{
			rem = (a[i]/div)%10;
			bucket[rem][bc[rem]] = a[i];
			bc[rem] += 1;
		}
		i=0;
		for(k=0; k<10; k++)
		{
			for(j=0; j<bc[k]; j++)
			{
				a[i] = bucket[k][j];
				i++;
			}
		}
		div = div*10;
	}
}
