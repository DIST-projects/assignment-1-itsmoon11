#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }

    int value = q->data[q->front++];

    if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }

    return value;
}

void push(Queue *q1, Queue *q2, int value) {
    enqueue(q2, value);

    while (!isEmpty(q1)) {
        enqueue(q2, dequeue(q1));
    }

    Queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

int pop(Queue *q1) {
    if (isEmpty(q1)) {
        return -1;
    }

    return dequeue(q1);
}

int top(Queue *q1) {
    if (isEmpty(q1)) {
        return -1;
    }

    return q1->data[q1->front];
}

void display(Queue *q1) {
    int i;

    if (isEmpty(q1)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (Top to Bottom): ");
    for (i = q1->front; i <= q1->rear; i++) {
        printf("%d ", q1->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    push(&q1, &q2, 10);
    push(&q1, &q2, 20);
    push(&q1, &q2, 30);

    display(&q1);

    printf("Popped element: %d\n", pop(&q1));
    printf("Top element: %d\n", top(&q1));

    display(&q1);

    return 0;
}
