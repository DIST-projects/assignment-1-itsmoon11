#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char text[50];
    struct Node *prev, *next;
} Node;

Node *head = NULL, *current = NULL;

void edit(char *s) {
    Node *n = malloc(sizeof(Node));
    strcpy(n->text, s);
    n->prev = n->next = NULL;

    if (!head) {
        head = current = n;
        return;
    }

    while (current->next) {
        Node *t = current->next;
        current->next = NULL;
        while (t) {
            Node *x = t->next;
            free(t);
            t = x;
        }
    }

    n->prev = current;
    current->next = n;
    current = n;
}

void undo(void) {
    if (current && current->prev)
        current = current->prev;
}

void redo(void) {
    if (current && current->next)
        current = current->next;
}

int main(void) {
    edit("Start");
    edit("Hello");
    edit("Hello C");
    edit("Hello C Lab");

    printf("Current: %s\n", current->text);

    undo();
    printf("Undo: %s\n", current->text);

    undo();
    printf("Undo: %s\n", current->text);

    redo();
    printf("Redo: %s\n", current->text);

    return 0;
}
