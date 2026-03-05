#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; // element found
    }
    return -1; // element not found
}

// Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    int result1 = linearSearch(arr, n, key);
    if(result1 != -1)
        printf("Element found using Linear Search at index %d\n", result1);
    else
        printf("Element not found using Linear Search\n");

    // Binary Search
    int result2 = binarySearch(arr, 0, n-1, key);
    if(result2 != -1)
        printf("Element found using Binary Search at index %d\n", result2);
    else
        printf("Element not found using Binary Search\n");

    return 0;
}