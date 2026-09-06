#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int time;
} Cell;

typedef struct {
    Cell data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, Cell c) {
    q->data[++q->rear] = c;
}

Cell dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int isValid(int row, int col, int m, int n) {
    return row >= 0 && row < m &&
           col >= 0 && col < n;
}

int rottenOranges(int mat[][5], int m, int n) {
    Queue q;
    int fresh = 0;
    int maxTime = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    initQueue(&q);

    /* Add all rotten oranges */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (mat[i][j] == 2) {
                Cell c = {i, j, 0};
                enqueue(&q, c);
            }
            else if (mat[i][j] == 1) {
                fresh++;
            }
        }
    }

    /* BFS */
    while (!isEmpty(&q)) {
        Cell current = dequeue(&q);

        for (int i = 0; i < 4; i++) {
            int nr = current.row + dr[i];
            int nc = current.col + dc[i];

            if (isValid(nr, nc, m, n) &&
                mat[nr][nc] == 1) {

                mat[nr][nc] = 2;
                fresh--;

                Cell next = {nr, nc, current.time + 1};
                enqueue(&q, next);

                if (next.time > maxTime) {
                    maxTime = next.time;
                }
            }
        }
    }

    if (fresh > 0) {
        return -1;
    }

    return maxTime;
}

void printMatrix(int mat[][5], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[3][5] = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    int m = 3;
    int n = 5;

    printf("Initial Matrix:\n");
    printMatrix(mat, m, n);

    int result = rottenOranges(mat, m, n);

    printf("\nFinal Matrix:\n");
    printMatrix(mat, m, n);

    printf("\nMinimum time required = %d\n", result);

    return 0;
}
