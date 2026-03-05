#include <stdio.h>
#define MAX 100   // Maximum size of the array
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Current Array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int insert(int arr[], int n, int element, int position) {
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    if (position < 0 || position > n) {
        printf("Invalid position!\n");
        return n;
    }
    // Shift elements to the right
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    printf("Inserted %d at position %d.\n", element, position);
    return n + 1;
}
int delete(int arr[], int n, int element) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Element %d not found in the array.\n", element);
        return n;
    }
    // Shift elements to the left
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Deleted %d from the array.\n", element);
    return n - 1;
}
int main() {
    int arr[MAX];
    int n = 0;  // Current size of the array
    int choice, element, position;
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &position);
                n = insert(arr, n, element, position);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                n = delete(arr, n, element);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
