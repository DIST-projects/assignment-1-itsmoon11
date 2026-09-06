#include <stdio.h>

#define MAX 100

void calculateSpan(int price[], int n, int span[]) {
    int stack[MAX];
    int top = -1;

    stack[++top] = 0;
    span[0] = 1;

    for (int i = 1; i < n; i++) {

        while (top >= 0 && price[stack[top]] <= price[i]) {
            top--;
        }

        if (top == -1) {
            span[i] = i + 1;
        } else {
            span[i] = i - stack[top];
        }

        stack[++top] = i;
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[MAX];

    calculateSpan(price, n, span);

    printf("Stock Prices: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    printf("\nStock Span: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }

    printf("\n");

    return 0;
}
