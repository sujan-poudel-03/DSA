#include <stdio.h>

#define MAX_SIZE 100

struct List {
    int arr[MAX_SIZE];
    int size;
};

void initList(struct List* list) {
    list->size = 0;
}

void insert(struct List* list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return;
    }

    if (list->size == MAX_SIZE) {
        printf("List is full!\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = list->size; i > position; i--) {
        list->arr[i] = list->arr[i - 1];
    }

    list->arr[position] = data;
    list->size++;
}

void removeElement(struct List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left to remove the element at the given position
    for (int i = position; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    list->size--;
}

void update(struct List* list, int data, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position!\n");
        return;
    }

    list->arr[position] = data;
}

void display(struct List* list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int main() {
    struct List myList;

    initList(&myList);

    insert(&myList, 5, 0);    // Insert 5 at position 0
    insert(&myList, 10, 1);   // Insert 10 at position 1
    insert(&myList, 15, 1);   // Insert 15 at position 1

    display(&myList);         // Output: List: 5 15 10

    update(&myList, 20, 1);   // Update element at position 1 to 20

    display(&myList);         // Output: List: 5 20 10

    removeElement(&myList, 0);    // Remove element at position 0

    display(&myList);         // Output: List: 20 10

    return 0;
}
