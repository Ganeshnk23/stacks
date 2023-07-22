#include <stdio.h>

void selective_sort(int arr[], int n) {
    int i,j;
    for ( i = 0; i < n-1; i++) {
        int min_index = i;
        for ( j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int arr[] = {3, 7, 1, 9, 2, 6, 5, 8, 4};
    int i, n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selective_sort(arr, n);

    printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
