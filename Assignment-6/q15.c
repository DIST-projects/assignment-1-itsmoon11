#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *stack[100];
int top = -1;

Node *newNode(char x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
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

int main(void) {
    char exp[] = "ab+c*";

    for (int i = 0; exp[i]; i++) {
        if (isalnum((unsigned char)exp[i])) {
            stack[++top] = newNode(exp[i]);
        } else {
            Node *right = stack[top--];
            Node *left = stack[top--];

            Node *op = newNode(exp[i]);
            op->left = left;
            op->right = right;

            stack[++top] = op;
        }
    }

    printf("Expression: ");
    inorder(stack[top]);
    printf("\n");

    return 0;
}
