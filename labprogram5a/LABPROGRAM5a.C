#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* create(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    printf("First element (%d) deleted.\n", temp->data);
    free(temp);
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("Last element (%d) deleted. List is now empty.\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Last element (%d) deleted.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteSpecified(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty. Element not found.\n");
        return NULL;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        printf("Element %d deleted.\n", value);
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found in the list.\n", value);
    } else {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        printf("Element %d deleted.\n", value);
        free(nodeToDelete);
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value;
    head =create(head,10);
    head =create(head,20);
    head =create(head,30);
    head =create(head,40);
    head=create(head,50);
    head=create(head,60);
    printf("\n=== LINKED LIST DELETION MENU ===");
    printf("\n1. Delete First Element");
    printf("\n2. Delete Specified Element");
    printf("\n3. Delete Last Element");
    printf("\n4. Display List");
    printf("\n5. Exit");
        while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = deleteFirst(head);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteSpecified(head, value);
                break;
            case 3:
                head = deleteLast(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program. Freeing memory...\n");
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
