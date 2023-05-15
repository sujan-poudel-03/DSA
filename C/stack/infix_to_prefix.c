#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

/* Check if the stack is full */
int isFull() {
    return (top == MAX_SIZE - 1);
}

/* Check if the stack is empty */
int isEmpty() {
    return (top == -1);
}

/* Add elements into stack */
void push(char c) {
    if (!isFull()) {
        stack[++top] = c;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

/* Remove element from stack */
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
        return '\0';
    }
}

/* Returns element at top of stack */
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}

// Reverse a string
void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/* Convert infix to prefix */
void infixToprefix(char infix[], char prefix[]) {
    int i, j;
    i = j = 0;
    int infixLength = strlen(infix);

    // Reverse the infix expression
    reverseString(infix);

    while (i < infixLength) {
        char current = infix[i];

        // If the scanned character is an operand, add it to output. isalnum() is a function that checks if a character is alphanumeric(a letter or a digit).
        if (isalnum(current)) 
        {
            prefix[j++] = current;
        }
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (current == ')') 
        {
            push(current);
        } 
        // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
        else if (current == '(') 
        {
            // pop until '(' is encountered
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            // pop '('
            if (top != -1 && stack[top] == ')') {
                pop();
            }
        
        } 
        else 
        {
            // an operator is encountered
            // while (top != -1 && precedence(current) <= precedence(stack[top])) {
            while (precedence(current) <= precedence(stack[top])) {
                if (top == -1)
                {
                    break;
                } 
                else {
                    prefix[j++] = pop();
                }
            }

            // push current operator to stack
            push(current);
        }

        i++;
    }

    // pop all the remaining operators from the stack
    while (top != -1) {
        prefix[j++] = pop();
    }
    
    // Add null character to mark the end of string
    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    reverseString(prefix);

}



int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToprefix(infix, prefix);

    printf("Infix expression: %s\n", infix);
    printf("prefix expression: %s\n", prefix);

    return 0;
}
