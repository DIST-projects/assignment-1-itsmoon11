#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *r, int x) {
    if (!r) return newNode(x);

    if (x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);

    return r;
}

Node *minimum(Node *r) {
    while (r->left) r = r->left;
    return r;
}

Node *deleteNode(Node *r, int x) {
    if (!r) return NULL;

    if (x < r->data)
        r->left = deleteNode(r->left, x);
    else if (x > r->data)
        r->right = deleteNode(r->right, x);
    else {
        if (!r->left || !r->right) {
            Node *t = r->left ? r->left : r->right;
            free(r);
            return t;
        }

        Node *t = minimum(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }

    return r;
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

int main(void) {
    Node *r = NULL;
    int a[] = {50, 30, 20, 40, 70, 60, 80};

    for (int i = 0; i < 7; i++)
        r = insert(r, a[i]);

    r = deleteNode(r, 20);
    r = deleteNode(r, 30);
    r = deleteNode(r, 50);

    printf("After deletion: ");
    inorder(r);
    printf("\n");

    return 0;
}
