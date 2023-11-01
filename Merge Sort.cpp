#include <stdio.h>

void merge_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        int b[ub - lb + 1];
        int i = lb, j = mid + 1, m = 0, k;

        while (i <= mid && j <= ub)
        {
            if (a[i] < a[j])
            {
                b[m] = a[i];
                i++;
            }
            else
            {
                b[m] = a[j];
                j++;
            }
            m++;
        }

        while (i <= mid)
        {
            b[m] = a[i];
            i++;
            m++;
        }

        while (j <= ub)
        {
            b[m] = a[j];
            j++;
            m++;
        }

        for (k = 0; k < m; k++)
        {
            a[lb + k] = b[k];
        }
    }
}


int main()
{
    int arr[100];
    int arr_size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

