#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/* Balanced BST from sorted inorder */
Node *fromIn(int a[], int l, int h) {
    if (l > h) return NULL;

    int m = (l + h) / 2;
    Node *r = newNode(a[m]);

    r->left = fromIn(a, l, m - 1);
    r->right = fromIn(a, m + 1, h);
    return r;
}

/* BST from preorder */
Node *fromPre(int a[], int *i, int n,
              long long lo, long long hi) {
    if (*i == n || a[*i] <= lo || a[*i] >= hi)
        return NULL;

    int x = a[(*i)++];
    Node *r = newNode(x);

    r->left = fromPre(a, i, n, lo, x);
    r->right = fromPre(a, i, n, x, hi);
    return r;
}

/* BST from postorder */
Node *fromPost(int a[], int *i,
               long long lo, long long hi) {
    if (*i < 0 || a[*i] <= lo || a[*i] >= hi)
        return NULL;

    int x = a[(*i)--];
    Node *r = newNode(x);

    r->right = fromPost(a, i, x, hi);
    r->left = fromPost(a, i, lo, x);
    return r;
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

int main(void) {
    int in[]  = {20, 30, 40, 50, 60, 70, 80};
    int pre[] = {50, 30, 20, 40, 70, 60, 80};
    int post[] = {20, 40, 30, 60, 80, 70, 50};

    int i = 0, j = 6;

    Node *a = fromIn(in, 0, 6);
    Node *b = fromPre(pre, &i, 7, LLONG_MIN, LLONG_MAX);
    Node *c = fromPost(post, &j, LLONG_MIN, LLONG_MAX);

    printf("From inorder: ");
    inorder(a);
    printf("\nFrom preorder: ");
    inorder(b);
    printf("\nFrom postorder: ");
    inorder(c);
    printf("\n");

    return 0;
}
