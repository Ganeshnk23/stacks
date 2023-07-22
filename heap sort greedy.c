#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if (left_child < n && arr[left_child] > arr[largest]) {
        largest = left_child;
    }
    if (right_child < n && arr[right_child] > arr[largest]) {
        largest = right_child;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    int i;
    for ( i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for ( i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {int i;
    int arr[] = {3, 7, 1, 9, 2, 6, 5, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heap_sort(arr, n);

    printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
