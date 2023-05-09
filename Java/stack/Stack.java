public class Stack {
    static int MAXLEN = 10;
    static int top = -1;
    static int[] stack = new int[MAXLEN];

    public static void main(String[] args) {
        // push items on to the stack
        push(3);
        push(5);
        push(9);
        push(1);
        push(12);
        push(15);

        System.out.printf("Element at top of the stack: %d\n", peek());
        System.out.println("Elements:");

        // print stack data
        display();

        // remove element from stack
        System.out.printf("\nElement popped: %d\n", pop());
        System.out.printf("Element at top of the stack: %d\n", peek());
        System.out.println("Elements:");

        // print stack data
        display();
    }

    public static void push(int item) {
        if (isFull()) {
            System.out.println("Cannot push, stack is full!");
            return;
        }

        stack[++top] = item;
    }

    public static int pop() {
        if (isEmpty()) {
            System.out.println("Cannot pop, stack is empty!");
            return 0;
        }

        return stack[top--];
    }

    public static int peek() {
        if (isEmpty()) {
            System.out.println("Cannot peek, stack is empty");
            return 0;
        }

        return stack[top];
    }

    public static void display() {
        System.out.print("[");
        for(int i = 0; i <= top; i++) {
            System.out.printf("%d", stack[i]);
            if (i < top) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static boolean isFull() {
        return top == MAXLEN;
    }

    public static boolean isEmpty() {
        return top == -1;
    }
}
