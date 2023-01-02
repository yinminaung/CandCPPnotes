#include "stdio.h"
#include "stdlib.h"


#define MAXOFSTACK 10

struct stack {
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

void createEmptyStack (st *myStack) {
    myStack->top = -1;
}

int isStackFull(st *myStack) {
    if (myStack->top == MAXOFSTACK -1) {
        return 1;
    } else {
        return 0;
    }
}

int isStackEmpty(st *myStack) {
    if (myStack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(st *myStack, int value) {
    if (isStackFull(myStack)) {
        printf("Stack is full.\n");
    } else {
        myStack->top++;
        myStack->data[myStack->top] = value;
    }
}

void pop(st *myStack) {
    if (isStackEmpty(myStack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Pop from stack is %d.\n", myStack->data[myStack->top]);
        myStack->top--;
    }
}

void printStack(st *myStack) {
    if(isStackEmpty(myStack)) {
        printf("The stack is empty.");
    } else {
        printf("There are %d elements in the stack.\nThey are : ", myStack->top + 1);
        
        for (int i = 0; i < myStack->top+1; i++) {               
            printf("%d ", myStack->data[i]);
        }
    }

    printf("\n");
}

int main() {

    st *myStack = (st*)malloc(sizeof(st));

    createEmptyStack(myStack);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);

    printStack(myStack);
    return 0;
}