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

void deleteMiddle(Node **h) {
    if (!*h) return;

    Node *slow = *h, *fast = *h;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow->prev)
        slow->prev->next = slow->next;
    else
        *h = slow->next;

    if (slow->next)
        slow->next->prev = slow->prev;

    free(slow);
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

    add(&h, 10); add(&h, 20); add(&h, 30);
    add(&h, 40); add(&h, 50);

    printf("Before: ");
    show(h);

    deleteMiddle(&h);

    printf("After: ");
    show(h);
    return 0;
}
