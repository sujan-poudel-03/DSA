#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Maximum size of the queue

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

bool isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front when enqueueing the first element
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
    printf("%d enqueued.\n", value);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Reset front and rear when dequeueing the last element
    } else {
        queue->front++;
    }
    return value;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}
