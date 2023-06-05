#include <stdio.h>
#include <stdlib.h>

struct PrintJob {
    int jobID;
    int priority;
};

struct Queue {
    struct PrintJob* list;
    int front;
    int rear;
    int size;
};

// Function to create an empty queue
void createQueue(struct Queue* queue, int capacity) {
    queue->list = (struct PrintJob*)malloc(capacity * sizeof(struct PrintJob));
    queue->front = -1;  // Initialize front index
    queue->rear = -1;   // Initialize rear index
    queue->size = capacity;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % queue->size == queue->front);
}

// Function to enqueue (add) a print job to the queue
void enqueue(struct Queue* queue, int jobID, int priority) {
    // Check if the queue is full
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    // Update the rear index and add the print job to the rear position
    queue->rear = (queue->rear + 1) % queue->size;
    queue->list[queue->rear].jobID = jobID;
    queue->list[queue->rear].priority = priority;

    // If it's the first element, update the front index as well
    if (queue->front == -1) {
        queue->front = queue->rear;
    }

    printf("Print job with ID %d and priority %d enqueued.\n", jobID, priority);
}

// Function to dequeue (remove) a print job from the queue
void dequeue(struct Queue* queue) {
    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Store the print job to be dequeued
    struct PrintJob job = queue->list[queue->front];

    // If there is only one element, reset both front and rear indexes
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Otherwise, move the front index to the next position
        queue->front = (queue->front + 1) % queue->size;
    }

    printf("Print job with ID %d and priority %d dequeued.\n", job.jobID, job.priority);
}

// Function to display the print jobs in the queue
void display(struct Queue* queue) {
    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    // Start from the front index and traverse to the rear index
    int current = queue->front;
    printf("Print Job Queue:\n");
    while (current != queue->rear) {
        printf("Job ID: %d, Priority: %d\n", queue->list[current].jobID, queue->list[current].priority);
        current = (current + 1) % queue->size;
    }
    printf("Job ID: %d, Priority: %d\n", queue->list[current].jobID, queue->list[current].priority);
}

int main() {
    int queueCapacity = 5; // Maximum number of print jobs in the queue
    struct Queue jobQueue;
    createQueue(&jobQueue, queueCapacity);

    // Enqueue print jobs with different priorities
    enqueue(&jobQueue, 1, 2);  // Enqueue print job ID 1 with priority 2
    enqueue(&jobQueue, 2, 1);  // Enqueue print job ID 2 with priority 1
    enqueue(&jobQueue, 3, 3);  // Enqueue print job ID 3 with priority 3
    enqueue(&jobQueue, 4, 2);  // Enqueue print job ID 4 with priority 2

    // Display the print job queue
    display(&jobQueue);

    // Process the print jobs in the queue (dequeue)
    dequeue(&jobQueue);  // Dequeue the highest priority job
    dequeue(&jobQueue);  // Dequeue the next highest priority job

    // Display the updated print job queue
    display(&jobQueue);

    return 0;
}
