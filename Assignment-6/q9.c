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

int search(Node *r, int key) {
    if (!r) return 0;
    if (r->data == key) return 1;

    return search(r->left, key) || search(r->right, key);
}

int main(void) {
    Node *r = newNode(10);
    r->left = newNode(20);
    r->right = newNode(30);
    r->left->left = newNode(40);
    r->left->right = newNode(50);

    int key = 50;

    if (search(r, key))
        printf("%d found\n", key);
    else
        printf("%d not found\n", key);

    return 0;
}
