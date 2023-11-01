#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int n)
{
	int i, j ,temp;
	for (i=0; i<n; i++)
	{
		temp = arr[i];
		j = i-1;
		while (j>=0 && temp <= arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main()
{
	int n, arr[100];
	printf("Enter the number of elements of the array : ");
	scanf("%d", &n);
	
	printf("Enter the elements of array : ");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	insert(arr, n);
	
	printf("Sorted elements are :");
	for (int i=0; i<n; i++)
	{
		printf("%d", arr[i]);
	}
	
	return 0;
}











