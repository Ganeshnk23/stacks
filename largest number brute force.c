#include <stdio.h>

int findLargest(int arr[], int n) {
    int i;

    int largest = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int arr[] = {19, 6, 14, 3, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int largest = findLargest(arr, n);
    printf("The largest number in the array is %d", largest);
    return 0;
}

