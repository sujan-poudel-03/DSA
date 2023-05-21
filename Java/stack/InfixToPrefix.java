package Java.stack;

import java.util.Scanner;

public class InfixToPrefix {
    public static int MAX_SIZE = 100;
    public static int top = -1;
    public static char[] stack = new char[MAX_SIZE];

    public static boolean isFull() {
        return top == MAX_SIZE - 1;
    }

    public static boolean isEmpty() {
        return top < 0;
    }

    public static void push(char c) {
        if (!isFull()) {
            stack[++top] = c;
        } else {
            System.out.println("Could not insert data, stack is full");
        }
    }

    public static char pop() {
        if (!isEmpty()) {
            return stack[top--];
        } else {
            System.out.println("Could not insert data, stack is full");
            return '\0';
        }
    }

    public static int precedence(char c) {
        switch (c) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return 0;
        }
    }

    public static void reverseString(char[] str) {
        int i = 0, j = str.length - 1;
        while (i < j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }

    public static void infixToPrefix(char[] infix, char[] prefix) {
        int i, j, infixLength = infix.length;

        i = j = 0;

        reverseString(infix);

        while (i < infixLength) {
            char current = infix[i];

            if (Character.isLetterOrDigit(current)) {
                prefix[j++] = current;
            } else if (current == '(') {
                push(current);
            } else if (current == ')') {
                while (top != -1 && stack[top] != '(') {
                    prefix[j++] = pop();
                }

                if (top != -1 && stack[top] == '(') {
                    pop();
                }
            } else {
                while (precedence(current) <= precedence(stack[top + 1])) {
                    if (top == -1)
                        break;
                    prefix[j++] = pop();
                }

                push(current);
            }
            i++;
        }

        while (top != -1) {
            prefix[j++] = pop();
        }

        prefix[j - 1] = '\0';

        reverseString(prefix);
    }

    public static void main(String[] args) {
        char[] infix = new char[MAX_SIZE];
        char[] prefix = new char[MAX_SIZE];

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter an infix expression:");
        String expr = scanner.nextLine();

        for (int i = 0; i < expr.length(); i++) {
            infix[i] = expr.charAt(i);
        }

        infixToPrefix(infix, prefix);

        System.out.println("\nInfix expression:");
        traversal(infix);
        System.out.println("\nprefix expression:");
        traversal(prefix);

        scanner.close();
    }

    public static void traversal(char[] arr) {
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            System.out.printf("%c", arr[i]);
        }

        System.out.println("\n");
    }
}