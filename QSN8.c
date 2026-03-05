#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBegin(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Delete a node
void deleteNode(int key) {
    struct Node *temp = head, *prev = NULL;

    // If head node holds the value
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
}

// Display linked list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertBegin(30);
    insertBegin(20);
    insertBegin(10);

    printf("Linked List after insertion:\n");
    display();

    deleteNode(20);

    printf("Linked List after deletion:\n");
    display();

    return 0;
}