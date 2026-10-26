#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;

    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->left = create();
    n->right = create();
    return n;
}

int isBST(Node *r, long long lo, long long hi) {
    if (!r) return 1;
    if (r->data <= lo || r->data >= hi) return 0;

    return isBST(r->left, lo, r->data) &&
           isBST(r->right, r->data, hi);
}

int main() {
    Node *root = create();

    if (isBST(root, LLONG_MIN, LLONG_MAX))
        printf("BST");
    else
        printf("Not a BST");

    return 0;
}
