#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[100];
    int id;
    struct Employee* next;
};

struct Employee* createEmployeeNode(char name[], int id) {
    struct Employee* employeeNode = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(employeeNode->name, name);
    employeeNode->id = id;
    employeeNode->next = NULL;
    return employeeNode;
}

struct Employee* insertEmployeeAtBeginning(struct Employee* head, char name[], int id) {
    struct Employee* newEmployee = createEmployeeNode(name, id);
    newEmployee->next = head;
    head = newEmployee;
    return head;
}

struct Employee* insertEmployeeAtEnd(struct Employee* head, char name[], int id) {
    struct Employee* newEmployee = createEmployeeNode(name, id);
    if (head == NULL) {
        head = newEmployee;
    } else {
        struct Employee* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmployee;
    }
    return head;
}

void updateEmployee(struct Employee* head, int id, char newName[]) {
    struct Employee* current = head;
    while (current != NULL) {
        if (current->id == id) {
            strcpy(current->name, newName);
            printf("Employee with ID %d has been updated with a new name: %s\n", id, newName);
            return;
        }
        current = current->next;
    }
    printf("No employee found with ID %d\n", id);
}

struct Employee* deleteEmployee(struct Employee* head, int id) {
    if (head == NULL) {
        printf("No employees in the list\n");
        return head;
    }

    if (head->id == id) {
        struct Employee* temp = head;
        head = head->next;
        free(temp);
        printf("Employee with ID %d has been deleted\n", id);
        return head;
    }

    struct Employee* current = head;
    while (current->next != NULL) {
        if (current->next->id == id) {
            struct Employee* temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Employee with ID %d has been deleted\n", id);
            return head;
        }
        current = current->next;
    }

    printf("No employee found with ID %d\n", id);
    return head;
}

void displayEmployees(struct Employee* head) {
    if (head == NULL) {
        printf("No employees in the list\n");
    } else {
        struct Employee* current = head;
        while (current != NULL) {
            printf("Employee Name: %s ID: %d\n", current->name, current->id);
            current = current->next;
        }
    }
}

int main() {
    struct Employee* employeeList = NULL;
    employeeList = insertEmployeeAtBeginning(employeeList, "John Doe", 101);
    employeeList = insertEmployeeAtEnd(employeeList, "Jane Smith", 102);
    employeeList = insertEmployeeAtEnd(employeeList, "Mike Johnson", 103);
    displayEmployees(employeeList);

    updateEmployee(employeeList, 102, "Jane Miller");
    displayEmployees(employeeList);

    employeeList = deleteEmployee(employeeList, 101);
    displayEmployees(employeeList);

    return 0;
}
