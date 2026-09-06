#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

void sortStack(Stack *s) {
    Stack temp;
    initStack(&temp);

    while (!isEmpty(s)) {
        int x = pop(s);

        while (!isEmpty(&temp) && peek(&temp) < x) {
            push(s, pop(&temp));
        }

        push(&temp, x);
    }

    *s = temp;
}

void display(Stack *s) {
    int i;

    printf("Sorted Stack (Smallest to Largest): ");

    for (i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }

    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 34);
    push(&s, 3);
    push(&s, 31);
    push(&s, 98);
    push(&s, 92);
    push(&s, 23);

    printf("Original Stack (Top to Bottom): ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");

    sortStack(&s);

    display(&s);

    return 0;
}
