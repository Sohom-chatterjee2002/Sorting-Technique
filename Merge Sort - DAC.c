/* Merge sort- Divide and Conquer Approach*/
#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high)
{
	int i,j,k;
	int b[10];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		arr[i]=b[i];
	}
}
void merge_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;      //divide
		merge_sort(arr,low,mid);   //conquer
		merge_sort(arr,mid+1,high);  //conquer
		merge(arr,low,mid,high);   //combine
	}
}
int main()
{
	int *arr;
	int n,i;
	printf("Enter the number of array elements: ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter your array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("your sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	free(arr);
	return 0;
}
