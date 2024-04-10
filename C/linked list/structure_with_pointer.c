#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    int age;
    char *name;
};

int main() {
    struct Person person1;

    // Allocate memory for the name
    person1.name = (char *)malloc(50 * sizeof(char));
    if (person1.name == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign values to the structure members
    strcpy(person1.name, "John");
    person1.age = 30;

    // Access and print the values of the structure members
    printf("Age: %d\n", person1.age);
    printf("Name: %s\n", person1.name);

    // Free the allocated memory
    free(person1.name);

    return 0;
}
