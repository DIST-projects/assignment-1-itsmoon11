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

void removeSorted(Node *h) {
    while (h && h->next) {
        if (h->data == h->next->data) {
            Node *t = h->next;
            h->next = t->next;
            if (t->next) t->next->prev = h;
            free(t);
        } else {
            h = h->next;
        }
    }
}

void removeUnsorted(Node *h) {
    for (Node *p = h; p; p = p->next) {
        Node *q = p->next;

        while (q) {
            if (p->data == q->data) {
                Node *t = q;
                q = q->next;
                t->prev->next = t->next;
                if (t->next) t->next->prev = t->prev;
                free(t);
            } else {
                q = q->next;
            }
        }
    }
}

void show(Node *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main(void) {
    Node *s = NULL, *u = NULL;

    int a[] = {10, 10, 20, 20, 30, 40, 40};
    int b[] = {30, 10, 20, 30, 10, 40};

    for (int i = 0; i < 7; i++) add(&s, a[i]);
    for (int i = 0; i < 6; i++) add(&u, b[i]);

    removeSorted(s);
    removeUnsorted(u);

    printf("Sorted DLL: ");
    show(s);

    printf("Unsorted DLL: ");
    show(u);
    return 0;
}
