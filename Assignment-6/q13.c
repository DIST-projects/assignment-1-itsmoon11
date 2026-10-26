#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int p;
    struct Node *left, *right;
} Node;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->p = x;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *r, int x) {
    if (!r) return newNode(x);

    if (x < r->p) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);

    return r;
}

Node *maximum(Node *r) {
    while (r && r->right) r = r->right;
    return r;
}

Node *deleteMax(Node *r) {
    if (!r) return NULL;

    if (!r->right) {
        Node *t = r->left;
        free(r);
        return t;
    }

    r->right = deleteMax(r->right);
    return r;
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->p);
    inorder(r->right);
}

int main(void) {
    Node *r = NULL;
    int a[] = {40, 80, 30, 90, 60};

    for (int i = 0; i < 5; i++)
        r = insert(r, a[i]);

    printf("Priorities: ");
    inorder(r);

    printf("\nHighest: %d\n", maximum(r)->p);

    r = deleteMax(r);

    printf("After deletion: ");
    inorder(r);
    printf("\n");

    return 0;
}
