#include <stdio.h>
#include <string.h>

#define MAX 50
#define SIZE 100

typedef struct {
    char pages[MAX][SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char page[]) {
    if (isFull(s)) {
        printf("History is full.\n");
        return;
    }

    strcpy(s->pages[++s->top], page);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("No previous page available.\n");
        return;
    }

    s->top--;
}

void display(Stack *s) {
    int i;

    if (isEmpty(s)) {
        printf("History is empty.\n");
        return;
    }

    printf("\nBrowsing History:\n");

    for (i = s->top; i >= 0; i--) {
        printf("%s\n", s->pages[i]);
    }
}

void currentPage(Stack *s) {
    if (isEmpty(s)) {
        printf("No page is currently open.\n");
    } else {
        printf("Current Page: %s\n", s->pages[s->top]);
    }
}

int main() {
    Stack history;
    int choice;
    char page[SIZE];

    initStack(&history);

    while (1) {
        printf("\n1. Visit Page");
        printf("\n2. Back");
        printf("\n3. Current Page");
        printf("\n4. Display History");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", page);
                push(&history, page);
                printf("Visited: %s\n", page);
                break;

            case 2:
                if (!isEmpty(&history)) {
                    printf("Going back from: %s\n",
                           history.pages[history.top]);
                    pop(&history);
                } else {
                    printf("No previous page available.\n");
                }
                break;

            case 3:
                currentPage(&history);
                break;

            case 4:
                display(&history);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
