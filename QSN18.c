#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
#define NAME_LENGTH 50
char queue[MAX][NAME_LENGTH];
int front = -1;
int rear = -1;
// Check if queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}
// Check if queue is empty
int isEmpty() {
    return front == -1;
}
// Add patient (Enqueue)
void addPatient() {
    if (isFull()) {
        printf("\nQueue is full! Cannot add more patients.\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter patient name: ");
    scanf(" %[^\n]", name);
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    strcpy(queue[rear], name);
    printf("Patient %s added successfully.\n", name);
}
// View next patient (Peek)
void viewNextPatient() {
    if (isEmpty()) {
        printf("\nNo patients waiting.\n");
        return;
    }
    printf("\nNext patient: %s\n", queue[front]);
}
// Serve patient (Dequeue)
void servePatient() {
    if (isEmpty()) {
        printf("\nNo patients to serve.\n");
        return;
    }
    printf("\nPatient %s has been served.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  // Queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}
// Display all waiting patients
void displayPatients() {
    if (isEmpty()) {
        printf("\nNo patients in queue.\n");
        return;
    }
    printf("\nWaiting Patients:\n");
    int i = front;
    while (1) {
        printf("- %s\n", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
// Main function
int main() {
    int choice;
    do {
        printf("\n===== Clinic Appointment System =====\n");
        printf("1. Add Patient\n");
        printf("2. View Next Patient\n");
        printf("3. Serve Patient\n");
        printf("4. Display All Patients\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewNextPatient();
                break;
            case 3:
                servePatient();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                printf("\nExiting system...\n");
               break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

