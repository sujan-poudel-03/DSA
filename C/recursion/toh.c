#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    tower_of_hanoi(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n-1, auxiliary, destination, source);
}

int main() {
    int num_disks = 3;
    char source = 'A';
    char destination = 'C';
    char auxiliary = 'B';
    
    tower_of_hanoi(num_disks, source, destination, auxiliary);
    
    return 0;
}
