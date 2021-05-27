/*A program to sort an array based on heap sort algorithm.*/
#include<stdio.h>
#include<stdlib.h>
void heap_adjust(int arr[],int i,int n)         //to adjust max heap binary tree
{
	int key=arr[i];
	int j=2*i;
	while(j<=n)
	{
		if((j<n) && (arr[j]<arr[j+1]))   // check children value
			j++;
		if(arr[j]<key)     //check parent value
			break;
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=key;
}
void heapify(int arr[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heap_adjust(arr,i,n);
	}
}
void display(int arr[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}
void heapsort(int arr[],int n)
{
	int i;
	heapify(arr,n);
	for(i=n;i>=2;i--)
	{
		int temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		heap_adjust(arr,1,i-1);
		display(arr,n);
	}
}
int main()
{
	int *arr;
	int n,i;
	printf("Heap Sort Technique Implementation\n");
	printf("-----------------------------------------------\n");
	printf("Enter the number of element: ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter array element:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Your entered array is:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
	printf("Passes of Heap Sort:\n");
	printf("----------------------------------------\n");
	heapsort(arr,n);
	printf("\nYour sorted array will be: \n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
	free(arr);
	return 0;
}
