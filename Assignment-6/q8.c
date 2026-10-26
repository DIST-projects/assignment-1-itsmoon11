#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

void add(Node **h, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;

    if (!*h) {
        n->next = n->prev = n;
        *h = n;
        return;
    }

    Node *last = (*h)->prev;
    n->next = *h;
    n->prev = last;
    last->next = n;
    (*h)->prev = n;
}

int frequency(Node *h, int key) {
    if (!h) return 0;

    int count = 0;
    Node *t = h;

    do {
        if (t->data == key) count++;
        t = t->next;
    } while (t != h);

    return count;
}

int main(void) {
    Node *h = NULL;

    add(&h, 10); add(&h, 20);
    add(&h, 10); add(&h, 30);
    add(&h, 10);

    printf("Frequency of 10 = %d\n", frequency(h, 10));
    return 0;
}
