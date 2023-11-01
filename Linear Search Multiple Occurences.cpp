#include <stdio.h>

void linearSearchMultiple(int arr[], int size, int target) {
    int occurrences = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            occurrences++;
        }
    }

    if (occurrences == 0)
        printf("Element not found\n");
    else
        printf("Total occurrences: %d\n", occurrences);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    linearSearchMultiple(arr, n, target);

    return 0;
}

