#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *create(char c) {
    Node *n = malloc(sizeof(Node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

void inorder(Node *r) {
    if (!r) return;
    if (r->left || r->right) printf("(");
    inorder(r->left);
    printf("%c", r->data);
    inorder(r->right);
    if (r->left || r->right) printf(")");
}

int main() {
    char p[100];
    Node *s[100], *n;
    int top = -1, i;

    scanf("%99s", p);

    for (i = 0; p[i]; i++) {
        n = create(p[i]);
        if (isalnum((unsigned char)p[i]))
            s[++top] = n;
        else {
            n->right = s[top--];
            n->left = s[top--];
            s[++top] = n;
        }
    }

    inorder(s[top]);
    return 0;
}
