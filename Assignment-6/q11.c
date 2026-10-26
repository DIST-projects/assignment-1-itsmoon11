#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *head = NULL, *prev = NULL;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void convert(Node *r) {
    if (!r) return;

    convert(r->left);

    if (!prev)
        head = r;
    else {
        r->left = prev;
        prev->right = r;
    }

    prev = r;
    convert(r->right);
}

int main(void) {
    Node *r = newNode(10);
    r->left = newNode(5);
    r->right = newNode(20);
    r->left->left = newNode(2);
    r->left->right = newNode(7);

    convert(r);

    printf("DLL: ");
    for (Node *t = head; t; t = t->right)
        printf("%d ", t->data);

    printf("\n");
    return 0;
}
