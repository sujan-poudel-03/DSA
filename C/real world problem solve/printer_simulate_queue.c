#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }

    return data;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Simulating a printer job queue
    enqueue(1);  // Job 1 added to the queue
    enqueue(2);  // Job 2 added to the queue
    enqueue(3);  // Job 3 added to the queue

    printQueue();  // Output: Queue: 1 2 3

    int currentJob = dequeue();  // Start processing the current job
    printf("Processing Job: %d\n", currentJob);  // Output: Processing Job: 1

    printQueue();  // Output: Queue: 2 3

    return 0;
}
