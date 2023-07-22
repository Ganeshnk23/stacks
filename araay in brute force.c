#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for ( i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 5, 15, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 1;
    int index = search(arr, n, x);
    if (index == -1) {
        printf("%d is not found in the array", x);
    } else {
        printf("%d is found at index %d", x, index);
    }
    return 0;
}
