#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition_first(int arr[],int low,int high)      //for first element as pivot
{ 
	int pivot=arr[low];
	int left=low;
	int right=high+1;
	while(left<right)
	{
		do{
			left++;
		}while(left<=high && arr[left]<pivot);
		do{
			right--;
		}while(arr[right]>pivot);
		if(left<right)
			swap(&arr[left],&arr[right]);
	}
	swap(&arr[low],&arr[right]);

	return right;
}
void algorithm_quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int j=partition_first(arr,low,high);
		algorithm_quick_sort(arr,low,j);
		algorithm_quick_sort(arr,j+1,high);
	}
}
int main()
{
	int *arr;
	int n,i;
	printf("Enter the number of array elements: ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the array element: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	algorithm_quick_sort(arr,0,n-1);
	printf("Your sorted array: ");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	free(arr);
	return 0;
}
/*
int partition_end(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=(low-1),j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int j=partition_end(arr,low,high);
		quick_sort(arr,low,j);
		quick_sort(arr,j+1,high);
	}
}
*/
/*
int main()
{
	int ch,n,i;
	while(1)
	{
		printf("-------------------------------------------------------------------------\n");
		printf("          QUICK SORT ALGORITHM- DIVIDE AND CONQUER APPROACH              \n");
		printf("-------------------------------------------------------------------------\n");
		printf("1. Pivot element as first element.\n");
		printf("2. Pivot element as last element.\n");
		printf("3.Exit.\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number of elements in your array: ");
				scanf("%d",&n);
				int *arr1;
				arr1=(int *)malloc(n*sizeof(int));
				printf("Enter the elements of your array: ");
				for(i=0;i<n;i++)
					scanf("%d",&arr1[n]);
				algorithm_quick_sort(arr1,0,n-1);
				printf("Your sorted array is (considering first element is pivot element): ");
				for(i=0;i<n;i++)
					printf("%d",arr1[i]);
				free(arr1);
				break;
			case 2:
				printf("Enter the number of elements in your array: ");
				scanf("%d",&n);
				int *arr2;
				arr2=(int *)malloc(n*sizeof(int));
				printf("Enter the elements of your array: ");
				for(i=0;i<n;i++)
					scanf("%d",&arr2[n]);
				quick_sort(arr1,0,n-1);
				printf("Your sorted array is (considering last element is pivot element): ");
				for(i=0;i<n;i++)
					printf("%d",arr2[i]);
				free(arr2);
				break;
			case 3:
				printf("Thank you for using this program. Plaese visit again for your requirement.\n");
				exit(0);
				break;
			default:
				printf("Wrong input.\n");
				break;
		}
	}
	return 0;
}
*/
