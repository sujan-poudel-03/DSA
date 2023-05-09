#include <stdio.h>

void traversal(int arr[], int size) {
    printf("-------------------Traversal Operation------------------- \n");

    printf("[");

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("]\n");
}

void insert(int arr[], int size, int index, int element) {
    printf("-------------------Insert Operation------------------- \n");

    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    size++;

    printf("Element inserted successfully \n");
    printf("Now the new array is : \n");
    traversal(arr, size);
}

void delete(int arr[], int size, int index) {
    printf("-------------------Delete Operation------------------- \n");

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Element deleted successfully \n");
    printf("Now the new array is : \n");
    traversal(arr, size);
}

void search(int arr[], int size, int element) {
    printf("-------------------Search Operation------------------- \n");

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at index %d \n", i);
            return;
        }
    }

    printf("Element not found \n");
}

void update(int arr[], int size, int index, int element) {
    printf("-------------------Update Operation------------------- \n");

    arr[index] = element;

    printf("Element updated successfully \n");
    printf("Now the new array is : \n");
    traversal(arr, size);
}

void main() {
    int arr[10] = {1, 3, 5, 7, 9};

    int size = 5;
    printf("Size of array is : %d \n", size);

    traversal(arr, size);

    insert(arr, size, 2, 10);
    delete (arr, size, 2);
    search(arr, size, 7);
    update(arr, size, 2, 10);
}
