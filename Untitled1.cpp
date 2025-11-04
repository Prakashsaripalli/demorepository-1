#include <stdio.h>

// Merge function (combines two sorted halves)
void mergesort(int arr[], int low, int mid, int high) {
    int b[100];  // temporary array (should be large enough)
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    // Copy remaining elements from the left sub-array
    while (i <= mid)
        b[k++] = arr[i++];

    // Copy remaining elements from the right sub-array
    while (j <= high)
        b[k++] = arr[j++];

    // Copy sorted elements back into original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = b[k];
}

// Merge sort recursive function
void merge(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        mergesort(arr, low, mid, high);
    }
}

// Main function
int main() {
    int n, i, a[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
