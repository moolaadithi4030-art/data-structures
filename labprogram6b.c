#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node *front = NULL, *rear = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto Stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from Stack.\n", top->data);
    top = top->next;
    free(temp);
}

void peekStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into Queue.\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d from Queue.\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void peekQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void stackMenu() {
    int choice, val;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek (Top)\n4. Display Stack\n5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peekStack();
                break;
            case 4:
                displayStack();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void queueMenu() {
    int choice, val;
    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek (Front)\n4. Display Queue\n5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekQueue();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}


int main() {
    int mainChoice;
    while (1) {
        printf("\n==============================\n");
        printf("  MAIN MENU (LINKED LIST)     \n");
        printf("==============================\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                stackMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}
