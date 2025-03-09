#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the linked list
struct Node {
    int data;               // Data field to store the value
    struct Node* next;      // Pointer to the next node in the list
};

// Define a structure for the LinkedList
struct LinkedList {
    struct Node* head;      // Pointer to the first node (head) of the list
};

// Function to create an empty linked list
struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;      // Initialize head as NULL (empty list)
    return list;
}

// Function to insert a node at the front of the list
void insertFront(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data;   // Assign the given data to the new node
    newNode->next = list->head; // Point new node to current head
    list->head = newNode;   // Update head to new node
    printf("%d inserted at the front of the list.\n", data);
    printf("Current head: %d\n", list->head->data); // Print the new head
}

// Function to insert a node at the end of the list
void insertEnd(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data;   // Assign the given data to the new node
    newNode->next = NULL;   // Set new node's next to NULL (as it will be the last node)

    if (list->head == NULL) { // If list is empty, make newNode the head
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) { // Traverse to the last node
            current = current->next;
        }
        current->next = newNode; // Update last node's next pointer to new node
    }
    printf("%d inserted at the end of the list.\n", data);
    printf("Current head: %d\n", list->head->data); // Print the head
}

// Function to update a node's value in the list
void update(struct LinkedList* list, int oldValue, int newValue) {
    struct Node* current = list->head;
    while (current != NULL) { // Traverse the list
        if (current->data == oldValue) { // If oldValue is found, update it
            current->data = newValue;
            printf("Value %d updated to %d\n", oldValue, newValue);
            printf("Current head: %d\n", list->head->data); // Print the head
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", oldValue);
}

// Function to delete a node with a specific value
void delete(struct LinkedList* list, int data) {
    if (list->head == NULL) { // If list is empty
        printf("List is empty.\n");
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;

    // If head node holds the value to be deleted
    if (current != NULL && current->data == data) {
        list->head = current->next; // Move head to the next node
        free(current); // Free memory
        printf("Value %d deleted from the list.\n", data);
        printf("Current head: %d\n", list->head ? list->head->data : -1); // Print the new head (or -1 if list is empty)
        return;
    }

    // Traverse the list to find the node to be deleted
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If value is not found
    if (current == NULL) {
        printf("Value %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the list and free memory
    prev->next = current->next;
    free(current);
    printf("Value %d deleted from the list.\n", data);
    printf("Current head: %d\n", list->head ? list->head->data : -1); // Print the new head (or -1 if list is empty)
}

// Function to display the linked list
void display(struct LinkedList* list) {
    if (list->head == NULL) { // If list is empty
        printf("List is empty.\n");
        return;
    }
    struct Node* current = list->head;
    printf("List: ");
    while (current != NULL) { // Traverse the list
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    struct LinkedList* list = createLinkedList(); // Create an empty linked list

    insertFront(list, 5);     // Insert 5 at the front
    insertFront(list, 10);    // Insert 10 at the front
    insertEnd(list, 15);      // Insert 15 at the end
    display(list);            // Output: List: 10 5 15

    update(list, 5, 20);      // Update value 5 to 20
    display(list);            // Output: List: 10 20 15

    delete(list, 10);         // Delete value 10
    display(list);            // Output: List: 20 15

    return 0;
}
