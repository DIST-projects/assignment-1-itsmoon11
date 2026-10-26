#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right, *nextRight;
} Node;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = n->nextRight = NULL;
    return n;
}

void connect(Node *root) {
    Node *level = root;

    while (level) {
        Node *nextLevel = NULL, *tail = NULL;

        for (Node *p = level; p; p = p->nextRight) {
            Node *child[2] = {p->left, p->right};

            for (int i = 0; i < 2; i++) {
                if (!child[i]) continue;

                if (!nextLevel) nextLevel = child[i];
                if (tail) tail->nextRight = child[i];

                tail = child[i];
            }
        }

        if (tail) tail->nextRight = NULL;
        level = nextLevel;
    }
}

void showLevels(Node *level) {
    while (level) {
        Node *next = NULL;

        for (Node *p = level; p && !next; p = p->nextRight)
            next = p->left ? p->left : p->right;

        for (Node *p = level; p; p = p->nextRight)
            printf("%d ", p->data);

        printf("\n");
        level = next;
    }
}

int main(void) {
    Node *r = newNode(1);
    r->left = newNode(2);
    r->right = newNode(3);
    r->left->left = newNode(4);
    r->left->right = newNode(5);
    r->right->right = newNode(6);

    connect(r);
    showLevels(r);

    return 0;
}
