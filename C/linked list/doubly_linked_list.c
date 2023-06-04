#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

struct DoublyLinkedList* createDoublyLinkedList() {
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    printf("%d inserted at the front of the list.\n", data);
}

void insertAtEnd(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("%d inserted at the end of the list.\n", data);
}

void update(struct DoublyLinkedList* list, int oldValue, int newValue) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            printf("%d updated with new value: %d\n", oldValue, newValue);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", oldValue);
}

void delete(struct DoublyLinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL)
                    list->head->prev = NULL;
                else
                    list->tail = NULL;
            } else if (current == list->tail) {
                list->tail = current->prev;
                list->tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("%d deleted from the list.\n", data);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", data);
}

void display(struct DoublyLinkedList* list) {
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
    struct DoublyLinkedList* list = createDoublyLinkedList();

    insertAtFront(list, 3);     // Insert 3 at the front
    insertAtFront(list, 2);     // Insert 2 at the front
    insertAtEnd(list, 4);       // Insert 4 at the end

    display(list);              // Output: List: 2 3 4

    update(list, 2, 5);         // Update 2 with 5
    update(list, 6, 7);         // Update 6 (not found)

    delete(list, 3);            // Delete 3
    delete(list, 6);            // Delete 6 (not found)

    display(list);              // Output: List: 2 4

    return 0;
}
