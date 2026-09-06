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

void enqueue(Queue *q, int value) {
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

int peek(Queue *q) {
    return q->data[q->front];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int main() {
    int arr[] = {-8, 2, 3, -6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    Queue q;
    initQueue(&q);

    printf("Output: ");

    for (int i = 0; i < n; i++) {

        if (arr[i] < 0) {
            enqueue(&q, i);
        }

        if (!isEmpty(&q) && peek(&q) <= i - k) {
            dequeue(&q);
        }

        if (i >= k - 1) {
            if (!isEmpty(&q)) {
                printf("%d ", arr[peek(&q)]);
            } else {
                printf("0 ");
            }
        }
    }

    printf("\n");

    return 0;
}
