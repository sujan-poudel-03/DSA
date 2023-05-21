package Java.queue;

public class LinearQueue {
    public static int MAX_SIZE = 5;
    public static int[] items = new int[MAX_SIZE];
    public static int front = -1;
    public static int rear = -1;

    public static void main(String[] args) {
        //dequeue is not possible on empty queue
        dequeue();

        //enqueue 5 elements
        enqueue(1);
        enqueue(2);
        enqueue(3);
        enqueue(4);
        enqueue(5);

        // 6th element can't be added to because the queue is full
        enqueue(6);

        display();

        //dequeue removes element entered first i.e. 1
        dequeue();

        //Now we have just 4 elements
        display();
    }

    public static void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full");
        } else {
            if (front == -1) front = 0;
            rear++;
            items[rear] = value;
            System.out.println("Inserted -> " + value);
        }
    }

    public static void dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
        } else {
            System.out.println("Deleted -> " + items[front]);
            front++;
            if (front > rear) front = rear = -1;
        }
    }

    public static boolean isEmpty() {
        return front < 0;
    }

    public static boolean isFull() {
        return rear == MAX_SIZE - 1;
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
