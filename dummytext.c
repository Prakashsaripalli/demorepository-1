#include <stdio.h>

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == x) {
            printf("Element is present at index %d\n", x);
            return 0; 
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element is not present in array\n");
    return 0;
}



