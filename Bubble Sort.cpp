#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
        }
        printf("Array after each step is : ");
    	for (int x=0; x<n; x++)
    	{
    		printf("%d",arr[x]);
		}
		printf("\n");
		
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
	bubbleSort(arr, n);
	
	return 0;
}











