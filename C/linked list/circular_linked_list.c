#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
    } else {
        newNode->next = (*head)->next;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head->next;
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the circular linked list
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Displaying the circular linked list
    printf("Circular Linked List: ");
    displayList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}
