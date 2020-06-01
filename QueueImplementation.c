#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
struct queue {
 int front, rear;
 unsigned capacity, size;
 int *items ;
};

struct queue* createQueue(int capacity) {
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue->front = queue->rear = queue->size = 0;
    queue->capacity = capacity;
    queue->items = (int*) malloc(sizeof(int)*capacity);
    return queue;
}

bool isEmpty(struct queue* q) {
 return q->size == 0;
}

bool isFull(struct queue* q) {
 return q->size == q->capacity;
}

int front(struct queue* q) {
 if(isEmpty(q)) {
    printf("Queue is empty");
    return;
 }
 else {
    return q->items[q->front];
 }
}

int rear(struct queue* q) {
 if(isEmpty(q)) {
    printf("Queue is empty\n");
    return;
 }
 else {
    return q->items[q->rear];
 }
}

void enqueue(struct queue* q, int item) {
    if(isFull(q)) {
        printf("Queue is full. Please dequeue some elements before enqueue\n");
        return;
    }
    else {
        q->rear = (q->rear+1)%q->capacity;
        q->items[q->rear] = item;
        q->size++;
    }
}

int dequeue(struct queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty. Please enqueue some elements before dequeue\n");
        return;
    }
    else {
        int val = q->items[q->front];
        q->front = (q->front+1)%q->capacity;
        q->size--;
        return val;
    }
}

void printEntireQueue(struct queue* q) {
    printf("Queue is: ");
    for(int i = q->front ; i< q->size; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void main() {
//isEmpty
//isFull
//front
//rear
//Create a queue
//Enqueue
//Dequeue
//print the whole queue
struct queue* q = createQueue(20);
enqueue(q, 1);
enqueue(q, 2);
enqueue(q, 3);
enqueue(q, 4);
printEntireQueue(q);
printf("Item dequeued: %d\n",dequeue(q));
printEntireQueue(q);

}
