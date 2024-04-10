#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at a specified position in the linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node at a specified position in the linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int currentPosition = 1;
    while (currentPosition < position && current != NULL) {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    head = insertAtPosition(head, 1, 1);
    head = insertAtPosition(head, 2, 2);
    head = insertAtPosition(head, 3, 3);
    head = insertAtPosition(head, 4, 4);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Insert a node at position 3
    head = insertAtPosition(head, 10, 3);
    printf("After inserting 10 at position 3: ");
    printList(head);

    // Delete the node at position 2
    head = deleteAtPosition(head, 2);
    printf("After deleting node at position 2: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
