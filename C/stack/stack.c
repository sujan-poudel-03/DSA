//skdhg

#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

/* Check if the stack is full */
int isFull() {
   if (top == MAXSIZE-1)
      return 1;
   else
      return 0;
}

/* Check if the stack is empty */
int isEmpty() {
   if (top == -1)
      return 1;
   else
      return 0;
}

/* Add elements into stack */
void push(int data) {
   if (!isFull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

/* Remove element from stack */
int pop() {
   int data;

   if (!isEmpty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

/* Returns element at top of stack */
int peek() {
   return stack[top];
}

/* Display the stack */
void display() {
   int i;

   if (!isEmpty()) {
      for (i = top; i >= 0; i--)
         printf("%d ", stack[i]);
      printf("\n");
   } else {
      printf("Stack is empty.\n");
   }
}

/* Search element in stack */
void search(int element) {
   printf("-------------------Search Operation------------------- \n");

   for (int i = 0; i < top; i++) {
      if (stack[i] == element) {
         printf("Element found at index %d \n", i);
         return;
      }
   }

   printf("Element not found \n");
}

int main() {
   // push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n", peek());
   printf("Elements: \n");

   // print stack data
   display();

   // remove element from stack
   printf("\nElement popped: %d\n", pop());
   printf("Element at top of the stack: %d\n", peek());
   printf("Elements: \n");

   // print stack data
   display();

   // search element in stack
   search(9);

   return 0;
}