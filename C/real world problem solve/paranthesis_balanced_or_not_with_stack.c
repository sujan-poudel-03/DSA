#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    top++;
    stack[top] = data;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop element.\n");
        return '\0';
    }

    char data = stack[top];
    top--;
    return data;
}

bool isBalanced(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return false;
            }

            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (top == -1);
}

int main() {
    char str[] = "(({})[)";
    if (isBalanced(str)) {
        printf("The string is balanced.\n");
    } else {
        printf("The string is not balanced.\n");
    }

    return 0;
}
