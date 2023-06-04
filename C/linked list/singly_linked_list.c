#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}

void insertFront(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    printf("%d inserted at the front of the list.\n", data);
}

void insertEnd(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("%d inserted at the end of the list.\n", data);
}

void update(struct LinkedList* list, int oldValue, int newValue) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            printf("Value %d updated with new value: %d\n", oldValue, newValue);
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", oldValue);
}

void delete(struct LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;

    if (current != NULL && current->data == data) {
        list->head = current->next;
        free(current);
        printf("Value %d deleted from the list.\n", data);
        return;
    }

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", data);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Value %d deleted from the list.\n", data);
}

void display(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList* list = createLinkedList();

    insertFront(list, 5);     // Insert 5 at the front
    insertFront(list, 10);    // Insert 10 at the front
    insertEnd(list, 15);      // Insert 15 at the end

    display(list);            // Output: List: 10 5 15

    update(list, 5, 20);      // Update 5 with 20
    display(list);            // Output: List: 10 20 15

    delete(list, 10);         // Delete 10
    display(list);            // Output: List: 20 15

    return 0;
}
