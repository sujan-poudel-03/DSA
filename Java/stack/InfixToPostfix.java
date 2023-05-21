package Java.stack;

import java.util.Scanner;

public class InfixToPostfix {
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
        switch(c) {
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

    public static void infixToPostfix(char[] infix, char[] postfix) {
        int i, j, infixLength = infix.length;
        
        i = j = 0;

        while(i < infixLength) {
            char current = infix[i];

            if (Character.isLetterOrDigit(current)) {
                postfix[j++] = current;
            } else if (current == '(') {
                push(current);
            } else if (current == ')') {
                while(top != -1 && stack[top] != '(') {
                    postfix[j++] = pop();
                }

                if (top != -1 && stack[top] == '(') {
                    pop();
                }
            } else {
                while(precedence(current) <= precedence(stack[top+1])) {
                    if (top == -1) break;
                    postfix[j++] = pop();
                }

                push(current);
            }
            i++;
        }

        while(top != -1) {
            postfix[j++] = pop();
        }

        postfix[j-1] = '\0';
    }

    public static void main(String[] args) {
        char[] infix = new char[MAX_SIZE];
        char[] postfix = new char[MAX_SIZE];

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter an infix expression:");
        String expr = scanner.nextLine();

        for (int i = 0; i < expr.length(); i++) {
            infix[i] = expr.charAt(i);
        }

        infixToPostfix(infix, postfix);
        
        System.out.println("\nInfix expression:");
        traversal(infix);
        System.out.println("\nPostfix expression:");
        traversal(postfix);

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