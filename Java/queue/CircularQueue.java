package Java.queue;

public class CircularQueue {
    public static int MAX_SIZE = 5;
    public static int[] items = new int[MAX_SIZE];
    public static int front = -1;
    public static int rear = -1;

    public static void main(String[] args) {
        // Fails because front = -1
        dequeue();

        enqueue(1);
        enqueue(2);
        enqueue(3);
        enqueue(4);
        enqueue(5);

        // Fails to enqueue because front == 0 && rear == SIZE - 1
        enqueue(6);

        display();
        dequeue();

        display();

        enqueue(7);
        display();

        // Fails to enqueue because front == rear + 1
        enqueue(8);
    }

    public static void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full");
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % MAX_SIZE;
            items[rear] = value;
            System.out.println("Inserted -> " + value);
        }
    }

    public static void dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
        } else {
            int element = items[front];

            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }

            System.out.println("Deleted -> " + element);
        }
    }

    public static boolean isEmpty() {
        return front < 0;
    }

    public static boolean isFull() {
        return (front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1);
    }

    public static void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
        } else {
            for (int i = front; i <= rear; i++) {
                System.out.printf("%d ", items[i]);
            }
        }
        System.out.println("\n");
    }
}
