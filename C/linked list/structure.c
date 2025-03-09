#include <stdio.h>
#include <string.h>
struct example
{
    int id;
    char name[50];
    char gender;
};

int main() {
    struct example ex1;
    // Assign values to the structure members
    ex1.id = 1;
    ex1.gender = 'M';
    strcpy(ex1.name, "John");

    // Print the values of the structure members
    printf("ID: %d\n", ex1.id);
    printf("Name: %s\n", ex1.name);
    printf("Gender: %c\n", ex1.gender);
    return 0;
}
