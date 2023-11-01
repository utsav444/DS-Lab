#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mid, l, i, arr[100], r, n, x, flag = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    l = 0;
    r = n - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == x)
        {
            printf("Element found");
            flag = 1;
            break;
        }
        if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (!flag)
    {
        printf("No element as same.");
    }

    return 0;
}

