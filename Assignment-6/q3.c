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

Node *find(Node *h, int x) {
    while (h && h->data != x) h = h->next;
    return h;
}

Node *swapNodes(Node *h, Node *a, Node *b) {
    if (!a || !b || a == b) return h;

    if (a->next == b) {
        if (a->prev) a->prev->next = b;
        else h = b;

        if (b->next) b->next->prev = a;

        a->next = b->next;
        b->prev = a->prev;
        b->next = a;
        a->prev = b;
    } else if (b->next == a) {
        return swapNodes(h, b, a);
    } else {
        Node *ap = a->prev, *an = a->next;
        Node *bp = b->prev, *bn = b->next;

        if (ap) ap->next = b;
        else h = b;

        if (an) an->prev = b;
        if (bp) bp->next = a;
        else h = a;

        if (bn) bn->prev = a;

        a->prev = bp; a->next = bn;
        b->prev = ap; b->next = an;
    }

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
    for (int i = 10; i <= 40; i += 10) add(&h, i);

    printf("Before: ");
    show(h);

    h = swapNodes(h, find(h, 20), find(h, 30));

    printf("After: ");
    show(h);
    return 0;
}
