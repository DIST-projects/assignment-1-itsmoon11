#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void add(Node **h, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;

    if (!*h) {
        *h = n;
        return;
    }

    Node *t = *h;
    while (t->next) t = t->next;
    t->next = n;
}

void show(Node *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

Node *intersection(Node *a, Node *b) {
    Node *r = NULL;

    while (a && b) {
        if (a->data == b->data) {
            add(&r, a->data);
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return r;
}

Node *unionList(Node *a, Node *b) {
    Node *r = NULL;

    while (a && b) {
        if (a->data < b->data) {
            add(&r, a->data);
            a = a->next;
        } else if (a->data > b->data) {
            add(&r, b->data);
            b = b->next;
        } else {
            add(&r, a->data);
            a = a->next;
            b = b->next;
        }
    }

    while (a) {
        add(&r, a->data);
        a = a->next;
    }
    while (b) {
        add(&r, b->data);
        b = b->next;
    }
    return r;
}

int main(void) {
    Node *a = NULL, *b = NULL;

    int x[] = {10, 20, 30, 40};
    int y[] = {20, 30, 50, 60};

    for (int i = 0; i < 4; i++) {
        add(&a, x[i]);
        add(&b, y[i]);
    }

    printf("Intersection: ");
    show(intersection(a, b));

    printf("Union: ");
    show(unionList(a, b));

    return 0;
}
