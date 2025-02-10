#include <stdio.h>
#include <stdlib.h>

void selection(int arr[], int n)
{
	int i, j ;
	for (i=0; i<n-1; i++)
	{
		int min =i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j] > arr[min])
			{
				min = j;
				int temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp; 
			}
			
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of elements of the array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of array : ");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	selection(arr, n);
	
	printf("Sorted elements are :");
	for (int x=0; x<n; x++)
	{
		printf("%d", arr[x]);
	}
	
	return 0;
}











