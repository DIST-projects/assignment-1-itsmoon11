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

int height(Node *r) {
    if (!r) return 0;

    int l = height(r->left);
    int rht = height(r->right);

    return 1 + (l > rht ? l : rht);
}

int main(void) {
    Node *r = newNode(10);
    r->left = newNode(20);
    r->right = newNode(30);
    r->left->left = newNode(40);

    printf("Height = %d\n", height(r));
    return 0;
}
