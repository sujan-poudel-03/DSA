#include <stdio.h>

#define MAX_SIZE 100

struct Queue {
    int list[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty queue
void createQueue(struct Queue* queue) {
    queue->front = -1;  // Initialize front index
    queue->rear = -1;   // Initialize rear index
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    // Check if the queue is full
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    // Update the rear index and add the element to the rear position
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->list[queue->rear] = data;

    // If it's the first element, update the front index as well
    if (queue->front == -1) {
        queue->front = queue->rear;
    }

    printf("%d enqueued to the queue.\n", data);
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue* queue) {
    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Store the element to be dequeued
    int data = queue->list[queue->front];

    // If there is only one element, reset both front and rear indexes
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Otherwise, move the front index to the next position
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue.\n", data);
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    // Start from the front index and traverse to the rear index
    int current = queue->front;
    printf("Queue: ");
    while (current != queue->rear) {
        printf("%d ", queue->list[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->list[queue->rear]);
}

int main() {
    struct Queue queue;

    createQueue(&queue);

    enqueue(&queue, 5);     // Enqueue 5
    enqueue(&queue, 10);    // Enqueue 10
    enqueue(&queue, 15);    // Enqueue 15

    display(&queue);        // Output: Queue: 5 10 15

    dequeue(&queue);        // Dequeue
    dequeue(&queue);        // Dequeue

    display(&queue);        // Output: Queue: 15

    return 0;
}
