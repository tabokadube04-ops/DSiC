#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insertion
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Deletion
void delete(int key) {
    struct Node *temp = head, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If head node is to be deleted
    if (head->data == key) {
        while (temp->next != head)
            temp = temp->next;

        if (temp == head) {
            free(head);
            head = NULL;
        }
        else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Element not found\n");
    }
    else {
        prev->next = temp->next;
        free(temp);
    }
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main() {

    insert(10);
    insert(20);
    insert(30);

    printf("Circular Linked List:\n");
    display();

    delete(20);

    printf("\nAfter Deletion:\n");
    display();

    return 0;
}