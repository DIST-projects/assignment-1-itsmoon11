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

void sort(int arr[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Queue q;
    initQueue(&q);

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }

    int num1 = 0;
    int num2 = 0;
    int turn = 0;

    while (q.front <= q.rear) {
        int digit = dequeue(&q);

        if (turn == 0) {
            num1 = num1 * 10 + digit;
            turn = 1;
        } else {
            num2 = num2 * 10 + digit;
            turn = 0;
        }
    }

    printf("Number 1 = %d\n", num1);
    printf("Number 2 = %d\n", num2);
    printf("Minimum Sum = %d\n", num1 + num2);

    return 0;
}
