#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    struct Student* prev;
    struct Student* next;
};

struct StudentDatabase {
    struct Student* head;
    struct Student* tail;
};

struct StudentDatabase* createStudentDatabase() {
    struct StudentDatabase* database = (struct StudentDatabase*)malloc(sizeof(struct StudentDatabase));
    database->head = NULL;
    database->tail = NULL;
    return database;
}

struct Student* createStudent(int rollNumber, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(struct StudentDatabase* database, int rollNumber, const char* name) {
    struct Student* newStudent = createStudent(rollNumber, name);
    if (database->head == NULL) {
        database->head = newStudent;
        database->tail = newStudent;
    } else {
        newStudent->prev = database->tail;
        database->tail->next = newStudent;
        database->tail = newStudent;
    }
    printf("Student with Roll Number %d inserted into the database.\n", rollNumber);
}

void updateStudent(struct StudentDatabase* database, int rollNumber, const char* newName) {
    struct Student* current = database->head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            strcpy(current->name, newName);
            printf("Student with Roll Number %d updated with new name: %s\n", rollNumber, newName);
            return;
        }
        current = current->next;
    }
    printf("Student with Roll Number %d not found in the database.\n", rollNumber);
}

void deleteStudent(struct StudentDatabase* database, int rollNumber) {
    struct Student* current = database->head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            if (current == database->head) {
                database->head = current->next;
                if (database->head != NULL)
                    database->head->prev = NULL;
                else
                    database->tail = NULL;
            } else if (current == database->tail) {
                database->tail = current->prev;
                database->tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Student with Roll Number %d deleted from the database.\n", rollNumber);
            return;
        }
        current = current->next;
    }
    printf("Student with Roll Number %d not found in the database.\n", rollNumber);
}

void displayStudents(struct StudentDatabase* database) {
    if (database->head == NULL) {
        printf("Student database is empty.\n");
        return;
    }

    struct Student* current = database->head;
    printf("Student Database:\n");
    while (current != NULL) {
        printf("Roll Number: %d, Name: %s\n", current->rollNumber, current->name);
        current = current->next;
    }
}

int main() {
    struct StudentDatabase* database = createStudentDatabase();

    insertStudent(database, 101, "John");
    insertStudent(database, 102, "Emma");
    insertStudent(database, 103, "Michael");

    displayStudents(database);

    updateStudent(database, 102, "Emily");
    updateStudent(database, 104, "David");

    displayStudents(database);

    deleteStudent(database, 102);
    deleteStudent(database, 104);

    displayStudents(database);

    return 0;
}
