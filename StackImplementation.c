#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<malloc.h>

struct stack {
 int max_size;
 int top;
 int *items;
};

bool isEmpty(struct stack* st) {
 return st->top == -1;
}

bool isFull(struct stack* st) {
  return st->top == (st->max_size - 1);
}

int peek(struct stack *stack) {
    if(!isEmpty(stack)) {
        return stack->items[stack->top];
    }
    else {
        return NULL;
    }
}

void push(struct stack* st, int element) {
    if(isFull(st)) {
        printf("Stack is Full");
    }
    else {
    st->items[++st->top] = element;
    }
}

int pop(struct stack* st) {
 if(isEmpty(st)) {
    printf("Stack is Empty");
 }
 else {
    return st->items[st->top--];
 }

}
struct stack* createStack(int max_size) {
    struct stack *pt = (struct stack*) malloc (sizeof(struct stack));
    pt->max_size = max_size;
    pt->top = -1;
    pt->items = (int*) malloc(sizeof(int)*max_size);
    return pt;
}

void printFullStack(struct stack* st) {
    if(!isEmpty(st)) {
     printf("Stack: ");
     for(int i=0;i<=st->top;i++) {
        printf("%d ",st->items[i]);
     }
    printf("\n");
    }
    else {
        printf("Stack is empty. Nothing to print.\n");
    }
}

void insertAtBottom(struct stack* stack, int x) {
    if(stack->top == -1) {
        push(stack,x);
    }
    else {
        int a = peek(stack);

        pop(stack);
        insertAtBottom(stack,x);
        push(stack,a);
    }
}

void reverseStack(struct stack* stack) {
    if(stack->top != -1) {
        int x = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, x);
    }
}

void pushAsc(struct stack* stack, int x) {
    if(stack->top == -1)
        push(stack,x);
    else {
        int a = peek(stack);
        if(a<x) {
            pop(stack);
            pushAsc(stack, x);
            push(stack,a);
        }
        else {
            push(stack,x);
        }
    }
}

void sortStack(struct stack* stack) {
  if(stack->top != -1) {
    int x = pop(stack);
    sortStack(stack);
    pushAsc(stack, x);
  }
}

void main() {
    struct stack* st = createStack(4);
    push(st,1);
    push(st,1);
    push(st,5);
    push(st,4);
    printFullStack(st);
    //reverseStack(st);
    //printFullStack(st);
    sortStack(st);
    printFullStack(st);

}
