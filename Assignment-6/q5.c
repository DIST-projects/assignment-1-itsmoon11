#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

void add(Node **h, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->prev = n->next = NULL;

    if (!*h) {
        *h = n;
        return;
    }

    Node *t = *h;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

Node *reverse(Node *h) {
    Node *cur = h, *t = NULL;

    while (cur) {
        t = cur->prev;
        cur->prev = cur->next;
        cur->next = t;
        cur = cur->prev;
    }

    if (t) h = t->prev;
    return h;
}

void show(Node *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main(void) {
    Node *h = NULL;
    add(&h, 10); add(&h, 20);
    add(&h, 30); add(&h, 40);

    printf("Before: ");
    show(h);

    h = reverse(h);

    printf("After: ");
    show(h);
    return 0;
}
