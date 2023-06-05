#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct ToDoList {
    char tasks[MAX_SIZE][100];
    int size;
};

void initList(struct ToDoList* list) {
    list->size = 0;
}

void addTask(struct ToDoList* list, char task[]) {
    if (list->size == MAX_SIZE) {
        printf("List is full! Cannot add more tasks.\n");
        return;
    }
    
    strcpy(list->tasks[list->size], task);
    list->size++;
}

void displayTasks(struct ToDoList* list) {
    if (list->size == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    
    printf("Tasks:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

int main() {
    struct ToDoList myToDoList;
    initList(&myToDoList);
    
    addTask(&myToDoList, "Buy groceries");
    addTask(&myToDoList, "Pay bills");
    addTask(&myToDoList, "Do laundry");
    
    displayTasks(&myToDoList);

    return 0;
}
