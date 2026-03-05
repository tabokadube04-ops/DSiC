#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* ---------- STACK USING LINKED LIST ---------- */

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct Node* temp = top;
    printf("Stack: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- QUEUE USING LINKED LIST ---------- */

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct Node* temp = front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- CIRCULAR QUEUE USING LINKED LIST ---------- */

struct Node *cfront = NULL, *crear = NULL;

void insertCQ(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(cfront == NULL) {
        cfront = crear = newNode;
        newNode->next = cfront;
    }
    else {
        crear->next = newNode;
        crear = newNode;
        crear->next = cfront;
    }
}

void deleteCQ() {
    if(cfront == NULL) {
        printf("Circular Queue Underflow\n");
        return;
    }

    struct Node* temp = cfront;
    printf("Deleted element: %d\n", temp->data);

    if(cfront == crear) {
        cfront = crear = NULL;
    }
    else {
        cfront = cfront->next;
        crear->next = cfront;
    }

    free(temp);
}

void displayCQ() {
    if(cfront == NULL) {
        printf("Circular Queue is empty\n");
        return;
    }

    struct Node* temp = cfront;
    printf("Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != cfront);

    printf("\n");
}

/* ---------- MAIN FUNCTION ---------- */

int main() {

    /* Stack Operations */
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    printf("\n");

    /* Queue Operations */
    enqueue(5);
    enqueue(15);
    enqueue(25);
    displayQueue();
    dequeue();
    displayQueue();

    printf("\n");

    /* Circular Queue Operations */
    insertCQ(1);
    insertCQ(2);
    insertCQ(3);
    displayCQ();
    deleteCQ();
    displayCQ();

    return 0;
}