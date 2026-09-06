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
    if (isEmpty(s)) {
        return -1;
    }

    return s->data[s->top--];
}

void enqueue(Stack *s1, int value) {
    push(s1, value);
}

int dequeue(Stack *s1, Stack *s2) {
    int value;

    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }

    if (isEmpty(s2)) {
        return -1;
    }

    value = pop(s2);
    return value;
}

void display(Stack *s1, Stack *s2) {
    int i;

    printf("Queue (Front to Rear): ");

    for (i = s2->top; i >= 0; i--) {
        printf("%d ", s2->data[i]);
    }

    for (i = 0; i <= s1->top; i++) {
        printf("%d ", s1->data[i]);
    }

    printf("\n");
}

int main() {
    Stack s1, s2;

    initStack(&s1);
    initStack(&s2);

    enqueue(&s1, 10);
    enqueue(&s1, 20);
    enqueue(&s1, 30);

    /* Transfer elements to make display/deletion correct */
    while (!isEmpty(&s1)) {
        push(&s2, pop(&s1));
    }

    display(&s1, &s2);

    printf("Dequeued element: %d\n", dequeue(&s1, &s2));

    display(&s1, &s2);

    return 0;
}
