#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize Stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Push Element onto Stack
void push(struct Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed onto the stack.\n", value);
}

// Pop Element from Stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1; 
    }
    return stack->arr[stack->top--];
}

// Peek (Top) Element of Stack
int peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Check if Stack is Empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Display Stack Elements
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Peek: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
